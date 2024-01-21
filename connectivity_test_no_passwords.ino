//Wifi Conncetion test for ESP8226
//simple code that creates a saw tooth temperature output to test connectivity. 

//all tbe following liraries need to be installed and included
#include <ESP8266WiFi.h>
#include <WifiClient.h>
#include <ThingSpeak.h>

// put wifi name and password here (WiFi SSID is the hub name): 
#define WIFI_SSID "put wifi SSID here"
#define WIFI_PASSWORD "put wifi password here"

//ThingSpeak channel  
unsigned long myChannelNumber = put thingspeak chanel ID here, no speachmarks of brackets;  // UNCOMMENT THIS LINE
//ThingSpeak API key
const char * myWriteAPIKey = "put thingspeak API key here"; // UNCOMMENT THIS LINE

// 
WiFiClient client;

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);
  // Start the DS18B20 sensor
  

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() !=WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }

  Serial.println(); 
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println(String("ESP chip ID ") + ESP.getChipId());
  Serial.println();

  ThingSpeak.begin(client);
}

void loop() {

  //two float values so the recorded line will ping between values and make a sawtooth pattern if the connection is constant /\/\/\/\/\/\/ 
  float connected = 101;
  float connected2 = 111;
  
  //Sets the value of a specific field in the ThingSpeak channel. e.g temp. 
  //Without this line the temp is always -127.00ºC if ThingSpeak.writefields is not commented out
  //ping 1
  ThingSpeak.setField(1, connected);
  delay(1500);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  //ping 2
  ThingSpeak.setField(1, connected2);
  delay(1500);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  
  Serial.print("\n");
  Serial.println("if the values are pinging between 101-111 then the ESP8266 is connected");

  // delay(3000);
}