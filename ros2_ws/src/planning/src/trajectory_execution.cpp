#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <std_msgs/msg/bool.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <control_msgs/action/follow_joint_trajectory.hpp>
// #include <custom_msg_interfaces/srv/interpolation.hpp>
#include <custom_msg_interfaces/msg/start_end_position.hpp>
#include <custom_msg_interfaces/msg/via_points.hpp>
// #include <custom_msg_interfaces/srv/compute_trajectory.hpp>

#include <memory>
#include <chrono>
#include <functional>
#include <string>
#include <vector>

class TrajectoryExecutionNode : public rclcpp::Node{
    public:
        TrajectoryExecutionNode() : Node("trajectory_execution_node"){
            subscription_trajectory = this->create_subscription<custom_msg_interfaces::msg::ViaPoints>("/computed_trajectory",
                                    rclcpp::QoS(8), std::bind(&TrajectoryExecutionNode::trajectory_callback, this, std::placeholders::_1));  
            // action_trajectory = this->create_subscription<custom_msg_interfaces::msg::ViaPoints>("/computed_action", //change to the correct topic name
            //                         rclcpp::QoS(8), std::bind(&TrajectoryExecutionNode::action_callback, this, std::placeholders::_1)); 

            
            // service = this->create_service<custom_msg_interfaces::srv::Interpolation>(
            //     "interpolation",
            //     std::bind(&TrajectoryExecutionNode::interpolation_callback, this, std::placeholders::_1, std::placeholders::_2));

            // trajectory_client = this->create_client<custom_msg_interfaces::srv::ComputeTrajectory>("compute_trajectory"); 
            action_client = rclcpp_action::create_client<control_msgs::action::FollowJointTrajectory>(
            this,
            "/scaled_joint_trajectory_controller/joint_trajectory");
            
    
            // extrema_publisher = this->create_publisher<custom_msg_interfaces::msg::StartEndPosition>("/path_extrema", 8);
            publisher = this->create_publisher<std_msgs::msg::Bool>("trajectory_executed", rclcpp::QoS(8));

            RCLCPP_INFO(this->get_logger(), "TrajectoryExecutionNode initialized");
        }
    private:
        // void interpolation_callback(const std::shared_ptr<custom_msg_interfaces::srv::Interpolation::Request> request, 
        //             std::shared_ptr<custom_msg_interfaces::srv::Interpolation::Response> response){
        //     // Handle the interpolation request here
        //     RCLCPP_INFO(this->get_logger(), "Received interpolation request with start (%f, %f, %f) and end (%f, %f, %f)",
        //     request->pose_start.position.x, request->pose_start.position.y, request->pose_start.position.z,
        //     request->pose_end.position.x, request->pose_end.position.y, request->pose_end.position.z);

        //     custom_msg_interfaces::msg::StartEndPosition msg;
        //     msg.pose_start = request->pose_start;
        //     msg.pose_end = request->pose_end;
        //     msg.num_interpolations = 4;

        //     extrema_publisher -> publish(msg);

        //     RCLCPP_INFO(this->get_logger(), "Calling service to compute path.");

        // }
        
        //void path_callback(const std::shared_ptr<geometry_msgs::msg::PoseArray> msg){
        //    if(msg->poses.size() == 0){
        //         RCLCPP_ERROR(this->get_logger(), "No poses received from path service");
        //         return;
        //     }
        //     RCLCPP_INFO(this->get_logger(), "Received path response with %zu points", msg->poses.size());
        //     std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory::Request> trajectory_request = std::make_shared<custom_msg_interfaces::srv::ComputeTrajectory::Request>();
        //     trajectory_request->array = geometry_msgs::msg::PoseArray();
            
        //     trajectory_request->array.poses = msg->poses;
        //     RCLCPP_INFO(this->get_logger(), "Calling service to compute trajectory.");

        //     while (!trajectory_client->wait_for_service(std::chrono::seconds(1))) {
        //         if (!rclcpp::ok()) {
        //             RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for compute TRAJECTORY service. Exiting.");
        //             return;
        //         }
        //         RCLCPP_INFO(this->get_logger(), "Service not available, waiting again...");
        //     }
        //     auto future_trajectory = trajectory_client->async_send_request(trajectory_request);
        //     auto future_result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), future_trajectory);
           
        //     if(future_result != rclcpp::FutureReturnCode::SUCCESS){
        //         RCLCPP_ERROR(this->get_logger(), "Failed to call compute_trajectory service");
        //         return;
        //     }
        //     RCLCPP_INFO(this->get_logger(), "Trajectory computed successfully.");
        //     trajectory_client_handler(future_trajectory.get());

        // }

        //void trajectory_client_handler(const std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory::Response>  trajectory_response){
        void trajectory_callback(const custom_msg_interfaces::msg::ViaPoints::SharedPtr msg){  
            if(msg->status_message.length() < 30){
                RCLCPP_ERROR(this->get_logger(), "Error in computing trajectory");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Received trajectory response with %zu points and %zu joints", msg->trajectory.points.size(), msg->trajectory.joint_names.size());

            auto goal_msg = control_msgs::action::FollowJointTrajectory::Goal();
            goal_msg.trajectory = msg->trajectory;
            goal_msg.goal_time_tolerance.nanosec = 500000000;
    
            RCLCPP_INFO(this->get_logger(), "Sending trajectory goal %zu", current_trajectory_index_ + 1);
    
            auto send_goal_options = rclcpp_action::Client<control_msgs::action::FollowJointTrajectory>::SendGoalOptions();
            send_goal_options.goal_response_callback =
                [this](const GoalHandleFollowJointTrajectory::SharedPtr &goal_handle) {
                    if (!goal_handle)
                    {
                        RCLCPP_ERROR(this->get_logger(), "Goal was rejected by the server");
                    }
                    else
                    {
                        RCLCPP_INFO(this->get_logger(), "Goal accepted by the server, waiting for result");
                    }
                };
    
            send_goal_options.result_callback =
                [this](const control_msgs::action::GoalHandleFollowJointTrajectory::WrappedResult &result) {
                    switch (result.code)
                    {
                    case rclcpp_action::ResultCode::SUCCEEDED:
                        RCLCPP_INFO(this->get_logger(), "Goal %zu succeeded", current_trajectory_index_ + 1);
                        handle_trajectory_success();
                        break;
                    case rclcpp_action::ResultCode::ABORTED:
                        RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
                        break;
                    case rclcpp_action::ResultCode::CANCELED:
                        RCLCPP_WARN(this->get_logger(), "Goal was canceled");
                        break;
                    default:
                        RCLCPP_ERROR(this->get_logger(), "Unknown result code");
                        break;
                    }
                };
    
            action_client ->async_send_goal(goal_msg, send_goal_options);


            
            // auto goal = control_msgs::action::FollowJointTrajectory::Goal();
            // // control_msgs::action::FollowJointTrajectory::Goal goal = control_msgs::action::FollowJointTrajectory::Goal();
            // goal.trajectory = msg->trajectory;
            // // goal.trajectory.header.stamp = this->now();
            // // The header stamp must usually be "now + small_offset" so the controller
            // // doesn't see a fully expired goal. If you stamp it at 'now()', some
            // // controllers will reject if they think the trajectory start time is in
            // // the past. A common trick is:
            // goal.trajectory.header.stamp = this->get_clock()->now() + rclcpp::Duration(0, 500000000); 
            
            // RCLCPP_INFO(this->get_logger(), "Sending trajectory to action server.");
            // // auto future_goal = action_client->async_send_goal(goal);
            // // 3) Send the goal, spinning THIS node until we at least get a GoalHandle
            // auto future_goal_handle = action_client->async_send_goal(goal);

            // // Spin this node until the send_goal handshake completes (or times out)
            //   if (rclcpp::spin_until_future_complete(shared_from_this(), future_goal_handle)
            //       != rclcpp::FutureReturnCode::SUCCESS)
            //   {
            //     RCLCPP_ERROR(this->get_logger(),
            //                  "Failed to receive acknowledgment from FollowJointTrajectory server");
            //     return;
            //   }
            // auto goal_handle = future_goal_handle.get();
            //   if (!goal_handle) {
            //     RCLCPP_ERROR(this->get_logger(),
            //                  "Trajectory execution was rejected by the action server");
            //     std_msgs::msg::Bool message;
            //     message.data = false;
            //     publisher->publish(message);
            //     return;
            //   }
            //   RCLCPP_INFO(this->get_logger(), "Trajectory execution accepted.");
            
            // //auto future_result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), future_goal);
            // // rclcpp::executors::SingleThreadedExecutor temp_executor;
            // // auto traj_temp_node = std::make_shared<rclcpp::Node>("temp_client_node");
            // // temp_executor.add_node(traj_temp_node);
            // // auto future_result = temp_executor.spin_until_future_complete(future_goal);
            // // temp_executor.remove_node(traj_temp_node);

            // // 4) Now spin until the result (we can reuse the same node)
            //   auto future_result = action_client->async_get_result(goal_handle);
            //   if (rclcpp::spin_until_future_complete(shared_from_this(), future_result)
            //       != rclcpp::FutureReturnCode::SUCCESS)
            //   {
            //     RCLCPP_ERROR(this->get_logger(), "Failed to get action result");
            //     return;
            //   }
            
            // // if(future_result != rclcpp::FutureReturnCode::SUCCESS){
            // //     RCLCPP_ERROR(this->get_logger(), "Failed to call action service");
            // //     return;
            // // }
            // // RCLCPP_INFO(this->get_logger(), "Action computed successfully.");
            // // action_client_handler(future_goal.get());         
            // auto wrapped_result = future_result.get();
            //   if (wrapped_result.code != rclcpp_action::ResultCode::SUCCEEDED) {
            //     RCLCPP_ERROR(this->get_logger(),
            //                  "Trajectory execution failed with result code: %d",
            //                  static_cast<int>(wrapped_result.code));
            //     return;
            //   }
            
            //   RCLCPP_INFO(this->get_logger(), "Trajectory executed successfully.");
            //   std_msgs::msg::Bool message;
            //   message.data = true;
            //   publisher->publish(message);
            
        }
        void action_client_handler(const 
            rclcpp_action::ClientGoalHandle<control_msgs::action::FollowJointTrajectory>::SharedPtr goal_handle){
            
            std_msgs::msg::Bool message;
            
            if(!goal_handle){
                RCLCPP_ERROR(this->get_logger(), "Trajectory execution rejected from action server");
                message.data = false;
                publisher->publish(message);
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Trajectory execution accepted.");
            if(!goal_handle->is_result_aware()){
                RCLCPP_ERROR(this->get_logger(), "Action server is not result aware");
                return;
            }


            auto future = action_client->async_get_result(goal_handle);
            if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) != rclcpp::FutureReturnCode::SUCCESS) {
                RCLCPP_ERROR(this->get_logger(), "Failed to get action result");
                return;
            }
            
            auto wrapped_result = future.get();
            if (wrapped_result.code != rclcpp_action::ResultCode::SUCCEEDED) {
                RCLCPP_ERROR(this->get_logger(), "Trajectory execution failed with result code: %d", static_cast<int>(wrapped_result.code));
                return;
            }
            
            RCLCPP_INFO(this->get_logger(), "Trajectory executed successfully.");
            message.data = true;
            publisher->publish(message);

        }

        // rclcpp::Client<custom_msg_interfaces::srv::ComputeTrajectory>::SharedPtr trajectory_client;
        rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr publisher;
        rclcpp_action::Client<control_msgs::action::FollowJointTrajectory>::SharedPtr action_client;
        // rclcpp::Service<custom_msg_interfaces::srv::Interpolation>::SharedPtr service;

        // rclcpp::Publisher<custom_msg_interfaces::msg::StartEndPosition>::SharedPtr extrema_publisher;
        // rclcpp::Subscription<geometry_msgs::msg::PoseArray>::SharedPtr subscription_path;
        rclcpp::Subscription<custom_msg_interfaces::msg::ViaPoints>::SharedPtr subscription_trajectory;

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
