#include <DHT.h>  
#include <ESP8266WiFi.h>  
#include <WiFiClient.h>  
#include <ThingSpeak.h>
#include <MQ7.h>
#include "MQ135.h"
#define ANALOGPIN A0

MQ135 gasSensor = MQ135(ANALOGPIN);

MQ7 mq7(A1,5.0);



#define DHTPIN D4  
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);  

const char* ssid = "heyyo";  
const char* password = "azzdream1";  
WiFiClient client;  
unsigned long myChannelNumber = 802524;  
const char * myWriteAPIKey = "UTFJPTOKE1KNS0X7";  
uint8_t temperature;
void setup()  
{  
  Serial.begin(115200);  

   float rzero = gasSensor.getRZero();
   delay(3000);
   Serial.print("MQ135 RZERO Calibration Value : ");
   Serial.println(rzero);

  dht.begin();  
  delay(10); 
  // Connect to WiFi network  
  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
  // Print the IP address  
  Serial.println(WiFi.localIP());  
  ThingSpeak.begin(client);  
}  
void loop()   
{  

  float ppm = gasSensor.getPPM();
  delay(1000);

   Serial.print("CO2 ppm value : ");
  Serial.println(ppm);
}
  temperature = dht.readTemperature(); 
  Serial.print("Temperature Value is :");  
  Serial.print(temperature);  
  Serial.println("C");  
 
   
  ThingSpeak.writeField(myChannelNumber,1,temperature,myWriteAPIKey); 
  Serial.println("done"); 

  Serial.println(mq7.getPPM());
  delay(1000);
      
  delay(3000); // ThingSpeak will only accept updates every 15 seconds.  
} 



