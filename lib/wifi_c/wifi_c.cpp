#include "wifi_c.h"

#include <unistd.h>
#include <WiFi.h>
#include <Arduino.h>


/**
* Establish a WiFi connection with your router
*
* @param ssid  WiFI network name
* @param pwd   WiFi password
* @param timeout timeout duration for connection attempt, by default 10s 
* @param debug   if true displays the debugging messages by default false
*
* @return true if the connection is established 
*/
bool wifi_connect(const char* ssid, const char* pwd, int timeout, bool debug) {
    WiFi.begin(ssid, pwd);
    
    while(WiFi.status() != WL_CONNECTED  && (timeout-- > 0)) {
        if (debug) Serial.print(".");
        sleep(1);  // sleep 1s 
    }

    return wifi_is_connected(debug);
}

/**
* Check if the WiFi is connected
*
* @param debug   if true displays the debugging messages by default false
*
* @return true if the connection is established 
*/
bool wifi_is_connected(bool debug) {
    bool connected; 
    if (WiFi.status() != WL_CONNECTED) {
        if (debug) Serial.println("\nERROR: WiFi fail connection");
        connected = false;
    }
    else {
        if (debug) {
            Serial.print("\nWiFi connected, IP address: ");
            Serial.print(WiFi.localIP()); 
            Serial.println();
        }
        connected =  true;
    }
    return connected;
}
