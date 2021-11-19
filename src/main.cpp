#include <Arduino.h>
#include <WiFiClientSecure.h>

#include <ifttt.h>
#include <wifi_c.h>
#include "../config.h"

// Prototype
WiFiClientSecure client;
IFTTT ifttt_mail(IFTTT_KEY, client);   // Initialize Ifttt object.

// Variables
int sum_measure;

void setup() {
  Serial.begin(115200);
  
  pinMode(MOISTURE_SENSOR_PIN,INPUT);
  adcAttachPin(MOISTURE_SENSOR_PIN);
  
  // Connect to WiFi
  if (!wifi_connect(WIFI_SSID, WIFI_PWD)){
    esp_deep_sleep_start();
  };

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

  // Send mail
  ifttt_mail.triggerEvent(IFTTT_EVENT_NAME, MAILTO, mail_object, mail_body);
  
  // Start deep sleep
  Serial.println("Calibration finish, going to sleep ...");
  delay(2000);
  esp_deep_sleep_start();
}
  
void loop() {}

