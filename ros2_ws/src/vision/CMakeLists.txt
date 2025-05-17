cmake_minimum_required(VERSION 3.8)
project(vision)

set(CMAKE_CXX_STANDARD 17)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ROS 2 dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(vision_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenCV REQUIRED)
find_package(libstatistics_collector REQUIRED)

# Torch
set(torch_DIR "/home/ubuntu/ros2_ws/src/Robotics/ros2_ws/external/libtorch/libtorch/share/cmake/Torch")
find_package(Torch REQUIRED)

include_directories(
  include
  ${TORCH_INCLUDE_DIRS}
)

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

# ================== yolo_detection_node ==================
add_executable(yolo_detection_node src/detection.cpp)

ament_target_dependencies(yolo_detection_node
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
  vision_msgs
  cv_bridge
  image_transport
  OpenCV
)

# 🔑 Torch must be added *after* ament_target_dependencies
target_link_libraries(yolo_detection_node "${TORCH_LIBRARIES}")
target_compile_options(yolo_detection_node PRIVATE "${TORCH_CXX_FLAGS}")

# ================== pose_from_camera_node ==================
add_executable(pose_from_camera_node src/position.cpp)

ament_target_dependencies(pose_from_camera_node
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
  vision_msgs
  libstatistics_collector
)

install(TARGETS
  yolo_detection_node
  pose_from_camera_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
