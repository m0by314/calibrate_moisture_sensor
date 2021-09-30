# Calibrate soil moisture sensor
Tool to calibrate a soil moisture sensor for a desired soil type with an ESP32  
 _(Tested with captor YL69 amd module HC-38)_  

## How it works

The tool performs 600 measurements and then calculates the average which gives the calibration value for the soil type.  

The result is sent by email via an IFTTT webhooks.  

The ESP goes into hibernation at the end of the measurements.  
To perform a new calibration, simply press the XXXX key.  

## Connect the soil moisture sensor 

![image](static/img/Soil_Moisture_Interfacing_Diagram.png)


## Create IFTTT webhooks

* Go to the link: https://ifttt.com/
* Then click on the "create" button 
![image](static/img/ifttt_create.png)
* Then click on "add" in the "If This" section 
![image](static/img/ifttt_add.png)
* Search for the "Webhooks" service
![image](static/img/ifttt_webhooks.png)
* Select "Receive a web request"
![image](static/img/ifttt_web_request.png)
 Define the event name (to keep aside it will be used in the configuration file) then create the trigger
![image](static/img/ifttt_event_name.png)
* In the "Then that" section click on "add
![image](static/img/ifttt_then.png)
* Search for the Gmail service
* Then select "send an email"
![image](static/img/ifttt_mail.png)
* Complete action fields like this:
![image](static/img/ifttt_fields.png)


* Go to the following link to get your key: https://ifttt.com/maker_webhooks/settings   
The key is at the end of the URL
![image](static/img/ifttt_key.png)  

## Setup 