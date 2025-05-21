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
            model = torch::jit::load("/home/ubuntu/ros2_ws/Robotics/ros2_ws/src/vision/model/yolo11n.torchscript");
            // model = torch::jit::load("/home/ubuntu/ros2_ws/Robotics/ros2_ws/src/vision/model/yolo11s.torchscript");
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
        // cv::Mat img;
        cv::Mat bgr_img;
        try {
            RCLCPP_INFO(this->get_logger(), "Converting using cv_bridge (BGR8)");
            bgr_img = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8)->image;
        } catch (cv_bridge::Exception &e) {
            RCLCPP_ERROR(this->get_logger(), "cv_bridge conversion failed: %s", e.what());
            return;
        }

        cv::Mat rgb_img;
        RCLCPP_INFO(this->get_logger(), "Converting (BGR8)->(RGB8)");
        cv::cvtColor(bgr_img, rgb_img, cv::COLOR_BGR2RGB);
        // try {
        //     RCLCPP_INFO(this->get_logger(), "converting using cvbridge");
        //     img = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8)->image;
        // } catch (cv_bridge::Exception &e) {
        //     RCLCPP_ERROR(this->get_logger(), "cv_bridge conversion failed: %s", e.what());
        //     return;
        // }

        cv::Mat resized_img;
        try {
            RCLCPP_INFO(this->get_logger(), "resizing image");
            cv::resize(rgb_img, resized_img, cv::Size(512, 512)); //640,640

            //cv::imshow("YOLO input image", resized_img);
            //cv::waitKey(1);

            resized_img.convertTo(resized_img, CV_32F, 1.0 / 255.0); // Normalize to [0, 1]

            // cv::imshow("YOLO input image", resized_img);
            // cv::waitKey(1);
            
        } catch (const std::exception &e) {
            RCLCPP_ERROR(this->get_logger(), "Image preprocessing failed: %s", e.what());
            return;
        }

        cv::Mat input_img = resized_img.clone();
        auto input_tensor = torch::from_blob(input_img.data, {1, 512, 512, 3}, //might be 512,512 
                    torch::TensorOptions().dtype(torch::kFloat32)).permute({0, 3, 1, 2}).contiguous();
        
        torch::Tensor output;
        try {
            RCLCPP_INFO(this->get_logger(), "Feeding model the resized image. Input tensor shape: %s", c10::str(input_tensor.sizes()).c_str());
            std::vector<torch::jit::IValue> inputs;
            inputs.push_back(input_tensor);
            
            auto output_ivalue = model.forward(inputs);
            RCLCPP_INFO(this->get_logger(), "Model forward pass completed.");

            output = output_ivalue.toTensor(); // should be shape: [1, 15, 5376]

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
        output = output.squeeze(0).transpose(0, 1); // [5376, 15]
        
        std_msgs::msg::Float32MultiArray result_msg;
        std::vector<float> data_vector;

        RCLCPP_INFO(this->get_logger(), "Ouptut size:%ld", output.size(0));
        for (int i = 0; i < output.size(0); ++i) {
            auto pred = output[i];  // shape: [15]
            
            auto class_scores = pred.slice(0, 4, 15); // getting all the class prediction scores
            auto max_result = class_scores.max(0); //finding the highest score
            float class_conf = std::get<0>(max_result).item<float>(); // finding highest confidence

            if (class_conf < 0.6) continue;
            RCLCPP_INFO(this->get_logger(), "Confidence is:%f", class_conf);
        
            int class_id = std::get<1>(max_result).item<int>();  // getting the class id of the highest confidence
        
            int x1 = pred[0].item<int>();
            int y1 = pred[1].item<int>();
            int x2 = pred[2].item<int>();
            int y2 = pred[3].item<int>();

            cv::rectangle(input_img, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(0, 255, 0), 2);

            std::string label = "Class " + std::to_string(class_id) + " (" + std::to_string(class_conf).substr(0, 4) + ")";
            cv::putText(input_img, label, cv::Point(x1, y1 - 5),
                        cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 1);

            // RCLCPP_INFO(this->get_logger(), "class:%f, x1:%f, y1:%f, x2:%f, y2:%f", class_id, x1, y1, x2, y2);
            
            // data_vector.push_back(class_id);
            // data_vector.push_back(x1);
            // data_vector.push_back(y1);
            // data_vector.push_back(x2);
            // data_vector.push_back(y2);
        }
        cv::imshow("Detections", input_img);
        cv::waitKey(1);
        subscription.reset();
        return;
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
