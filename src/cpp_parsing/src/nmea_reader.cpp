#include <string>
#include <chrono>
#include <iostream>
#include <fstream>
#include <QtSerialPort/QSerialPort>
#include <QDebug>

#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std;

class NmeaReader: public rclcpp::Node
{
public:
    NmeaReader(): Node("nmea_reader")
    {
        serial.setPortName("/dev/ttyACM0");
        serial.setBaudRate(115200);
        serial.open(QIODevice::ReadWrite);
        
        if (!serial.isOpen())
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to open serial port");
            return;
        }

        publisher_ = this->create_publisher<std_msgs::msg::String>("nmea_data", 10);
        timer_ = this->create_wall_timer(500ms, bind(&NmeaReader::nmea_data_read, this));
    }
private:
    string port;
    int brate;
    float time;
    string raw_data;
    QSerialPort serial;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

    void nmea_data_read()
    {
        if (serial.canReadLine())
        {
            QByteArray data = serial.readLine();
            QString dataStr = QString::fromUtf8(data.constData()).trimmed();
            string raw_data = dataStr.toStdString();
            std_msgs::msg::String msg;
            msg.data = raw_data;
            publisher_->publish(msg);
            RCLCPP_INFO_STREAM(this->get_logger(), "RAW DATA: [" << raw_data << "]"); 
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