cmake_minimum_required(VERSION 3.8)
project(vision)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(vision_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenCV REQUIRED)

set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};/home/ubuntu/ros2_ws/Robotics/ros2_ws/external/libtorch/libtorch")
find_package(Torch REQUIRED)

include_directories(
  include
  ${TORCH_INCLUDE_DIRS}
)

add_executable(pose_from_camera_node src/position.cpp)
target_link_libraries(pose_from_camera_node  ${TORCH_LIBRARIES})
ament_target_dependencies(pose_from_camera_node
  rclcpp
  rclcpp_action
  std_msgs
  sensor_msgs
  geometry_msgs
  vision_msgs
  libstatistics_collector
)



add_executable(yolo_detection_node src/detection.cpp)
target_include_directories(yolo_detection_node PRIVATE 
  ${TORCH_INCLUDE_DIRS}
)
ament_target_dependencies(yolo_detection_node
  rclcpp
  rclcpp_action
  std_msgs
  sensor_msgs
  geometry_msgs
  vision_msgs
  cv_bridge
  image_transport
  OpenCV
)
target_link_libraries(yolo_detection_node "${TORCH_LIBRARIES}")

install(TARGETS
  pose_from_camera_node
  yolo_detection_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
