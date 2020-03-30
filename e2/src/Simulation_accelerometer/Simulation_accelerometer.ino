int16_t num_zerog = (3.3 / 5) * 512;
int16_t num_xaxis = num_zerog;
uint8_t num_random = 0;
 
void setup() {
   Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  num_random = random(256);
  if (num_random == 255) {
    num_xaxis += 200;
  }
  else if (num_random == 0) {
    num_xaxis -= 200;
  }
  else if (num_random < 100) {
    num_xaxis += 1;
  }
  else if (num_random > 155) {
    num_xaxis += 1;
  }
  else {
    num_xaxis += (num_zerog - num_xaxis) / 4;
  }
  if(num_xaxis < 0 || num_xaxis > 675) {
    num_xaxis = num_zerog;
  }
  Serial.println(num_xaxis);
  delay(10);
}
