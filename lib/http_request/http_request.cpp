#include "http_request.h"

HTTPClient http;

void post_http_request(String url, String content){
  //Start to send data to url
  http.begin(url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/json");
  
  int httpResponseCode = http.POST(content);
  
  if (httpResponseCode != 200) {
    Serial.print("ERROR post http request return code: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}