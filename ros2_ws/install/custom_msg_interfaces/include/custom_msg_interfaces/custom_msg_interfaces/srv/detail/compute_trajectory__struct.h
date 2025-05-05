// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msg_interfaces:srv/ComputeTrajectory.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/srv/compute_trajectory.h"


#ifndef CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_TRAJECTORY__STRUCT_H_
#define CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'array'
#include "geometry_msgs/msg/detail/pose_array__struct.h"

/// Struct defined in srv/ComputeTrajectory in the package custom_msg_interfaces.
typedef struct custom_msg_interfaces__srv__ComputeTrajectory_Request
{
  geometry_msgs__msg__PoseArray array;
} custom_msg_interfaces__srv__ComputeTrajectory_Request;

// Struct for a sequence of custom_msg_interfaces__srv__ComputeTrajectory_Request.
typedef struct custom_msg_interfaces__srv__ComputeTrajectory_Request__Sequence
{
  custom_msg_interfaces__srv__ComputeTrajectory_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_interfaces__srv__ComputeTrajectory_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.h"
// Member 'status_message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ComputeTrajectory in the package custom_msg_interfaces.
typedef struct custom_msg_interfaces__srv__ComputeTrajectory_Response
{
  trajectory_msgs__msg__JointTrajectory trajectory;
  rosidl_runtime_c__String status_message;
} custom_msg_interfaces__srv__ComputeTrajectory_Response;

// Struct for a sequence of custom_msg_interfaces__srv__ComputeTrajectory_Response.
typedef struct custom_msg_interfaces__srv__ComputeTrajectory_Response__Sequence
{
  custom_msg_interfaces__srv__ComputeTrajectory_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_interfaces__srv__ComputeTrajectory_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  custom_msg_interfaces__srv__ComputeTrajectory_Event__request__MAX_SIZE = 1
};
// response
enum
{
  custom_msg_interfaces__srv__ComputeTrajectory_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ComputeTrajectory in the package custom_msg_interfaces.
typedef struct custom_msg_interfaces__srv__ComputeTrajectory_Event
{
  service_msgs__msg__ServiceEventInfo info;
  custom_msg_interfaces__srv__ComputeTrajectory_Request__Sequence request;
  custom_msg_interfaces__srv__ComputeTrajectory_Response__Sequence response;
} custom_msg_interfaces__srv__ComputeTrajectory_Event;

// Struct for a sequence of custom_msg_interfaces__srv__ComputeTrajectory_Event.
typedef struct custom_msg_interfaces__srv__ComputeTrajectory_Event__Sequence
{
  custom_msg_interfaces__srv__ComputeTrajectory_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_interfaces__srv__ComputeTrajectory_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_TRAJECTORY__STRUCT_H_
