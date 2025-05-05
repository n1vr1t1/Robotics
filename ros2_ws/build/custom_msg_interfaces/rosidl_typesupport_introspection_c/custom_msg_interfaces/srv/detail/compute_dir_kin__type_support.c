// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_msg_interfaces:srv/ComputeDirKin.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_msg_interfaces/srv/detail/compute_dir_kin__rosidl_typesupport_introspection_c.h"
#include "custom_msg_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_msg_interfaces/srv/detail/compute_dir_kin__functions.h"
#include "custom_msg_interfaces/srv/detail/compute_dir_kin__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `joints`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `frame_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__ComputeDirKin_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_msg_interfaces__srv__ComputeDirKin_Request__init(message_memory);
}

void custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__ComputeDirKin_Request_fini_function(void * message_memory)
{
  custom_msg_interfaces__srv__ComputeDirKin_Request__fini(message_memory);
}

size_t custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__size_function__ComputeDirKin_Request__joints(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__get_const_function__ComputeDirKin_Request__joints(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__get_function__ComputeDirKin_Request__joints(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__fetch_function__ComputeDirKin_Request__joints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__get_const_function__ComputeDirKin_Request__joints(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__assign_function__ComputeDirKin_Request__joints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__get_function__ComputeDirKin_Request__joints(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__resize_function__ComputeDirKin_Request__joints(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__ComputeDirKin_Request_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg_interfaces__srv__ComputeDirKin_Request, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg_interfaces__srv__ComputeDirKin_Request, joints),  // bytes offset in struct
    NULL,  // default value
    custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__size_function__ComputeDirKin_Request__joints,  // size() function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__get_const_function__ComputeDirKin_Request__joints,  // get_const(index) function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__get_function__ComputeDirKin_Request__joints,  // get(index) function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__fetch_function__ComputeDirKin_Request__joints,  // fetch(index, &value) function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__assign_function__ComputeDirKin_Request__joints,  // assign(index, value) function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__resize_function__ComputeDirKin_Request__joints  // resize(index) function pointer
  },
  {
    "frame_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg_interfaces__srv__ComputeDirKin_Request, frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__ComputeDirKin_Request_message_members = {
  "custom_msg_interfaces__srv",  // message namespace
  "ComputeDirKin_Request",  // message name
  3,  // number of fields
  sizeof(custom_msg_interfaces__srv__ComputeDirKin_Request),
  false,  // has_any_key_member_
  custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__ComputeDirKin_Request_message_member_array,  // message members
  custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__ComputeDirKin_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__ComputeDirKin_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__ComputeDirKin_Request_message_type_support_handle = {
  0,
  &custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__ComputeDirKin_Request_message_members,
  get_message_typesupport_handle_function,
  &custom_msg_interfaces__srv__ComputeDirKin_Request__get_type_hash,
  &custom_msg_interfaces__srv__ComputeDirKin_Request__get_type_description,
  &custom_msg_interfaces__srv__ComputeDirKin_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msg_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputeDirKin_Request)() {
  custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__ComputeDirKin_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__ComputeDirKin_Request_message_type_support_handle.typesupport_identifier) {
    custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__ComputeDirKin_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__ComputeDirKin_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_dir_kin__rosidl_typesupport_introspection_c.h"
// already included above
// #include "custom_msg_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_dir_kin__functions.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_dir_kin__struct.h"


// Include directives for member types
// Member `final_pose`
#include "geometry_msgs/msg/pose.h"
// Member `final_pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `status_message`
// Member `frame_id`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_msg_interfaces__srv__ComputeDirKin_Response__rosidl_typesupport_introspection_c__ComputeDirKin_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_msg_interfaces__srv__ComputeDirKin_Response__init(message_memory);
}

void custom_msg_interfaces__srv__ComputeDirKin_Response__rosidl_typesupport_introspection_c__ComputeDirKin_Response_fini_function(void * message_memory)
{
  custom_msg_interfaces__srv__ComputeDirKin_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember custom_msg_interfaces__srv__ComputeDirKin_Response__rosidl_typesupport_introspection_c__ComputeDirKin_Response_message_member_array[3] = {
  {
    "final_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg_interfaces__srv__ComputeDirKin_Response, final_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "status_message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg_interfaces__srv__ComputeDirKin_Response, status_message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg_interfaces__srv__ComputeDirKin_Response, frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_msg_interfaces__srv__ComputeDirKin_Response__rosidl_typesupport_introspection_c__ComputeDirKin_Response_message_members = {
  "custom_msg_interfaces__srv",  // message namespace
  "ComputeDirKin_Response",  // message name
  3,  // number of fields
  sizeof(custom_msg_interfaces__srv__ComputeDirKin_Response),
  false,  // has_any_key_member_
  custom_msg_interfaces__srv__ComputeDirKin_Response__rosidl_typesupport_introspection_c__ComputeDirKin_Response_message_member_array,  // message members
  custom_msg_interfaces__srv__ComputeDirKin_Response__rosidl_typesupport_introspection_c__ComputeDirKin_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_msg_interfaces__srv__ComputeDirKin_Response__rosidl_typesupport_introspection_c__ComputeDirKin_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_msg_interfaces__srv__ComputeDirKin_Response__rosidl_typesupport_introspection_c__ComputeDirKin_Response_message_type_support_handle = {
  0,
  &custom_msg_interfaces__srv__ComputeDirKin_Response__rosidl_typesupport_introspection_c__ComputeDirKin_Response_message_members,
  get_message_typesupport_handle_function,
  &custom_msg_interfaces__srv__ComputeDirKin_Response__get_type_hash,
  &custom_msg_interfaces__srv__ComputeDirKin_Response__get_type_description,
  &custom_msg_interfaces__srv__ComputeDirKin_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msg_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputeDirKin_Response)() {
  custom_msg_interfaces__srv__ComputeDirKin_Response__rosidl_typesupport_introspection_c__ComputeDirKin_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!custom_msg_interfaces__srv__ComputeDirKin_Response__rosidl_typesupport_introspection_c__ComputeDirKin_Response_message_type_support_handle.typesupport_identifier) {
    custom_msg_interfaces__srv__ComputeDirKin_Response__rosidl_typesupport_introspection_c__ComputeDirKin_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_msg_interfaces__srv__ComputeDirKin_Response__rosidl_typesupport_introspection_c__ComputeDirKin_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_dir_kin__rosidl_typesupport_introspection_c.h"
// already included above
// #include "custom_msg_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_dir_kin__functions.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_dir_kin__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "custom_msg_interfaces/srv/compute_dir_kin.h"
// Member `request`
// Member `response`
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_dir_kin__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_msg_interfaces__srv__ComputeDirKin_Event__init(message_memory);
}

void custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_fini_function(void * message_memory)
{
  custom_msg_interfaces__srv__ComputeDirKin_Event__fini(message_memory);
}

size_t custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__size_function__ComputeDirKin_Event__request(
  const void * untyped_member)
{
  const custom_msg_interfaces__srv__ComputeDirKin_Request__Sequence * member =
    (const custom_msg_interfaces__srv__ComputeDirKin_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__get_const_function__ComputeDirKin_Event__request(
  const void * untyped_member, size_t index)
{
  const custom_msg_interfaces__srv__ComputeDirKin_Request__Sequence * member =
    (const custom_msg_interfaces__srv__ComputeDirKin_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__get_function__ComputeDirKin_Event__request(
  void * untyped_member, size_t index)
{
  custom_msg_interfaces__srv__ComputeDirKin_Request__Sequence * member =
    (custom_msg_interfaces__srv__ComputeDirKin_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__fetch_function__ComputeDirKin_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const custom_msg_interfaces__srv__ComputeDirKin_Request * item =
    ((const custom_msg_interfaces__srv__ComputeDirKin_Request *)
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__get_const_function__ComputeDirKin_Event__request(untyped_member, index));
  custom_msg_interfaces__srv__ComputeDirKin_Request * value =
    (custom_msg_interfaces__srv__ComputeDirKin_Request *)(untyped_value);
  *value = *item;
}

void custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__assign_function__ComputeDirKin_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  custom_msg_interfaces__srv__ComputeDirKin_Request * item =
    ((custom_msg_interfaces__srv__ComputeDirKin_Request *)
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__get_function__ComputeDirKin_Event__request(untyped_member, index));
  const custom_msg_interfaces__srv__ComputeDirKin_Request * value =
    (const custom_msg_interfaces__srv__ComputeDirKin_Request *)(untyped_value);
  *item = *value;
}

bool custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__resize_function__ComputeDirKin_Event__request(
  void * untyped_member, size_t size)
{
  custom_msg_interfaces__srv__ComputeDirKin_Request__Sequence * member =
    (custom_msg_interfaces__srv__ComputeDirKin_Request__Sequence *)(untyped_member);
  custom_msg_interfaces__srv__ComputeDirKin_Request__Sequence__fini(member);
  return custom_msg_interfaces__srv__ComputeDirKin_Request__Sequence__init(member, size);
}

size_t custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__size_function__ComputeDirKin_Event__response(
  const void * untyped_member)
{
  const custom_msg_interfaces__srv__ComputeDirKin_Response__Sequence * member =
    (const custom_msg_interfaces__srv__ComputeDirKin_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__get_const_function__ComputeDirKin_Event__response(
  const void * untyped_member, size_t index)
{
  const custom_msg_interfaces__srv__ComputeDirKin_Response__Sequence * member =
    (const custom_msg_interfaces__srv__ComputeDirKin_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__get_function__ComputeDirKin_Event__response(
  void * untyped_member, size_t index)
{
  custom_msg_interfaces__srv__ComputeDirKin_Response__Sequence * member =
    (custom_msg_interfaces__srv__ComputeDirKin_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__fetch_function__ComputeDirKin_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const custom_msg_interfaces__srv__ComputeDirKin_Response * item =
    ((const custom_msg_interfaces__srv__ComputeDirKin_Response *)
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__get_const_function__ComputeDirKin_Event__response(untyped_member, index));
  custom_msg_interfaces__srv__ComputeDirKin_Response * value =
    (custom_msg_interfaces__srv__ComputeDirKin_Response *)(untyped_value);
  *value = *item;
}

void custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__assign_function__ComputeDirKin_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  custom_msg_interfaces__srv__ComputeDirKin_Response * item =
    ((custom_msg_interfaces__srv__ComputeDirKin_Response *)
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__get_function__ComputeDirKin_Event__response(untyped_member, index));
  const custom_msg_interfaces__srv__ComputeDirKin_Response * value =
    (const custom_msg_interfaces__srv__ComputeDirKin_Response *)(untyped_value);
  *item = *value;
}

bool custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__resize_function__ComputeDirKin_Event__response(
  void * untyped_member, size_t size)
{
  custom_msg_interfaces__srv__ComputeDirKin_Response__Sequence * member =
    (custom_msg_interfaces__srv__ComputeDirKin_Response__Sequence *)(untyped_member);
  custom_msg_interfaces__srv__ComputeDirKin_Response__Sequence__fini(member);
  return custom_msg_interfaces__srv__ComputeDirKin_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg_interfaces__srv__ComputeDirKin_Event, info),  // bytes offset in struct
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
    offsetof(custom_msg_interfaces__srv__ComputeDirKin_Event, request),  // bytes offset in struct
    NULL,  // default value
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__size_function__ComputeDirKin_Event__request,  // size() function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__get_const_function__ComputeDirKin_Event__request,  // get_const(index) function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__get_function__ComputeDirKin_Event__request,  // get(index) function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__fetch_function__ComputeDirKin_Event__request,  // fetch(index, &value) function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__assign_function__ComputeDirKin_Event__request,  // assign(index, value) function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__resize_function__ComputeDirKin_Event__request  // resize(index) function pointer
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
    offsetof(custom_msg_interfaces__srv__ComputeDirKin_Event, response),  // bytes offset in struct
    NULL,  // default value
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__size_function__ComputeDirKin_Event__response,  // size() function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__get_const_function__ComputeDirKin_Event__response,  // get_const(index) function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__get_function__ComputeDirKin_Event__response,  // get(index) function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__fetch_function__ComputeDirKin_Event__response,  // fetch(index, &value) function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__assign_function__ComputeDirKin_Event__response,  // assign(index, value) function pointer
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__resize_function__ComputeDirKin_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_message_members = {
  "custom_msg_interfaces__srv",  // message namespace
  "ComputeDirKin_Event",  // message name
  3,  // number of fields
  sizeof(custom_msg_interfaces__srv__ComputeDirKin_Event),
  false,  // has_any_key_member_
  custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_message_member_array,  // message members
  custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_message_type_support_handle = {
  0,
  &custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_message_members,
  get_message_typesupport_handle_function,
  &custom_msg_interfaces__srv__ComputeDirKin_Event__get_type_hash,
  &custom_msg_interfaces__srv__ComputeDirKin_Event__get_type_description,
  &custom_msg_interfaces__srv__ComputeDirKin_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msg_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputeDirKin_Event)() {
  custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputeDirKin_Request)();
  custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputeDirKin_Response)();
  if (!custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_message_type_support_handle.typesupport_identifier) {
    custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_msg_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_dir_kin__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers custom_msg_interfaces__srv__detail__compute_dir_kin__rosidl_typesupport_introspection_c__ComputeDirKin_service_members = {
  "custom_msg_interfaces__srv",  // service namespace
  "ComputeDirKin",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // custom_msg_interfaces__srv__detail__compute_dir_kin__rosidl_typesupport_introspection_c__ComputeDirKin_Request_message_type_support_handle,
  NULL,  // response message
  // custom_msg_interfaces__srv__detail__compute_dir_kin__rosidl_typesupport_introspection_c__ComputeDirKin_Response_message_type_support_handle
  NULL  // event_message
  // custom_msg_interfaces__srv__detail__compute_dir_kin__rosidl_typesupport_introspection_c__ComputeDirKin_Response_message_type_support_handle
};


static rosidl_service_type_support_t custom_msg_interfaces__srv__detail__compute_dir_kin__rosidl_typesupport_introspection_c__ComputeDirKin_service_type_support_handle = {
  0,
  &custom_msg_interfaces__srv__detail__compute_dir_kin__rosidl_typesupport_introspection_c__ComputeDirKin_service_members,
  get_service_typesupport_handle_function,
  &custom_msg_interfaces__srv__ComputeDirKin_Request__rosidl_typesupport_introspection_c__ComputeDirKin_Request_message_type_support_handle,
  &custom_msg_interfaces__srv__ComputeDirKin_Response__rosidl_typesupport_introspection_c__ComputeDirKin_Response_message_type_support_handle,
  &custom_msg_interfaces__srv__ComputeDirKin_Event__rosidl_typesupport_introspection_c__ComputeDirKin_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    custom_msg_interfaces,
    srv,
    ComputeDirKin
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    custom_msg_interfaces,
    srv,
    ComputeDirKin
  ),
  &custom_msg_interfaces__srv__ComputeDirKin__get_type_hash,
  &custom_msg_interfaces__srv__ComputeDirKin__get_type_description,
  &custom_msg_interfaces__srv__ComputeDirKin__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputeDirKin_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputeDirKin_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputeDirKin_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msg_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputeDirKin)(void) {
  if (!custom_msg_interfaces__srv__detail__compute_dir_kin__rosidl_typesupport_introspection_c__ComputeDirKin_service_type_support_handle.typesupport_identifier) {
    custom_msg_interfaces__srv__detail__compute_dir_kin__rosidl_typesupport_introspection_c__ComputeDirKin_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)custom_msg_interfaces__srv__detail__compute_dir_kin__rosidl_typesupport_introspection_c__ComputeDirKin_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputeDirKin_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputeDirKin_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_interfaces, srv, ComputeDirKin_Event)()->data;
  }

  return &custom_msg_interfaces__srv__detail__compute_dir_kin__rosidl_typesupport_introspection_c__ComputeDirKin_service_type_support_handle;
}
