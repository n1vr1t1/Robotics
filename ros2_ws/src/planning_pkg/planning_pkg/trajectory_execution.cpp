#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <std_msgs/msg/string.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <control_msgs/action/follow_joint_trajectory.hpp>
#include <custom_msg_interfaces/srv/interpolation.hpp>
#include <custom_msg_interfaces/srv/compute_path.hpp>
#include <custom_msg_interfaces/srv/compute_trajectory.hpp>

#include <memory>
#include <chrono>
#include <functional>
#include <string>
#include <vector>

class TrajectoryExecutionNode : public rclcpp::Node{
    public:
        TrajectoryExecutionNode() : Node("trajectory_execution_node"){
            service = this->create_service<custom_msg_interfaces::srv::Interpolation>(
                "interpolation",
                std::bind(&TrajectoryExecutionNode::interpolation_callback, this, std::placeholders::_1, std::placeholders::_2));

            path_client = this->create_client<custom_msg_interfaces::srv::ComputePath>("compute_path");
            trajectory_client = this->create_client<custom_msg_interfaces::srv::ComputeTrajectory>("compute_trajectory"); 
            action_client = rclcpp_action::create_client<control_msgs::action::FollowJointTrajectory>(
            this,
            "/scaled_joint_trajectory_controller/follow_joint_trajectory");
            publisher = this->create_publisher<std_msgs::msg::String>("trajectory_executed", rclcpp::QoS(8));

            RCLCPP_INFO(this->get_logger(), "TrajectoryExecutionNode initialized");
        }
    private:
        void interpolation_callback(const std::shared_ptr<custom_msg_interfaces::srv::Interpolation::Request> request, 
                    std::shared_ptr<custom_msg_interfaces::srv::Interpolation::Response> response){
            // Handle the interpolation request here
            RCLCPP_INFO(this->get_logger(), "Received interpol ation request with start (%f, %f, %f) and end (%f, %f, %f)",
                request->pose_start.position.x, request->pose_start.position.y, request->pose_start.position.z,
                request->pose_end.position.x, request->pose_end.position.y, request->pose_end.position.z);

            std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Request> path_request = std::make_shared<custom_msg_interfaces::srv::ComputePath::Request>();
            path_request->pose_start = request->pose_start;
            path_request->pose_end = request->pose_end;
            path_request->num_interpolations = 4; // to be changed, need to discuss first

            RCLCPP_INFO(this->get_logger(), "Calling service to compute path.");

            // waiting every 1s to check if the service is available, time can be changed
            while (!path_client->wait_for_service(std::chrono::seconds(1))) {
                if (!rclcpp::ok()) {
                    RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for compute PATH service. Exiting interpolation_callback.");
                    response->success = false;
                    response->message = "Failed to enter path service";
                }
                RCLCPP_INFO(this->get_logger(), "Service not available, waiting again...");
            }

            rclcpp::Client<custom_msg_interfaces::srv::ComputePath>::SharedFuture future_path = path_client->async_send_request(path_request).future.share();

            auto future_result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), future_path);
            if(future_result != rclcpp::FutureReturnCode::SUCCESS){
                RCLCPP_ERROR(this->get_logger(), "Failed to call compute_path service");
                response->success = false;
                response->message = "Failed path service";
            }
            RCLCPP_INFO(this->get_logger(), "Path computed successfully.");
            path_client_handler(future_path.get(), response);
            std_msgs::msg::String message;

            if(response->success){
                response->message = "Success";
                message.data = "Success";
                publisher->publish(message);
            }else{
                response->message = "Failed";
                message.data = "Failed";
                publisher->publish(message);
            }
        }
        
        void path_client_handler(const std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Response> path_response,
                                std::shared_ptr<custom_msg_interfaces::srv::Interpolation::Response> interpolation_response){
            if(path_response->poses.size() == 0){
                RCLCPP_ERROR(this->get_logger(), "No poses received from path service");
                interpolation_response->success = false;
                interpolation_response->message = "Failed path service";
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Received path response with %zu points", path_response->poses.size());
            std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory::Request> trajectory_request = std::make_shared<custom_msg_interfaces::srv::ComputeTrajectory::Request>();
            trajectory_request->array = geometry_msgs::msg::PoseArray();
            
            trajectory_request->array.poses = path_response->poses;
            RCLCPP_INFO(this->get_logger(), "Calling service to compute trajectory.");

            while (!trajectory_client->wait_for_service(std::chrono::seconds(1))) {
                if (!rclcpp::ok()) {
                    RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for compute TRAJECTORY service. Exiting.");
                    interpolation_response->success = false;
                    interpolation_response->message = "Failed to enter trajectory service";
                    return;
                }
                RCLCPP_INFO(this->get_logger(), "Service not available, waiting again...");
            }
            rclcpp::Client<custom_msg_interfaces::srv::ComputeTrajectory>::SharedFuture future_trajectory = trajectory_client->async_send_request(trajectory_request).future.share();
            auto future_result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), future_trajectory);
            if(future_result != rclcpp::FutureReturnCode::SUCCESS){
                RCLCPP_ERROR(this->get_logger(), "Failed to call compute_trajectory service");
                interpolation_response->success = false;
                interpolation_response->message = "Failed trajectory service";
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Trajectory computed successfully.");
            trajectory_client_handler(future_trajectory.get(), interpolation_response);

        }
        void trajectory_client_handler(const std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory::Response>  trajectory_response,
                                std::shared_ptr<custom_msg_interfaces::srv::Interpolation::Response> interpolation_response){
            if(trajectory_response->trajectory.points.size() == 0 || trajectory_response->trajectory.joint_names.size() == 0){
                RCLCPP_ERROR(this->get_logger(), "No poses or joints received from trajectory service");
                interpolation_response->success = false;
                interpolation_response->message = "Failed trajectory service";
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Received trajectory response with %zu points and %zu joints", trajectory_response->trajectory.points.size(), trajectory_response->trajectory.joint_names.size());

            // need to check what the possible strings for trajectory_response->status_message are
            
            auto goal = control_msgs::action::FollowJointTrajectory::Goal();
            goal.trajectory = trajectory_response->trajectory;
            goal.trajectory.header.stamp = this->now();
            
            RCLCPP_INFO(this->get_logger(), "Sending trajectory to action server.");
            auto future_goal = action_client->async_send_goal(goal);

            auto future_result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), future_goal);
            if(future_result != rclcpp::FutureReturnCode::SUCCESS){
                RCLCPP_ERROR(this->get_logger(), "Failed to call action service");
                interpolation_response->success = false;
                interpolation_response->message = "Failed action service";
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Action computed successfully.");
            action_client_handler(future_goal.get(), interpolation_response);            
        }
        void action_client_handler(const 
            rclcpp_action::ClientGoalHandle<control_msgs::action::FollowJointTrajectory>::SharedPtr goal_handle, std::shared_ptr<custom_msg_interfaces::srv::Interpolation::Response> interpolation_response){
            if(!goal_handle){
                RCLCPP_ERROR(this->get_logger(), "Trajectory execution rejected from action server");
                interpolation_response->success = false;
                interpolation_response->message = "Failed trajectory execution";

                std_msgs::msg::String message;
                message.data = "Failed";
                publisher->publish(message); //maybe can to change to bool
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Trajectory execution accepted.");
            if(!goal_handle->is_result_aware()){
                RCLCPP_ERROR(this->get_logger(), "Action server is not result aware");
                interpolation_response->success = false;
                interpolation_response->message = "Failed trajectory execution";
                return;
            }


            auto future = action_client->async_get_result(goal_handle);
            if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) != rclcpp::FutureReturnCode::SUCCESS) {
                RCLCPP_ERROR(this->get_logger(), "Failed to get action result");
                interpolation_response->success = false;
                interpolation_response->message = "Failed to get result";
                return;
            }
            
            auto wrapped_result = future.get();
            if (wrapped_result.code != rclcpp_action::ResultCode::SUCCEEDED) {
                RCLCPP_ERROR(this->get_logger(), "Trajectory execution failed with result code: %d", static_cast<int>(wrapped_result.code));
                interpolation_response->success = false;
                interpolation_response->message = "Execution failed";
                return;
            }
            
            RCLCPP_INFO(this->get_logger(), "Trajectory executed successfully.");
            interpolation_response->success = true;
            interpolation_response->message = "Execution succeeded";


            //Substituted with the code above
            /*auto future_result = action_client->async_get_result(goal_handle).get();
            // future_result.wait();
            if(future_result != rclcpp::FutureReturnCode::SUCCESS){
                RCLCPP_ERROR(this->get_logger(), "Failed to execute trajectory");
                interpolation_response->success = false;
                interpolation_response->message = "Failed execution";
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Trajectory executed successfully.");*/
        }

        rclcpp::Client<custom_msg_interfaces::srv::ComputePath>::SharedPtr path_client;
        rclcpp::Client<custom_msg_interfaces::srv::ComputeTrajectory>::SharedPtr trajectory_client;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
        rclcpp_action::Client<control_msgs::action::FollowJointTrajectory>::SharedPtr action_client;
        rclcpp::Service<custom_msg_interfaces::srv::Interpolation>::SharedPtr service;
};
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TrajectoryExecutionNode>();
    rclcpp::spin(node);
    node.reset();
    rclcpp::shutdown();
    return 0;
}
