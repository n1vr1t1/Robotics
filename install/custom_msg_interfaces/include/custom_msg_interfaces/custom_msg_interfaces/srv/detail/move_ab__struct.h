// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msg_interfaces:srv/MoveAB.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/srv/move_ab.h"


#ifndef CUSTOM_MSG_INTERFACES__SRV__DETAIL__MOVE_AB__STRUCT_H_
#define CUSTOM_MSG_INTERFACES__SRV__DETAIL__MOVE_AB__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose_start'
// Member 'pose_end'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/MoveAB in the package custom_msg_interfaces.
typedef struct custom_msg_interfaces__srv__MoveAB_Request
{
  geometry_msgs__msg__Pose pose_start;
  geometry_msgs__msg__Pose pose_end;
} custom_msg_interfaces__srv__MoveAB_Request;

// Struct for a sequence of custom_msg_interfaces__srv__MoveAB_Request.
typedef struct custom_msg_interfaces__srv__MoveAB_Request__Sequence
{
  custom_msg_interfaces__srv__MoveAB_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_interfaces__srv__MoveAB_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/MoveAB in the package custom_msg_interfaces.
typedef struct custom_msg_interfaces__srv__MoveAB_Response
{
  bool success;
  rosidl_runtime_c__String message;
} custom_msg_interfaces__srv__MoveAB_Response;

// Struct for a sequence of custom_msg_interfaces__srv__MoveAB_Response.
typedef struct custom_msg_interfaces__srv__MoveAB_Response__Sequence
{
  custom_msg_interfaces__srv__MoveAB_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_interfaces__srv__MoveAB_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  custom_msg_interfaces__srv__MoveAB_Event__request__MAX_SIZE = 1
};
// response
enum
{
  custom_msg_interfaces__srv__MoveAB_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/MoveAB in the package custom_msg_interfaces.
typedef struct custom_msg_interfaces__srv__MoveAB_Event
{
  service_msgs__msg__ServiceEventInfo info;
  custom_msg_interfaces__srv__MoveAB_Request__Sequence request;
  custom_msg_interfaces__srv__MoveAB_Response__Sequence response;
} custom_msg_interfaces__srv__MoveAB_Event;

// Struct for a sequence of custom_msg_interfaces__srv__MoveAB_Event.
typedef struct custom_msg_interfaces__srv__MoveAB_Event__Sequence
{
  custom_msg_interfaces__srv__MoveAB_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_interfaces__srv__MoveAB_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSG_INTERFACES__SRV__DETAIL__MOVE_AB__STRUCT_H_
