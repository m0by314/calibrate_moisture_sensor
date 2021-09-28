#include <Arduino.h>
#include <string> 

#include <config.h>
#include <wifi_con.h>
#include <http_request.h>
#include <ifttt.h>

// Prototype
Ifttt ifttt_mail(GMAIL_TRIGGER);           // Initialize Ifttt object with Gmail trigger.

// Variables
int sum_measure;

void setup() {
  Serial.begin(115200);
  
  pinMode(MOISTURE_SENSOR_PIN,INPUT);
  adcAttachPin(MOISTURE_SENSOR_PIN);
  
  wifi_connect(&Serial);
  
  delay(2000); 
}
  
void loop() {  
  Serial.println("Reading From the Sensor ...");
  
   
  for (int n_measure = 0; n_measure < NB_MEASURE; n_measure++){
    int soil_moisture = analogRead(MOISTURE_SENSOR_PIN);
    Serial.print(soil_moisture);
    Serial.print("\n");
    sum_measure += soil_moisture;
    delay(4000);  // 4s
  }
  
  int avg_measure = sum_measure / NB_MEASURE; // calculates the average of the calibration measures
  String mail_object = "Finished calibration:<br>";
  String mail_body = "The average for this type of soil is : " + String(avg_measure) + ".<br><br>ESP32 is asleep.<br><br>To start a new calibration press the EN button.<br>";
  ifttt_mail.post_request(MAILTO, mail_object, mail_body);
  
  Serial.print("\n");
  Serial.println("Calibration finish, going to sleep ...\n");
  
  delay(2000);
  
  esp_deep_sleep_start();
}
