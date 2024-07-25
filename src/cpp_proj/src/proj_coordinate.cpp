#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
#include <proj.h>

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

// GPGGA, 시간, 위도, 경도, 계산종류, 위성수, 노이즈, 고도, 고도2, dgps, checksum
// GPGSA, 
// GPRMC, 
// GPGSV, 
// GNHDT,
// GNRMC,
// GNGGA,
// string message_id;
// float utc;
// float lat;
// string lat_dir;
// float lon;
// string lon_dir;
// int quality;
// int num_satelite;
// float HDOP;
// float alt;
// string alt_unit;
// float sep;
// string sep_unit;
// float diff_age;
// string check_sum;

int main()
{
    string line;

    ifstream file("/home/sunny/ros2_ws/src/cpp_proj/src/TalkFile_nmea.txt");
    
    string raw_data;
    
    PJ_CONTEXT *C;
    PJ *P;
    PJ_COORD a, b;

    C = proj_context_create();
    P = proj_create_crs_to_crs(C, "EPSG:4326", "EPSG:32652", 0);

    if (P == nullptr) {
        cerr << "Failed to create transformation object." << endl;
        proj_context_destroy(C);
        return 1;
    }
    
    if(file.is_open()) {
        // while(getline(file, line)) {
            getline(file,line);
            cout << "---------- GGA DATA ----------" << endl;
            raw_data = line;
            cout << raw_data << endl;
            vector<string> result = split(line, ',');
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << endl;
            }

            double latitude = stod(result[2]);
            double longitude = stod(result[4]);

            int lat_degrees = static_cast<int>(latitude / 100);
            double lat_minutes = latitude - (lat_degrees * 100);
            double lat = lat_degrees + (lat_minutes / 60.0);
            if (result[3] == "S") lat = -lat;

            int lon_degrees = static_cast<int>(longitude / 100);
            double lon_minutes = longitude - (lon_degrees * 100);
            double lon = lon_degrees + (lon_minutes / 60.0);
            if (result[5] == "W") lon = -lon;

            cout << "lon: " << lon << " lat: " << lat << endl;

            a = proj_coord(proj_torad(lon), proj_torad(lat), 0, 0); // 472;
            cout << a.xyzt.x << " " << a.xyzt.y << " " << a.xyzt.z << " " << a.xyzt.t << endl;
            b = proj_trans(P, PJ_FWD, a);
            cout << "Easting: " << b.enu.e/100 << ", Northing: " << b.enu.n/100 << endl;
        // }
        proj_destroy(P);
        proj_context_destroy(C);
        file.close();
    }
    else {
        cout << "err" << endl;
        return 0;
    }
    return 0;
}