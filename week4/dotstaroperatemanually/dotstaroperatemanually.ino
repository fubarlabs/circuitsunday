/*
    Manual mode Dotstar
    Inpired by Julian Illet https://www.youtube.com/watch?v=UYvC-hukz-0

    Start Frame: 0000
    Color: red:   1001
           green: 1010
           blue:  1100

     Set first led red:
     00001001

*/

#define DATAPIN    4
#define CLOCKPIN   9
#define DI    4
#define CI   9

int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(DI, OUTPUT);
  pinMode(CI, OUTPUT);
  start();
  Serial.println("Start entering frames and color codes");
}

void loop() {

  if (Serial.available() > 0) {
    count++;
    char ch = Serial.read();
    if ( count % 8 == 0) {
      Serial.println(ch);
    } else {
      Serial.print(ch);
    }
    if ( ch ==  '0' ) {
      shiftOut(DI, CI, MSBFIRST, 0x00);
    }
    if ( ch ==  '1' ) {
      shiftOut(DI, CI, MSBFIRST, 0xff);
    }
    if(ch == 'h' || ch == '?') {
              printHelp();
    }
  }
}

void start() {
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
  Serial.println();

}

void printHelp() {
  Serial.println("Press ? for help");
  Serial.println("Press 0 for 0 byte");
  Serial.println("Press 1 for 1 byte");
  Serial.println("Press enter/return to send pattern");
  Serial.println("Start Frame: 0000\nColor: \nred:   1001\ngreen: 1010\nblue:  1100\nOff: 1000\nSet first led red:\n00001001");
  Serial.println("Each additional color added lights the next led.");
  Serial.println("00001111100111111001");
  Serial.println();

}


