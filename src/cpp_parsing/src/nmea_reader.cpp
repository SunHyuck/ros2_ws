#include <string>
#include <chrono>
#include <iostream>
#include <fstream>
#include <boost/asio.hpp>

#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std;
using namespace boost::asio;

class NmeaReader: public rclcpp::Node
{
public:
    NmeaReader(): Node("nmea_reader"), port("/dev/ttyACM0"), brate(115200), context(), serial(context, port)
    {
        serial.set_option(serial_port_base::baud_rate(brate));
        start_reading();
        publisher_ = this->create_publisher<std_msgs::msg::String>("nmea_data", 10);
        // timer_ = this->create_wall_timer(500ms, bind(&NmeaReader::nmea_data_read, this));
        io_thread = std::thread([this]() {context.run(); });
    }
    ~NmeaReader() {
        context.stop();
        if (io_thread.joinable()) {
            io_thread.join();
        }
    }
private:
    string port;
    int brate;
    io_context context;
    serial_port serial;
    boost::asio::streambuf buffer;
    std::thread io_thread;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

    void start_reading()
    {
        async_read_until(serial, buffer, "\n", bind(&NmeaReader::handle_read, this, std::placeholders::_1, std::placeholders::_2));
    }

    void handle_read(const boost::system::error_code &error, size_t /*bytes_transferred*/)
    {
        if (!error)
        {
            std::istream is(&buffer);
            string raw_data;
            getline(is, raw_data);
            publish_data(raw_data);
        }
        start_reading();
    }

    void publish_data(const string &raw_data)
    {
        std_msgs::msg::String msg;
        msg.data = raw_data;
        publisher_->publish(msg);
        RCLCPP_INFO_STREAM(this->get_logger(), "RAW DATA: " << raw_data << ""); 
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<NmeaReader>());
    rclcpp::shutdown();
    return 0;
}