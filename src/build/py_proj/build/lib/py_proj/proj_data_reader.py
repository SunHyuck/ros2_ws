import serial
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

from pyproj import pyproj, Transformer

class RawDataPub(Node):

    def __init__(self):
        super().__init__('raw_data_publisher')
        self.data_publisher = self.create_publisher(String, 'nmea_data', 10)

        self.port = "/dev/ttyACM0"
        self.brate = 115200
        self.seri = serial.Serial(self.port, baudrate=self.brate, timeout=None)
        self.time = 0.1
        self.timer = self.create_timer(self.time, self.timer_callback)
        
    def timer_callback(self):
        if self.seri.in_waiting != 0:
            raw_data = self.seri.readline()
            raw_data = raw_data.decode('utf-8', 'ignore').strip()
            if len(raw_data.split(",")) <= 15:
                self.nmea_data_callback(raw_data)

    def nmea_data_callback(self, raw_dataset):
        msg = String()
        msg.data = raw_dataset
        self.data_publisher.publish(msg)
        self.get_logger().info(f'Publishing: {msg.data}')

def main(args=None):

    rclpy.init(args=args)

    raw_data_publisher = RawDataPub()

    rclpy.spin(raw_data_publisher)

    raw_data_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()