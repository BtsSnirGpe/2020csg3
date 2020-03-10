#include <WiFi.h>
const char* ssid = "Redmi";
const char* password = "Dyllan280999";

void setup(){

  Serial.begin(115200);
  delay(10);
  Serial.print("Connecting to");
  Serial.println(ssid);
  
  
  WiFi.begin(ssid, password);
  while(WiFi.status()!= WL_CONNECTED){
    delay(5000);
    Serial.print("");
  }
  Serial.println("WiFi connected");
}

void loop(){

  
  
}
