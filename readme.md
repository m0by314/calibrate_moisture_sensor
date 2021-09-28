# Calibrate soil moisture sensor
Tool to calibrate a soil moisture sensor for a desired soil type with an ESP32
 _(Tested with captor YL69 amd module HC-38)_  
## How it works

The tool performs 600 measurements (by default) for each threshold (dry soil and wet soil). The result of the measurements are stored on google drive. 
The program counts the number of reboot of the ESP to define the test mode. 
* Reboot 0 --> dry soil 
* Reboot 1 --> wet soil
* Reboot 2 --> reset the counter to zero and restart

An email is sent at the end of each test. The ESP goes into hibernation at the end of the tests. To perform the next test, just press the XXXX key.

Once the tests are finished, launch the python script to display the calibration graph.  

## Connect the soil moisture sensor 

![image](static/img/Soil_Moisture_Interfacing_Diagram.png)

## Create Ifttt

### Gmail 

