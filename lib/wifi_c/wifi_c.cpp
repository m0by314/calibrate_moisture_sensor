#include "wifi_c.h"

/* 
*   Constructor
*/
Wifi::Wifi (const char* ssid, const char* pwd)
    : _ssid(ssid), _pwd(pwd) {}

/* 
*   Establish a Wi-Fi connection with your router
*   Returns 1 if the connection is established, 0 in case of failure
*/
bool Wifi::connect() {
    WiFi.begin(_ssid, _pwd);
    
    int timeout = 10;  // 10 seconds

    while(WiFi.status() != WL_CONNECTED  && (timeout-- > 0)) {
        sleep(1);  // sleep 1s 
    }

    if (WiFi.status() != WL_CONNECTED) {
        return false;
    }
    else {
        return true;
    }  
}

/*
*   Disconnect WiFi
*/
void Wifi::disconnect(){
    WiFi.disconnect();
}

/* 
*  Get ip adress
*  Return an object IPAddress
*/
IPAddress Wifi::getIp(){
    return WiFi.localIP();
}