// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from custom_msg_interfaces:srv/ComputeDirKin.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "custom_msg_interfaces/srv/detail/compute_dir_kin__functions.h"
#include "custom_msg_interfaces/srv/detail/compute_dir_kin__struct.hpp"
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

typedef struct _ComputeDirKin_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ComputeDirKin_Request_type_support_ids_t;

static const _ComputeDirKin_Request_type_support_ids_t _ComputeDirKin_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ComputeDirKin_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ComputeDirKin_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ComputeDirKin_Request_type_support_symbol_names_t _ComputeDirKin_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_msg_interfaces, srv, ComputeDirKin_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msg_interfaces, srv, ComputeDirKin_Request)),
  }
};

typedef struct _ComputeDirKin_Request_type_support_data_t
{
  void * data[2];
} _ComputeDirKin_Request_type_support_data_t;

static _ComputeDirKin_Request_type_support_data_t _ComputeDirKin_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ComputeDirKin_Request_message_typesupport_map = {
  2,
  "custom_msg_interfaces",
  &_ComputeDirKin_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ComputeDirKin_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ComputeDirKin_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ComputeDirKin_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ComputeDirKin_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &custom_msg_interfaces__srv__ComputeDirKin_Request__get_type_hash,
  &custom_msg_interfaces__srv__ComputeDirKin_Request__get_type_description,
  &custom_msg_interfaces__srv__ComputeDirKin_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_msg_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_msg_interfaces::srv::ComputeDirKin_Request>()
{
  return &::custom_msg_interfaces::srv::rosidl_typesupport_cpp::ComputeDirKin_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, custom_msg_interfaces, srv, ComputeDirKin_Request)() {
  return get_message_type_support_handle<custom_msg_interfaces::srv::ComputeDirKin_Request>();
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
// #include "custom_msg_interfaces/srv/detail/compute_dir_kin__functions.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_dir_kin__struct.hpp"
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

typedef struct _ComputeDirKin_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ComputeDirKin_Response_type_support_ids_t;

static const _ComputeDirKin_Response_type_support_ids_t _ComputeDirKin_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ComputeDirKin_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ComputeDirKin_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ComputeDirKin_Response_type_support_symbol_names_t _ComputeDirKin_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_msg_interfaces, srv, ComputeDirKin_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msg_interfaces, srv, ComputeDirKin_Response)),
  }
};

typedef struct _ComputeDirKin_Response_type_support_data_t
{
  void * data[2];
} _ComputeDirKin_Response_type_support_data_t;

static _ComputeDirKin_Response_type_support_data_t _ComputeDirKin_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ComputeDirKin_Response_message_typesupport_map = {
  2,
  "custom_msg_interfaces",
  &_ComputeDirKin_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ComputeDirKin_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ComputeDirKin_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ComputeDirKin_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ComputeDirKin_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &custom_msg_interfaces__srv__ComputeDirKin_Response__get_type_hash,
  &custom_msg_interfaces__srv__ComputeDirKin_Response__get_type_description,
  &custom_msg_interfaces__srv__ComputeDirKin_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_msg_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_msg_interfaces::srv::ComputeDirKin_Response>()
{
  return &::custom_msg_interfaces::srv::rosidl_typesupport_cpp::ComputeDirKin_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, custom_msg_interfaces, srv, ComputeDirKin_Response)() {
  return get_message_type_support_handle<custom_msg_interfaces::srv::ComputeDirKin_Response>();
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
// #include "custom_msg_interfaces/srv/detail/compute_dir_kin__functions.h"
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_dir_kin__struct.hpp"
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

typedef struct _ComputeDirKin_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ComputeDirKin_Event_type_support_ids_t;

static const _ComputeDirKin_Event_type_support_ids_t _ComputeDirKin_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ComputeDirKin_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ComputeDirKin_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ComputeDirKin_Event_type_support_symbol_names_t _ComputeDirKin_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_msg_interfaces, srv, ComputeDirKin_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msg_interfaces, srv, ComputeDirKin_Event)),
  }
};

typedef struct _ComputeDirKin_Event_type_support_data_t
{
  void * data[2];
} _ComputeDirKin_Event_type_support_data_t;

static _ComputeDirKin_Event_type_support_data_t _ComputeDirKin_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ComputeDirKin_Event_message_typesupport_map = {
  2,
  "custom_msg_interfaces",
  &_ComputeDirKin_Event_message_typesupport_ids.typesupport_identifier[0],
  &_ComputeDirKin_Event_message_typesupport_symbol_names.symbol_name[0],
  &_ComputeDirKin_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ComputeDirKin_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ComputeDirKin_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &custom_msg_interfaces__srv__ComputeDirKin_Event__get_type_hash,
  &custom_msg_interfaces__srv__ComputeDirKin_Event__get_type_description,
  &custom_msg_interfaces__srv__ComputeDirKin_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_msg_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_msg_interfaces::srv::ComputeDirKin_Event>()
{
  return &::custom_msg_interfaces::srv::rosidl_typesupport_cpp::ComputeDirKin_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, custom_msg_interfaces, srv, ComputeDirKin_Event)() {
  return get_message_type_support_handle<custom_msg_interfaces::srv::ComputeDirKin_Event>();
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
// #include "custom_msg_interfaces/srv/detail/compute_dir_kin__struct.hpp"
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

typedef struct _ComputeDirKin_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ComputeDirKin_type_support_ids_t;

static const _ComputeDirKin_type_support_ids_t _ComputeDirKin_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ComputeDirKin_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ComputeDirKin_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ComputeDirKin_type_support_symbol_names_t _ComputeDirKin_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_msg_interfaces, srv, ComputeDirKin)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msg_interfaces, srv, ComputeDirKin)),
  }
};

typedef struct _ComputeDirKin_type_support_data_t
{
  void * data[2];
} _ComputeDirKin_type_support_data_t;

static _ComputeDirKin_type_support_data_t _ComputeDirKin_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ComputeDirKin_service_typesupport_map = {
  2,
  "custom_msg_interfaces",
  &_ComputeDirKin_service_typesupport_ids.typesupport_identifier[0],
  &_ComputeDirKin_service_typesupport_symbol_names.symbol_name[0],
  &_ComputeDirKin_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ComputeDirKin_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ComputeDirKin_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<custom_msg_interfaces::srv::ComputeDirKin_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<custom_msg_interfaces::srv::ComputeDirKin_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<custom_msg_interfaces::srv::ComputeDirKin_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<custom_msg_interfaces::srv::ComputeDirKin>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<custom_msg_interfaces::srv::ComputeDirKin>,
  &custom_msg_interfaces__srv__ComputeDirKin__get_type_hash,
  &custom_msg_interfaces__srv__ComputeDirKin__get_type_description,
  &custom_msg_interfaces__srv__ComputeDirKin__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_msg_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<custom_msg_interfaces::srv::ComputeDirKin>()
{
  return &::custom_msg_interfaces::srv::rosidl_typesupport_cpp::ComputeDirKin_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, custom_msg_interfaces, srv, ComputeDirKin)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<custom_msg_interfaces::srv::ComputeDirKin>();
}

#ifdef __cplusplus
}
#endif
