cmake_minimum_required(VERSION 3.8)
project(planning)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(control_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(vision_msgs REQUIRED)
find_package(custom_msg_interfaces REQUIRED) # might need to change?

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

add_executable(trajectory_execution_node src/trajectory_execution.cpp)
ament_target_dependencies(trajectory_execution_node
  rclcpp
  rclcpp_action
  std_msgs
  geometry_msgs
  control_msgs
  custom_msg_interfaces
  tf2_ros
)

add_executable(control_node src/control_unit.cpp)
ament_target_dependencies(control_node
  rclcpp
  geometry_msgs
  std_msgs
  std_srvs
  vision_msgs
  tf2_ros
  custom_msg_interfaces
)
install(TARGETS
  trajectory_execution_node
  control_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
