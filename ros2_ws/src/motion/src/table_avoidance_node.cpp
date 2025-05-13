#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2/exceptions.h>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include "std_msgs/msg/bool.hpp"

using namespace std::chrono_literals;

const double z_threshold = 0.87 + 0.10; // Example threshold

// Helper Function: Log status of the end effector
void logEndEffectorStatus(rclcpp::Logger logger, bool is_too_low, double z_value)
{
  if (is_too_low)
  {
    RCLCPP_WARN(logger, "End effector is too low! Z=%.3f", z_value);
  }
  else
  {
    RCLCPP_INFO(logger, "End effector height OK. Z=%.3f", z_value);
  }
}

class EndEffectorHeightChecker : public rclcpp::Node
{
public:
  EndEffectorHeightChecker()
  : Node("end_effector_height_checker"),
    tf_buffer_(this->get_clock()),
    tf_listener_(tf_buffer_)
  {
    // Initialize publisher
    shutdown_pub_ = this->create_publisher<std_msgs::msg::Bool>("shutdown", 10);

    // Initialize timer with a lambda callback
    timer_ = this->create_wall_timer(
      500ms,  // Timer frequency
      [this]()
      {
        this->checkEndEffectorHeight();
      });
  }

private:
  void checkEndEffectorHeight()
  {
    // Attempt to fetch the transform
    geometry_msgs::msg::TransformStamped transform_stamped;
    try
    {
      transform_stamped = tf_buffer_.lookupTransform(
        "base_link",  // source frame
        "tool0",      // target frame
        tf2::TimePointZero
      );
    }
    catch (const tf2::TransformException &ex)
    {
      RCLCPP_WARN(this->get_logger(), "Failed to get transform: %s", ex.what());
      return;
    }

    // Determine if the end effector is below the threshold
    // Publish shutdown signal if necessary
    if (transform_stamped.transform.translation.z < z_threshold)
    {
       // Log the status
      logEndEffectorStatus(this->get_logger(), true, transform_stamped.transform.translation.z);
      std_msgs::msg::Bool shutdown_msg;
      shutdown_msg.data = true;
      shutdown_pub_->publish(shutdown_msg);
      
    }else{
       // Log the status
      logEndEffectorStatus(this->get_logger(), false, transform_stamped.transform.translation.z);
    }
  }

  // TF objects
  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;

  // ROS 2 Publisher
  rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr shutdown_pub_;

  // ROS 2 Timer
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<EndEffectorHeightChecker>());
  rclcpp::shutdown();
  return 0;
}
