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
#include "custom_msg_interfaces/msg/class_pose.hpp"

const double SAFE_HEIGHT = 0.5;
const double TABLE_HEIGHT = 1.0; // MAYBE 0.9
float CAMERA_COORDINATES[] = {0.7f, 0.0f, 1.580f};

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

class ControlNode : public rclcpp::Node{
    public:
        ControlNode() : Node("control_node"),
        tf_buffer(this->get_clock()),
        tf_listener(tf_buffer, this){

            perception_subscription = this->create_subscription<custom_msg_interfaces::msg::ClassPose>(
                "/inference_3d",
                rclcpp::QoS(8),
                std::bind(&ControlNode::perception_callback, this, std::placeholders::_1)
            );
            
            execution_status_subscription = this->create_subscription<std_msgs::msg::String>(
                "/trajectory_executed",
                rclcpp::QoS(8),
                std::bind(&ControlNode::current_task_callback, this, std::placeholders::_1)
            );
            current_task_index = 0;
            planned_poses= geometry_msgs::msg::PoseArray();

            // Initialize current_pose to a default safe pose first
            current_pose.position.x = 0.0; // change to a known safe x
            current_pose.position.y = 0.0; // change to a known safe  y
            current_pose.position.z = SAFE_HEIGHT;
            current_pose.orientation.w = 1.0; // Default orientation (no rotation)
            RCLCPP_INFO(this->get_logger(), "Set initial gripper pose to default safe pose. Attempting to update from TF...");

            while(rclcpp::ok()){
                try {
                    auto base_gripper_tf = tf_buffer.lookupTransform("base", "gripper", tf2::TimePointZero, tf2::durationFromSec(1.0));
                    current_pose.position.x = base_gripper_tf.transform.translation.x;
                    current_pose.position.y = base_gripper_tf.transform.translation.y;
                    current_pose.position.z = base_gripper_tf.transform.translation.z;
                    current_pose.orientation = base_gripper_tf.transform.rotation;
                    RCLCPP_INFO(this->get_logger(), "Successfully updated initial gripper pose from TF: (%f, %f, %f)", current_pose.position.x, current_pose.position.y, current_pose.position.z);
                    break; // Exit loop if transform is successful
                } catch (const tf2::TransformException & ex) {
                    RCLCPP_WARN(this->get_logger(), "Could not get initial gripper pose from TF: %s. Retrying...", ex.what());
                }
                rclcpp::sleep_for(std::chrono::seconds(1)); // Wait a bit before retrying
            }
            
            if (!rclcpp::ok() && !(current_pose.position.x != 0.0 || current_pose.position.y != 0.0 || current_pose.position.z != SAFE_HEIGHT)) {
                RCLCPP_WARN(this->get_logger(), "Node is shutting down and initial gripper pose could not be obtained from TF. Using default safe pose.");
            }

            publisher = this->create_publisher<geometry_msgs::msg::PoseArray>("/planned_poses", rclcpp::QoS(8));
            RCLCPP_INFO(this->get_logger(), "ControlNode node started"); 
        }
        // ~ControlNode(){
        //     RCLCPP_INFO(this->get_logger(), "ControlNode node has been destroyed");
        // }
    private: 
    void perception_callback(const custom_msg_interfaces::msg::ClassPose::SharedPtr msg){
        if (msg->poses.empty() || msg->class_ids.empty()) {
            RCLCPP_WARN(this->get_logger(), "No 3D positions and classes data received");
            return;
        }
        if( msg->class_ids.size() != msg->poses.size()){
            RCLCPP_WARN(this->get_logger(), "Mismatch between number of poses and class IDs");
            return;
        }
        if (msg->poses.size() != static_cast<size_t>(msg->len)){
            RCLCPP_WARN(this->get_logger(), "Mismatch between number of blocks detected and length");
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Received %u blocks", msg->len);
        for (int i = 0; i < msg->len; ++i){
            auto block = msg->poses[i];
            RCLCPP_INFO(this->get_logger(), "Block ID: %d", msg->class_ids[i]);
            RCLCPP_INFO(this->get_logger(), "Position: (%f, %f, %f)", block.position.x, block.position.y, block.position.z);
            RCLCPP_INFO(this->get_logger(), "Orientation: (%f, %f, %f, %f)", block.orientation.x, block.orientation.y, block.orientation.z, block.orientation.w);
        }
        blocks = msg;
        perception_subscription.reset();

        RCLCPP_INFO(this->get_logger(), "Unsubscribed from vision topic");
        //not called in the other code but maybe this is the entry point to start communicating the coordinates
        for(int cb=0; cb<blocks->len; cb++){
            processing_current_block(cb);
        }
    }
    void processing_current_block(int current_block_index){
        if (!blocks || blocks->poses.empty() || blocks->class_ids.empty()) {
            RCLCPP_WARN(this->get_logger(), "blocks was never initialized");
            return;
        }
        if(current_block_index >= blocks->len) {
            RCLCPP_WARN(this->get_logger(), "No more blocks to process");
            return;
        }
        geometry_msgs::msg::Pose block_pose = blocks->poses[current_block_index];
        int block_class_id = blocks->class_ids[current_block_index];
        geometry_msgs::msg::Pose destination = get_block_destination(block_class_id);
        if (destination.position.x == -1 && destination.position.y == -1 && destination.position.z == -1) {
            RCLCPP_ERROR(this->get_logger(), "Invalid class ID: %d", block_class_id);
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Processing block %d", current_block_index);
        RCLCPP_INFO(this->get_logger(), "Moving to destination: (%f, %f, %f)", destination.position.x, destination.position.y, destination.position.z);
        
        current_task_index = 0;
        planned_poses.poses.clear();

        //getting current position of gripper
        planned_poses.poses.push_back(current_pose);

        // moving to a safe height above the block
        auto block_z = block_pose.position.z;
        block_pose.position.z = SAFE_HEIGHT;
        planned_poses.poses.push_back(block_pose);

        // moving down to the block position
        block_pose.position.z = block_z;
        planned_poses.poses.push_back(block_pose);

        // going back up to the safe height
        block_pose.position.z = SAFE_HEIGHT;
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

        current_pose = destination;

        publisher->publish(planned_poses);
        RCLCPP_INFO(this->get_logger(), "Planned poses published");

        processing_current_task();
    }
    void current_task_callback(const std_msgs::msg::String::SharedPtr msg){
        if (msg->data.find("Success") != std::string::npos) { //maybe can be converted to bool
            current_task_index++;
            processing_current_task();
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
            RCLCPP_WARN(this->get_logger(), "No more tasks to process for the current block segment."); // Clarified log
            return;
        }
        
        auto interpolation_client = this->create_client<custom_msg_interfaces::srv::Interpolation>("interpolation");

        RCLCPP_INFO(this->get_logger(), "Calling interpolation service for task index %ld", current_task_index);

        while (!interpolation_client->wait_for_service(std::chrono::seconds(1))) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for INTERPOLATION service. Exiting.");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Interpolation service not available, waiting again...");
        }

        auto interpolation_request = std::make_shared<custom_msg_interfaces::srv::Interpolation::Request>();
        interpolation_request->pose_start = planned_poses.poses[current_task_index];
        interpolation_request->pose_end = planned_poses.poses[current_task_index + 1];

        const int max_retries = 3;
        int retry_count = 0;
        bool success = false;

        while(retry_count < max_retries && !success) {
            if (retry_count > 0) {
                RCLCPP_INFO(this->get_logger(), "Retrying interpolation service call (attempt %d/%d)...", retry_count + 1, max_retries);
                rclcpp::sleep_for(std::chrono::seconds(1));
            }

            rclcpp::Client<custom_msg_interfaces::srv::Interpolation>::SharedFuture future_interpolation = interpolation_client->async_send_request(interpolation_request).future.share();
            auto future_result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), future_interpolation);
            
            if(future_result != rclcpp::FutureReturnCode::SUCCESS){
                RCLCPP_ERROR(this->get_logger(), "Failed to call interpolation service (communication issue, attempt %d).", retry_count + 1);
            } else {
                auto interpolation_response = future_interpolation.get();
                if(interpolation_response->success){
                    RCLCPP_INFO(this->get_logger(), "Interpolation service call successful (attempt %d).", retry_count + 1);
                    success = true;
                } else {
                    RCLCPP_ERROR(this->get_logger(), "Interpolation service reported failure (e.g., unable to generate trajectory, attempt %d).", retry_count + 1);
                }
            }
            retry_count++;
        }

        if (!success) {
            RCLCPP_FATAL(this->get_logger(), "Failed to get successful interpolation after %d retries for task index %ld. Cannot process current block.", max_retries, current_task_index);
            return;
        }
    }
    void gripper_service(const std::string &service_name){
        auto client = this->create_client<std_srvs::srv::Trigger>(service_name);
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
    rclcpp::Subscription<custom_msg_interfaces::msg::ClassPose>::SharedPtr perception_subscription;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr execution_status_subscription;
    rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr publisher; //for visualization ?
    custom_msg_interfaces::msg::ClassPose::SharedPtr blocks;
    size_t current_task_index;
    geometry_msgs::msg::Pose current_pose;
    geometry_msgs::msg::PoseArray planned_poses; 
    tf2_ros::Buffer tf_buffer;
    tf2_ros::TransformListener tf_listener;

};
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ControlNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
