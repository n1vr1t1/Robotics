#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <std_msgs/msg/bool.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <control_msgs/action/follow_joint_trajectory.hpp>
#include <custom_msg_interfaces/msg/start_end_position.hpp>
#include <custom_msg_interfaces/msg/via_points.hpp>

#include <memory>
#include <chrono>
#include <functional>
#include <string>
#include <vector>

using FollowJointTrajectory  = control_msgs::action::FollowJointTrajectory;
using GoalHandleFollowJointTrajectory =  rclcpp_action::ClientGoalHandle<FollowJointTrajectory>;

class TrajectoryExecutionNode : public rclcpp::Node{
    public:
        TrajectoryExecutionNode() : Node("trajectory_execution_node"){
            subscription_trajectory = this->create_subscription<custom_msg_interfaces::msg::ViaPoints>("/computed_trajectory",
                                    rclcpp::QoS(8), std::bind(&TrajectoryExecutionNode::trajectory_callback, this, std::placeholders::_1));  
         
            action_client = rclcpp_action::create_client<control_msgs::action::FollowJointTrajectory>(
            this,
            "/scaled_joint_trajectory_controller/joint_trajectory");
            
            publisher = this->create_publisher<std_msgs::msg::Bool>("trajectory_executed", rclcpp::QoS(8));

            RCLCPP_INFO(this->get_logger(), "TrajectoryExecutionNode initialized");
        }
    private:
      
        void trajectory_callback(const custom_msg_interfaces::msg::ViaPoints::SharedPtr msg){  
            if(msg->status_message.length() < 30){
                RCLCPP_ERROR(this->get_logger(), "Error in computing trajectory");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Received trajectory response with %zu points and %zu joints", msg->trajectory.points.size(), msg->trajectory.joint_names.size());

            auto goal_msg = FollowJointTrajectory::Goal();
            goal_msg.trajectory = msg->trajectory;
            goal_msg.goal_time_tolerance.nanosec = 500000000;
    
            RCLCPP_INFO(this->get_logger(), "Defyning goal callback");
    
            auto send_goal_options = rclcpp_action::Client<FollowJointTrajectory>::SendGoalOptions();
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

           
             RCLCPP_INFO(this->get_logger(), "Defining goal result callback");
            send_goal_options.result_callback =
                [this](const GoalHandleFollowJointTrajectory::WrappedResult &result) {
                    switch (result.code)
                    {
                    case rclcpp_action::ResultCode::SUCCEEDED:
                        RCLCPP_INFO(this->get_logger(), "Goal succeeded");
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

           

             RCLCPP_INFO(this->get_logger(), "Sending trajectory goal");
            action_client ->async_send_goal(goal_msg, send_goal_options);            
        }

        rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr publisher;
        rclcpp_action::Client<control_msgs::action::FollowJointTrajectory>::SharedPtr action_client;
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
