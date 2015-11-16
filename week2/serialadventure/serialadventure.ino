int health = 10;
void walkNorth() {
        Serial.println("I'm walking north");
}
int printHealth() {
        Serial.print("health: ");
        Serial.println(health);
}
void printHelp() {
        Serial.println("Press n to walk north.");
}
void setup() {
        // put your setup code here, to run once:
        Serial.begin(9600);
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
                if (ch == '?') {
                        printHelp();
                }
        }
}
