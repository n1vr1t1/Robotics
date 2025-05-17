// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msg_interfaces:srv/ComputeDirKin.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/srv/compute_dir_kin.h"


#ifndef CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_DIR_KIN__STRUCT_H_
#define CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_DIR_KIN__STRUCT_H_

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
// Member 'joints'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'frame_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ComputeDirKin in the package custom_msg_interfaces.
typedef struct custom_msg_interfaces__srv__ComputeDirKin_Request
{
  /// Request
  std_msgs__msg__Header header;
  rosidl_runtime_c__double__Sequence joints;
  rosidl_runtime_c__String frame_id;
} custom_msg_interfaces__srv__ComputeDirKin_Request;

// Struct for a sequence of custom_msg_interfaces__srv__ComputeDirKin_Request.
typedef struct custom_msg_interfaces__srv__ComputeDirKin_Request__Sequence
{
  custom_msg_interfaces__srv__ComputeDirKin_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_interfaces__srv__ComputeDirKin_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'final_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'status_message'
// Member 'frame_id'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ComputeDirKin in the package custom_msg_interfaces.
typedef struct custom_msg_interfaces__srv__ComputeDirKin_Response
{
  geometry_msgs__msg__Pose final_pose;
  rosidl_runtime_c__String status_message;
  rosidl_runtime_c__String frame_id;
} custom_msg_interfaces__srv__ComputeDirKin_Response;

// Struct for a sequence of custom_msg_interfaces__srv__ComputeDirKin_Response.
typedef struct custom_msg_interfaces__srv__ComputeDirKin_Response__Sequence
{
  custom_msg_interfaces__srv__ComputeDirKin_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_interfaces__srv__ComputeDirKin_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  custom_msg_interfaces__srv__ComputeDirKin_Event__request__MAX_SIZE = 1
};
// response
enum
{
  custom_msg_interfaces__srv__ComputeDirKin_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ComputeDirKin in the package custom_msg_interfaces.
typedef struct custom_msg_interfaces__srv__ComputeDirKin_Event
{
  service_msgs__msg__ServiceEventInfo info;
  custom_msg_interfaces__srv__ComputeDirKin_Request__Sequence request;
  custom_msg_interfaces__srv__ComputeDirKin_Response__Sequence response;
} custom_msg_interfaces__srv__ComputeDirKin_Event;

// Struct for a sequence of custom_msg_interfaces__srv__ComputeDirKin_Event.
typedef struct custom_msg_interfaces__srv__ComputeDirKin_Event__Sequence
{
  custom_msg_interfaces__srv__ComputeDirKin_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_interfaces__srv__ComputeDirKin_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_DIR_KIN__STRUCT_H_
