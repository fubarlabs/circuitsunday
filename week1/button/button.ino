// This sketch demonstrates how to blink the on-board LED
// and read the on-board button. When you run the sketch,
// The LED will blink slowly until you hold down the PRG
// button. Then it will blink fast.

// Controls the LED blink speed, in ms
int LedSpeed = 1000;

void setup()
{
  // Set up our two pins of interest
  digitalWrite(PIN_LED1, LOW);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_BTN1, INPUT);
}

void loop()
{
  digitalWrite(PIN_LED1, HIGH);
  delay(LedSpeed);
  digitalWrite(PIN_LED1, LOW);
  delay(LedSpeed);
  if (digitalRead(PIN_BTN1) == 1)
  {
    LedSpeed = 1000;
  }
  else
  {
    LedSpeed = 50;
  }
}
