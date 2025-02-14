import rclpy

from custom_interfaces.msg import Utm
from pyproj import pyproj, Transformer
from rclpy.node import Node
from std_msgs.msg import String

class ParsingPublisher(Node):

    def __init__(self):
        super().__init__('parsing_publisher')
        self.publisher_ = self.create_publisher(Utm, 'parsing_data', 10)

    def publish_data(self, data):
        msg = Utm()
        msg.raw_data = data[0]
        msg.message_id = data[1][1:]
        msg.utc = self._convert_to_float(data[2])
        msg.lat = self._convert_to_float(data[3])
        msg.lat_dir = data[4]
        msg.lon = self._convert_to_float(data[5])
        msg.lon_dir = data[6]
        msg.quality = self._convert_to_int(data[7])
        msg.num_satelite = self._convert_to_int(data[8])
        msg.hdop = self._convert_to_float(data[9])
        msg.alt = self._convert_to_float(data[10])
        msg.alt_unit = data[11]
        msg.sep = self._convert_to_float(data[12])
        msg.sep_unit = data[13]
        msg.diff_age = self._convert_to_float(data[14])
        if len(data) <= 18:
            msg.diff_station = 0
        else:
            msg.diff_station = self._convert_to_int(data[15])
        msg.check_sum = data[15][-2:]
        msg.easting = self._convert_to_int(data[16])
        msg.northing = self._convert_to_int(data[17])

        self.publisher_.publish(msg)
        self.get_logger().info(self._log_message_form(msg))
    

    def _convert_to_float(self, value):
        return float(value) if value else 0.0

    def _convert_to_int(self, value):
        return int(value) if value else 0

    def _log_message_form(self, msg):
        return (f"\n---------- GGA DATA ----------\n"
        f"GGA.raw_data : {msg.raw_data}\n"
        f"GGA.message_id : {msg.message_id}\n"
        f"GGA.utc : {msg.utc}\n"
        f"GGA.lat : {msg.lat:.7f}\n"
        f"GGA.lat_dir : {msg.lat_dir}\n"
        f"GGA.lon : {msg.lon:.7f}\n"
        f"GGA.lon_dir : {msg.lon_dir}\n"
        f"GGA.quality : {msg.quality}\n"
        f"GGA.num_satelite : {msg.num_satelite}\n"
        f"GGA.HDOP : {msg.hdop}\n"
        f"GGA.alt : {msg.alt}\n"
        f"GGA.alt_unit : {msg.alt_unit}\n"
        f"GGA.sep : {msg.sep}\n"
        f"GGA.sep_unit : {msg.sep_unit}\n"
        f"GGA.diff_age : {msg.diff_age}\n"
        f"GGA.diff_station : {msg.diff_station}\n"
        f"GGA.check_sum : {msg.check_sum}\n"
        f"UTM.Easting : {msg.easting}\n"
        f"UTM.Norting : {msg.northing}\n")

class DataSubscriber(Node):

    def __init__(self):
        super().__init__('data_subscriber')
        self.subscription = self.create_subscription(
            String,
            'nmea_data',
            self.data_listener_callback,
            10
        )
        self.publisher = ParsingPublisher()
        self.transformer = Transformer.from_crs("EPSG:4326", "EPSG:32652")
    
    def data_listener_callback(self, msg):
        self.get_logger().info(f"Subscriber: {msg.data}")
        raw_data = [msg.data.strip()]
        raw_data += msg.data.split(",")
        if raw_data[1][3:] == "GGA" and len(raw_data) == 16:
            processed_data = [d.strip() for d in raw_data]

            processed_data[3], processed_data[5] = self._calculate_lat_lon(
                lat=float(raw_data[3]), lat_dir=raw_data[4], 
                lon=float(raw_data[5]), lon_dir=raw_data[6]
            )
            
            easting, northing = self.transformer.transform(processed_data[3], processed_data[5])
            processed_data.extend([easting, northing])

            self.publisher.publish_data(processed_data)
    
    def _calculate_lat_lon(self, lat, lat_dir, lon, lon_dir):
        lat_deg = int(lat // 100)
        lat_mint = lat - (lat_deg * 100)
        lat = lat_deg + (lat_mint / 60.0)
        if (lat_dir == "S"): lat = -lat

        lon_deg = int(lon // 100)
        lon_mint = lon - (lon_deg * 100)
        lon = lon_deg + (lon_mint / 60.0)
        if (lon_dir == "W"): lon = -lon

        return lat, lon

def main(args=None):
    rclpy.init(args=args)

    data_subscriber = DataSubscriber()

    rclpy.spin(data_subscriber)

    data_subscriber.destroy_node()

    parsing_pub.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()