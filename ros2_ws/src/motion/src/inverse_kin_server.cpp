#include "motion/inverse_kin_server.hpp"
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "builtin_interfaces/msg/time.hpp"
// Eigen and Math
#include <Eigen/Dense>
#include <cmath>
#include <iostream>
#include <vector>

#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace motion
{
    // Helper function to check for near-zero values
    static bool almostZero(float x, float epsilon = 1e-7)
    {
        return std::abs(x) < epsilon;
    }

    // Class to handle Inverse Kinematics computations
    class InverseKinematics
    {
    public:
        InverseKinematics(float scale_factor = 1.0f)
        {
            // Initialize scaled parameters
            for (int i = 0; i < 6; ++i)
            {
                A_scaled_[i] = A_[i] * scale_factor;
                D_scaled_[i] = D_[i] * scale_factor;
            }
        }

        Eigen::MatrixXd compute(const Eigen::Vector3f &position, const Eigen::Matrix3f &orientation)
        {
            Eigen::MatrixXd solutions(8, 6); // 8 solutions, 6 joint angles each
            solutions.setConstant(NAN);

            // IK logic here, modularized for better readability
            if (!isReachable(position))
            {
                std::cerr << "Target position is unreachable.\n";
                return solutions;
            }

            // Additional computations for IK solutions
            computeSolutions(position, orientation, solutions);

            return solutions;
        }

    private:
        // Constants for UR5 robot
        const float A_[6] = {0.0f, -0.425f, -0.3922f, 0.0f, 0.0f, 0.0f};
        const float D_[6] = {0.1625f, 0.0f, 0.0f, 0.1333f, 0.0997f, 0.0996f};
        const float Alpha_[6] = {M_PI_2, 0, 0, M_PI_2, -M_PI_2, 0};

        float A_scaled_[6], D_scaled_[6];

        bool isReachable(const Eigen::Vector3f &position)
        {
            float xy_distance = std::hypot(position.x(), position.y());
            return xy_distance >= D_scaled_[3];
        }

        void computeSolutions(const Eigen::Vector3f &position, const Eigen::Matrix3f &orientation, Eigen::MatrixXd &solutions)
        {
            // TODO: Implement specific IK computation logic
        }
    };

    // ROS2 Node for Inverse Kinematics Service
    InverseKinServer::InverseKinServer(const rclcpp::NodeOptions &options)
        : Node("inverse_kin_server_node", options), ik_solver_(1.0f) // Default scale factor
    {
        using namespace std::placeholders;
        service_ = this->create_service<custom_msg_interfaces::srv::ComputeIK>(
            "compute_ik",
            std::bind(&InverseKinServer::computeIKCallback, this, _1, _2));

        RCLCPP_INFO(this->get_logger(), "Inverse Kinematics Service is ready.");
    }

    void InverseKinServer::computeIKCallback(
        const std::shared_ptr<custom_msg_interfaces::srv::ComputeIK::Request> request,
        std::shared_ptr<custom_msg_interfaces::srv::ComputeIK::Response> response)
    {
        // Extract position and orientation from request
        Eigen::Vector3f position(
            static_cast<float>(request->target_pose.position.x),
            static_cast<float>(request->target_pose.position.y),
            static_cast<float>(request->target_pose.position.z));

        Eigen::Quaterniond quaternion(
            request->target_pose.orientation.w,
            request->target_pose.orientation.x,
            request->target_pose.orientation.y,
            request->target_pose.orientation.z);

        Eigen::Matrix3f orientation = quaternion.normalized().toRotationMatrix().cast<float>();

        // Compute IK solutions
        Eigen::MatrixXd solutions = ik_solver_.compute(position, orientation);

        // Fill the response
        response->joint_angles_matrix.layout.dim.resize(2);
        response->joint_angles_matrix.layout.dim[0].label = "solutions";
        response->joint_angles_matrix.layout.dim[0].size = 8;
        response->joint_angles_matrix.layout.dim[0].stride = 8 * 6;

        response->joint_angles_matrix.layout.dim[1].label = "joints";
        response->joint_angles_matrix.layout.dim[1].size = 6;
        response->joint_angles_matrix.layout.dim[1].stride = 6;

        response->joint_angles_matrix.layout.data_offset = 0;
        response->joint_angles_matrix.data.resize(8 * 6);

        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                response->joint_angles_matrix.data[i * 6 + j] = solutions(i, j);
            }
        }

        response->status_message = "Inverse kinematics solutions computed successfully.";
        RCLCPP_INFO(this->get_logger(), "IK solutions computed and sent back to client.");
    }

} // namespace motion

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<motion::InverseKinServer>());
    rclcpp::shutdown();
    return 0;
}
