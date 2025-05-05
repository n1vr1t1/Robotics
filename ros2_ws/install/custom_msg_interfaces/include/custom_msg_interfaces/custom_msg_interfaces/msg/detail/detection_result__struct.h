// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msg_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/msg/detection_result.h"


#ifndef CUSTOM_MSG_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_H_
#define CUSTOM_MSG_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_H_

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
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/DetectionResult in the package custom_msg_interfaces.
typedef struct custom_msg_interfaces__msg__DetectionResult
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__float__Sequence data;
} custom_msg_interfaces__msg__DetectionResult;

// Struct for a sequence of custom_msg_interfaces__msg__DetectionResult.
typedef struct custom_msg_interfaces__msg__DetectionResult__Sequence
{
  custom_msg_interfaces__msg__DetectionResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_interfaces__msg__DetectionResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSG_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_H_
