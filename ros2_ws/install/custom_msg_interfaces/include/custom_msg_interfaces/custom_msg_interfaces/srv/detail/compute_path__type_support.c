// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_msg_interfaces:srv/ComputePath.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_msg_interfaces/srv/detail/compute_path__rosidl_typesupport_introspection_c.h"
#include "custom_msg_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_msg_interfaces/srv/detail/compute_path__functions.h"
#include "custom_msg_interfaces/srv/detail/compute_path__struct.h"


// Include directives for member types
// Member `pose_start`
// Member `pose_end`
#include "geometry_msgs/msg/pose.h"
// Member `pose_start`
// Member `pose_end`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_msg_interfaces__srv__ComputePath_Request__init(message_memory);
}

void custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_fini_function(void * message_memory)
{
  custom_msg_interfaces__srv__ComputePath_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_message_member_array[3] = {
  {
    "pose_start",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg_interfaces__srv__ComputePath_Request, pose_start),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose_end",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg_interfaces__srv__ComputePath_Request, pose_end),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_interpolations",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg_interfaces__srv__ComputePath_Request, num_interpolations),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_message_members = {
  "custom_msg_interfaces__srv",  // message namespace
  "ComputePath_Request",  // message name
  3,  // number of fields
  sizeof(custom_msg_interfaces__srv__ComputePath_Request),
  false,  // has_any_key_member_
  custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_message_member_array,  // message members
  custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_message_type_support_handle = {
  0,
  &custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_message_members,
  get_message_typesupport_handle_function,
  &custom_msg_interfaces__srv__ComputePath_Request__get_type_hash,
  &custom_msg_interfaces__srv__ComputePath_Request__get_type_description,
  &custom_msg_interfaces__srv__ComputePath_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msg_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputePath_Request)() {
  custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_message_type_support_handle.typesupport_identifier) {
    custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_path__rosidl_typesupport_introspection_c.h"
// already included above
// #include "custom_msg_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_path__functions.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_path__struct.h"


// Include directives for member types
// Member `poses`
// already included above
// #include "geometry_msgs/msg/pose.h"
// Member `poses`
// already included above
// #include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__ComputePath_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_msg_interfaces__srv__ComputePath_Response__init(message_memory);
}

void custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__ComputePath_Response_fini_function(void * message_memory)
{
  custom_msg_interfaces__srv__ComputePath_Response__fini(message_memory);
}

size_t custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__size_function__ComputePath_Response__poses(
  const void * untyped_member)
{
  const geometry_msgs__msg__Pose__Sequence * member =
    (const geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__get_const_function__ComputePath_Response__poses(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Pose__Sequence * member =
    (const geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__get_function__ComputePath_Response__poses(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Pose__Sequence * member =
    (geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__fetch_function__ComputePath_Response__poses(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Pose * item =
    ((const geometry_msgs__msg__Pose *)
    custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__get_const_function__ComputePath_Response__poses(untyped_member, index));
  geometry_msgs__msg__Pose * value =
    (geometry_msgs__msg__Pose *)(untyped_value);
  *value = *item;
}

void custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__assign_function__ComputePath_Response__poses(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Pose * item =
    ((geometry_msgs__msg__Pose *)
    custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__get_function__ComputePath_Response__poses(untyped_member, index));
  const geometry_msgs__msg__Pose * value =
    (const geometry_msgs__msg__Pose *)(untyped_value);
  *item = *value;
}

bool custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__resize_function__ComputePath_Response__poses(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Pose__Sequence * member =
    (geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  geometry_msgs__msg__Pose__Sequence__fini(member);
  return geometry_msgs__msg__Pose__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__ComputePath_Response_message_member_array[1] = {
  {
    "poses",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg_interfaces__srv__ComputePath_Response, poses),  // bytes offset in struct
    NULL,  // default value
    custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__size_function__ComputePath_Response__poses,  // size() function pointer
    custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__get_const_function__ComputePath_Response__poses,  // get_const(index) function pointer
    custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__get_function__ComputePath_Response__poses,  // get(index) function pointer
    custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__fetch_function__ComputePath_Response__poses,  // fetch(index, &value) function pointer
    custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__assign_function__ComputePath_Response__poses,  // assign(index, value) function pointer
    custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__resize_function__ComputePath_Response__poses  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__ComputePath_Response_message_members = {
  "custom_msg_interfaces__srv",  // message namespace
  "ComputePath_Response",  // message name
  1,  // number of fields
  sizeof(custom_msg_interfaces__srv__ComputePath_Response),
  false,  // has_any_key_member_
  custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__ComputePath_Response_message_member_array,  // message members
  custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__ComputePath_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__ComputePath_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__ComputePath_Response_message_type_support_handle = {
  0,
  &custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__ComputePath_Response_message_members,
  get_message_typesupport_handle_function,
  &custom_msg_interfaces__srv__ComputePath_Response__get_type_hash,
  &custom_msg_interfaces__srv__ComputePath_Response__get_type_description,
  &custom_msg_interfaces__srv__ComputePath_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msg_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputePath_Response)() {
  custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__ComputePath_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__ComputePath_Response_message_type_support_handle.typesupport_identifier) {
    custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__ComputePath_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__ComputePath_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_path__rosidl_typesupport_introspection_c.h"
// already included above
// #include "custom_msg_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_path__functions.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_path__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "custom_msg_interfaces/srv/compute_path.h"
// Member `request`
// Member `response`
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_path__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_msg_interfaces__srv__ComputePath_Event__init(message_memory);
}

void custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_fini_function(void * message_memory)
{
  custom_msg_interfaces__srv__ComputePath_Event__fini(message_memory);
}

size_t custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__size_function__ComputePath_Event__request(
  const void * untyped_member)
{
  const custom_msg_interfaces__srv__ComputePath_Request__Sequence * member =
    (const custom_msg_interfaces__srv__ComputePath_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__get_const_function__ComputePath_Event__request(
  const void * untyped_member, size_t index)
{
  const custom_msg_interfaces__srv__ComputePath_Request__Sequence * member =
    (const custom_msg_interfaces__srv__ComputePath_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__get_function__ComputePath_Event__request(
  void * untyped_member, size_t index)
{
  custom_msg_interfaces__srv__ComputePath_Request__Sequence * member =
    (custom_msg_interfaces__srv__ComputePath_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__fetch_function__ComputePath_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const custom_msg_interfaces__srv__ComputePath_Request * item =
    ((const custom_msg_interfaces__srv__ComputePath_Request *)
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__get_const_function__ComputePath_Event__request(untyped_member, index));
  custom_msg_interfaces__srv__ComputePath_Request * value =
    (custom_msg_interfaces__srv__ComputePath_Request *)(untyped_value);
  *value = *item;
}

void custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__assign_function__ComputePath_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  custom_msg_interfaces__srv__ComputePath_Request * item =
    ((custom_msg_interfaces__srv__ComputePath_Request *)
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__get_function__ComputePath_Event__request(untyped_member, index));
  const custom_msg_interfaces__srv__ComputePath_Request * value =
    (const custom_msg_interfaces__srv__ComputePath_Request *)(untyped_value);
  *item = *value;
}

bool custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__resize_function__ComputePath_Event__request(
  void * untyped_member, size_t size)
{
  custom_msg_interfaces__srv__ComputePath_Request__Sequence * member =
    (custom_msg_interfaces__srv__ComputePath_Request__Sequence *)(untyped_member);
  custom_msg_interfaces__srv__ComputePath_Request__Sequence__fini(member);
  return custom_msg_interfaces__srv__ComputePath_Request__Sequence__init(member, size);
}

size_t custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__size_function__ComputePath_Event__response(
  const void * untyped_member)
{
  const custom_msg_interfaces__srv__ComputePath_Response__Sequence * member =
    (const custom_msg_interfaces__srv__ComputePath_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__get_const_function__ComputePath_Event__response(
  const void * untyped_member, size_t index)
{
  const custom_msg_interfaces__srv__ComputePath_Response__Sequence * member =
    (const custom_msg_interfaces__srv__ComputePath_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__get_function__ComputePath_Event__response(
  void * untyped_member, size_t index)
{
  custom_msg_interfaces__srv__ComputePath_Response__Sequence * member =
    (custom_msg_interfaces__srv__ComputePath_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__fetch_function__ComputePath_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const custom_msg_interfaces__srv__ComputePath_Response * item =
    ((const custom_msg_interfaces__srv__ComputePath_Response *)
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__get_const_function__ComputePath_Event__response(untyped_member, index));
  custom_msg_interfaces__srv__ComputePath_Response * value =
    (custom_msg_interfaces__srv__ComputePath_Response *)(untyped_value);
  *value = *item;
}

void custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__assign_function__ComputePath_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  custom_msg_interfaces__srv__ComputePath_Response * item =
    ((custom_msg_interfaces__srv__ComputePath_Response *)
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__get_function__ComputePath_Event__response(untyped_member, index));
  const custom_msg_interfaces__srv__ComputePath_Response * value =
    (const custom_msg_interfaces__srv__ComputePath_Response *)(untyped_value);
  *item = *value;
}

bool custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__resize_function__ComputePath_Event__response(
  void * untyped_member, size_t size)
{
  custom_msg_interfaces__srv__ComputePath_Response__Sequence * member =
    (custom_msg_interfaces__srv__ComputePath_Response__Sequence *)(untyped_member);
  custom_msg_interfaces__srv__ComputePath_Response__Sequence__fini(member);
  return custom_msg_interfaces__srv__ComputePath_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg_interfaces__srv__ComputePath_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(custom_msg_interfaces__srv__ComputePath_Event, request),  // bytes offset in struct
    NULL,  // default value
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__size_function__ComputePath_Event__request,  // size() function pointer
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__get_const_function__ComputePath_Event__request,  // get_const(index) function pointer
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__get_function__ComputePath_Event__request,  // get(index) function pointer
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__fetch_function__ComputePath_Event__request,  // fetch(index, &value) function pointer
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__assign_function__ComputePath_Event__request,  // assign(index, value) function pointer
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__resize_function__ComputePath_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(custom_msg_interfaces__srv__ComputePath_Event, response),  // bytes offset in struct
    NULL,  // default value
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__size_function__ComputePath_Event__response,  // size() function pointer
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__get_const_function__ComputePath_Event__response,  // get_const(index) function pointer
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__get_function__ComputePath_Event__response,  // get(index) function pointer
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__fetch_function__ComputePath_Event__response,  // fetch(index, &value) function pointer
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__assign_function__ComputePath_Event__response,  // assign(index, value) function pointer
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__resize_function__ComputePath_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_message_members = {
  "custom_msg_interfaces__srv",  // message namespace
  "ComputePath_Event",  // message name
  3,  // number of fields
  sizeof(custom_msg_interfaces__srv__ComputePath_Event),
  false,  // has_any_key_member_
  custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_message_member_array,  // message members
  custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_message_type_support_handle = {
  0,
  &custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_message_members,
  get_message_typesupport_handle_function,
  &custom_msg_interfaces__srv__ComputePath_Event__get_type_hash,
  &custom_msg_interfaces__srv__ComputePath_Event__get_type_description,
  &custom_msg_interfaces__srv__ComputePath_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msg_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputePath_Event)() {
  custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputePath_Request)();
  custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputePath_Response)();
  if (!custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_message_type_support_handle.typesupport_identifier) {
    custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_msg_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_path__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers custom_msg_interfaces__srv__detail__compute_path__rosidl_typesupport_introspection_c__ComputePath_service_members = {
  "custom_msg_interfaces__srv",  // service namespace
  "ComputePath",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // custom_msg_interfaces__srv__detail__compute_path__rosidl_typesupport_introspection_c__ComputePath_Request_message_type_support_handle,
  NULL,  // response message
  // custom_msg_interfaces__srv__detail__compute_path__rosidl_typesupport_introspection_c__ComputePath_Response_message_type_support_handle
  NULL  // event_message
  // custom_msg_interfaces__srv__detail__compute_path__rosidl_typesupport_introspection_c__ComputePath_Response_message_type_support_handle
};


static rosidl_service_type_support_t custom_msg_interfaces__srv__detail__compute_path__rosidl_typesupport_introspection_c__ComputePath_service_type_support_handle = {
  0,
  &custom_msg_interfaces__srv__detail__compute_path__rosidl_typesupport_introspection_c__ComputePath_service_members,
  get_service_typesupport_handle_function,
  &custom_msg_interfaces__srv__ComputePath_Request__rosidl_typesupport_introspection_c__ComputePath_Request_message_type_support_handle,
  &custom_msg_interfaces__srv__ComputePath_Response__rosidl_typesupport_introspection_c__ComputePath_Response_message_type_support_handle,
  &custom_msg_interfaces__srv__ComputePath_Event__rosidl_typesupport_introspection_c__ComputePath_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    custom_msg_interfaces,
    srv,
    ComputePath
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    custom_msg_interfaces,
    srv,
    ComputePath
  ),
  &custom_msg_interfaces__srv__ComputePath__get_type_hash,
  &custom_msg_interfaces__srv__ComputePath__get_type_description,
  &custom_msg_interfaces__srv__ComputePath__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputePath_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputePath_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputePath_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msg_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputePath)(void) {
  if (!custom_msg_interfaces__srv__detail__compute_path__rosidl_typesupport_introspection_c__ComputePath_service_type_support_handle.typesupport_identifier) {
    custom_msg_interfaces__srv__detail__compute_path__rosidl_typesupport_introspection_c__ComputePath_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)custom_msg_interfaces__srv__detail__compute_path__rosidl_typesupport_introspection_c__ComputePath_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputePath_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputePath_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputePath_Event)()->data;
  }

  return &custom_msg_interfaces__srv__detail__compute_path__rosidl_typesupport_introspection_c__ComputePath_service_type_support_handle;
}
