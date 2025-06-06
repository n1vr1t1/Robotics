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
constexpr double ALPHA[6] = {PI / 2, 0, 0, PI / 2, -PI / 2, 0};


namespace motion
{
    class DirectKinServer : public rclcpp::Node{
        public:
            DirectKinServer();
        
        private:

            void computeDirectKinematics( const std::shared_ptr<custom_msg_interfaces::srv::ComputeDirKin::Request> request, std::shared_ptr<custom_msg_interfaces::srv::ComputeDirKin::Response> response);
            std::shared_ptr<custom_msg_interfaces::srv::ComputeDirKin::Response> ur5Direct(const std::vector<double>& Th, double scaleFactor, Eigen::Vector3d& pe, Eigen::Matrix3d& Re, std::vector<Eigen::Matrix4d>& Tm);
            rclcpp::Service<custom_msg_interfaces::srv::ComputeDirKin>::SharedPtr service_;

        };


    class InverseKinServer : public rclcpp::Node{
        public:
          explicit InverseKinServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());
          
        private:
          void computeIKCallback(
            const std::shared_ptr<custom_msg_interfaces::srv::ComputeIK::Request> request,
            std::shared_ptr<custom_msg_interfaces::srv::ComputeIK::Response>      response);
        
          Eigen::MatrixXd ur5Inverse(const Eigen::Vector3f & p60, const Eigen::Matrix3f & R60, float scaleFactor);
    
      inline bool almzero(float x) const{      
        return std::fabs(x) < 1e-7;
      }
    
    private:
      rclcpp::Service<custom_msg_interfaces::srv::ComputeIK>::SharedPtr service_;
    };

    Eigen::Matrix4f Tij(double th, double alpha, double d, double a){
        Eigen::Matrix<float,4,4> T;
        T << std::cos(th), -std::sin(th) * std::cos(alpha), std::sin(th) * std::sin(alpha), a * std::cos(th),
             std::sin(th), std::cos(th) * std::cos(alpha), -std::cos(th) * std::sin(alpha), a * std::sin(th),
             0, std::sin(alpha), std::cos(alpha), d,
             0, 0, 0, 1;
        return T;
    }
}  


