#include "motion/compute_path.hpp"

namespace motion{
    
    PathPlannerNode::PathPlannerNode() : Node("path_planner_node") {
        //initialize service
        
        // Defining variable callback
        // auto service_callback = [this](const std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Request> request,
        //                                 std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Response> response){
        //                                 this->handle_compute_path(request, response);};

        // Creating the service using the callback
        // service_ = this->create_service<custom_msg_interfaces::srv::ComputePath>("compute_path", service_callback);
        
        //initialize_publisher
        auto qos = rclcpp::QoS(10).transient_local().reliable();
        publisher_ = this->create_publisher<geometry_msgs::msg::PoseArray>("computed_trajectory", qos);

        //Initializing publisher and subscriber to share the interpolation poses
        subscription_extrema = this->create_subscription<custom_msg_interfaces::msg::StartEndPosition>("/path_extrema",
                                rclcpp::QoS(8), std::bind(&PathPlannerNode::handle_compute_path, this, std::placeholders::_1));

        path_publisher = this->create_publisher<geometry_msgs::msg::PoseArray>("/computed_path", 8);
            
        RCLCPP_INFO(this->get_logger(), "Path Planner Node is ready");
    }
    
    
    //void PathPlannerNode::handle_compute_path(const std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Request> request,
     //                                       std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Response> response) {

    void PathPlannerNode::handle_compute_path(const custom_msg_interfaces::msg::StartEndPosition::SharedPtr msg) {

        RCLCPP_INFO(this->get_logger(), "Handling compute path");
        // Perform interpolation
        //auto interpolated_poses = compute_interpolated_poses(    //40
        //    request->pose_start, request->pose_end, request->num_interpolations
        //);

        auto interpolated_poses = compute_interpolated_poses(    //40
            msg->pose_start, msg->pose_end, msg->num_interpolations
        );

        geometry_msgs::msg::PoseArray response;
        
        response.poses = interpolated_poses;
        
        RCLCPP_INFO(this->get_logger(), "Sending response to service with %zu poses", response.poses.size());

        for (size_t i = 0; i < response.poses.size(); ++i) {
            const auto& pose = response.poses[i];
            RCLCPP_INFO(this->get_logger(),
                "Pose %zu: Position(x=%.2f, y=%.2f, z=%.2f), Orientation(x=%.2f, y=%.2f, z=%.2f, w=%.2f)",
                i,
                pose.position.x, pose.position.y, pose.position.z,
                pose.orientation.x, pose.orientation.y, pose.orientation.z, pose.orientation.w);
        }

        path_publisher -> publish(response);
        
    }
    
    std::vector<geometry_msgs::msg::Pose> PathPlannerNode::compute_interpolated_poses(
        const geometry_msgs::msg::Pose& start_pose,
        const geometry_msgs::msg::Pose& end_pose,
        int num_interpolations) const {
        
        std::vector<geometry_msgs::msg::Pose> poses;
        for (int i = 0; i <= num_interpolations; ++i) {
            double t = static_cast<double>(i) / num_interpolations;            
            poses.push_back(s_lerp(start_pose, end_pose, t));
        }
        return poses;
    }

    geometry_msgs::msg::Pose PathPlannerNode::s_lerp(const geometry_msgs::msg::Pose& start, const geometry_msgs::msg::Pose& end, double t) const {
        
        geometry_msgs::msg::Pose result;
    
        // Linear interpolation of position
        result.position.x = start.position.x + t * (end.position.x - start.position.x);
        result.position.y = start.position.y + t * (end.position.y - start.position.y);
        result.position.z = start.position.z + t * (end.position.z - start.position.z);
    
        // Spherical linear interpolation (SLERP) of orientation
        tf2::Quaternion q_start, q_end;
        tf2::fromMsg(start.orientation, q_start);
        tf2::fromMsg(end.orientation, q_end);
    
        tf2::Quaternion q_interp = q_start.slerp(q_end, t);
        result.orientation = tf2::toMsg(q_interp);
    
        return result;
        
    }
       
    
}

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<motion::PathPlannerNode>());
    rclcpp::shutdown();
    return 0;
}
