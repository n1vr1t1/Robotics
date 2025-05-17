// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msg_interfaces:srv/ComputeTrajectory.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msg_interfaces/srv/compute_trajectory.hpp"


#ifndef CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_TRAJECTORY__STRUCT_HPP_
#define CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_TRAJECTORY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'array'
#include "geometry_msgs/msg/detail/pose_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_msg_interfaces__srv__ComputeTrajectory_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_msg_interfaces__srv__ComputeTrajectory_Request __declspec(deprecated)
#endif

namespace custom_msg_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ComputeTrajectory_Request_
{
  using Type = ComputeTrajectory_Request_<ContainerAllocator>;

  explicit ComputeTrajectory_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : array(_init)
  {
    (void)_init;
  }

  explicit ComputeTrajectory_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : array(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _array_type =
    geometry_msgs::msg::PoseArray_<ContainerAllocator>;
  _array_type array;

  // setters for named parameter idiom
  Type & set__array(
    const geometry_msgs::msg::PoseArray_<ContainerAllocator> & _arg)
  {
    this->array = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msg_interfaces__srv__ComputeTrajectory_Request
    std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msg_interfaces__srv__ComputeTrajectory_Request
    std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeTrajectory_Request_ & other) const
  {
    if (this->array != other.array) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeTrajectory_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeTrajectory_Request_

// alias to use template instance with default allocator
using ComputeTrajectory_Request =
  custom_msg_interfaces::srv::ComputeTrajectory_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_msg_interfaces


// Include directives for member types
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_msg_interfaces__srv__ComputeTrajectory_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_msg_interfaces__srv__ComputeTrajectory_Response __declspec(deprecated)
#endif

namespace custom_msg_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ComputeTrajectory_Response_
{
  using Type = ComputeTrajectory_Response_<ContainerAllocator>;

  explicit ComputeTrajectory_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status_message = "";
    }
  }

  explicit ComputeTrajectory_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_alloc, _init),
    status_message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status_message = "";
    }
  }

  // field types and members
  using _trajectory_type =
    trajectory_msgs::msg::JointTrajectory_<ContainerAllocator>;
  _trajectory_type trajectory;
  using _status_message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_message_type status_message;

  // setters for named parameter idiom
  Type & set__trajectory(
    const trajectory_msgs::msg::JointTrajectory_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }
  Type & set__status_message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status_message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msg_interfaces__srv__ComputeTrajectory_Response
    std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msg_interfaces__srv__ComputeTrajectory_Response
    std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeTrajectory_Response_ & other) const
  {
    if (this->trajectory != other.trajectory) {
      return false;
    }
    if (this->status_message != other.status_message) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeTrajectory_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeTrajectory_Response_

// alias to use template instance with default allocator
using ComputeTrajectory_Response =
  custom_msg_interfaces::srv::ComputeTrajectory_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_msg_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_msg_interfaces__srv__ComputeTrajectory_Event __attribute__((deprecated))
#else
# define DEPRECATED__custom_msg_interfaces__srv__ComputeTrajectory_Event __declspec(deprecated)
#endif

namespace custom_msg_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ComputeTrajectory_Event_
{
  using Type = ComputeTrajectory_Event_<ContainerAllocator>;

  explicit ComputeTrajectory_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ComputeTrajectory_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msg_interfaces::srv::ComputeTrajectory_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msg_interfaces::srv::ComputeTrajectory_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msg_interfaces::srv::ComputeTrajectory_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msg_interfaces::srv::ComputeTrajectory_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msg_interfaces::srv::ComputeTrajectory_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msg_interfaces::srv::ComputeTrajectory_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msg_interfaces__srv__ComputeTrajectory_Event
    std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msg_interfaces__srv__ComputeTrajectory_Event
    std::shared_ptr<custom_msg_interfaces::srv::ComputeTrajectory_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeTrajectory_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeTrajectory_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeTrajectory_Event_

// alias to use template instance with default allocator
using ComputeTrajectory_Event =
  custom_msg_interfaces::srv::ComputeTrajectory_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_msg_interfaces

namespace custom_msg_interfaces
{

namespace srv
{

struct ComputeTrajectory
{
  using Request = custom_msg_interfaces::srv::ComputeTrajectory_Request;
  using Response = custom_msg_interfaces::srv::ComputeTrajectory_Response;
  using Event = custom_msg_interfaces::srv::ComputeTrajectory_Event;
};

}  // namespace srv

}  // namespace custom_msg_interfaces

#endif  // CUSTOM_MSG_INTERFACES__SRV__DETAIL__COMPUTE_TRAJECTORY__STRUCT_HPP_
