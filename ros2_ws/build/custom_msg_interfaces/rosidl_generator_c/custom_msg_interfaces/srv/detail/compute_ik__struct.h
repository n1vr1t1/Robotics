// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msg_interfaces:srv/ComputeIK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/srv/compute_ik.h"


#ifndef CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_IK__STRUCT_H_
#define CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_IK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'target_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/ComputeIK in the package custom_msg_interfaces.
typedef struct custom_msg_interfaces__srv__ComputeIK_Request
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Pose target_pose;
} custom_msg_interfaces__srv__ComputeIK_Request;

// Struct for a sequence of custom_msg_interfaces__srv__ComputeIK_Request.
typedef struct custom_msg_interfaces__srv__ComputeIK_Request__Sequence
{
  custom_msg_interfaces__srv__ComputeIK_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_interfaces__srv__ComputeIK_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'joint_angles_matrix'
#include "std_msgs/msg/detail/float64_multi_array__struct.h"
// Member 'status_message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ComputeIK in the package custom_msg_interfaces.
typedef struct custom_msg_interfaces__srv__ComputeIK_Response
{
  std_msgs__msg__Float64MultiArray joint_angles_matrix;
  rosidl_runtime_c__String status_message;
} custom_msg_interfaces__srv__ComputeIK_Response;

// Struct for a sequence of custom_msg_interfaces__srv__ComputeIK_Response.
typedef struct custom_msg_interfaces__srv__ComputeIK_Response__Sequence
{
  custom_msg_interfaces__srv__ComputeIK_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_interfaces__srv__ComputeIK_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  custom_msg_interfaces__srv__ComputeIK_Event__request__MAX_SIZE = 1
};
// response
enum
{
  custom_msg_interfaces__srv__ComputeIK_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ComputeIK in the package custom_msg_interfaces.
typedef struct custom_msg_interfaces__srv__ComputeIK_Event
{
  service_msgs__msg__ServiceEventInfo info;
  custom_msg_interfaces__srv__ComputeIK_Request__Sequence request;
  custom_msg_interfaces__srv__ComputeIK_Response__Sequence response;
} custom_msg_interfaces__srv__ComputeIK_Event;

// Struct for a sequence of custom_msg_interfaces__srv__ComputeIK_Event.
typedef struct custom_msg_interfaces__srv__ComputeIK_Event__Sequence
{
  custom_msg_interfaces__srv__ComputeIK_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_interfaces__srv__ComputeIK_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_IK__STRUCT_H_
