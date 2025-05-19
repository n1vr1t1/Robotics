cmake_minimum_required(VERSION 3.8)
project(custom_msg_interfaces)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)


rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/DetectionResult.msg"
  "msg/ClassPose.msg"
  "srv/ComputeIK.srv"
  "srv/ComputeDirKin.srv"
  "srv/ComputePath.srv"
  "srv/ComputeTrajectory.srv"
  "srv/Interpolation.srv"
  DEPENDENCIES std_msgs geometry_msgs trajectory_msgs

)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
