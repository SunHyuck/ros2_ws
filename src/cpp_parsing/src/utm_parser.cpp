#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "custom_interfaces/msg/utm.hpp"

using namespace std;

class UtmParser: public rclcpp::Node
{
public:
    UtmParser(): Node("utm_parser")
    {
        publisher_ = this->create_publisher<custom_interfaces::msg::Utm>("parsing_data", 10);
    }
private:
    rclcpp::Publisher<custom_interfaces::msg::Utm>::SharedPtr publisher_;
};

class NmeaSubscriber: public rclcpp::Node
{
public:
    NmeaSubscriber(): Node("nmea_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "nmea_data", 10, std::bind(&NmeaSubscriber::nmea_data_transformer, this));
    }
private:
    UtmParser parser;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

    void nmea_data_transformer()
    {

    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NmeaSubscriber>());
    rclcpp::shutdown();
    return 0;
}