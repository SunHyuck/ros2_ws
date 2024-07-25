// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:msg/Utm.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/utm__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `raw_data`
// Member `message_id`
// Member `lat_dir`
// Member `lon_dir`
// Member `alt_unit`
// Member `sep_unit`
// Member `check_sum`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_interfaces__msg__Utm__init(custom_interfaces__msg__Utm * msg)
{
  if (!msg) {
    return false;
  }
  // raw_data
  if (!rosidl_runtime_c__String__init(&msg->raw_data)) {
    custom_interfaces__msg__Utm__fini(msg);
    return false;
  }
  // message_id
  if (!rosidl_runtime_c__String__init(&msg->message_id)) {
    custom_interfaces__msg__Utm__fini(msg);
    return false;
  }
  // utc
  // lat
  // lat_dir
  if (!rosidl_runtime_c__String__init(&msg->lat_dir)) {
    custom_interfaces__msg__Utm__fini(msg);
    return false;
  }
  // lon
  // lon_dir
  if (!rosidl_runtime_c__String__init(&msg->lon_dir)) {
    custom_interfaces__msg__Utm__fini(msg);
    return false;
  }
  // quality
  // num_satelite
  // hdop
  // alt
  // alt_unit
  if (!rosidl_runtime_c__String__init(&msg->alt_unit)) {
    custom_interfaces__msg__Utm__fini(msg);
    return false;
  }
  // sep
  // sep_unit
  if (!rosidl_runtime_c__String__init(&msg->sep_unit)) {
    custom_interfaces__msg__Utm__fini(msg);
    return false;
  }
  // diff_age
  // diff_station
  // check_sum
  if (!rosidl_runtime_c__String__init(&msg->check_sum)) {
    custom_interfaces__msg__Utm__fini(msg);
    return false;
  }
  // easting
  // northing
  return true;
}

void
custom_interfaces__msg__Utm__fini(custom_interfaces__msg__Utm * msg)
{
  if (!msg) {
    return;
  }
  // raw_data
  rosidl_runtime_c__String__fini(&msg->raw_data);
  // message_id
  rosidl_runtime_c__String__fini(&msg->message_id);
  // utc
  // lat
  // lat_dir
  rosidl_runtime_c__String__fini(&msg->lat_dir);
  // lon
  // lon_dir
  rosidl_runtime_c__String__fini(&msg->lon_dir);
  // quality
  // num_satelite
  // hdop
  // alt
  // alt_unit
  rosidl_runtime_c__String__fini(&msg->alt_unit);
  // sep
  // sep_unit
  rosidl_runtime_c__String__fini(&msg->sep_unit);
  // diff_age
  // diff_station
  // check_sum
  rosidl_runtime_c__String__fini(&msg->check_sum);
  // easting
  // northing
}

bool
custom_interfaces__msg__Utm__are_equal(const custom_interfaces__msg__Utm * lhs, const custom_interfaces__msg__Utm * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // raw_data
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->raw_data), &(rhs->raw_data)))
  {
    return false;
  }
  // message_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message_id), &(rhs->message_id)))
  {
    return false;
  }
  // utc
  if (lhs->utc != rhs->utc) {
    return false;
  }
  // lat
  if (lhs->lat != rhs->lat) {
    return false;
  }
  // lat_dir
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->lat_dir), &(rhs->lat_dir)))
  {
    return false;
  }
  // lon
  if (lhs->lon != rhs->lon) {
    return false;
  }
  // lon_dir
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->lon_dir), &(rhs->lon_dir)))
  {
    return false;
  }
  // quality
  if (lhs->quality != rhs->quality) {
    return false;
  }
  // num_satelite
  if (lhs->num_satelite != rhs->num_satelite) {
    return false;
  }
  // hdop
  if (lhs->hdop != rhs->hdop) {
    return false;
  }
  // alt
  if (lhs->alt != rhs->alt) {
    return false;
  }
  // alt_unit
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->alt_unit), &(rhs->alt_unit)))
  {
    return false;
  }
  // sep
  if (lhs->sep != rhs->sep) {
    return false;
  }
  // sep_unit
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->sep_unit), &(rhs->sep_unit)))
  {
    return false;
  }
  // diff_age
  if (lhs->diff_age != rhs->diff_age) {
    return false;
  }
  // diff_station
  if (lhs->diff_station != rhs->diff_station) {
    return false;
  }
  // check_sum
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->check_sum), &(rhs->check_sum)))
  {
    return false;
  }
  // easting
  if (lhs->easting != rhs->easting) {
    return false;
  }
  // northing
  if (lhs->northing != rhs->northing) {
    return false;
  }
  return true;
}

bool
custom_interfaces__msg__Utm__copy(
  const custom_interfaces__msg__Utm * input,
  custom_interfaces__msg__Utm * output)
{
  if (!input || !output) {
    return false;
  }
  // raw_data
  if (!rosidl_runtime_c__String__copy(
      &(input->raw_data), &(output->raw_data)))
  {
    return false;
  }
  // message_id
  if (!rosidl_runtime_c__String__copy(
      &(input->message_id), &(output->message_id)))
  {
    return false;
  }
  // utc
  output->utc = input->utc;
  // lat
  output->lat = input->lat;
  // lat_dir
  if (!rosidl_runtime_c__String__copy(
      &(input->lat_dir), &(output->lat_dir)))
  {
    return false;
  }
  // lon
  output->lon = input->lon;
  // lon_dir
  if (!rosidl_runtime_c__String__copy(
      &(input->lon_dir), &(output->lon_dir)))
  {
    return false;
  }
  // quality
  output->quality = input->quality;
  // num_satelite
  output->num_satelite = input->num_satelite;
  // hdop
  output->hdop = input->hdop;
  // alt
  output->alt = input->alt;
  // alt_unit
  if (!rosidl_runtime_c__String__copy(
      &(input->alt_unit), &(output->alt_unit)))
  {
    return false;
  }
  // sep
  output->sep = input->sep;
  // sep_unit
  if (!rosidl_runtime_c__String__copy(
      &(input->sep_unit), &(output->sep_unit)))
  {
    return false;
  }
  // diff_age
  output->diff_age = input->diff_age;
  // diff_station
  output->diff_station = input->diff_station;
  // check_sum
  if (!rosidl_runtime_c__String__copy(
      &(input->check_sum), &(output->check_sum)))
  {
    return false;
  }
  // easting
  output->easting = input->easting;
  // northing
  output->northing = input->northing;
  return true;
}

custom_interfaces__msg__Utm *
custom_interfaces__msg__Utm__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__Utm * msg = (custom_interfaces__msg__Utm *)allocator.allocate(sizeof(custom_interfaces__msg__Utm), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__msg__Utm));
  bool success = custom_interfaces__msg__Utm__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__msg__Utm__destroy(custom_interfaces__msg__Utm * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__msg__Utm__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__msg__Utm__Sequence__init(custom_interfaces__msg__Utm__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__Utm * data = NULL;

  if (size) {
    data = (custom_interfaces__msg__Utm *)allocator.zero_allocate(size, sizeof(custom_interfaces__msg__Utm), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__msg__Utm__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__msg__Utm__fini(&data[i - 1]);
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
custom_interfaces__msg__Utm__Sequence__fini(custom_interfaces__msg__Utm__Sequence * array)
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
      custom_interfaces__msg__Utm__fini(&array->data[i]);
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

custom_interfaces__msg__Utm__Sequence *
custom_interfaces__msg__Utm__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__Utm__Sequence * array = (custom_interfaces__msg__Utm__Sequence *)allocator.allocate(sizeof(custom_interfaces__msg__Utm__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__msg__Utm__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__msg__Utm__Sequence__destroy(custom_interfaces__msg__Utm__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__msg__Utm__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__msg__Utm__Sequence__are_equal(const custom_interfaces__msg__Utm__Sequence * lhs, const custom_interfaces__msg__Utm__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__msg__Utm__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__msg__Utm__Sequence__copy(
  const custom_interfaces__msg__Utm__Sequence * input,
  custom_interfaces__msg__Utm__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__msg__Utm);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__msg__Utm * data =
      (custom_interfaces__msg__Utm *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__msg__Utm__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__msg__Utm__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__msg__Utm__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
