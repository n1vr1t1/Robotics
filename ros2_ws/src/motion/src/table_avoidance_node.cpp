#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2/exceptions.h>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include "std_msgs/msg/bool.hpp"

using namespace std::chrono_literals;

const double z_threshold = 1.0; 


class EndEffectorHeightChecker : public rclcpp::Node{

public:

  EndEffectorHeightChecker() : Node("end_effector_height_checker"), tf_buffer_(this->get_clock()), tf_listener_(tf_buffer_){

    shutdown_pub_ = this->create_publisher<std_msgs::msg::Bool>("shutdown", 10);
    auto callback = [this]() { this->checkEndEffectorHeight(); };
    timer_ = this->create_wall_timer( 500ms, callback);
  }

private:

  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;
  rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr shutdown_pub_;
  rclcpp::TimerBase::SharedPtr timer_;


  void checkEndEffectorHeight(){
    try{
      const auto transform_stamped = tf_buffer_.lookupTransform(
        "base_link",  
        "tool0",     
        tf2::TimePointZero
      );
      
      const double z_value = transform_stamped.transform.translation.z;
      
      if (z_value < z_threshold){
        RCLCPP_WARN(this->get_logger(), "End effector is too low! Z=%.3f", z_value);
        std_msgs::msg::Bool shutdown_msg;
        shutdown_msg.data = true;
        shutdown_pub_->publish(shutdown_msg);
      }else{
        RCLCPP_INFO(this->get_logger(), "End effector height OK. Z=%.3f", z_value);
      }
    }catch (const tf2::TransformException &ex){
      RCLCPP_WARN(this->get_logger(), "Failed to get transform: %s", ex.what());
    } 
  }
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<EndEffectorHeightChecker>());
  rclcpp::shutdown();
  return 0;
}
