#include <motion/compute_path_service.hpp>

PathPlannerNode::PathPlannerNode() : Node("path_planner_node") {
    // Initialize service and publisher
    initialize_service();
    initialize_publisher();
    RCLCPP_INFO(this->get_logger(), "Path Planner Node is ready");
}

void PathPlannerNode::initialize_service() {
    service_ = this->create_service<custom_msg_interfaces::srv::ComputePath>(
        "compute_path",
        [this](const std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Request> request,
               std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Response> response) {
            handle_compute_path(request, response);
        }
    );
}

void PathPlannerNode::initialize_publisher() {
    publisher_ = this->create_publisher<geometry_msgs::msg::PoseArray>(
        "computed_trajectory",
        rclcpp::QoS(10).transient_local().reliable()
    );
}

void PathPlannerNode::handle_compute_path(
    const std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Request> request,
    std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Response> response) {
    
    // Perform interpolation
    auto interpolated_poses = compute_interpolated_poses(
        request->pose_start, request->pose_end, request->num_interpolations
    );
    response->poses = interpolated_poses;

    // Publish for visualization
    publish_pose_array(interpolated_poses);
}

std::vector<geometry_msgs::msg::Pose> compute_interpolated_poses(
    const geometry_msgs::msg::Pose& start_pose,
    const geometry_msgs::msg::Pose& end_pose,
    int num_interpolations) const {
    
    std::vector<geometry_msgs::msg::Pose> poses;
    tf2::Quaternion q_start(start_pose.orientation.x, start_pose.orientation.y,
                             start_pose.orientation.z, start_pose.orientation.w);
    tf2::Quaternion q_end(end_pose.orientation.x, end_pose.orientation.y,
                           end_pose.orientation.z, end_pose.orientation.w);

    for (int i = 0; i <= num_interpolations; ++i) {
        double t = static_cast<double>(i) / num_interpolations;

        geometry_msgs::msg::Pose interp_pose;
        interp_pose.position.x = lerp(start_pose.position.x, end_pose.position.x, t);
        interp_pose.position.y = lerp(start_pose.position.y, end_pose.position.y, t);
        interp_pose.position.z = lerp(start_pose.position.z, end_pose.position.z, t);

        tf2::Quaternion q_interp = q_start.slerp(q_end, t);
        interp_pose.orientation.x = q_interp.x();
        interp_pose.orientation.y = q_interp.y();
        interp_pose.orientation.z = q_interp.z();
        interp_pose.orientation.w = q_interp.w();

        poses.push_back(interp_pose);
    }
    return poses;
}

void PathPlannerNode::publish_pose_array(const std::vector<geometry_msgs::msg::Pose>& poses) const {
    geometry_msgs::msg::PoseArray pose_array;
    pose_array.header.stamp = this->now();
    pose_array.header.frame_id = "base";
    pose_array.poses = poses;
    publisher_->publish(pose_array);
}

double PathPlannerNode::lerp(double a, double b, double t) const {
    return a + t * (b - a);
}


int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PathPlannerNode>());
    rclcpp::shutdown();
    return 0;
}
