import rclpy
from rclpy.node import Node
from std_msgs.msg import String

from pyproj import pyproj, Transformer

class ParsingPublisher(Node):
    def __init__(self):
        super().__init__('parsing_publisher')
        self.publisher_ = self.create_publisher(String, 'parsing_data', 10)
        timer_period = 0.5
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
    
    def timer_callback(self):
        msg = String()
        msg.data = f"Hello World: {self.i}"
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: {msg.data}')
        self.i += 1

class DataSubscriber(Node):
    def __init__(self):
        super().__init__('data_subscriber')
        self.subscription = self.create_subscription(
            String,
            'nmea_data',
            self.data_listener_callback,
            10
        )
        self.subscription
    
    def data_listener_callback(sefl, msg):
        self.get_logger().info(f"Subscribe: {msg.data}")

class RawDataExtractor():
    def __init__(self, raw_data):
        self.raw_data = raw_data
        self.message_id = raw_data[0]
        self.utc = raw_data[1]
        self.lat = float(raw_data[2])
        self.lat_dir = raw_data[3]
        self.lon = float(raw_data[4])
        self.lon_dir = raw_data[5]
        self.quality = raw_data[6]
        self.num_satelite = raw_data[7]
        self.HDOP = raw_data[8]
        self.alt = raw_data[9]
        self.alt_unit = raw_data[10]
        self.sep = raw_data[11]
        self.sep_unit = raw_data[12]
        self.diff_age = raw_data[13]
        if len(raw_data) <= 15:
            self.diff_station = 0
        else:
            self.diff_station = raw_data[14]
        self.check_sum = raw_data[-1][-2:]
        self.easting = None
        self.northing = None
    
    def cal_lat_lon(self):
        lat_deg = int(self.lat // 100)
        lat_mint = self.lat - (lat_deg * 100)
        self.lat = lat_deg + (lat_mint / 60.0)
        if (self.lat_dir == "S"): self.lat = -self.lat

        lon_deg = int(self.lon // 100)
        lon_mint = self.lon - (lon_deg * 100)
        self.lon = lon_deg + (lon_mint / 60.0)
        if (self.lon_dir == "W"): self.lon = -self.lon

    def print_data(self):
        print("---------- GGA DATA ----------")
        print(f"GGA.raw_data : {','.join(self.raw_data)}\n"
        f"GGA.message_id : {self.message_id}\n"
        f"GGA.utc : {self.utc}\n"
        f"GGA.lat : {self.lat:.7f}\n"
        f"GGA.lat_dir : {self.lat_dir}\n"
        f"GGA.lon : {self.lon:.7f}\n"
        f"GGA.lon_dir : {self.lon_dir}\n"
        f"GGA.quality : {self.quality}\n"
        f"GGA.num_satelite : {self.num_satelite}\n"
        f"GGA.HDOP : {self.HDOP}\n"
        f"GGA.alt : {self.alt}\n"
        f"GGA.alt_unit : {self.alt_unit}\n"
        f"GGA.sep : {self.sep}\n"
        f"GGA.sep_unit : {self.sep_unit}\n"
        f"GGA.diff_age : {self.diff_age}\n"
        f"GGA.diff_station : {self.diff_station}\n"
        f"GGA.check_sum : {self.check_sum}\n")
    
def convert_coordinates(lon, lat):
    new_lat, new_lon = transformer.transform(lat, lon)
    return new_lon, new_lat

def main(args=None):
    rclpy.init(args=args)

    data_subscriber = DataSubscriber()
    parsing_publisher = ParsingPublisher()

    transformer = Transformer.from_crs("EPSG:4326", "EPSG:32652")

    filename = "/home/sunny/ros2_ws/src/py_proj/py_proj/TalkFile_nmea.txt"
    f = open(filename, 'r')
    lines = f.readlines()

    for line in lines:
        line = line.strip()
        print(line)
        raw_data = line.split(",")

        if raw_data[0][3:] == "GGA":
            data = RawDataExtractor(raw_data)
            data.cal_lat_lon()
            data.easting, data.northing = transformer.transform(data.lat, data.lon)
            data.print_data()

    rclpy.spin(data_subscriber)
    rclpy.spin(parsing_publisher)

    data_subscriber.destroy_node()
    parsing_pub.destroy_node()
    
    rclpy.shutdown()

if __name__ == "__main__":
    main()