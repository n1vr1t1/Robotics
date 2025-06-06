#include "motion/compute_trajectory.hpp"
using namespace std::chrono_literals;  

std::vector<std::array<double, 6>> waypoints;
const std::vector<std::string> JOINT_NAMES = {
    "shoulder_pan_joint",
    "shoulder_lift_joint",
    "elbow_joint",
    "wrist_1_joint",
    "wrist_2_joint",
    "wrist_3_joint"
};

std::array<double, 4> compute_cubic_coefficients(double q0, double q1, double v0, double v1, double T){
    
    double a0 = q0;
    double a1 = v0;
    double a2 = (3 * (q1 - q0) / std::pow(T, 2)) - (2 * v0 / T) - (v1 / T);
    double a3 = (-2 * (q1 - q0) / std::pow(T, 3)) + ((v1 + v0) / std::pow(T, 2));
    return {a0, a1, a2, a3};
}

trajectory_msgs::msg::JointTrajectory  generate_cubic_trajectory (const std::vector<std::array<double, 6>>& waypoints, double segment_time){

    trajectory_msgs::msg::JointTrajectory traj_msg;
    traj_msg.joint_names = JOINT_NAMES;
    double total_time = 0.0;

    for (size_t i = 0; i < waypoints.size() - 1; ++i) {
        std::array<double, 6> q0 = waypoints[i];
        std::array<double, 6> q1 = waypoints[i + 1];

        std::array<double, 6> v0, v1;

        if (i == 0) {
            v0.fill(0.0);
            for (size_t j = 0; j < 6; ++j) {
                v1[j] = (waypoints[i + 2][j] - q0[j]) / (2.0 * segment_time);
            }
        }
        else if (i == waypoints.size() - 2) {
            v1.fill(0.0);
            for (size_t j = 0; j < 6; ++j) {
                v0[j] = (q1[j] - waypoints[i - 1][j]) / (2.0 * segment_time);
            }
        }
        else {
            for (size_t j = 0; j < 6; ++j) {
                double avg_velocity = (waypoints[i + 1][j] - waypoints[i - 1][j]) / (2.0 * segment_time);
                v0[j] = avg_velocity;
                v1[j] = avg_velocity;
            }
        }

        std::array<std::array<double, 4>, 6> coefficients;
        for (size_t j = 0; j < 6; ++j) {
            coefficients[j] = compute_cubic_coefficients(q0[j], q1[j], v0[j], v1[j], segment_time);
        }

        for (int step = 0; step <= STEPS; ++step) {
            double t = (step / static_cast<double>(STEPS)) * segment_time;
            trajectory_msgs::msg::JointTrajectoryPoint interpolated_point;
            interpolated_point.positions.resize(6);
            interpolated_point.velocities.resize(6);

            for (size_t j = 0; j < 6; ++j) {
                double a0 = coefficients[j][0];
                double a1 = coefficients[j][1];
                double a2 = coefficients[j][2];
                double a3 = coefficients[j][3];

                double pos = a0 + a1 * t + a2 * t * t + a3 * t * t * t;
                double vel = a1 + 2.0 * a2 * t + 3.0 * a3 * t * t;

                interpolated_point.positions[j] = pos;
                interpolated_point.velocities[j] = vel;
            }

            double dt = segment_time / static_cast<double>(STEPS);
            total_time += dt;
            interpolated_point.time_from_start = rclcpp::Duration::from_seconds(total_time);
            traj_msg.points.push_back(interpolated_point);
        }
    }

    return traj_msg;
}
ComputeTrajectoryService::ComputeTrajectoryService() : Node("compute_trajectory_service"), received_initial_joints_(false){

    RCLCPP_INFO(this->get_logger(), "ComputeTrajectoryService node ready on 'compute_trajectory'");

    auto joint_state_callback = [this](const sensor_msgs::msg::JointState::SharedPtr msg) {this->joint_state_callback(msg);};
    joint_state_subscriber_ = this->create_subscription<sensor_msgs::msg::JointState>("/joint_states", 10, joint_state_callback);
    RCLCPP_INFO(this->get_logger(), "Subscribed to '/joint_states' to capture initial joint values");

    ik_client_node_ = std::make_shared<rclcpp::Node>("compute_ik_client_node");
    ik_client_ = ik_client_node_->create_client<custom_msg_interfaces::srv::ComputeIK>("/compute_ik");
    RCLCPP_INFO(this->get_logger(), "Create inverse kinematics client");  

    subscription_path = this->create_subscription<geometry_msgs::msg::PoseArray>("/computed_path",
                        rclcpp::QoS(8), std::bind(&ComputeTrajectoryService::compute_trajectory_callback, this, std::placeholders::_1));
    trajectory_publisher = this->create_publisher<custom_msg_interfaces::msg::ViaPoints>("/computed_trajectory", 8);
    
}


void ComputeTrajectoryService::print_joint_angles_matrix(const std::vector<double> &matrix) {

    RCLCPP_INFO(this->get_logger(), "Computing joint angles matrix");  
    
    if (matrix.size() != 8 * 6) {
        RCLCPP_WARN(this->get_logger(), "Unexpected matrix size: %zu (expected 8x6)", matrix.size());
        return;
    }

    std::ostringstream ss;
    for (size_t i = 0; i < 8; ++i) {
        ss << "Row " << (i + 1) << ": ";
        for (size_t j = 0; j < 6; ++j) {
            if (j > 0) ss << ", ";
            ss << matrix[i * 6 + j];
        }
        if (i < 7) ss << " | ";
    }
    RCLCPP_INFO(this->get_logger(), "IK solution matrix:\n%s", ss.str().c_str());
}

void ComputeTrajectoryService::joint_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg) {

    initial_joint_array_.resize(JOINT_NAMES.size(), 0.0);

    for (size_t i = 0; i < JOINT_NAMES.size(); ++i) {
        auto it = std::find(msg->name.begin(), msg->name.end(), JOINT_NAMES[i]);
        if (it != msg->name.end()) {
            size_t index = std::distance(msg->name.begin(), it);
            initial_joint_array_[i] = msg->position[index];
        } else {
            RCLCPP_WARN(this->get_logger(), "Joint '%s' not found in /joint_states",
                        JOINT_NAMES[i].c_str());
        }
    }

    std::ostringstream oss;
    for (size_t i = 0; i < JOINT_NAMES.size(); ++i) {
        oss << JOINT_NAMES[i] << ": " << initial_joint_array_[i];
        if (i < JOINT_NAMES.size() - 1) oss << " | ";
    }
}

std::vector<double> ComputeTrajectoryService::select_closest_one(const std::vector<double> &prev_joints,const std::vector<double> &joint_angles_matrix) {

    RCLCPP_INFO(this->get_logger(), "Selecting the closes solutions");  
    
    if (joint_angles_matrix.size() != 8 * 6 || prev_joints.size() != 6) {
        RCLCPP_WARN(this->get_logger(),
                    "Invalid sizes: prev_joints = %zu, joint_angles_matrix = %zu (expected 6 and 48)",
                    prev_joints.size(), joint_angles_matrix.size());
        return {};
    }

    double min_cost = std::numeric_limits<double>::max();
    std::vector<double> best_solution(6, 0.0);

    for (size_t i = 0; i < 8; ++i) {
        double norm = 0.0;
        double penalty = 0.0;
        bool valid = true;

        for (size_t j = 0; j < 6; ++j) {
            double joint_angle = joint_angles_matrix[i * 6 + j];

            if (std::isnan(joint_angle)) {
                valid = false;
                break;
            }

            double diff = joint_angle - prev_joints[j];
            norm += diff * diff;

            if (joint_angle < -M_PI || joint_angle > M_PI) {
                penalty += 100.0; 
            }
        }

        if (!valid) {
            RCLCPP_WARN(this->get_logger(),
                        "Configuration %zu contains NaN values and will be skipped.", i);
            continue;
        }

        double cost = norm + penalty;
        if (cost < min_cost) {
            min_cost = cost;
            for (size_t j = 0; j < 6; ++j) {
                best_solution[j] = joint_angles_matrix[i * 6 + j];
            }
        }
    }

    if (min_cost == std::numeric_limits<double>::max()) {
        RCLCPP_WARN(this->get_logger(), "No valid solution found.");
        return {};
    }

    RCLCPP_INFO(this->get_logger(), "Selected solution with cost: %f", min_cost);
    return best_solution;
}

bool ComputeTrajectoryService::ur5_singAvoid(const Eigen::VectorXd &Th, double scaleFactor){

    RCLCPP_INFO(this->get_logger(), "Avoiding singularities");  
    std::vector<Eigen::Matrix4d> Tm = computeChainFK(Th, scaleFactor);

    if (Tm.size() < 7) {
        RCLCPP_ERROR(this->get_logger(), "ur5_singAvoid: FK result has only %ld transforms, expected 7.", Tm.size());
        return false; 
    }

    Eigen::Matrix<double, 6, 6> J;
    J.setZero();

    Eigen::Vector3d o_6 = Tm[6].block<3,1>(0,3);
    
    for (int i = 1; i <= 6; ++i){
        
        Eigen::Vector3d z_im1 = Tm[i-1].block<3,3>(0,0).col(2);
        Eigen::Vector3d o_im1 = Tm[i-1].block<3,1>(0,3);
        Eigen::Vector3d linPart = z_im1.cross(o_6 - o_im1);
        Eigen::Vector3d angPart = z_im1;
        J.block<3,1>(0, i-1) = linPart;
        J.block<3,1>(3, i-1) = angPart;
    }


    double detJ = J.determinant();
    if (std::fabs(detJ) < 1e-5) {
        RCLCPP_WARN(rclcpp::get_logger("ur5_singAvoid"),
                    "Near a singularity! Determinant: %f", detJ);
        return true;
    }

    return false;
}


std::vector<Eigen::Matrix4d> ComputeTrajectoryService::computeChainFK(const Eigen::VectorXd &Th, double scaleFactor){

    std::vector<double> A = {0,     -0.425,  -0.3922,  0,     0,     0};
    std::vector<double> D = {0.1625, 0,       0,        0.1333,0.0997,0.0996};
    std::vector<double> ALPHA = {M_PI/2, 0, 0, M_PI/2, -M_PI/2, 0};

    for (auto &a : A) a *= scaleFactor;
    for (auto &d : D) d *= scaleFactor;

    std::vector<Eigen::Matrix4d> Tm(7, Eigen::Matrix4d::Identity());

    for (int i=0; i<6; ++i) {
        Eigen::Matrix4d T = Eigen::Matrix4d::Identity();
        T <<  std::cos(Th(i)), -std::sin(Th(i))*std::cos(ALPHA[i]),  std::sin(Th(i))*std::sin(ALPHA[i]),  A[i]*std::cos(Th(i)),
              std::sin(Th(i)),  std::cos(Th(i))*std::cos(ALPHA[i]), -std::cos(Th(i))*std::sin(ALPHA[i]),  A[i]*std::sin(Th(i)),
                    0,                std::sin(ALPHA[i]),                  std::cos(ALPHA[i]),                  D[i],
                    0,                0,                                0,                                1;
        
        Tm[i+1] = Tm[i] * T; 
    }
    return Tm;
}

 void ComputeTrajectoryService::compute_trajectory_callback(geometry_msgs::msg::PoseArray::SharedPtr msg){
    RCLCPP_INFO(this->get_logger(), "[CALLBACK] compute_trajectory_callback STARTED");
    const size_t num_poses = msg->poses.size();
    RCLCPP_INFO(this->get_logger(), "Got %zu poses", num_poses);

    custom_msg_interfaces::msg::ViaPoints response;
    
    if (num_poses == 0) {
        RCLCPP_WARN(this->get_logger(), "[WARNING] No poses received!");
        response.trajectory = trajectory_msgs::msg::JointTrajectory();
        response.status_message = "No poses provided";
        return;
    }
    
    if (!ik_client_->wait_for_service(5s)) {
        RCLCPP_ERROR(this->get_logger(), "IK service not available after waiting");
        response.trajectory = trajectory_msgs::msg::JointTrajectory();
        response.status_message = "IK service unavailable";
        return;
    }

    waypoints.clear();
    waypoints.resize(num_poses + 1);
    
    for (size_t j = 0; j < 6; ++j) {
        waypoints[0][j] = initial_joint_array_[j];
    }
    
    for (size_t i = 0; i < num_poses; ++i) {
        RCLCPP_INFO(this->get_logger(), "Processing Pose %zu/%zu", i + 1, num_poses);
    
        auto ik_request = std::make_shared<custom_msg_interfaces::srv::ComputeIK::Request>();
        ik_request->header.stamp = this->now();
        ik_request->header.frame_id = "base";
        ik_request->target_pose = msg->poses[i];
    
        auto future_result = ik_client_->async_send_request(ik_request);
        auto ret = rclcpp::spin_until_future_complete(
            ik_client_node_->get_node_base_interface(),
            future_result, 10s
        );
    
        if (ret == rclcpp::FutureReturnCode::SUCCESS) {
            auto result = future_result.get();
            if (!result || result->joint_angles_matrix.data.empty()) {
                RCLCPP_WARN(this->get_logger(), "IK computation for Pose %zu returned no solution!", i + 1);
            } else {
                RCLCPP_INFO(this->get_logger(), "[SUCCESS] IK response for Pose %zu received", i + 1);
                print_joint_angles_matrix(result->joint_angles_matrix.data);

                bool has_nan = false;
                for (const auto& val : result->joint_angles_matrix.data) {
                    if (std::isnan(val)) {
                        has_nan = true;
                        break;
                    }
                }
                
                if (has_nan) {
                    RCLCPP_WARN(this->get_logger(), "[Warning] The angle matrix has only NaN values. Stopping computations.");
                }else{
    
                    std::vector<double> prev_joints(waypoints[i].begin(), waypoints[i].end());
        
                    std::vector<double> best_solution = select_closest_one(prev_joints, result->joint_angles_matrix.data);
        
                    Eigen::VectorXd Th = Eigen::VectorXd::Map(best_solution.data(), best_solution.size());
        
                    if (ur5_singAvoid(Th, 1.0)) {
                        RCLCPP_WARN(rclcpp::get_logger("compute_trajectory_service"), "Selected joint configuration is near a singularity!");
                        std::fill(best_solution.begin(), best_solution.end(), std::numeric_limits<double>::quiet_NaN());
                    }
        
                    for (size_t j = 0; j < 6; ++j) {
                        waypoints[i + 1][j] = best_solution[j];
                    }
                }
            }
        } else {
            RCLCPP_ERROR(this->get_logger(), "IK service call for Pose %zu failed!", i + 1);
        }
        
    }
    
    RCLCPP_INFO(this->get_logger(), "WAYPOINTS (total rows = %zu):", waypoints.size());
    for (size_t i = 0; i < waypoints.size(); ++i) {
        std::ostringstream row_stream;
        row_stream << "Row " << i << ": ";
        for (size_t j = 0; j < 6; ++j) {
            row_stream << waypoints[i][j] << (j < 5 ? ", " : "");
        }
        RCLCPP_INFO(this->get_logger(), "%s", row_stream.str().c_str());
    }

    double segment_time = 0.8; 
    RCLCPP_INFO(this->get_logger(), "Computing cubic trajectory");
    trajectory_msgs::msg::JointTrajectory cubic_traj = generate_cubic_trajectory(waypoints, segment_time);

    response.trajectory = cubic_traj;
    response.status_message = "IK computed, cubic trajectory generated successfully.";

    trajectory_publisher -> publish(response);
}

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ComputeTrajectoryService>();
    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
