#ifndef _WIFI_C_H_
#define _WIFI_C_H_

#include <unistd.h>
#include <WiFi.h>

/* 
*   Class that stores state and functions for interacting with Wifi.
*/
class Wifi {
    public:
        Wifi(const char* ssid, const char* pwd);
        bool connect();
        void disconnect();
        IPAddress getIp();

    private:
        const char* _ssid;
        const char* _pwd;
};

#endif