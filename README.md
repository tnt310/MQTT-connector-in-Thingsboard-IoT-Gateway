# Visualizing-sensor-data-on-Thingsboard-IoT-platform
This is a project about Thingsboard and Thingsboard Gateway.
In this project:
  - STM32F103C8T6 is used to collect sensor data (DHT11, MAX44009, Moisture sensor). 
  - ESP8266 receives data ( bytes) from STM32 and send them to Mosquitto broker on local. 
  - Thingsboard Gateway (run port 1884) will sub data from Mosquitto broker ( run port 1883), and then Thingsboard Gateway will send data (formatted) to Thingsboard cloud through MQTT connector.
  - Besides, a gui is as mqtt client also sub data from Mosquitto broker.

![image](https://user-images.githubusercontent.com/67432831/120340822-8a348680-c320-11eb-9758-d851d31f62a2.png)

https://thingsboard.io/docs/user-guide/install/ubuntu/

https://thingsboard.io/docs/iot-gateway/config/mqtt/

https://thingsboard.io/docs/samples/esp8266/gpio/
