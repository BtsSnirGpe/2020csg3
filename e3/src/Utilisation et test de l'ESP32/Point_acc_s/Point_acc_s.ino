#include <WiFi.h>

const char* ssid = "ESP32";
const char* password = "ESP32SAP";

void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n");
  
  Serial.println("Creation du point d'acces...");
  WiFi.softAP(ssid, password);
  
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.softAPIP());
}

void loop()
{
  
}
