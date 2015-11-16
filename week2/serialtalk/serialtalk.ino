void setup() {
        Serial.begin(9600);
        // USB port - baud doesn't matter Serial0.begin(115200);
        // UART1 - Fubarino SD pins 8 and 9, Fubarino Mini 17,18 Serial1.begin(115200);
        // UART2 - Fubarino SD pins 28 and 29, Fubarino Mini 25,26
}

void loop() {
        Serial.println("This is USB serial ");
        Serial0.println("This is serial0 ");
        Serial1.println("This is serial1 ");
        if (Serial.available()) { // Echo back what got sent + 1
                Serial.println(byte(Serial.read() + 1));
        }
        if (Serial0.available()) { // Echo back what got sent + 1
                Serial0.println(byte(Serial0.read() + 1));
        }
        if (Serial1.available()) { // Echo back what got sent + 1
                Serial1.println(byte(Serial1.read() + 1));
        }
        delay(200);
}
