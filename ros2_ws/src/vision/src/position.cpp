#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "sensor_msgs/point_cloud2_iterator.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"
#include "geometry_msgs/msg/point_stamped.hpp"
#include "vision_msgs/msg/detection3_d_array.hpp"
#include "vision_msgs/msg/object_hypothesis_with_pose.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include <memory>
#include <cmath>
#include <string>

#include "custom_msg_interfaces/msg/class_pose.hpp"

namespace std {
    template <>
    struct iterator_traits<sensor_msgs::PointCloud2ConstIterator<float>> {
        using difference_type = std::ptrdiff_t;
        using value_type = float;
        using pointer = float*;
        using reference = float&;
        using iterator_category = std::forward_iterator_tag;  // Assuming it's a forward iterator
    };
}

class CameraPoseNode : public rclcpp::Node{
    //("check if pixel coordinates match between the color image and point cloud");
    public:
        CameraPoseNode(): Node("pose_from_camera_node"),
                            tf_buffer(this->get_clock()), 
                            tf_listener(std::make_shared<tf2_ros::TransformListener>(tf_buffer)){
            subscription_pixel = this->create_subscription<std_msgs::msg::Float32MultiArray>(
                "/inference_result", rclcpp::QoS(8), std::bind(&CameraPoseNode::image_callback, this, std::placeholders::_1));
            subscription_cloud = this->create_subscription<sensor_msgs::msg::PointCloud2>(
                "/camera/depth/points", rclcpp::QoS(8), std::bind(&CameraPoseNode::cloud_callback, this, std::placeholders::_1));
            publisher = this->create_publisher<custom_msg_interfaces::msg::ClassPose>("/inference_3d", 8);
            current_cloud = nullptr;
        }

    private:
        void cloud_callback(const sensor_msgs::msg::PointCloud2::SharedPtr msg){
            current_cloud = msg;
        }
        void image_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg){
            if(current_cloud == nullptr){
                RCLCPP_WARN(this->get_logger(), "No point cloud data available as yet. Waiting for point cloud data :)");
                return;
            }
            
            custom_msg_interfaces::msg::ClassPose publish_positions;
            publish_positions.len=0;

            auto positions = msg->data;
            if(positions.size() == 0){
                RCLCPP_WARN(this->get_logger(), "No positions data available as yet. Waiting for positions data :)");
                return;
            }
            for(size_t i =0; i+2 < positions.size(); i+=3){
                int id = static_cast<int>(positions[i]);
                float x = positions[i+1];
                float y = positions[i+2];

                int width = current_cloud->width;
                int height = current_cloud->height;

                int u = static_cast<int>(x * static_cast<float>(width));
                int v = static_cast<int>(y * static_cast<float>(height));


                if(u < 0 || u >= width || v < 0 || v >= height){
                    RCLCPP_WARN(this->get_logger(), "Invalid pixel coordinates: (%d, %d)", u, v);
                    continue;
                }
                float index_1d = static_cast<float>(v * width + u);

                sensor_msgs::PointCloud2ConstIterator<float> iter_x(*current_cloud, "x");
                sensor_msgs::PointCloud2ConstIterator<float> iter_y(*current_cloud, "y");
                sensor_msgs::PointCloud2ConstIterator<float> iter_z(*current_cloud, "z");

                std::advance(iter_x, index_1d);
                std::advance(iter_y, index_1d);
                std::advance(iter_z, index_1d);

                x = *iter_x;
                y = *iter_y;
                float z = *iter_z;

                if(!std::isfinite(x) || !std::isfinite(y) || !std::isfinite(z)){
                    RCLCPP_WARN(this->get_logger(), "Invalid point cloud data at index_1d: %f", index_1d);
                    continue;
                }

                geometry_msgs::msg::Pose pose;
                geometry_msgs::msg::PointStamped camera_point, base_point;
                camera_point.header = current_cloud->header;
                camera_point.point.x = x;
                camera_point.point.y = y;
                camera_point.point.z = z;

                try{
                    base_point = tf_buffer.transform(camera_point, "base_link", tf2::durationFromSec(0.1));
                    pose.position.x = base_point.point.x;
                    pose.position.y = base_point.point.y;
                    pose.position.z = base_point.point.z;
                }catch(const tf2::TransformException &ex){
                    RCLCPP_WARN(this->get_logger(), "TF transform failed: %s", ex.what());
                    return;
                }

                pose.orientation.w = 1.0; //need to initiaze the orientation of x,y, z too
    
                publish_positions.class_ids.push_back(id);
                publish_positions.poses.push_back(pose);
                publish_positions.len++;
                
                RCLCPP_INFO(this->get_logger(), "Pose ID: %d, Position: (%f, %f, %f)", id, x, y, z);
            }
            publisher->publish(publish_positions);

        }
        tf2_ros::Buffer tf_buffer;
        std::shared_ptr<tf2_ros::TransformListener> tf_listener;
        rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr subscription_cloud;
        rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr subscription_pixel;
        rclcpp::Publisher<custom_msg_interfaces::msg::ClassPose>::SharedPtr publisher;
        sensor_msgs::msg::PointCloud2::SharedPtr current_cloud;
};
int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CameraPoseNode>();
    rclcpp::spin(node);
    node.reset();
    rclcpp::shutdown();
}
