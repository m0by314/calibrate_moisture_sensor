#include <Arduino.h>

#include <wifi_c.h>
#include <http_request.h>
#include <ifttt.h>
#include "../config.h"

// Prototype
Ifttt ifttt_mail(IFTTT_EVENT_NAME, IFTTT_KEY);   // Initialize Ifttt object with Gmail trigger.
Wifi wifi(WIFI_SSID, WIFI_PWD);               // Initialize wifi object

// Variables
int sum_measure;

void setup() {
  Serial.begin(115200);
  
  pinMode(MOISTURE_SENSOR_PIN,INPUT);
  adcAttachPin(MOISTURE_SENSOR_PIN);
  
  if (!wifi.connect()){
    Serial.print("ERROR: WiFI fail connection\n");
    esp_deep_sleep_start();
  }
  
  Serial.println("Reading From the Sensor ...");
  // Performs the measurements.
  for (int n_measure = 0; n_measure < NB_MEASURE; n_measure++){
    int soil_moisture = analogRead(MOISTURE_SENSOR_PIN);
    Serial.println(soil_moisture);
    sum_measure += soil_moisture;
    delay(4000);  // 4s
  }
  
  // Calculates the average of the calibration measures
  int avg_measure = sum_measure / NB_MEASURE; 

  // Built the mail 
  String mail_object = "Finished calibration:<br>";
  String mail_body = "The average for this type of soil is : " + String(avg_measure) + ".<br><br>ESP32 is asleep.<br><br>To start a new calibration press the EN button.<br>";
  String url = ifttt_mail.get_url();
  String content = ifttt_mail.build_content(MAILTO, mail_object, mail_body);

  // Send mail
  post_http_request(url, content);
  
  // Start deep sleep
  Serial.println("Calibration finish, going to sleep ...");
  delay(2000);
  esp_deep_sleep_start();
}
  
void loop() {}

