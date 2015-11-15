//Blink

void setup() {
  pinMode(PIN_LED1, OUTPUT);
}

void loop() {
  digitalWrite(PIN_LED1, HIGH);
  delay(1000);
  digitalWrite(PIN_LED1, LOW);
  delay(1000);
}
