import rclpy
from rclpy.node import Node
from std_msgs.msg import String

from pyproj import pyproj, Transformer

class RawDataPub(Node):
    def __init__(self, raw_dataset):
        super().__init__('raw_data_pub')
        self.raw_dataset = raw_dataset
        self.publisher_ = self.create_publisher(String, 'nmea_data', 10)
        timer_period = 0.5
        self.data_publisher = self.create_timer(timer_period, self.nmea_data_callback)
        self.i = 0
        
    def nmea_data_callback(self):
        if self.i < len(self.raw_dataset):
            msg = String()
            msg.data = self.raw_dataset[self.i]
            self.publisher_.publish(msg)
            self.get_logger().info(f'Publishing: {msg.data}')
            self.i += 1

def main(args=None):
    rclpy.init(args=args)

    filename = "/home/sunny/ros2_ws/src/py_proj/py_proj/TalkFile_nmea.txt"
    f = open(filename, 'r')
    lines = f.readlines()

    raw_data_pub = RawDataPub(lines)

    rclpy.spin(raw_data_pub)

    raw_data_pub.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()