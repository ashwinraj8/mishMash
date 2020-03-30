
#include <DHT.h>  // Including library for dht

#include <ESP8266WiFi.h>
 
String apiKey = "Your API of thingsspeak";   

const char *ssid =  "#####";     
const char *pass =  "##";
const char* server = "##";

#define DHTPIN 0         
 
DHT dht(DHTPIN, DHT11);

WiFiClient client;
 
void setup() 
{
       Serial.begin(115200);
       delay(10);
       dht.begin();
 
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
}
 

