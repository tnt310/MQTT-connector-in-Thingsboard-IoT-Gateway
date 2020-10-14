#include <ESP8266WiFi.h>
#include <PubSubClient.h>
const char* ssid ="account Wifi"; 
const char* password ="password"; 
char *mqtt_server ="ID server";
char dem[4];
float lux;
unsigned int soil,temp,humid;

/*khởi động thư viện Pubsubclient*/
WiFiClient espClient;
PubSubClient client(espClient);

void setup() 
{
  Serial.begin(9600);
  setup_wifi();// cấu hình module để kết nối wifi.
  client.setServer(mqtt_server,1883);// đăng ký Broker server Mosquitto và TCP port 1883
}
void loop()
{
 if (!client.connected()) 
  {
    reconnect();
  }
 client.loop();
 if(Serial.available()>0)
  { 
    Serial.readBytes(dem,4);//read soil              
    soil=Bytes2float(&dem[0]);
    Serial.println(soil);
    Serial.readBytes(dem,4);//read temperature              
    temp=Bytes2float(&dem[0]);
    Serial.println(temp);
    Serial.readBytes(dem,4);//read humidity
    humid=Bytes2float(&dem[0]);
    Serial.println(humid);
    Serial.readBytes(dem,4);//read lux              
    lux=Bytes2float(&dem[0]);
    Serial.println(lux);
    // Prepare a JSON payload string
      String payload = "{";
      payload += "\"soil\":";
      payload += soil;
      payload += ",";
      payload += "\"temperature\":"; 
      payload += temp; 
      payload += ",";
      payload += "\"humidity\":"; 
      payload += humid;
      payload += ",";
      payload += "\"lux\":";
      payload += lux;
      payload += "}";
   // Send payload
      char telemetry[200];
      payload.toCharArray(telemetry,200);
      client.publish("Temperature",telemetry);
      Serial.println(telemetry);
 } 
}
void setup_wifi()
{
  WiFi.begin(ssid, password);
  while (WiFi.status()!= WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}
void reconnect() 
{
  while (!client.connected()) 
  {
    if(client.connect("ESP8266Client"))
     {
        Serial.println("Connected");
     }
    else 
     {
      Serial.println("Notconnected");
      delay(3000);
     }
  }
}
float Bytes2float(char* bytes_array)
{
  union
    {
     float float_variable;
     char  temp_array[4];
    }u;
   memcpy(u.temp_array,bytes_array,4);
   return u.float_variable;
}
