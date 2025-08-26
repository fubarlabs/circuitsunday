#define PIN_LED1 2
#define PIN_BTN1 0

int count = 0;
int countb = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_BTN1, INPUT);

  Serial.begin(9600);

}
//my single line comment

void loop() {
  digitalWrite(PIN_LED1, HIGH);
  delay(50);
  digitalWrite(PIN_LED1, LOW);
  delay(50);

  Serial.print("button: ");
  Serial.println(digitalRead(PIN_BTN1));

  if (digitalRead(PIN_BTN1) == HIGH)
  {
    count++;
    Serial.println("HIGH");
  }
  else
  {
    countb--;
  }
  Serial.print("HIGH Count: ");
  Serial.println(count);
  Serial.print("Low Count: ");
  Serial.println(countb);

}

