#include "motion/compute_path_service.hpp"

namespace motion{
    
    PathPlannerNode::PathPlannerNode() : Node("path_planner_node") {
        //initialize service
        
        // Defining variable callback
        auto service_callback = [this](const std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Request> request,
                                        std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Response> response){
                                        this->handle_compute_path(request, response);};

        // Creating the service using the callback
        service_ = this->create_service<custom_msg_interfaces::srv::ComputePath>("compute_path", service_callback);
        
        //initialize_publisher
        auto qos = rclcpp::QoS(10).transient_local().reliable();
        publisher_ = this->create_publisher<geometry_msgs::msg::PoseArray>("computed_trajectory", qos);
            
        RCLCPP_INFO(this->get_logger(), "Path Planner Node is ready");
    }
    
    
    void PathPlannerNode::handle_compute_path(
        const std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Request> request,
        std::shared_ptr<custom_msg_interfaces::srv::ComputePath::Response> response) {
        
        // Perform interpolation
        auto interpolated_poses = compute_interpolated_poses(    //40
            request->pose_start, request->pose_end, request->num_interpolations
        );
        response->poses = interpolated_poses;
    
        // Publish for visualization
        publish_pose_array(interpolated_poses);    //70
    }
    
    std::vector<geometry_msgs::msg::Pose> PathPlannerNode::compute_interpolated_poses(
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
            poses.push_back(s_lerp(start_pose, end_pose, t);
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
    
    void PathPlannerNode::publish_pose_array(const std::vector<geometry_msgs::msg::Pose>& poses) const {
        geometry_msgs::msg::PoseArray pose_array;
        pose_array.header.stamp = this->now();
        pose_array.header.frame_id = "base";
        pose_array.poses = poses;
        publisher_->publish(pose_array);
    }
    
    
}

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<motion::PathPlannerNode>());
    rclcpp::shutdown();
    return 0;
}
