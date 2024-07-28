#include <string>
#include <chrono>
#include <iostream>
#include <fstream>

#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std;


class NmeaReader: public rclcpp::Node
{
public:
    NmeaReader(): Node("nmea_reader")
    {
        port = "/dev/ttyACM0";
        brate = 115200;
        time = 0.1;

        publisher_ = this->create_publisher<std_msgs::msg::String>("nmea_data", 10);
        file.open("/home/sunny/ros2_ws/src/cpp_parsing/src/TalkFile_nmea.txt");
        if (!file.is_open())
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to open file");
        }
        timer_ = this->create_wall_timer(500ms, bind(&NmeaReader::nmea_data_callback, this));
    }
private:
    string port;
    int brate;
    float time;
    string raw_data;
    ifstream file;
    

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

    void nmea_data_callback()
    {
        if (file.is_open()) {
            while(getline(file, raw_data)) {
                RCLCPP_INFO_STREAM(this->get_logger(), "RAW DATA: [" << raw_data << "]");
                std_msgs::msg::String msg;
                msg.data = raw_data;
                publisher_->publish(msg);
            }
        }
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NmeaReader>());
    rclcpp::shutdown();
    return 0;
}