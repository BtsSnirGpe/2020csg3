// ESP32 contact test
// Il suffit de tester la broche tactile - Touch0 est t0 qui est sur GPIO 4.(D4)

void setup()
{
  pinMode(22, OUTPUT);
  Serial.begin(115200);
  delay(1000); 
  Serial.println("ESP32 Contact Test");
  
}

void loop()
{
  int x=0;
  Serial.println(x=touchRead(T0));  
  //delay(1000);
  if(x<50)
  {
    digitalWrite(22, LOW); 
    Serial.println("Contact");
    delay(500);
   }
   else
   {
    digitalWrite(22, HIGH);
    Serial.println("Pas de contact");
    delay(500);
    }
}
