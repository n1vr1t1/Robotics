#pragma once

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
#include <trajectory_msgs/msg/joint_trajectory_point.hpp>
#include <custom_msg_interfaces/srv/compute_trajectory.hpp>
#include <custom_msg_interfaces/srv/compute_ik.hpp>


#include <vector>
#include <array>
#include <sstream>
#include <limits>
#include <algorithm>
#include <chrono>
#include <cmath>  // For std::isnan
#include <iostream>
#include <Eigen/Dense>

using namespace std::chrono_literals;  

std::array<double, 4> compute_cubic_coefficients(double q0, double q1, double v0, double v1, double T);

trajectory_msgs::msg::JointTrajectory generate_cubic_trajectory(const std::vector<std::array<double, 6>>& waypoints,
    double segment_time);

class ComputeTrajectoryService : public rclcpp::Node {
public:
  ComputeTrajectoryService();
private:
   rclcpp::Service<custom_msg_interfaces::srv::ComputeTrajectory>::SharedPtr service_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_subscriber_;
    rclcpp::Node::SharedPtr ik_client_node_;
    rclcpp::Client<custom_msg_interfaces::srv::ComputeIK>::SharedPtr ik_client_;

    std::vector<double> initial_joint_array_;
    bool received_initial_joints_;
  
  void print_joint_angles_matrix(const std::vector<double> &matrix);

  void joint_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg);

  std::vector<double> select_closest_one(const std::vector<double> &prev_joints,const std::vector<double> &joint_angles_matrix);

  bool ur5_singAvoid(const Eigen::VectorXd &Th, double scaleFactor);

  Eigen::Matrix4d Tij(double theta, double alpha, double d, double a);

  std::vector<Eigen::Matrix4d> computeChainFK(const Eigen::VectorXd &Th, double scaleFactor);

  void compute_trajectory_callback(
        const std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory::Request> request,
        std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory::Response> response);

};








