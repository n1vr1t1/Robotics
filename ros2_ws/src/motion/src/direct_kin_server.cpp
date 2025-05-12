#include "motion/direct_kin_server.hpp"

#include <cmath>
#include <Eigen/Dense>
#include <vector>

// Helper class for Kinematics operations
class Kinematics {
public:
    static Eigen::Matrix4d computeTransformMatrix(double th, double alpha, double d, double a) {
        Eigen::Matrix4d T;
        T << std::cos(th), -std::sin(th) * std::cos(alpha), std::sin(th) * std::sin(alpha), a * std::cos(th),
             std::sin(th), std::cos(th) * std::cos(alpha), -std::cos(th) * std::sin(alpha), a * std::sin(th),
             0, std::sin(alpha), std::cos(alpha), d,
             0, 0, 0, 1;
        return T;
    }

    static void computeDirectKinematics(
        const std::vector<double>& joints, double scaleFactor, Eigen::Vector3d& position,
        Eigen::Matrix3d& orientation, std::vector<Eigen::Matrix4d>& transforms) {
        
        std::vector<double> A = {0, -0.425, -0.3922, 0, 0, 0};
        std::vector<double> D = {0.1625, 0, 0, 0.1333, 0.0997, 0.0996};
        std::vector<double> Alpha = {M_PI / 2, 0, 0, M_PI / 2, -M_PI / 2, 0};

        for (auto& a : A) a *= scaleFactor;
        for (auto& d : D) d *= scaleFactor;

        for (size_t i = 0; i < joints.size(); ++i) {
            transforms.push_back(computeTransformMatrix(joints[i], Alpha[i], D[i], A[i]));
        }

        Eigen::Matrix4d finalTransform = transforms[0];
        for (size_t i = 1; i < transforms.size(); ++i) {
            finalTransform *= transforms[i];
        }

        position = finalTransform.block<3, 1>(0, 3);
        orientation = finalTransform.block<3, 3>(0, 0);
    }
};

// The main DirectKinServer class
DirectKinServer::DirectKinServer() : Node("direct_kin_server") {
    service_ = create_service<custom_msg_interfaces::srv::ComputeDirKin>(
        "compute_dir_kin", 
        [this](const std::shared_ptr<custom_msg_interfaces::srv::ComputeDirKin::Request> request,
               std::shared_ptr<custom_msg_interfaces::srv::ComputeDirKin::Response> response) {
            handleServiceRequest(request, response);
        });

    RCLCPP_INFO(this->get_logger(), "Direct Kinematics Service is ready.");
}

void handleServiceRequest(
    const std::shared_ptr<custom_msg_interfaces::srv::ComputeDirKin::Request> request,
    std::shared_ptr<custom_msg_interfaces::srv::ComputeDirKin::Response> response) {

    try {
        Eigen::Vector3d end_effector_position;
        Eigen::Matrix3d end_effector_orientation;
        std::vector<Eigen::Matrix4d> transforms;

        // Perform kinematics computation
        Kinematics::computeDirectKinematics(
            request->joints, 1.0, end_effector_position, end_effector_orientation, transforms);

        // Populate the response
        response->final_pose.position.x = end_effector_position(0);
        response->final_pose.position.y = end_effector_position(1);
        response->final_pose.position.z = end_effector_position(2);

        Eigen::Quaterniond quaternion(end_effector_orientation);
        response->final_pose.orientation.x = quaternion.x();
        response->final_pose.orientation.y = quaternion.y();
        response->final_pose.orientation.z = quaternion.z();
        response->final_pose.orientation.w = quaternion.w();

        response->status_message = "Direct kinematics calculated successfully";
        response->frame_id = request->frame_id;
    } catch (const std::exception& e) {
        RCLCPP_ERROR(this->get_logger(), "Error in direct kinematics calculation: %s", e.what());
        response->status_message = "Failed to calculate direct kinematics";
    }
}

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DirectKinServer>());
    rclcpp::shutdown();
    return 0;
}
