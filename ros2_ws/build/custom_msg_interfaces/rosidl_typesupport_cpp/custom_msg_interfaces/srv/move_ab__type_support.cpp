// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from custom_msg_interfaces:srv/MoveAB.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "custom_msg_interfaces/srv/detail/move_ab__functions.h"
#include "custom_msg_interfaces/srv/detail/move_ab__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace custom_msg_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveAB_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAB_Request_type_support_ids_t;

static const _MoveAB_Request_type_support_ids_t _MoveAB_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveAB_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAB_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAB_Request_type_support_symbol_names_t _MoveAB_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_msg_interfaces, srv, MoveAB_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msg_interfaces, srv, MoveAB_Request)),
  }
};

typedef struct _MoveAB_Request_type_support_data_t
{
  void * data[2];
} _MoveAB_Request_type_support_data_t;

static _MoveAB_Request_type_support_data_t _MoveAB_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAB_Request_message_typesupport_map = {
  2,
  "custom_msg_interfaces",
  &_MoveAB_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAB_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAB_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAB_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAB_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &custom_msg_interfaces__srv__MoveAB_Request__get_type_hash,
  &custom_msg_interfaces__srv__MoveAB_Request__get_type_description,
  &custom_msg_interfaces__srv__MoveAB_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_msg_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_msg_interfaces::srv::MoveAB_Request>()
{
  return &::custom_msg_interfaces::srv::rosidl_typesupport_cpp::MoveAB_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, custom_msg_interfaces, srv, MoveAB_Request)() {
  return get_message_type_support_handle<custom_msg_interfaces::srv::MoveAB_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/move_ab__functions.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/move_ab__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_msg_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveAB_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAB_Response_type_support_ids_t;

static const _MoveAB_Response_type_support_ids_t _MoveAB_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveAB_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAB_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAB_Response_type_support_symbol_names_t _MoveAB_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_msg_interfaces, srv, MoveAB_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msg_interfaces, srv, MoveAB_Response)),
  }
};

typedef struct _MoveAB_Response_type_support_data_t
{
  void * data[2];
} _MoveAB_Response_type_support_data_t;

static _MoveAB_Response_type_support_data_t _MoveAB_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAB_Response_message_typesupport_map = {
  2,
  "custom_msg_interfaces",
  &_MoveAB_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAB_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAB_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAB_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAB_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &custom_msg_interfaces__srv__MoveAB_Response__get_type_hash,
  &custom_msg_interfaces__srv__MoveAB_Response__get_type_description,
  &custom_msg_interfaces__srv__MoveAB_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_msg_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_msg_interfaces::srv::MoveAB_Response>()
{
  return &::custom_msg_interfaces::srv::rosidl_typesupport_cpp::MoveAB_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, custom_msg_interfaces, srv, MoveAB_Response)() {
  return get_message_type_support_handle<custom_msg_interfaces::srv::MoveAB_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/move_ab__functions.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/move_ab__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_msg_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveAB_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAB_Event_type_support_ids_t;

static const _MoveAB_Event_type_support_ids_t _MoveAB_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveAB_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAB_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAB_Event_type_support_symbol_names_t _MoveAB_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_msg_interfaces, srv, MoveAB_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msg_interfaces, srv, MoveAB_Event)),
  }
};

typedef struct _MoveAB_Event_type_support_data_t
{
  void * data[2];
} _MoveAB_Event_type_support_data_t;

static _MoveAB_Event_type_support_data_t _MoveAB_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAB_Event_message_typesupport_map = {
  2,
  "custom_msg_interfaces",
  &_MoveAB_Event_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAB_Event_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAB_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAB_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAB_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &custom_msg_interfaces__srv__MoveAB_Event__get_type_hash,
  &custom_msg_interfaces__srv__MoveAB_Event__get_type_description,
  &custom_msg_interfaces__srv__MoveAB_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_msg_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_msg_interfaces::srv::MoveAB_Event>()
{
  return &::custom_msg_interfaces::srv::rosidl_typesupport_cpp::MoveAB_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, custom_msg_interfaces, srv, MoveAB_Event)() {
  return get_message_type_support_handle<custom_msg_interfaces::srv::MoveAB_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "custom_msg_interfaces/srv/detail/move_ab__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_msg_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveAB_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAB_type_support_ids_t;

static const _MoveAB_type_support_ids_t _MoveAB_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveAB_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAB_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAB_type_support_symbol_names_t _MoveAB_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_msg_interfaces, srv, MoveAB)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msg_interfaces, srv, MoveAB)),
  }
};

typedef struct _MoveAB_type_support_data_t
{
  void * data[2];
} _MoveAB_type_support_data_t;

static _MoveAB_type_support_data_t _MoveAB_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAB_service_typesupport_map = {
  2,
  "custom_msg_interfaces",
  &_MoveAB_service_typesupport_ids.typesupport_identifier[0],
  &_MoveAB_service_typesupport_symbol_names.symbol_name[0],
  &_MoveAB_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveAB_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAB_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<custom_msg_interfaces::srv::MoveAB_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<custom_msg_interfaces::srv::MoveAB_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<custom_msg_interfaces::srv::MoveAB_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<custom_msg_interfaces::srv::MoveAB>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<custom_msg_interfaces::srv::MoveAB>,
  &custom_msg_interfaces__srv__MoveAB__get_type_hash,
  &custom_msg_interfaces__srv__MoveAB__get_type_description,
  &custom_msg_interfaces__srv__MoveAB__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_msg_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<custom_msg_interfaces::srv::MoveAB>()
{
  return &::custom_msg_interfaces::srv::rosidl_typesupport_cpp::MoveAB_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, custom_msg_interfaces, srv, MoveAB)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<custom_msg_interfaces::srv::MoveAB>();
}

#ifdef __cplusplus
}
#endif
