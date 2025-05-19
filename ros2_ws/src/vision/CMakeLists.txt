cmake_minimum_required(VERSION 3.8)
project(vision)

cmake_policy(SET CMP0074 NEW)
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE BOOL "No dev warnings")

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wconversion -Wpedantic -Wextra -Wshadow -Werror)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(vision_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenCV REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(libstatistics_collector REQUIRED)
find_package(custom_msg_interfaces REQUIRED)

set(Torch_DIR "/home/ubuntu/ros2_ws/Robotics/ros2_ws/external/libtorch/libtorch/share/cmake/Torch")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/home/ubuntu/ros2_ws/Robotics/ros2_ws/external/libtorch/libtorch")
message("cmake path is: ${CMAKE_PREFIX_PATH}")
find_package(Torch REQUIRED)

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

add_executable(yolo_detection_node src/detection.cpp)
target_include_directories(yolo_detection_node PRIVATE 
  ${TORCH_INCLUDE_DIRS}
)
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
target_link_libraries(yolo_detection_node
  ${rclcpp_LIBRARIES}
  ${std_msgs_LIBRARIES}
  ${sensor_msgs_LIBRARIES}
  ${geometry_msgs_LIBRARIES}
  ${vision_msgs_LIBRARIES}
  ${cv_bridge_LIBRARIES}
  ${image_transport_LIBRARIES}
  ${OpenCV_LIBRARIES}
  ${TORCH_LIBRARIES}
)

add_executable(pose_from_camera_node src/position.cpp)
ament_target_dependencies(pose_from_camera_node
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
  vision_msgs
  tf2_ros
  tf2_geometry_msgs
  libstatistics_collector
  custom_msg_interfaces
)

install(TARGETS
  yolo_detection_node
  pose_from_camera_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
