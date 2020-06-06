#include<WiFi.h>

const char* ssid = "ESP32_SAP";
const char* password = "2020csg3sapCDCF";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n");
  
  Serial.println("Creation du point d'acces...");
  WiFi.softAP(ssid, password);
  
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  
}
