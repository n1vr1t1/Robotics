cmake_minimum_required(VERSION 3.8)
project(vision)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)


# Set the path to LibTorch
set(Torch_DIR "${CMAKE_SOURCE_DIR}/external/pytorch/share/cmake/Torch")

# Now, find and include LibTorch
find_package(Torch REQUIRED)

include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
  ${TORCH_INCLUDE_DIRS}
)

add_executable(detection_node src/detection_node.cpp)

target_link_libraries(detection_node
  ${OpenCV_LIBS}
  ${TORCH_LIBRARIES}
)

ament_target_dependencies(detection_node
  rclcpp
  sensor_msgs
  std_msgs
  cv_bridge
)

install(TARGETS
  detection_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
