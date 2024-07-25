// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/Utm.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__UTM__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__UTM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/utm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_Utm_northing
{
public:
  explicit Init_Utm_northing(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::Utm northing(::custom_interfaces::msg::Utm::_northing_type arg)
  {
    msg_.northing = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_easting
{
public:
  explicit Init_Utm_easting(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_northing easting(::custom_interfaces::msg::Utm::_easting_type arg)
  {
    msg_.easting = std::move(arg);
    return Init_Utm_northing(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_check_sum
{
public:
  explicit Init_Utm_check_sum(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_easting check_sum(::custom_interfaces::msg::Utm::_check_sum_type arg)
  {
    msg_.check_sum = std::move(arg);
    return Init_Utm_easting(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_diff_station
{
public:
  explicit Init_Utm_diff_station(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_check_sum diff_station(::custom_interfaces::msg::Utm::_diff_station_type arg)
  {
    msg_.diff_station = std::move(arg);
    return Init_Utm_check_sum(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_diff_age
{
public:
  explicit Init_Utm_diff_age(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_diff_station diff_age(::custom_interfaces::msg::Utm::_diff_age_type arg)
  {
    msg_.diff_age = std::move(arg);
    return Init_Utm_diff_station(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_sep_unit
{
public:
  explicit Init_Utm_sep_unit(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_diff_age sep_unit(::custom_interfaces::msg::Utm::_sep_unit_type arg)
  {
    msg_.sep_unit = std::move(arg);
    return Init_Utm_diff_age(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_sep
{
public:
  explicit Init_Utm_sep(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_sep_unit sep(::custom_interfaces::msg::Utm::_sep_type arg)
  {
    msg_.sep = std::move(arg);
    return Init_Utm_sep_unit(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_alt_unit
{
public:
  explicit Init_Utm_alt_unit(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_sep alt_unit(::custom_interfaces::msg::Utm::_alt_unit_type arg)
  {
    msg_.alt_unit = std::move(arg);
    return Init_Utm_sep(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_alt
{
public:
  explicit Init_Utm_alt(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_alt_unit alt(::custom_interfaces::msg::Utm::_alt_type arg)
  {
    msg_.alt = std::move(arg);
    return Init_Utm_alt_unit(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_hdop
{
public:
  explicit Init_Utm_hdop(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_alt hdop(::custom_interfaces::msg::Utm::_hdop_type arg)
  {
    msg_.hdop = std::move(arg);
    return Init_Utm_alt(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_num_satelite
{
public:
  explicit Init_Utm_num_satelite(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_hdop num_satelite(::custom_interfaces::msg::Utm::_num_satelite_type arg)
  {
    msg_.num_satelite = std::move(arg);
    return Init_Utm_hdop(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_quality
{
public:
  explicit Init_Utm_quality(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_num_satelite quality(::custom_interfaces::msg::Utm::_quality_type arg)
  {
    msg_.quality = std::move(arg);
    return Init_Utm_num_satelite(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_lon_dir
{
public:
  explicit Init_Utm_lon_dir(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_quality lon_dir(::custom_interfaces::msg::Utm::_lon_dir_type arg)
  {
    msg_.lon_dir = std::move(arg);
    return Init_Utm_quality(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_lon
{
public:
  explicit Init_Utm_lon(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_lon_dir lon(::custom_interfaces::msg::Utm::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_Utm_lon_dir(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_lat_dir
{
public:
  explicit Init_Utm_lat_dir(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_lon lat_dir(::custom_interfaces::msg::Utm::_lat_dir_type arg)
  {
    msg_.lat_dir = std::move(arg);
    return Init_Utm_lon(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_lat
{
public:
  explicit Init_Utm_lat(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_lat_dir lat(::custom_interfaces::msg::Utm::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_Utm_lat_dir(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_utc
{
public:
  explicit Init_Utm_utc(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_lat utc(::custom_interfaces::msg::Utm::_utc_type arg)
  {
    msg_.utc = std::move(arg);
    return Init_Utm_lat(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_message_id
{
public:
  explicit Init_Utm_message_id(::custom_interfaces::msg::Utm & msg)
  : msg_(msg)
  {}
  Init_Utm_utc message_id(::custom_interfaces::msg::Utm::_message_id_type arg)
  {
    msg_.message_id = std::move(arg);
    return Init_Utm_utc(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

class Init_Utm_raw_data
{
public:
  Init_Utm_raw_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Utm_message_id raw_data(::custom_interfaces::msg::Utm::_raw_data_type arg)
  {
    msg_.raw_data = std::move(arg);
    return Init_Utm_message_id(msg_);
  }

private:
  ::custom_interfaces::msg::Utm msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::Utm>()
{
  return custom_interfaces::msg::builder::Init_Utm_raw_data();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__UTM__BUILDER_HPP_
