// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msg_interfaces:srv/ComputeIK.idl
// generated code does not contain a copyright notice
#include "custom_msg_interfaces/srv/detail/compute_ik__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `target_pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
custom_msg_interfaces__srv__ComputeIK_Request__init(custom_msg_interfaces__srv__ComputeIK_Request * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    custom_msg_interfaces__srv__ComputeIK_Request__fini(msg);
    return false;
  }
  // target_pose
  if (!geometry_msgs__msg__Pose__init(&msg->target_pose)) {
    custom_msg_interfaces__srv__ComputeIK_Request__fini(msg);
    return false;
  }
  return true;
}

void
custom_msg_interfaces__srv__ComputeIK_Request__fini(custom_msg_interfaces__srv__ComputeIK_Request * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // target_pose
  geometry_msgs__msg__Pose__fini(&msg->target_pose);
}

bool
custom_msg_interfaces__srv__ComputeIK_Request__are_equal(const custom_msg_interfaces__srv__ComputeIK_Request * lhs, const custom_msg_interfaces__srv__ComputeIK_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // target_pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->target_pose), &(rhs->target_pose)))
  {
    return false;
  }
  return true;
}

bool
custom_msg_interfaces__srv__ComputeIK_Request__copy(
  const custom_msg_interfaces__srv__ComputeIK_Request * input,
  custom_msg_interfaces__srv__ComputeIK_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // target_pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->target_pose), &(output->target_pose)))
  {
    return false;
  }
  return true;
}

custom_msg_interfaces__srv__ComputeIK_Request *
custom_msg_interfaces__srv__ComputeIK_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg_interfaces__srv__ComputeIK_Request * msg = (custom_msg_interfaces__srv__ComputeIK_Request *)allocator.allocate(sizeof(custom_msg_interfaces__srv__ComputeIK_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msg_interfaces__srv__ComputeIK_Request));
  bool success = custom_msg_interfaces__srv__ComputeIK_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msg_interfaces__srv__ComputeIK_Request__destroy(custom_msg_interfaces__srv__ComputeIK_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msg_interfaces__srv__ComputeIK_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msg_interfaces__srv__ComputeIK_Request__Sequence__init(custom_msg_interfaces__srv__ComputeIK_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg_interfaces__srv__ComputeIK_Request * data = NULL;

  if (size) {
    data = (custom_msg_interfaces__srv__ComputeIK_Request *)allocator.zero_allocate(size, sizeof(custom_msg_interfaces__srv__ComputeIK_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msg_interfaces__srv__ComputeIK_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msg_interfaces__srv__ComputeIK_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_msg_interfaces__srv__ComputeIK_Request__Sequence__fini(custom_msg_interfaces__srv__ComputeIK_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_msg_interfaces__srv__ComputeIK_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_msg_interfaces__srv__ComputeIK_Request__Sequence *
custom_msg_interfaces__srv__ComputeIK_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg_interfaces__srv__ComputeIK_Request__Sequence * array = (custom_msg_interfaces__srv__ComputeIK_Request__Sequence *)allocator.allocate(sizeof(custom_msg_interfaces__srv__ComputeIK_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msg_interfaces__srv__ComputeIK_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msg_interfaces__srv__ComputeIK_Request__Sequence__destroy(custom_msg_interfaces__srv__ComputeIK_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msg_interfaces__srv__ComputeIK_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msg_interfaces__srv__ComputeIK_Request__Sequence__are_equal(const custom_msg_interfaces__srv__ComputeIK_Request__Sequence * lhs, const custom_msg_interfaces__srv__ComputeIK_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msg_interfaces__srv__ComputeIK_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msg_interfaces__srv__ComputeIK_Request__Sequence__copy(
  const custom_msg_interfaces__srv__ComputeIK_Request__Sequence * input,
  custom_msg_interfaces__srv__ComputeIK_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msg_interfaces__srv__ComputeIK_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_msg_interfaces__srv__ComputeIK_Request * data =
      (custom_msg_interfaces__srv__ComputeIK_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msg_interfaces__srv__ComputeIK_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_msg_interfaces__srv__ComputeIK_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msg_interfaces__srv__ComputeIK_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `joint_angles_matrix`
#include "std_msgs/msg/detail/float64_multi_array__functions.h"
// Member `status_message`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_msg_interfaces__srv__ComputeIK_Response__init(custom_msg_interfaces__srv__ComputeIK_Response * msg)
{
  if (!msg) {
    return false;
  }
  // joint_angles_matrix
  if (!std_msgs__msg__Float64MultiArray__init(&msg->joint_angles_matrix)) {
    custom_msg_interfaces__srv__ComputeIK_Response__fini(msg);
    return false;
  }
  // status_message
  if (!rosidl_runtime_c__String__init(&msg->status_message)) {
    custom_msg_interfaces__srv__ComputeIK_Response__fini(msg);
    return false;
  }
  return true;
}

void
custom_msg_interfaces__srv__ComputeIK_Response__fini(custom_msg_interfaces__srv__ComputeIK_Response * msg)
{
  if (!msg) {
    return;
  }
  // joint_angles_matrix
  std_msgs__msg__Float64MultiArray__fini(&msg->joint_angles_matrix);
  // status_message
  rosidl_runtime_c__String__fini(&msg->status_message);
}

bool
custom_msg_interfaces__srv__ComputeIK_Response__are_equal(const custom_msg_interfaces__srv__ComputeIK_Response * lhs, const custom_msg_interfaces__srv__ComputeIK_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // joint_angles_matrix
  if (!std_msgs__msg__Float64MultiArray__are_equal(
      &(lhs->joint_angles_matrix), &(rhs->joint_angles_matrix)))
  {
    return false;
  }
  // status_message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status_message), &(rhs->status_message)))
  {
    return false;
  }
  return true;
}

bool
custom_msg_interfaces__srv__ComputeIK_Response__copy(
  const custom_msg_interfaces__srv__ComputeIK_Response * input,
  custom_msg_interfaces__srv__ComputeIK_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // joint_angles_matrix
  if (!std_msgs__msg__Float64MultiArray__copy(
      &(input->joint_angles_matrix), &(output->joint_angles_matrix)))
  {
    return false;
  }
  // status_message
  if (!rosidl_runtime_c__String__copy(
      &(input->status_message), &(output->status_message)))
  {
    return false;
  }
  return true;
}

custom_msg_interfaces__srv__ComputeIK_Response *
custom_msg_interfaces__srv__ComputeIK_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg_interfaces__srv__ComputeIK_Response * msg = (custom_msg_interfaces__srv__ComputeIK_Response *)allocator.allocate(sizeof(custom_msg_interfaces__srv__ComputeIK_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msg_interfaces__srv__ComputeIK_Response));
  bool success = custom_msg_interfaces__srv__ComputeIK_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msg_interfaces__srv__ComputeIK_Response__destroy(custom_msg_interfaces__srv__ComputeIK_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msg_interfaces__srv__ComputeIK_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msg_interfaces__srv__ComputeIK_Response__Sequence__init(custom_msg_interfaces__srv__ComputeIK_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg_interfaces__srv__ComputeIK_Response * data = NULL;

  if (size) {
    data = (custom_msg_interfaces__srv__ComputeIK_Response *)allocator.zero_allocate(size, sizeof(custom_msg_interfaces__srv__ComputeIK_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msg_interfaces__srv__ComputeIK_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msg_interfaces__srv__ComputeIK_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_msg_interfaces__srv__ComputeIK_Response__Sequence__fini(custom_msg_interfaces__srv__ComputeIK_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_msg_interfaces__srv__ComputeIK_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_msg_interfaces__srv__ComputeIK_Response__Sequence *
custom_msg_interfaces__srv__ComputeIK_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg_interfaces__srv__ComputeIK_Response__Sequence * array = (custom_msg_interfaces__srv__ComputeIK_Response__Sequence *)allocator.allocate(sizeof(custom_msg_interfaces__srv__ComputeIK_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msg_interfaces__srv__ComputeIK_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msg_interfaces__srv__ComputeIK_Response__Sequence__destroy(custom_msg_interfaces__srv__ComputeIK_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msg_interfaces__srv__ComputeIK_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msg_interfaces__srv__ComputeIK_Response__Sequence__are_equal(const custom_msg_interfaces__srv__ComputeIK_Response__Sequence * lhs, const custom_msg_interfaces__srv__ComputeIK_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msg_interfaces__srv__ComputeIK_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msg_interfaces__srv__ComputeIK_Response__Sequence__copy(
  const custom_msg_interfaces__srv__ComputeIK_Response__Sequence * input,
  custom_msg_interfaces__srv__ComputeIK_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msg_interfaces__srv__ComputeIK_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_msg_interfaces__srv__ComputeIK_Response * data =
      (custom_msg_interfaces__srv__ComputeIK_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msg_interfaces__srv__ComputeIK_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_msg_interfaces__srv__ComputeIK_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msg_interfaces__srv__ComputeIK_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "custom_msg_interfaces/srv/detail/compute_ik__functions.h"

bool
custom_msg_interfaces__srv__ComputeIK_Event__init(custom_msg_interfaces__srv__ComputeIK_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    custom_msg_interfaces__srv__ComputeIK_Event__fini(msg);
    return false;
  }
  // request
  if (!custom_msg_interfaces__srv__ComputeIK_Request__Sequence__init(&msg->request, 0)) {
    custom_msg_interfaces__srv__ComputeIK_Event__fini(msg);
    return false;
  }
  // response
  if (!custom_msg_interfaces__srv__ComputeIK_Response__Sequence__init(&msg->response, 0)) {
    custom_msg_interfaces__srv__ComputeIK_Event__fini(msg);
    return false;
  }
  return true;
}

void
custom_msg_interfaces__srv__ComputeIK_Event__fini(custom_msg_interfaces__srv__ComputeIK_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  custom_msg_interfaces__srv__ComputeIK_Request__Sequence__fini(&msg->request);
  // response
  custom_msg_interfaces__srv__ComputeIK_Response__Sequence__fini(&msg->response);
}

bool
custom_msg_interfaces__srv__ComputeIK_Event__are_equal(const custom_msg_interfaces__srv__ComputeIK_Event * lhs, const custom_msg_interfaces__srv__ComputeIK_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!custom_msg_interfaces__srv__ComputeIK_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!custom_msg_interfaces__srv__ComputeIK_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
custom_msg_interfaces__srv__ComputeIK_Event__copy(
  const custom_msg_interfaces__srv__ComputeIK_Event * input,
  custom_msg_interfaces__srv__ComputeIK_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!custom_msg_interfaces__srv__ComputeIK_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!custom_msg_interfaces__srv__ComputeIK_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

custom_msg_interfaces__srv__ComputeIK_Event *
custom_msg_interfaces__srv__ComputeIK_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg_interfaces__srv__ComputeIK_Event * msg = (custom_msg_interfaces__srv__ComputeIK_Event *)allocator.allocate(sizeof(custom_msg_interfaces__srv__ComputeIK_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msg_interfaces__srv__ComputeIK_Event));
  bool success = custom_msg_interfaces__srv__ComputeIK_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msg_interfaces__srv__ComputeIK_Event__destroy(custom_msg_interfaces__srv__ComputeIK_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msg_interfaces__srv__ComputeIK_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msg_interfaces__srv__ComputeIK_Event__Sequence__init(custom_msg_interfaces__srv__ComputeIK_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg_interfaces__srv__ComputeIK_Event * data = NULL;

  if (size) {
    data = (custom_msg_interfaces__srv__ComputeIK_Event *)allocator.zero_allocate(size, sizeof(custom_msg_interfaces__srv__ComputeIK_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msg_interfaces__srv__ComputeIK_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msg_interfaces__srv__ComputeIK_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_msg_interfaces__srv__ComputeIK_Event__Sequence__fini(custom_msg_interfaces__srv__ComputeIK_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_msg_interfaces__srv__ComputeIK_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_msg_interfaces__srv__ComputeIK_Event__Sequence *
custom_msg_interfaces__srv__ComputeIK_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msg_interfaces__srv__ComputeIK_Event__Sequence * array = (custom_msg_interfaces__srv__ComputeIK_Event__Sequence *)allocator.allocate(sizeof(custom_msg_interfaces__srv__ComputeIK_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msg_interfaces__srv__ComputeIK_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msg_interfaces__srv__ComputeIK_Event__Sequence__destroy(custom_msg_interfaces__srv__ComputeIK_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msg_interfaces__srv__ComputeIK_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msg_interfaces__srv__ComputeIK_Event__Sequence__are_equal(const custom_msg_interfaces__srv__ComputeIK_Event__Sequence * lhs, const custom_msg_interfaces__srv__ComputeIK_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msg_interfaces__srv__ComputeIK_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msg_interfaces__srv__ComputeIK_Event__Sequence__copy(
  const custom_msg_interfaces__srv__ComputeIK_Event__Sequence * input,
  custom_msg_interfaces__srv__ComputeIK_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msg_interfaces__srv__ComputeIK_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_msg_interfaces__srv__ComputeIK_Event * data =
      (custom_msg_interfaces__srv__ComputeIK_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msg_interfaces__srv__ComputeIK_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_msg_interfaces__srv__ComputeIK_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msg_interfaces__srv__ComputeIK_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
