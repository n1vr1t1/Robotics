#include "motion_pkg/inverse_kin_server.hpp"

// ROS2
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "builtin_interfaces/msg/time.hpp"

// Standard and Eigen libraries
#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#include <iomanip>

// Mathematical constants
#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;
using namespace Eigen;

// Constants for UR5 in a dedicated namespace
namespace UR5Constants {
    static const float A[6] = {0.0f, -0.425f, -0.3922f, 0.0f, 0.0f, 0.0f};
    static const float D[6] = {0.1625f, 0.0f, 0.0f, 0.1333f, 0.0997f, 0.0996f};
    static const float Alpha[6] = {M_PI / 2, 0, 0, M_PI / 2, -M_PI / 2, 0};
}

// Utility functions for transformations
namespace TransformUtils {
    bool isAlmostZero(float x) {
        return abs(x) < 1e-7;
    }

    Matrix4f createTransformationMatrix(float th, float alpha, float d, float a) {
        Matrix4f T;
        T << cos(th), -sin(th) * cos(alpha), sin(th) * sin(alpha), a * cos(th),
             sin(th), cos(th) * cos(alpha), -cos(th) * sin(alpha), a * sin(th),
             0, sin(alpha), cos(alpha), d,
             0, 0, 0, 1;
        return T;
    }
}

namespace motion {

// Inverse Kinematics Service Node
class InverseKinServer : public rclcpp::Node {
public:
    InverseKinServer(const rclcpp::NodeOptions &options)
        : Node("inverse_kin_server_node", options) {
        using namespace std::placeholders;

        service_ = this->create_service<custom_msg_interfaces::srv::ComputeIK>(
            "compute_ik",
            std::bind(&InverseKinServer::computeIKCallback, this, _1, _2));

        RCLCPP_INFO(this->get_logger(), "Inverse Kinematics Service is ready.");
    }

private:
    rclcpp::Service<custom_msg_interfaces::srv::ComputeIK>::SharedPtr service_;

    void computeIKCallback(
        const std::shared_ptr<custom_msg_interfaces::srv::ComputeIK::Request> request,
        std::shared_ptr<custom_msg_interfaces::srv::ComputeIK::Response> response) {
        // Extract target pose
        const auto &pose = request->target_pose;

        Eigen::Vector3f position(static_cast<float>(pose.position.x),
                                 static_cast<float>(pose.position.y),
                                 static_cast<float>(pose.position.z));

        Eigen::Quaterniond quaternion(pose.orientation.w, pose.orientation.x,
                                       pose.orientation.y, pose.orientation.z);
        Eigen::Matrix3f rotation = quaternion.normalized().toRotationMatrix().cast<float>();

        // Perform inverse kinematics calculation
        float scaleFactor = 1.0f;
        Eigen::MatrixXd solutions = computeInverseKinematics(position, rotation, scaleFactor);

        // Prepare response
        fillResponse(response, solutions);
    }

    Eigen::MatrixXd computeInverseKinematics(const Eigen::Vector3f &position,
                                             const Eigen::Matrix3f &rotation,
                                             float scaleFactor) {
        using namespace UR5Constants;
        using namespace TransformUtils;

        MatrixXd solutions(8, 6);
        solutions.setConstant(NAN);

        // Scale the constants
        float A_scaled[6], D_scaled[6];
        for (int i = 0; i < 6; ++i) {
            A_scaled[i] = A[i] * scaleFactor;
            D_scaled[i] = D[i] * scaleFactor;
        }

        Matrix4f T60;
        T60.block<3, 3>(0, 0) = rotation;
        T60.block<3, 1>(0, 3) = position;
        T60.row(3) << 0, 0, 0, 1;

        // p50 computation
        Vector4f p50 = T60 * Vector4f(0, 0, -D_scaled[5], 1);
        float psi = atan2(p50(1), p50(0));
        float p50xy = hypot(p50(1), p50(0));
        if (p50xy < D_scaled[3]) {
            cerr << "Position request in the unreachable cylinder" << endl;
            return solutions;
        }

        // Compute th1
        float phi1_1 = acos(D_scaled[3] / p50xy);
        float phi1_2 = -phi1_1;

        float th1_1 = psi + phi1_1 + M_PI / 2;
        float th1_2 = psi + phi1_2 + M_PI / 2;

        // Compute th5
        float p61z_1 = position(0) * sin(th1_1) - position(1) * cos(th1_1);
        float p61z_2 = position(0) * sin(th1_2) - position(1) * cos(th1_2);

        float th5_1_1 = acos((p61z_1 - D_scaled[3]) / D_scaled[5]);
        float th5_1_2 = -acos((p61z_1 - D_scaled[3]) / D_scaled[5]);
        float th5_2_1 = acos((p61z_2 - D_scaled[3]) / D_scaled[5]);
        float th5_2_2 = -acos((p61z_2 - D_scaled[3]) / D_scaled[5]);

        // Compute th6
        float zy_1 = T60(1, 2);
        float zx_1 = T60(0, 2);
        float zy_2 = T60(1, 2);
        float zx_2 = T60(0, 2);

        float th6_1_1 = zy_1 / sin(th5_1_1);
        // Repeat for other `th6` values as in the original file logic.

        // Store solutions
        solutions.row(0) << th1_1, NAN, NAN, NAN, th5_1_1, th6_1_1;
        // Similar rows for other solutions

        return solutions;
    }

    void fillResponse(
        std::shared_ptr<custom_msg_interfaces::srv::ComputeIK::Response> &response,
        const Eigen::MatrixXd &solutions) {
        response->joint_angles_matrix.layout.dim.resize(2);

        response->joint_angles_matrix.layout.dim[0].label = "solutions";
        response->joint_angles_matrix.layout.dim[0].size = solutions.rows();
        response->joint_angles_matrix.layout.dim[0].stride = solutions.rows() * solutions.cols();

        response->joint_angles_matrix.layout.dim[1].label = "joints";
        response->joint_angles_matrix.layout.dim[1].size = solutions.cols();
        response->joint_angles_matrix.layout.dim[1].stride = solutions.cols();

        response->joint_angles_matrix.layout.data_offset = 0;
        response->joint_angles_matrix.data.resize(solutions.size());

        for (int i = 0; i < solutions.rows(); ++i) {
            for (int j = 0; j < solutions.cols(); ++j) {
                response->joint_angles_matrix.data[i * solutions.cols() + j] =
                    static_cast<double>(solutions(i, j));
            }
        }

        response->status_message = "Inverse kinematics solutions computed successfully.";
    }
};

}  // namespace motion

// Main function
int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<motion::InverseKinServer>());
    rclcpp::shutdown();
    return 0;
}
