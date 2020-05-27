#include <WiFiManager.h>

WiFiManager wm;
const char* ssid = "ESP32";
const char* password = "SAPESP32";

void setup()
{
  WiFi.mode(WIFI_STA);
  
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n");
  
  if(!wm.autoConnect(ssid, password))
    Serial.println("Erreur de connexion.");
  else
    Serial.println("Connexion etablie!");
}

void loop()
{
  if(touchRead(T0) < 50)
  {
    Serial.println("Suppression des reglages et redemarrage...");
    wm.resetSettings();
    ESP.restart();
  }
}
