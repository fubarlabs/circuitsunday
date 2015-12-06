int health = 10;
boolean onBoardLedStatus = false;
int analogValue = 0;

void walkNorth() {
  Serial.println("I'm walking north");
}
int printHealth() {
  Serial.print("health: ");
  Serial.println(health);
}
void printHelp() {
  Serial.println("Press ? for help");
  Serial.println("Press n to walk north");
  Serial.println("Press h for health");
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Set up our two pins of interest
  digitalWrite(PIN_LED1, LOW);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_BTN1, INPUT);

  while (1)
  {
    if (Serial.available() > 0)
    {
      char cc = Serial.read();
      if (cc == 'h' || cc == '?' || cc == '\n' || cc == '\r') {
        Serial.println("Press 's' to start.");
        printHelp();
      }
      if (cc == 's') {
        break;
      }
    }
  }
  Serial.println("start");


}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    char ch = Serial.read();
    Serial.print(ch);
    if (ch == 'n') {
      walkNorth();
    }
    if (ch == 'h') {
      printHealth();
    }
    if (ch == 'l') {
      onBoardLedStatus = !onBoardLedStatus;
      digitalWrite(PIN_LED1, onBoardLedStatus);
    }
    if (ch == 'p') {
      analogValue = analogRead(A9);
      Serial.print("Pot Val: ");
      Serial.println(analogValue);
    }
    if (ch == '?') {
      printHelp();
    }
  }


//Turn this into a function
if (digitalRead(PIN_BTN1) == 1)
{
  digitalWrite(PIN_LED1, HIGH);
}
else
{
  digitalWrite(PIN_LED1, LOW);
}
}
