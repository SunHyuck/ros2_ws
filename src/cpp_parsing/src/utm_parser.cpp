#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "custom_interfaces/msg/utm.hpp"

using namespace std;

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
        file.open("utm.csv");
        file << "Latitude, Longitude\n";
        publisher_ = this->create_publisher<custom_interfaces::msg::Utm>("parsing_data", 10);
    }
    ~UtmParser() {
        file.close();
    }
    void publishUtmData(const custom_interfaces::msg::Utm &utm_data)
    {
        RCLCPP_INFO_STREAM(this->get_logger(), logMessageForm(utm_data));
        file << fixed << setprecision(7) << utm_data.lat << "," << fixed << setprecision(7) << utm_data.lon << "\n";
        publisher_->publish(utm_data);
    }
private:
    string logMessageForm(const custom_interfaces::msg::Utm utm_data)
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

    ofstream file;
    rclcpp::Publisher<custom_interfaces::msg::Utm>::SharedPtr publisher_;
};

class NmeaSubscriber: public rclcpp::Node
{
public:
    NmeaSubscriber(): Node("nmea_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "nmea_data", 10, std::bind(&NmeaSubscriber::nmeaDataTransformer, this, std::placeholders::_1));
    }
private:
    void nmeaDataTransformer(const std_msgs::msg::String &msg) {
        // RCLCPP_INFO_STREAM(this->get_logger(), "I heard: '" << msg.data << "'");     // CHANGE
        vector<string> raw_data = split(msg.data, ',');
        if (raw_data[0].substr(3).compare("GGA") == 0 && raw_data.size() == 15 && raw_data[2].compare("") != 0) {
            calculateLatitudeLongitude(latitude_, longitude_, 
                                        safeStod(raw_data[2]), raw_data[3], 
                                        safeStod(raw_data[4]), raw_data[5]);
            latLonToUtm(easting_, northing_, latitude_, longitude_);
            makeUtmData(utm_data_, raw_data, latitude_, longitude_, easting_, northing_);

            parser_.publishUtmData(utm_data_);
        }
    }

    void calculateLatitudeLongitude(double & latitude, double & longitude,
                                    const double lat, const string lat_dir,
                                    const double lon, const string lon_dir)
    {
        int lat_deg = static_cast<int>(lat / 100);
        double lat_mint = lat - (lat_deg * 100);
        latitude = lat_deg + (lat_mint / 60.0);
        if (lat_dir.compare("S") == 0) latitude = -latitude;

        int lon_deg = static_cast<int>(lon / 100);
        double lon_mint = lon - (lon_deg * 100);
        longitude = lon_deg + (lon_mint / 60.0);
        if (lon_dir.compare("W") == 0) longitude = -longitude;
    }

    void latLonToUtm(double& easting, double& northing, const double latitude, const double longitude) {
        const double R = 6378137.0;
        const double f = 1 / 298.257223563;
        const double k0 = 0.9996;
        const double e = sqrt(2 * f - f * f);
        const double e_prime_sq = e * e / (1 - e * e);

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

    void makeUtmData(custom_interfaces::msg::Utm& utm_data, const vector<string> raw_data,
                    const double latitude, const double longitude, const double easting, const double northing)
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
        utm_data.utc = safeStod(raw_data[1]);
        utm_data.lat = latitude;
        utm_data.lat_dir = raw_data[3];
        utm_data.lon = longitude;
        utm_data.lon_dir = raw_data[5];
        utm_data.quality = stoi(raw_data[6]);
        utm_data.num_satelite = stoi(raw_data[7]);
        utm_data.hdop = safeStod(raw_data[8]);
        utm_data.alt = safeStod(raw_data[9]);
        utm_data.alt_unit = raw_data[10];
        utm_data.sep = safeStod(raw_data[11]);
        utm_data.sep_unit = raw_data[12];
        utm_data.diff_age = safeStod(raw_data[13]);
        if (raw_data.size() <= 18) {
            utm_data.diff_station = 0;
        }
        else {
            utm_data.diff_station = stoi(raw_data[14]);
        }
        utm_data.check_sum = raw_data[14].substr(raw_data[14].size()-2);
        utm_data.easting = easting;
        utm_data.northing = northing;
    }

    bool isValidDouble(const string& str)
    {
        try {
            size_t pos;
            stod(str, &pos);
            return pos == str.size();
        } catch (const invalid_argument& e) {
            return false;
        } catch (const out_of_range& e) {
            return false;
        }
    }

    double safeStod(const string& str, double defaultValue = 0.0) {
        if (str.empty() || !isValidDouble(str)) {
            return defaultValue;
        }
        return stod(str);
    }

    UtmParser parser_;
    double latitude_;
    double longitude_;
    double easting_;
    double northing_;

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    custom_interfaces::msg::Utm utm_data_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NmeaSubscriber>());
    rclcpp::shutdown();
    return 0;
}