#pragma once

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <custom_msg_interfaces/msg/start_end_position.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <vector>

namespace motion
{
  class PathPlannerNode : public rclcpp::Node
  {
  public:
    PathPlannerNode();
    
  private:
      // Service and publisher for path planning
      rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr publisher_;
      rclcpp::Subscription<custom_msg_interfaces::msg::StartEndPosition>::SharedPtr subscription_extrema;
      rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr path_publisher;
  
      // Callback for the ComputePath service
      void handle_compute_path(const custom_msg_interfaces::msg::StartEndPosition::SharedPtr msg);
          //const std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Request> request,
          //std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Response> response);


  
      // Helper function to compute interpolated poses between two poses
      std::vector<geometry_msgs::msg::Pose> compute_interpolated_poses(
          const geometry_msgs::msg::Pose& start_pose,
          const geometry_msgs::msg::Pose& end_pose,
          int num_interpolations) const;
  
      // Helper function for linear interpolation
     geometry_msgs::msg::Pose s_lerp(const geometry_msgs::msg::Pose& start, const geometry_msgs::msg::Pose& end, double t) const;
  };
}
