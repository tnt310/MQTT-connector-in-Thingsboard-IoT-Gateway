# Visualizing-sensor-data-on-Thingsboard-IoT-platform
This is a project about Thingsboard and Thingsboard Gateway.
In this project:
  - STM32F103C8T6 is used to collect sensor data (DHT11, MAX44009, Moisture sensor). 
  - ESP8266 receives data ( bytes) from STM32 and send them to Mosquitto broker on local. 
  - Thingsboard Gateway (run port 1884) will sub data from Mosquitto broker ( run port 1883), and then Thingsboard Gateway will send data (formatted) to Thingsboard cloud bu mqtt protocol.
  - Besides, a gui is as mqtt client also sub data from Mosquitto broker.

https://thingsboard.io/docs/user-guide/install/ubuntu/

https://thingsboard.io/docs/iot-gateway/config/mqtt/

https://thingsboard.io/docs/samples/esp8266/gpio/

