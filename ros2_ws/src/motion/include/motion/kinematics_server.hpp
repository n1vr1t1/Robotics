#pragma once

#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <custom_msg_interfaces/srv/compute_dir_kin.hpp>
#include "custom_msg_interfaces/srv/compute_ik.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include <geometry_msgs/msg/pose.hpp>
#include <Eigen/Dense>
#include <vector>
#include <string>
#include <cmath>

constexpr double PI = 3.14159265358979323846;
constexpr float A[6] = {0.0f, -0.425f, -0.3922f, 0.0f, 0.0f, 0.0f};
constexpr float D[6] = {0.1625f, 0.0f, 0.0f, 0.1333f, 0.0997f, 0.0996f};
constexpr double ALPHA = {PI / 2, 0, 0, PI / 2, -PI / 2, 0};


// Forward-declare the class
namespace motion
{
    class DirectKinServer : public rclcpp::Node
    {
    public:
        DirectKinServer();
    
    private:
        // Service callback function
        void computeDirectKinematics(
            const std::shared_ptr<custom_msg_interfaces::srv::ComputeDirKin::Request> request,
            std::shared_ptr<custom_msg_interfaces::srv::ComputeDirKin::Response> response);
    
        // Utility functions
        Eigen::Matrix4d Tij(double th, double alpha, double d, double a);
        void ur5Direct(const std::vector<double>& Th, double scaleFactor, Eigen::Vector3d& pe, Eigen::Matrix3d& Re, std::vector<Eigen::Matrix4d>& Tm);
    
        rclcpp::Service<custom_msg_interfaces::srv::ComputeDirKin>::SharedPtr service_;
    };


    class InverseKinServer : public rclcpp::Node
    {
    public:
      explicit InverseKinServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());
      
    private:
      // Callback for the "ComputeIK" service
      void computeIKCallback(
        const std::shared_ptr<custom_msg_interfaces::srv::ComputeIK::Request> request,
        std::shared_ptr<custom_msg_interfaces::srv::ComputeIK::Response>      response);
    
      // Our UR5 IK solver function adapted from your code
      // (uses single-precision floats internally, but we will convert to double in the response)
      Eigen::MatrixXd ur5Inverse(
        const Eigen::Vector3f & p60, 
        const Eigen::Matrix3f & R60, 
        float scaleFactor
      );
    
      // A small helper function to check for near-zero float values
      inline bool almzero(float x) const
      {
        return std::fabs(x) < 1e-7;
      }
    
    private:
      rclcpp::Service<custom_msg_interfaces::srv::ComputeIK>::SharedPtr service_;
    };
}  // namespace motion


