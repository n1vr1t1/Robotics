#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>
#include <sensor_msgs/image_encodings.hpp>

#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <torch/script.h>

#include <memory>
#include <string>
#include <vector>
#include <exception>

class DetectionNode : public rclcpp::Node {
public:
    DetectionNode() : Node("yolo_detection_node") {
        try {
            model = torch::jit::load("/home/ubuntu/ros2_ws/src/Robotics/ros2_ws/src/vision/model/yolo11n_0dropout.torchscript");
            model.to(torch::kCPU);
            model.eval();
        } catch (const c10::Error &e) {
            RCLCPP_ERROR(this->get_logger(), "Error loading the YOLO model: %s", e.what());
            rclcpp::shutdown();
            return;
        }

        subscription = this->create_subscription<sensor_msgs::msg::Image>(
            "/camera/image_raw/image",
            8,
            std::bind(&DetectionNode::image_callback, this, std::placeholders::_1)
        );

        publisher = this->create_publisher<std_msgs::msg::Float32MultiArray>("/inference_result", 8);
        RCLCPP_INFO(this->get_logger(), "Detection Node initialized.");
    }

private:
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Image_callback called");
        cv::Mat img;
        try {
            RCLCPP_INFO(this->get_logger(), "converting using cvbridge");
            img = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::RGB8)->image;
        } catch (cv_bridge::Exception &e) {
            RCLCPP_ERROR(this->get_logger(), "cv_bridge conversion failed: %s", e.what());
            return;
        }

        cv::Mat resized_img;
        try {
            RCLCPP_INFO(this->get_logger(), "resizing image");
            cv::resize(img, resized_img, cv::Size(640, 640));
            resized_img.convertTo(resized_img, CV_32F, 1.0 / 255.0); // Normalize to [0, 1]
        } catch (const std::exception &e) {
            RCLCPP_ERROR(this->get_logger(), "Image preprocessing failed: %s", e.what());
            return;
        }
        auto input_tensor = torch::from_blob(resized_img.data, {1, resized_img.rows, resized_img.cols, 3}, torch::kFloat32)
                                .permute({0, 3, 1, 2})
                                .to(torch::kCPU);

        torch::Tensor output;
        try {
            RCLCPP_INFO(this->get_logger(), "feeding model the resized image. Input tensor shape: %s", c10::str(input_tensor.sizes()).c_str());
            std::vector<torch::jit::IValue> inputs;
            inputs.push_back(input_tensor);
            
            auto output_ivalue = model.forward(inputs);
            RCLCPP_INFO(this->get_logger(), "Model forward pass completed.");

            output = output_ivalue.toTensor();

            RCLCPP_INFO(this->get_logger(), "Output tensor obtained. Shape: %s", c10::str(output.sizes()).c_str());
        } catch (const c10::Error &e) {
            RCLCPP_ERROR(this->get_logger(), "Model inference failed: %s", e.what());
            return;
        }

        if (output.numel() == 0) {
            RCLCPP_ERROR(this->get_logger(), "No detections found.");
            return;
        }

        RCLCPP_INFO(this->get_logger(), "getting detections");
        output = output.squeeze(0);
        
        output = output.transpose(0, 1);
        
        std_msgs::msg::Float32MultiArray result_msg;
        std::vector<float> data_vector;

        RCLCPP_INFO(this->get_logger(), "Ouptut size:%ld", output.size(0));
        for (int i = 0; i < output.size(0); ++i) {
            auto pred = output[i];  // shape: [15]

            auto class_scores = pred.slice(0, 5, 15);  // class scores
            auto max_result = class_scores.max(0);
            float class_conf = std::get<0>(max_result).item<float>();
            float obj_conf = pred[4].item<float>();

            RCLCPP_INFO(this->get_logger(), "Confidence is:%f", obj_conf);
            
            
            float final_conf = obj_conf * class_conf;
            RCLCPP_INFO(this->get_logger(), "Final Confidence is:%f", final_conf);
            
            if (final_conf < 0.5) continue;
        
            // Get class with highest score
            // auto class_scores = pred.slice(0, 5, 15);  // shape: [10]
            // auto max_result = class_scores.max(0);
            int class_id = std::get<1>(max_result).item<int>();
        
            float cx = pred[0].item<float>();
            float cy = pred[1].item<float>();
        
            data_vector.push_back(static_cast<float>(class_id));  // class
            data_vector.push_back(cx);  // x-center (normalized)
            data_vector.push_back(cy);  // y-center (normalized)
        }
        
        result_msg.data = data_vector;
        publisher->publish(result_msg);
        RCLCPP_INFO(this->get_logger(), "Published %zu detections.", data_vector.size() / 3);

    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription;
    rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr publisher;
    torch::jit::script::Module model;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DetectionNode>());
    rclcpp::shutdown();
    return 0;
}
