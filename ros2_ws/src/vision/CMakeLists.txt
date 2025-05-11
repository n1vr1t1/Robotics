cmake_minimum_required(VERSION 3.10)
project(vision)

# Set C++ standard and compile flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# === libTorch Setup ===
set(LIBTORCH_URL "https://download.pytorch.org/libtorch/cpu/libtorch-shared-with-deps-2.2.0%2Bcpu.zip")
set(LIBTORCH_DIR ${CMAKE_BINARY_DIR}/libtorch)
set(LIBTORCH_ZIP ${CMAKE_BINARY_DIR}/libtorch.zip)

if(NOT EXISTS ${LIBTORCH_DIR})
  message(STATUS "Downloading libTorch...")
  file(DOWNLOAD ${LIBTORCH_URL} ${LIBTORCH_ZIP} SHOW_PROGRESS)
  execute_process(COMMAND ${CMAKE_COMMAND} -E unzip ${LIBTORCH_ZIP}
                  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

# === ROS2 Dependencies ===
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(vision_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenCV REQUIRED)

# === libTorch Integration ===
list(APPEND CMAKE_PREFIX_PATH "${LIBTORCH_DIR}")
find_package(Torch REQUIRED)

# === Include Directories ===
include_directories(
  ${OpenCV_INCLUDE_DIRS}
  ${TORCH_INCLUDE_DIRS}
  include
)

# === Executable: YOLO Detection Node ===
add_executable(yolo_detection_node src/detection.cpp)
target_link_libraries(yolo_detection_node
  ${OpenCV_LIBS}
  ${TORCH_LIBRARIES}
  rclcpp::rclcpp
)
ament_target_dependencies(yolo_detection_node
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
  vision_msgs
  cv_bridge
  image_transport
)

# === Executable: Pose From Camera Node ===
add_executable(pose_from_camera_node src/position.cpp)
target_link_libraries(pose_from_camera_node
  rclcpp::rclcpp
)
ament_target_dependencies(pose_from_camera_node
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
  vision_msgs
  libstatistics_collector
)

# === Installation ===
install(TARGETS
  yolo_detection_node
  pose_from_camera_node
  DESTINATION lib/${PROJECT_NAME}
)

# === Package Declaration ===
ament_package()
