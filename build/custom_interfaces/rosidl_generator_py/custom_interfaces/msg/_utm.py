# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_interfaces:msg/Utm.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Utm(type):
    """Metaclass of message 'Utm'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interfaces.msg.Utm')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__utm
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__utm
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__utm
            cls._TYPE_SUPPORT = module.type_support_msg__msg__utm
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__utm

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Utm(metaclass=Metaclass_Utm):
    """Message class 'Utm'."""

    __slots__ = [
        '_raw_data',
        '_message_id',
        '_utc',
        '_lat',
        '_lat_dir',
        '_lon',
        '_lon_dir',
        '_quality',
        '_num_satelite',
        '_hdop',
        '_alt',
        '_alt_unit',
        '_sep',
        '_sep_unit',
        '_diff_age',
        '_diff_station',
        '_check_sum',
        '_easting',
        '_northing',
    ]

    _fields_and_field_types = {
        'raw_data': 'string',
        'message_id': 'string',
        'utc': 'double',
        'lat': 'double',
        'lat_dir': 'string',
        'lon': 'double',
        'lon_dir': 'string',
        'quality': 'int16',
        'num_satelite': 'int16',
        'hdop': 'double',
        'alt': 'double',
        'alt_unit': 'string',
        'sep': 'double',
        'sep_unit': 'string',
        'diff_age': 'double',
        'diff_station': 'int16',
        'check_sum': 'string',
        'easting': 'int32',
        'northing': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.raw_data = kwargs.get('raw_data', str())
        self.message_id = kwargs.get('message_id', str())
        self.utc = kwargs.get('utc', float())
        self.lat = kwargs.get('lat', float())
        self.lat_dir = kwargs.get('lat_dir', str())
        self.lon = kwargs.get('lon', float())
        self.lon_dir = kwargs.get('lon_dir', str())
        self.quality = kwargs.get('quality', int())
        self.num_satelite = kwargs.get('num_satelite', int())
        self.hdop = kwargs.get('hdop', float())
        self.alt = kwargs.get('alt', float())
        self.alt_unit = kwargs.get('alt_unit', str())
        self.sep = kwargs.get('sep', float())
        self.sep_unit = kwargs.get('sep_unit', str())
        self.diff_age = kwargs.get('diff_age', float())
        self.diff_station = kwargs.get('diff_station', int())
        self.check_sum = kwargs.get('check_sum', str())
        self.easting = kwargs.get('easting', int())
        self.northing = kwargs.get('northing', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.raw_data != other.raw_data:
            return False
        if self.message_id != other.message_id:
            return False
        if self.utc != other.utc:
            return False
        if self.lat != other.lat:
            return False
        if self.lat_dir != other.lat_dir:
            return False
        if self.lon != other.lon:
            return False
        if self.lon_dir != other.lon_dir:
            return False
        if self.quality != other.quality:
            return False
        if self.num_satelite != other.num_satelite:
            return False
        if self.hdop != other.hdop:
            return False
        if self.alt != other.alt:
            return False
        if self.alt_unit != other.alt_unit:
            return False
        if self.sep != other.sep:
            return False
        if self.sep_unit != other.sep_unit:
            return False
        if self.diff_age != other.diff_age:
            return False
        if self.diff_station != other.diff_station:
            return False
        if self.check_sum != other.check_sum:
            return False
        if self.easting != other.easting:
            return False
        if self.northing != other.northing:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def raw_data(self):
        """Message field 'raw_data'."""
        return self._raw_data

    @raw_data.setter
    def raw_data(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'raw_data' field must be of type 'str'"
        self._raw_data = value

    @builtins.property
    def message_id(self):
        """Message field 'message_id'."""
        return self._message_id

    @message_id.setter
    def message_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message_id' field must be of type 'str'"
        self._message_id = value

    @builtins.property
    def utc(self):
        """Message field 'utc'."""
        return self._utc

    @utc.setter
    def utc(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'utc' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'utc' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._utc = value

    @builtins.property
    def lat(self):
        """Message field 'lat'."""
        return self._lat

    @lat.setter
    def lat(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lat' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'lat' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._lat = value

    @builtins.property
    def lat_dir(self):
        """Message field 'lat_dir'."""
        return self._lat_dir

    @lat_dir.setter
    def lat_dir(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'lat_dir' field must be of type 'str'"
        self._lat_dir = value

    @builtins.property
    def lon(self):
        """Message field 'lon'."""
        return self._lon

    @lon.setter
    def lon(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lon' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'lon' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._lon = value

    @builtins.property
    def lon_dir(self):
        """Message field 'lon_dir'."""
        return self._lon_dir

    @lon_dir.setter
    def lon_dir(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'lon_dir' field must be of type 'str'"
        self._lon_dir = value

    @builtins.property
    def quality(self):
        """Message field 'quality'."""
        return self._quality

    @quality.setter
    def quality(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'quality' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'quality' field must be an integer in [-32768, 32767]"
        self._quality = value

    @builtins.property
    def num_satelite(self):
        """Message field 'num_satelite'."""
        return self._num_satelite

    @num_satelite.setter
    def num_satelite(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_satelite' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'num_satelite' field must be an integer in [-32768, 32767]"
        self._num_satelite = value

    @builtins.property
    def hdop(self):
        """Message field 'hdop'."""
        return self._hdop

    @hdop.setter
    def hdop(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hdop' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'hdop' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._hdop = value

    @builtins.property
    def alt(self):
        """Message field 'alt'."""
        return self._alt

    @alt.setter
    def alt(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'alt' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'alt' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._alt = value

    @builtins.property
    def alt_unit(self):
        """Message field 'alt_unit'."""
        return self._alt_unit

    @alt_unit.setter
    def alt_unit(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'alt_unit' field must be of type 'str'"
        self._alt_unit = value

    @builtins.property
    def sep(self):
        """Message field 'sep'."""
        return self._sep

    @sep.setter
    def sep(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'sep' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'sep' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._sep = value

    @builtins.property
    def sep_unit(self):
        """Message field 'sep_unit'."""
        return self._sep_unit

    @sep_unit.setter
    def sep_unit(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'sep_unit' field must be of type 'str'"
        self._sep_unit = value

    @builtins.property
    def diff_age(self):
        """Message field 'diff_age'."""
        return self._diff_age

    @diff_age.setter
    def diff_age(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'diff_age' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'diff_age' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._diff_age = value

    @builtins.property
    def diff_station(self):
        """Message field 'diff_station'."""
        return self._diff_station

    @diff_station.setter
    def diff_station(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'diff_station' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'diff_station' field must be an integer in [-32768, 32767]"
        self._diff_station = value

    @builtins.property
    def check_sum(self):
        """Message field 'check_sum'."""
        return self._check_sum

    @check_sum.setter
    def check_sum(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'check_sum' field must be of type 'str'"
        self._check_sum = value

    @builtins.property
    def easting(self):
        """Message field 'easting'."""
        return self._easting

    @easting.setter
    def easting(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'easting' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'easting' field must be an integer in [-2147483648, 2147483647]"
        self._easting = value

    @builtins.property
    def northing(self):
        """Message field 'northing'."""
        return self._northing

    @northing.setter
    def northing(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'northing' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'northing' field must be an integer in [-2147483648, 2147483647]"
        self._northing = value
