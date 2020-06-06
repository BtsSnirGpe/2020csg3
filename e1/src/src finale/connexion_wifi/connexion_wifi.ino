#include<WiFi.h>

const char* ssid = "Livebox-31FA";
const char* password = "QXNaL4rhxpdfcGbXgr";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n");
  
  WiFi.begin(ssid, password);
  Serial.print("Tentative de connexion...");
  
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }
  
  Serial.println("\n");
  Serial.println("Connexion établie !");
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:

}
