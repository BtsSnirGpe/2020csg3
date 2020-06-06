#include <WiFi.h>

WiFiManager wm;
const char* ssid = "ESP32_SAP";
const char* password = "2020csg3sapCDCF";
void setup() {
  // put your setup code here, to run once:
  
  WiFi.mode(WIFI_STA);
  
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n");
  
  if(!wm.autoConnect(ssid, pasword))
    Serial.println("Erreur de connexion!");
  else
    Serial.println("Connexion établie !");
 }

void loop() {
  // put your main code here, to run repeatedly:
  if(touchRead(T0) < 50)
  {
    Serial.println("Suppression des réglages et redemarrage...");
    wm.resetSettings();
    ESP.restart;
  }
}
