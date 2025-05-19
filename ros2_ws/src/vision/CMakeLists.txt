cmake_minimum_required(VERSION 3.8)
project(vision)

cmake_policy(SET CMP0074 NEW)
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE BOOL "No dev warnings")

set(CMAKE_CXX_STANDARD 17)

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

# Torch (custom path to your built libtorch)
set(torch_DIR "/home/ubuntu/ros2_ws/src/Robotics/ros2_ws/external/libtorch/libtorch/share/cmake/Torch")
find_package(Torch REQUIRED)

# include directories (Torch usually handles this)
include_directories(
  include
  ${TORCH_INCLUDE_DIRS}
)

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

# pose_from_camera_node executable
add_executable(pose_from_camera_node src/position.cpp)
ament_target_dependencies(pose_from_camera_node
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
  vision_msgs
  libstatistics_collector
)

# yolo_detection_node executable
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

# Link Torch libraries AFTER ament_target_dependencies
target_link_libraries(yolo_detection_node "${TORCH_LIBRARIES}")

# Add Torch compile flags AFTER ament_target_dependencies
target_compile_options(yolo_detection_node PRIVATE "${TORCH_CXX_FLAGS}")

install(TARGETS
  yolo_detection_node
  pose_from_camera_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
