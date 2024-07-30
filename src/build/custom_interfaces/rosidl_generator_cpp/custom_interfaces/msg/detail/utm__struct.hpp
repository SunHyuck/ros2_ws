// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/Utm.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__UTM__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__UTM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__Utm __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__Utm __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Utm_
{
  using Type = Utm_<ContainerAllocator>;

  explicit Utm_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->raw_data = "";
      this->message_id = "";
      this->utc = 0.0;
      this->lat = 0.0;
      this->lat_dir = "";
      this->lon = 0.0;
      this->lon_dir = "";
      this->quality = 0;
      this->num_satelite = 0;
      this->hdop = 0.0;
      this->alt = 0.0;
      this->alt_unit = "";
      this->sep = 0.0;
      this->sep_unit = "";
      this->diff_age = 0.0;
      this->diff_station = 0;
      this->check_sum = "";
      this->easting = 0l;
      this->northing = 0l;
    }
  }

  explicit Utm_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : raw_data(_alloc),
    message_id(_alloc),
    lat_dir(_alloc),
    lon_dir(_alloc),
    alt_unit(_alloc),
    sep_unit(_alloc),
    check_sum(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->raw_data = "";
      this->message_id = "";
      this->utc = 0.0;
      this->lat = 0.0;
      this->lat_dir = "";
      this->lon = 0.0;
      this->lon_dir = "";
      this->quality = 0;
      this->num_satelite = 0;
      this->hdop = 0.0;
      this->alt = 0.0;
      this->alt_unit = "";
      this->sep = 0.0;
      this->sep_unit = "";
      this->diff_age = 0.0;
      this->diff_station = 0;
      this->check_sum = "";
      this->easting = 0l;
      this->northing = 0l;
    }
  }

  // field types and members
  using _raw_data_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _raw_data_type raw_data;
  using _message_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_id_type message_id;
  using _utc_type =
    double;
  _utc_type utc;
  using _lat_type =
    double;
  _lat_type lat;
  using _lat_dir_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _lat_dir_type lat_dir;
  using _lon_type =
    double;
  _lon_type lon;
  using _lon_dir_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _lon_dir_type lon_dir;
  using _quality_type =
    int16_t;
  _quality_type quality;
  using _num_satelite_type =
    int16_t;
  _num_satelite_type num_satelite;
  using _hdop_type =
    double;
  _hdop_type hdop;
  using _alt_type =
    double;
  _alt_type alt;
  using _alt_unit_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _alt_unit_type alt_unit;
  using _sep_type =
    double;
  _sep_type sep;
  using _sep_unit_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _sep_unit_type sep_unit;
  using _diff_age_type =
    double;
  _diff_age_type diff_age;
  using _diff_station_type =
    int16_t;
  _diff_station_type diff_station;
  using _check_sum_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _check_sum_type check_sum;
  using _easting_type =
    int32_t;
  _easting_type easting;
  using _northing_type =
    int32_t;
  _northing_type northing;

  // setters for named parameter idiom
  Type & set__raw_data(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->raw_data = _arg;
    return *this;
  }
  Type & set__message_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message_id = _arg;
    return *this;
  }
  Type & set__utc(
    const double & _arg)
  {
    this->utc = _arg;
    return *this;
  }
  Type & set__lat(
    const double & _arg)
  {
    this->lat = _arg;
    return *this;
  }
  Type & set__lat_dir(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->lat_dir = _arg;
    return *this;
  }
  Type & set__lon(
    const double & _arg)
  {
    this->lon = _arg;
    return *this;
  }
  Type & set__lon_dir(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->lon_dir = _arg;
    return *this;
  }
  Type & set__quality(
    const int16_t & _arg)
  {
    this->quality = _arg;
    return *this;
  }
  Type & set__num_satelite(
    const int16_t & _arg)
  {
    this->num_satelite = _arg;
    return *this;
  }
  Type & set__hdop(
    const double & _arg)
  {
    this->hdop = _arg;
    return *this;
  }
  Type & set__alt(
    const double & _arg)
  {
    this->alt = _arg;
    return *this;
  }
  Type & set__alt_unit(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->alt_unit = _arg;
    return *this;
  }
  Type & set__sep(
    const double & _arg)
  {
    this->sep = _arg;
    return *this;
  }
  Type & set__sep_unit(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->sep_unit = _arg;
    return *this;
  }
  Type & set__diff_age(
    const double & _arg)
  {
    this->diff_age = _arg;
    return *this;
  }
  Type & set__diff_station(
    const int16_t & _arg)
  {
    this->diff_station = _arg;
    return *this;
  }
  Type & set__check_sum(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->check_sum = _arg;
    return *this;
  }
  Type & set__easting(
    const int32_t & _arg)
  {
    this->easting = _arg;
    return *this;
  }
  Type & set__northing(
    const int32_t & _arg)
  {
    this->northing = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::Utm_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::Utm_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::Utm_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::Utm_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::Utm_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::Utm_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::Utm_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::Utm_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::Utm_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::Utm_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__Utm
    std::shared_ptr<custom_interfaces::msg::Utm_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__Utm
    std::shared_ptr<custom_interfaces::msg::Utm_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Utm_ & other) const
  {
    if (this->raw_data != other.raw_data) {
      return false;
    }
    if (this->message_id != other.message_id) {
      return false;
    }
    if (this->utc != other.utc) {
      return false;
    }
    if (this->lat != other.lat) {
      return false;
    }
    if (this->lat_dir != other.lat_dir) {
      return false;
    }
    if (this->lon != other.lon) {
      return false;
    }
    if (this->lon_dir != other.lon_dir) {
      return false;
    }
    if (this->quality != other.quality) {
      return false;
    }
    if (this->num_satelite != other.num_satelite) {
      return false;
    }
    if (this->hdop != other.hdop) {
      return false;
    }
    if (this->alt != other.alt) {
      return false;
    }
    if (this->alt_unit != other.alt_unit) {
      return false;
    }
    if (this->sep != other.sep) {
      return false;
    }
    if (this->sep_unit != other.sep_unit) {
      return false;
    }
    if (this->diff_age != other.diff_age) {
      return false;
    }
    if (this->diff_station != other.diff_station) {
      return false;
    }
    if (this->check_sum != other.check_sum) {
      return false;
    }
    if (this->easting != other.easting) {
      return false;
    }
    if (this->northing != other.northing) {
      return false;
    }
    return true;
  }
  bool operator!=(const Utm_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Utm_

// alias to use template instance with default allocator
using Utm =
  custom_interfaces::msg::Utm_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__UTM__STRUCT_HPP_
