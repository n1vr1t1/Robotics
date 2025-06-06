#pragma once

#include <memory>
#include <vector>
#include <cmath>
#include <rclcpp/rclcpp.hpp>
#include <custom_msg_interfaces/srv/compute_dir_kin.hpp>
#include <custom_msg_interfaces/srv/compute_ik.hpp>
#include <Eigen/Dense>

namespace motion
{
  constexpr double PI = 3.14159265358979323846;
  constexpr float A[6]     = {0.0f, -0.425f, -0.3922f, 0.0f, 0.0f, 0.0f};
  constexpr float D[6]     = {0.1625f, 0.0f, 0.0f, 0.1333f, 0.0997f, 0.0996f};
  constexpr double ALPHA[6]= {PI/2, 0, 0, PI/2, -PI/2, 0};

  class KinematicsNode : public rclcpp::Node
  {
  public:
    KinematicsNode();

  private:
    // Service callbacks
    void computeDirectKinematics(
      const std::shared_ptr<custom_msg_interfaces::srv::ComputeDirKin::Request>  request,
      std::shared_ptr<custom_msg_interfaces::srv::ComputeDirKin::Response>       response);

    void computeInverseKinematics(
      const std::shared_ptr<custom_msg_interfaces::srv::ComputeIK::Request>      request,
      std::shared_ptr<custom_msg_interfaces::srv::ComputeIK::Response>           response);

    // Kin functions
    std::shared_ptr<custom_msg_interfaces::srv::ComputeDirKin::Response>
      ur5Direct(const std::vector<double>& Th, double scale,
                Eigen::Vector3d& pe, Eigen::Matrix3d& Re,
                std::vector<Eigen::Matrix4d>& Tm);

    Eigen::MatrixXd ur5Inverse(const Eigen::Vector3f& p60,
                               const Eigen::Matrix3f& R60,
                               float scale);

    static inline bool almzero(float x) { return std::fabs(x) < 1e-7f; }

    Eigen::Matrix<float,4,4> Tij(float th, float alpha, float d, float a){
      Eigen::Matrix<float,4,4> T;
      float c = static_cast<float>(std::cos(th));
      float s = static_cast<float>(std::sin(th));
      float ca = static_cast<float>(std::cos(alpha));
      float sa = static_cast<float>(std::sin(alpha));
      T << c, -s*ca,  s*sa, a*c,
           s,  c*ca, -c*sa, a*s,
           0,   sa,    ca,  d,
           0,    0,     0,  1;
      return T;
    }

    // Service handles
    rclcpp::Service<custom_msg_interfaces::srv::ComputeDirKin>::SharedPtr dir_service_;
    rclcpp::Service<custom_msg_interfaces::srv::ComputeIK>::SharedPtr      ik_service_;
  };
}
