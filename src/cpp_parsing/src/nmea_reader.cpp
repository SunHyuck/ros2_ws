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
    NmeaReader(): Node("nmea_reader"), 
    port_("/dev/ttyUSB0"), 
    brate_(115200), 
    context_(), 
    serial_(context_, port_) {
        serial_.set_option(serial_port_base::baud_rate(brate_));
        startReading();
        publisher_ = this->create_publisher<std_msgs::msg::String>("nmea_data", 10);
        io_thread_ = std::thread([this]() {context_.run(); });
    }

    ~NmeaReader() {
        context_.stop();
        if (io_thread_.joinable()) {
            io_thread_.join();
        }
    }
private:
    void startReading() {
        async_read_until(serial_, buffer_, "\n",
                        bind(&NmeaReader::handleRead, this, 
                        std::placeholders::_1, std::placeholders::_2));
    }

    void handleRead(const boost::system::error_code &error, size_t /*bytes_transferred*/) {
        if (!error) {
            std::istream is(&buffer_);
            string raw_data;
            getline(is, raw_data);
            publishData(raw_data);                                              
        }
        startReading();
    }

    void publishData(const string &raw_data)
    {
        std_msgs::msg::String msg;
        msg.data = raw_data;
        publisher_->publish(msg);
        RCLCPP_INFO_STREAM(this->get_logger(), "RAW DATA: " << raw_data); 
    }
    string port_;
    int brate_;
    io_context context_;
    serial_port serial_;
    boost::asio::streambuf buffer_;
    std::thread io_thread_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<NmeaReader>());
    rclcpp::shutdown();
    return 0;
}