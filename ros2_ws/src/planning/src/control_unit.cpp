#include<rclcpp/rclcpp.hpp>
#include<geometry_msgs/msg/pose.hpp>
#include<geometry_msgs/msg/pose_array.hpp>
#include<std_msgs/msg/string.hpp>
#include<std_srvs/srv/trigger.hpp>
#include<vision_msgs/msg/detection3_d_array.hpp>
#include<vision_msgs/msg/detection3_d.hpp>
#include<tf2_ros/buffer.h>
#include<tf2_ros/transform_listener.h>

#include "custom_msg_interfaces/srv/interpolation.hpp"
//#include "include\globals.hpp"

class ControlNode : public rclcpp::Node{
    public:
        ControlNode() : Node("control_node"),
        tf_buffer(this->get_clock()),
        tf_listener(tf_buffer, this){

            perception_subscription = this->create_subscription<geometry_msgs::msg::PoseArray>(
                "/inference_3d",
                rclcpp::QoS(8),
                std::bind(&ControlNode::perception_callback, this, std::placeholders::_1)
            );
            
            execution_status_subscription = this->create_subscription<std_msgs::msg::String>(
                "/trajectory_executed",
                rclcpp::QoS(8),
                std::bind(&ControlNode::current_task_callback, this, std::placeholders::_1)
            );
            current_block_index = 0;
            current_task_index = 0;
            planned_poses= geometry_msgs::msg::PoseArray();

            current_position = geometry_msgs::msg::Pose().position; 
            // Initialize the starting position of the gripper
            auto base_gripper_tf = tf_buffer.lookupTransform("base", "gripper", tf2::TimePointZero);
            current_position.x = base_gripper_tf.transform.translation.x;
            current_position.y = base_gripper_tf.transform.translation.y;
            current_position.z = base_gripper_tf.transform.translation.z;
            current_position.orientation = base_gripper_tf.transform.rotation;

            publisher = this->create_publisher<geometry_msgs::msg::PoseArray>("/planned_poses", rclcpp::QoS(8));
            RCLCPP_INFO(this->get_logger(), "ControlNode node started"); 
        }
        // ~ControlNode(){
        //     RCLCPP_INFO(this->get_logger(), "ControlNode node has been destroyed");
        // }
    private: 
    void perception_callback(const geometry_msgs::msg::PoseArray::SharedPtr msg){
        // postion_of_all_blocks = msg->detections;
        if (msg->detections.empty()) {
            RCLCPP_WARN(this->get_logger(), "No 3D positions and classes data received");
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Received %d blocks", msg->detections.size());
        for (const auto& block : msg->detections) {
            RCLCPP_INFO(this->get_logger(), "Block ID: %d", block.id);
            RCLCPP_INFO(this->get_logger(), "Position: (%f, %f, %f)", block.pose.position.x, block.pose.position.y, block.pose.position.z);
            RCLCPP_INFO(this->get_logger(), "Orientation: (%f, %f, %f, %f)", block.pose.orientation.x, block.pose.orientation.y, block.pose.orientation.z, block.pose.orientation.w);
        }
        this->destroy_subscription(perception_subscription);
        perception_subscription.reset();

        RCLCPP_INFO(this->get_logger(), "Unsubscribed from vision topic");
        //not called in the other code but maybe this is the entry point to start communicating the coordinates
        processing_current_block();
    }
    void processing_current_block(){
        if (position_of_all_blocks.detections.empty()) {
            RCLCPP_WARN(this->get_logger(), "No blocks detected");
            return;
        }
        if(current_block_index >= position_of_all_blocks.detections.size()) {
            RCLCPP_WARN(this->get_logger(), "No more blocks to process");
            return;
        }
        auto current_block = position_of_all_blocks.detections[current_block_index];
        geometry_msgs::msg::Pose destination = get_block_destination(current_block.class_id);
        if (destination.position.x == -1 && destination.position.y == -1 && destination.position.z == -1) {
            RCLCPP_ERROR(this->get_logger(), "Invalid class ID: %d", current_block.class_id);
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Processing block %d", current_block_index);
        RCLCPP_INFO(this->get_logger(), "Moving to destination: (%f, %f, %f)", destination.position.x, destination.position.y, destination.position.z);
        
        current_task_index = 0;
        planned_poses.poses.clear();

        //getting current position of gripper
        planned_poses.poses.push_back(current_position);

        // moving to a safe height above the block
        geometry_msgs::msg::Pose block_pose = current_block.pose;
        auto block_z = block_pose.position.z;
        block_pose.position.z = SAFE_HEIGHT;
        planned_poses.poses.push_back(block_pose);

        // moving down to the block position
        block_pose.position.z = block_z;
        planned_poses.poses.push_back(block_pose);

        // going back up to the safe height
        lock_pose.position.z = SAFE_HEIGHT;
        planned_poses.poses.push_back(block_pose);

        // moving to the destination
        auto destination_z = destination.position.z;
        destination.position.z = SAFE_HEIGHT;
        planned_poses.poses.push_back(destination);

        // moving down to the destination position
        destination.position.z = destination_z;
        planned_poses.poses.push_back(destination);
        
        // going back up to the safe height
        destination.position.z = SAFE_HEIGHT;
        planned_poses.poses.push_back(destination);

        current_position = destination;

        publisher->publish(planned_poses);
        RCLCPP_INFO(this->get_logger(), "Planned poses published");

        processing_current_task();
    }
    void current_task_callback(const std_msgs::msg::String::SharedPtr msg){
        if (msg->data.find("Success") != std::string::npos) { //maybe can be converted to bool
            current_task_index++;
            if(current_task_index < planned_poses.poses.size()-1){
                processing_current_task();
            }else{
                RCLCPP_INFO(this->get_logger(), "All tasks completed");
                current_block_index++;
                processing_current_block();
            }
        }
    }
    void processing_current_task(){
        if(planned_poses.poses.empty()){
            RCLCPP_WARN(this->get_logger(), "No planned poses available");
            return;
        }

        if(current_task_index == 1){
            gripper_service("/open_gripper");
        }else if(current_task_index == 2){
            gripper_service("/close_gripper");
        }else if(current_task_index == 5){
            gripper_service("/open_gripper");
        }else if(current_task_index == 6){
            gripper_service("/close_gripper"); //maybe not needed or change it to neutral if possible
        }

        if(current_task_index >= planned_poses.poses.size()-1){
            RCLCPP_WARN(this->get_logger(), "No more tasks to process");
            return;
        }
        
        auto interpolation_client = this->create_client<custom_msg_interfaces::srv::Interpolation>("interpolation");

        RCLCPP_INFO(this->get_logger(), "Calling interpolation service");

        while (!interpolation_client->wait_for_service(std::chrono::seconds(1))) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for INTERPOLATION. Exiting.");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Interpolation service not available, waiting again...");
        }

        auto interpolation_request = std::make_shared<custom_msg_interfaces::srv::Interpolation::Request>();
        interpolation_request->pose_start = planned_poses.poses[current_task_index];
        interpolation_request->pose_end = planned_poses.poses[current_task_index + 1];

    
        rclcpp::Client<custom_msg_interfaces::srv::Interpolation>::SharedFuture future_interpolation = trajectory_client->async_send_request(interpolation_request);
        auto future_result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), future_interpolation);
        if(future_result != rclcpp::FutureReturnCode::SUCCESS){
            RCLCPP_ERROR(this->get_logger(), "Failed to call interpolation service");
        }
        auto interpolation_response = future_interpolation.get();
        if(interpolation_response->success){
            RCLCPP_INFO(this->get_logger(), "Interpolation service called successfully");
        }else{
            RCLCPP_ERROR(this->get_logger(), "Failed to call interpolation service");
        }
    }
    void gripper_service(const std::string &service_name){
        auto client = thos->create_client<std_srvs::srv::Trigger>(service_name);
        if (!client->wait_for_service(std::chrono::seconds(1))) {
            RCLCPP_ERROR(this->get_logger(), "Gripper %s not available", service_name.c_str());
            return;
        }
        auto gripper_request = std::make_shared<std_srvs::srv::Trigger::Request>();
        auto future = client->async_send_request(gripper_request);
        auto future_result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
        if (future_result != rclcpp::FutureReturnCode::SUCCESS) {
            RCLCPP_ERROR(this->get_logger(), "Failed to call %s gripper service", service_name.c_str());
            return;
        }
        auto gripper_response = future.get();
        if (gripper_response->success) {
            RCLCPP_INFO(this->get_logger(), "Gripper %s successfully", service_name.c_str());
        } else {
            RCLCPP_ERROR(this->get_logger(), "Failed to %s gripper", service_name.c_str());
        }
    }
    rclcpp::Subscription<geometry_msgs::msg::PoseArray>::SharedPtr perception_subscription;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr execution_status_subscription;
    rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr publisher; //for visualization ?
    vision_msgs::msg::Detection3DArray position_of_all_blocks;
    int current_block_index;
    int current_task_index;
    geometry_msgs::msg::Pose current_position;
    geometry_msgs::msg::PoseArray planned_poses;
    tf2_ros::Buffer tf_buffer;
    tf2_ros::TransformListener tf_listener;

}
geometry_msgs::msg::Pose get_block_destination(int class_id){
    geometry_msgs::msg::Pose destination = geometry_msgs::msg::Pose();
    destination.position.z = 0.028; // Default height

    switch (class_id) {
        case 0: //X1_Y1_Z2
            destination.position.x = 0.0;
            destination.position.y = 0.0;
            destination.position.z = 0.019;
            break;
        case 1: //X1_Y2_Z1
            destination.position.x = 0.0;
            destination.position.y = 0.0;
            break;
        case 2: //X1_Y2_Z2
            destination.position.x = 0.0;
            destination.position.y = 0.0;
            break;
        case 3: //X1_Y2_Z2_CHAMFER
            destination.position.x = 0.0;
            destination.position.y = 0.0;
            break;
        case 4: //X1_Y2_Z2_TWINFILLET
            destination.position.x = 0.0;
            destination.position.y = 0.0;
            break;
        case 5:  //X1_Y3_Z2
            destination.position.x = 0.0;
            destination.position.y = 0.0;
            break;
        case 6: //X1_Y3_Z2_FILLET
            destination.position.x = 0.0;
            destination.position.y = 0.0;
            break;
        case 7:  //X1_Y4_Z1
            destination.position.x = 0.0;
            destination.position.y = 0.0;
            break;
        case 8: //X1_Y4_Z2
            destination.position.x = 0.0;
            destination.position.y = 0.0;
            break; 
        case 9: //X2_Y2_Z2
            destination.position.x = 0.0; 
            destination.position.y = 0.0; 
            destination.position.z = 0.019; 
            break; 
        case 10: //X2_Y2_Z2_FILLET
            destination.position.x = 0.0;
            destination.position.y = 0.0;  
            break;
        default:
            destination.position.x = -1;
            destination.position.y = -1;
            destination.position.z = -1; // Invalid class ID
            break;
    }
    return destination;
}
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ControlNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
