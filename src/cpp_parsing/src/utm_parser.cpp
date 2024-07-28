#include <string>

#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/utm"

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
    string _log_message_form()
    {
    }
}

class NmeaSubscriber: public rclcpp::Node
{
public:
    NmeaSubscriber(): Node("nmea_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "nmea_data", 10, std::bind(&NmeaSubscriber::topic_callback, this, _1));
        )
    }
private:
    UtmParser parser;
    
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NmeaSubscriber>());
    rclcpp::shutdown();
    return 0;
}