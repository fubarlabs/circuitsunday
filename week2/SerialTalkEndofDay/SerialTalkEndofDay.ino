void setup() {
  Serial.begin(9600);     // USB port - baud doesn't matter
  Serial0.begin(115200);  // UART1 - pins 8 and 9
  Serial1.begin(115200);  // UART2 - pins 28 and 29
}

void loop() {
 // Serial.println("This is USB serial ");
 // Serial0.println("This is serial0 ");
 // Serial1.println("This is serial1 ");
  if (Serial.available())
  {
    // Echo back what got sent + 1
    Serial0.print(Serial.read()));
  }
  while(Serial0.available() > 0)
  {
    // Echo back what got sent + 1
    Serial.print(char(Serial0.read()));
  
  }
  if (Serial1.available())
  {
    // Echo back what got sent + 1
    Serial1.println(byte(Serial1.read() + 1));
  }
  delay(200);
}
