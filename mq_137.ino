void setup() {
  Serial.begin(9600); //Baud rate 
}
 
void loop() { 
  float sensor_volt;  
  float RS_air;
  float R0; 
  float sensorValue; 
  for(int x = 0 ; x < 500 ;
  {
    sensorValue = sensorValue + analogRead(A0); 
  }
  sensorValue = sensorValue/500.0;
  sensor_volt = sensorValue*(5.0/1023.0); 
  RS_air = ((5.0*10.0)/sensor_volt)-10.0;
  R0 = RS_air/3.6; //Calculate R0 
 
  Serial.print("R0 = "); //Display "R0"
  Serial.println(R0);  
  delay(1000); 
}
