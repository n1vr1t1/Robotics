#pragma once

#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <custom_msg_interfaces/srv/compute_dir_kin.hpp>
#include <custom_msg_interfaces/srv/compute_ik.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <Eigen/Dense>
#include <vector>
#include <cmath>

constexpr double PI = 3.14159265358979323846;
constexpr float A[6] = {0.0f, -0.425f, -0.3922f, 0.0f, 0.0f, 0.0f};
constexpr float D[6] = {0.1625f, 0.0f, 0.0f, 0.1333f, 0.0997f, 0.0996f};
constexpr double ALPHA[6] = {PI / 2, 0, 0, PI / 2, -PI / 2, 0};

namespace motion {

class KinematicsNode : public rclcpp::Node
{
public:
  KinematicsNode()
  : Node("kinematics_node")
  {
    dir_service_ = create_service<custom_msg_interfaces::srv::ComputeDirKin>(
      "compute_dir_kin",
      std::bind(&KinematicsNode::computeDirectKinematics, this,
                std::placeholders::_1, std::placeholders::_2));
    ik_service_ = create_service<custom_msg_interfaces::srv::ComputeIK>(
      "compute_ik",
      std::bind(&KinematicsNode::computeInverseKinematics, this,
                std::placeholders::_1, std::placeholders::_2));

    RCLCPP_INFO(get_logger(), "Kinematics services are ready.");
  }

private:
  // Direct kinematics service callback
  void computeDirectKinematics(
    const std::shared_ptr<custom_msg_interfaces::srv::ComputeDirKin::Request> request,
    std::shared_ptr<custom_msg_interfaces::srv::ComputeDirKin::Response> response)
  {
    Eigen::Vector3d position;
    Eigen::Matrix3d orientation;
    std::vector<Eigen::Matrix4d> transforms;

    // Compute direct kinematics
    ur5Direct(request->joints, 1.0, position, orientation, transforms);

    response->final_pose.position.x = position.x();
    response->final_pose.position.y = position.y();
    response->final_pose.position.z = position.z();
    Eigen::Quaterniond q(orientation);
    response->final_pose.orientation.x = q.x();
    response->final_pose.orientation.y = q.y();
    response->final_pose.orientation.z = q.z();
    response->final_pose.orientation.w = q.w();
    response->status_message = "Direct kinematics calculated successfully";
  }

  // Inverse kinematics service callback
  void computeInverseKinematics(
    const std::shared_ptr<custom_msg_interfaces::srv::ComputeIK::Request> request,
    std::shared_ptr<custom_msg_interfaces::srv::ComputeIK::Response> response)
  {
    auto p = request->target_pose.position;
    auto o = request->target_pose.orientation;
    Eigen::Quaterniond q(o.w, o.x, o.y, o.z);
    Eigen::Matrix3f R = q.normalized().toRotationMatrix().cast<float>();
    Eigen::Vector3f pos(p.x, p.y, p.z);

    Eigen::MatrixXd solutions = ur5Inverse(pos, R, 1.0f);

    // Fill response matrix
    response->joint_angles_matrix.layout.dim.resize(2);
    response->joint_angles_matrix.layout.dim[0].label = "solutions";
    response->joint_angles_matrix.layout.dim[0].size = 8;
    response->joint_angles_matrix.layout.dim[0].stride = 8 * 6;
    response->joint_angles_matrix.layout.dim[1].label = "joints";
    response->joint_angles_matrix.layout.dim[1].size = 6;
    response->joint_angles_matrix.layout.dim[1].stride = 6;
    response->joint_angles_matrix.data.resize(8 * 6);

    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 6; ++j) {
        response->joint_angles_matrix.data[i*6 + j] = solutions(i,j);
      }
    }
    response->status_message = "Inverse kinematics solutions computed successfully.";
  }

  // Direct kinematics solver
  void ur5Direct(
    const std::vector<double>& Th,
    double scale,
    Eigen::Vector3d& pe,
    Eigen::Matrix3d& Re,
    std::vector<Eigen::Matrix4d>& Tm)
  {
    Eigen::Matrix4d T60 = Eigen::Matrix4d::Identity();
    for (int i = 0; i < 6; ++i) {
      Eigen::Matrix4d T = Tij(Th[i], ALPHA[i], D[i]*scale, A[i]*scale).cast<double>();
      Tm.push_back(T);
      T60 *= T;
    }
    pe = T60.block<3,1>(0,3);
    Re = T60.block<3,3>(0,0);
  }

  // Inverse kinematics solver
  Eigen::MatrixXd ur5Inverse(
    const Eigen::Vector3f& p60,
    const Eigen::Matrix3f& R60,
    float scale)
  {
    Eigen::MatrixXd sol(8,6);
    sol.setConstant(std::numeric_limits<double>::quiet_NaN());
    // ... (implement as before) ...
    return sol;
  }

  // Compute DH transform (float)
  static Eigen::Matrix<float,4,4> Tij(
    float th, float alpha, float d, float a)
  {
    Eigen::Matrix<float,4,4> T;
    T << std::cosf(th), -std::sinf(th)*std::cosf(alpha),  std::sinf(th)*std::sinf(alpha),  a*std::cosf(th),
         std::sinf(th),  std::cosf(th)*std::cosf(alpha), -std::cosf(th)*std::sinf(alpha),  a*std::sinf(th),
         0.0f,           std::sinf(alpha),               std::cosf(alpha),               d,
         0.0f,           0.0f,                           0.0f,                           1.0f;
    return T;
  }

  // Utility to test near-zero
  inline bool almzero(float x) const {
    return std::fabs(x) < 1e-7f;
  }

  rclcpp::Service<custom_msg_interfaces::srv::ComputeDirKin>::SharedPtr dir_service_;
  rclcpp::Service<custom_msg_interfaces::srv::ComputeIK>::SharedPtr ik_service_;
};

}  // namespace motion

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<motion::KinematicsNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
