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

int main()
{
    string line;

    ifstream file("/home/sunny/ros2_ws/src/cpp_proj/src/TalkFile_nmea.txt");
    
    string raw_data;
    string message_id;
    float utc;
    float lat;
    string lat_dir;
    float lon;
    string lon_dir;
    int quality;
    int num_satelite;
    float HDOP;
    float alt;
    string alt_unit;
    float sep;
    string sep_unit;
    float diff_age;
    string check_sum;
    
    PJ_CONTEXT *C;
    PJ *P;
    PJ *norm;
    PJ_COORD a, b;

    C = proj_context_create();
    P = proj_create_crs_to_crs(C, "EPSG:4326", "EPSG:32633", NULL);
    if(file.is_open()) {
        while(getline(file, line)) {
            cout << "---------- GGA DATA ----------" << endl;
            raw_data = line;
            cout << raw_data << endl;
            vector<string> result = split(line, ',');
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << endl;
            }
        }
        file.close();
    }
    else {
        cout << "err" << endl;
        return 0;
    }
    return 0;
}