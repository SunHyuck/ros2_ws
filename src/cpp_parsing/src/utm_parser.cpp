#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "custom_interfaces/msg/utm.hpp"

using namespace std;

vector<string> split(string line, char Delimiter);

vector<string> split(string line, char Delimiter) {
    istringstream iss(line);
    string buffer;

    vector<string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }

    return result;
}

class UtmParser: public rclcpp::Node
{
public:
    UtmParser(): Node("utm_parser")
    {
        publisher_ = this->create_publisher<custom_interfaces::msg::Utm>("parsing_data", 10);
    }
    void publish_utm_data(const custom_interfaces::msg::Utm &utm_data)
    {
        RCLCPP_INFO_STREAM(this->get_logger(), _log_message_form(utm_data));
        publisher_->publish(utm_data);
    }
private:
    rclcpp::Publisher<custom_interfaces::msg::Utm>::SharedPtr publisher_;

    string _log_message_form(const custom_interfaces::msg::Utm utm_data)
    {
        ostringstream msg;
        msg << "\n---------- GGA DATA ----------\n"
        << "GGA.raw_data : " << utm_data.raw_data << "\n"
        << "GGA.message_id : " << utm_data.message_id << "\n"
        << "GGA.utc : " << utm_data.utc << "\n"
        << "GGA.lat : " << fixed << setprecision(7) << utm_data.lat << "\n"
        << "GGA.lat_dir : " << utm_data.lat_dir << "\n"
        << "GGA.lon : " << fixed << setprecision(7) << utm_data.lon << "\n"
        << "GGA.lon_dir : " << utm_data.lon_dir << "\n"
        << "GGA.quality : " << utm_data.quality << "\n"
        << "GGA.num_satelite : " << utm_data.num_satelite << "\n"
        << "GGA.HDOP : " << fixed << setprecision(2) << utm_data.hdop << "\n"
        << "GGA.alt : " << fixed << setprecision(3) << utm_data.alt << "\n"
        << "GGA.alt_unit : " << utm_data.alt_unit << "\n"
        << "GGA.sep : " << fixed << setprecision(3) << utm_data.sep << "\n"
        << "GGA.sep_unit : " << utm_data.sep_unit << "\n"
        << "GGA.diff_age : " << fixed << setprecision(2) << utm_data.diff_age << "\n"
        << "GGA.diff_station : " << utm_data.diff_station << "\n"
        << "GGA.check_sum : " << utm_data.check_sum << "\n"
        << "UTM.Easting : " << utm_data.easting << "\n"
        << "UTM.Northing : " << utm_data.northing;

    return msg.str();
    }
};

class NmeaSubscriber: public rclcpp::Node
{
public:
    NmeaSubscriber(): Node("nmea_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "nmea_data", 10, std::bind(&NmeaSubscriber::nmea_data_transformer, this, std::placeholders::_1));
    }
private:
    UtmParser parser_;
    double latitude;
    double longitude;
    double easting;
    double northing;

    const double R = 6378137.0;
    const double f = 1 / 298.257223563;
    const double k0 = 0.9996;
    const double e = sqrt(2 * f - f * f);
    const double e_prime_sq = e * e / (1 - e * e);

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    custom_interfaces::msg::Utm utm_data;

    void nmea_data_transformer(const std_msgs::msg::String &msg)
    {
        vector<string> raw_data = split(msg.data, ',');
        if (raw_data[0].substr(3).compare("GGA") == 0 && raw_data.size() == 15)
        {
            calculate_latitude_longitude(latitude, longitude, stod(raw_data[2]), raw_data[3], stod(raw_data[4]), raw_data[5]);
            lat_lon_to_UTM(easting, northing, latitude, longitude);
            utm_data_maker(utm_data, raw_data, latitude, longitude, easting, northing);

            parser_.publish_utm_data(utm_data);
        }
    }

    void calculate_latitude_longitude(double & latitude, double & longitude, const double lat, const string lat_dir, const double lon, const string lon_dir)
    {
        int lat_deg, lon_deg;
        double lat_mint, lon_mint;

        lat_deg = static_cast<int>(lat / 100);
        lat_mint = lat - (lat_deg * 100);
        latitude = lat_deg + (lat_mint / 60.0);
        if (lat_dir.compare("S") == 0) latitude = -latitude;

        lon_deg = static_cast<int>(lon / 100);
        lon_mint = lon - (lon_deg * 100);
        longitude = lon_deg + (lon_mint / 60.0);
        if (lon_dir.compare("W") == 0) longitude = -longitude;
    }

    void lat_lon_to_UTM(double & easting, double & northing, const double latitude, const double longitude) {
        double phi = latitude * M_PI / 180.0;
        double lambda = longitude * M_PI / 180.0;
    
        int zone = static_cast<int>((longitude + 180) / 6) + 1;
        double lambda_0 = (zone * 6 - 183) * M_PI / 180.0;

        double N = R / sqrt(1 - e * e * sin(phi) * sin(phi));
        double T = tan(phi) * tan(phi);
        double C = e_prime_sq * cos(phi) * cos(phi);
        double A = (lambda - lambda_0) * cos(phi);

        double M = R * ((1 - e * e / 4 - 3 * e * e * e * e / 64 - 5 * e * e * e * e * e * e / 256) * phi
                        - (3 * e * e / 8 + 3 * e * e * e * e / 32 + 45 * e * e * e * e * e * e / 1024) * sin(2 * phi)
                        + (15 * e * e * e * e / 256 + 45 * e * e * e * e * e * e / 1024) * sin(4 * phi)
                        - (35 * e * e * e * e * e * e / 3072) * sin(6 * phi));

        easting = k0 * N * (A + (1 - T + C) * A * A * A / 6 + (5 - 18 * T + T * T + 72 * C - 58 * e_prime_sq) * A * A * A * A * A / 120) + 500000;
        northing = k0 * (M + N * tan(phi) * (A * A / 2 + (5 - T + 9 * C + 4 * C * C) * A * A * A * A / 24 + (61 - 58 * T + T * T + 600 * C - 330 * e_prime_sq) * A * A * A * A * A * A / 720));
    
        if (latitude < 0) {
            northing += 10000000;
        }
    }

    void utm_data_maker(custom_interfaces::msg::Utm & utm_data, const vector<string> raw_data, const double latitude, const double longitude, const double easting, const double northing)
    {
        string tmp;
        for (size_t i = 0; i < raw_data.size(); ++i) {
            tmp += raw_data[i];
            if (i != raw_data.size() - 1) {
                tmp += ",";
            }
        }
        utm_data.raw_data = tmp;
        utm_data.message_id = raw_data[0].substr(1);
        utm_data.utc = stod(raw_data[1]);
        utm_data.lat = latitude;
        utm_data.lat_dir = raw_data[3];
        utm_data.lon = longitude;
        utm_data.lon_dir = raw_data[5];
        utm_data.quality = stoi(raw_data[6]);
        utm_data.num_satelite = stoi(raw_data[7]);
        utm_data.hdop = stod(raw_data[8]);
        utm_data.alt = stod(raw_data[9]);
        utm_data.alt_unit = raw_data[10];
        utm_data.sep = stod(raw_data[11]);
        utm_data.sep_unit = raw_data[12];
        utm_data.diff_age = stod(raw_data[13]);
        if (raw_data.size() <= 18) {
            utm_data.diff_station = 0;
        }
        else {
            utm_data.diff_station = stoi(raw_data[14]);
        }
        utm_data.check_sum = raw_data[14].substr(raw_data[14].size()-3);
        utm_data.easting = easting;
        utm_data.northing = northing;
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NmeaSubscriber>());
    rclcpp::shutdown();
    return 0;
}