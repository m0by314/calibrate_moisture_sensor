#include "ifttt.h"

#include <unistd.h>
#include <WiFi.h>
#include <HTTPClient.h>

HTTPClient http;

/* 
*   Constructor
*/
Ifttt::Ifttt (String trigger_name, String ifttt_key, const char* ssid, const char* pwd) {
    this->_trigger_name = trigger_name;
    this->_ifttt_key = ifttt_key;
    this->_ssid = ssid;
    this->_pwd = pwd;
}

/*
* WiFi connection
*/
void Ifttt::connect() {
    if (WiFi.status() != WL_CONNECTED){
        WiFi.begin(this->_ssid, this->_pwd);
    
        int timeout = 10;  // 10 seconds

        while(WiFi.status() != WL_CONNECTED  && (timeout-- > 0)) {
            Serial.print(".");
            sleep(1);  // sleep 1s 
        }
    }   
}

/*
* Check if the WiFi is connected
*/
bool Ifttt::is_connected() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("ERROR: WiFi fail connection");
        return false;
    }
    else {
        Serial.println("WiFi connected, IP address: "); 
        Serial.println(WiFi.localIP());  
        return true;
    }  
}

/*
* Send ifttt request
*/
void Ifttt::post_request(String field1, String field2, String field3){
  //Start to send data to url
  http.begin(this->_build_url());

  // Specify content-type header
  http.addHeader("Content-Type", "application/json");
  
  int httpResponseCode = http.POST(this->_build_content(field1, field2, field3));
  
  if (httpResponseCode != 200) {
    Serial.print("ERROR post http request return code: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}

/*******************
 * Private Method *
 * ****************/
/* 
*   Build url 
*/
String Ifttt::_build_url() {
      return "http://maker.ifttt.com/trigger/" + this->_trigger_name + "/with/key/" + this->_ifttt_key;
}

/* 
*   Build content
*/ 
String Ifttt::_build_content(String field1, String field2, String field3) {
    return "{\"value1\":\"" + field1 + "\",\"value2\":\"" + field2 + "\",\"value3\":\"" + field3 +"\"}";
   
}

