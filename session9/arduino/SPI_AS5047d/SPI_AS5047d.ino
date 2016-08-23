#include <SPI.h>
#define AS5047D_select_pin 30
//#define shifting  registers
SPISettings settingsA(100000, MSBFIRST, SPI_MODE1);

uint8_t stat, val2, result;
//chip settings
#define PROG   0x0003
#define CORDICMAG 0x3FFD
#define DIAAGC 0x3FFC
#define ANGLECOM  0x3FFF
#define ANGLE  0x3FFE
#define ERRFL 0x0001
#define ZPOSM 0x0016
#define ZPOSL 0x0017
#define SETTINGS2 0x0019
#define SETTINGS1 0x0018

void setup() {
  pinMode (AS5047D_select_pin, OUTPUT);
  digitalWrite(AS5047D_select_pin, HIGH);
  SPI.begin();
  Serial.begin(9600);
  Serial.print("setup: ");
  while (1)
  {
    if (Serial.available() > 0)
    {
      char cc = Serial.read();
      if (cc == 'h' || cc == '?') {
        Serial.println("Press 's' to start.");
      }
      if (cc == 's') {
        break;
      }
    }
  }
  Serial.println("start");
  Serial.println("Write Register");
  writeRegister(0x0018, 0x5005);
  // AS5047D_Write( AS5047D_select_pin ,SETTINGS2, 0x0000);
  //AS5047D_Write( AS5047D_select_pin ,ZPOSM, 0x0000);  // is it really possible to initially set angle at 0 degrees??
  //AS5047D_Write( AS5047D_select_pin ,ZPOSL, 0x0000);
  uint16_t regvalue = readRegister(0x0018);

  Serial.print("Register 0x0018: ");
  Serial.println(regvalue, HEX);
  // Serial.print("Settings2  : "); Serial.println(readRegister(SETTINGS2 ), HEX );



}

void loop() {

}

uint16_t readRegister(uint16_t reg) {
  Serial.println("readReg start:");

  uint16_t cmd, result;
  byte res_h = 0;
  byte res_l = 0;

  cmd =  ( reg | (1 << 14));
  if (parity(cmd) != 0 )
  {
    cmd |= 1 << 15;
  }
  SPI.beginTransaction(settingsA);
  digitalWrite (AS5047D_select_pin, LOW);
  stat = SPI.transfer(  cmd >> 8);
  digitalWrite (AS5047D_select_pin, HIGH);
  digitalWrite (AS5047D_select_pin, LOW);
  result = SPI.transfer(cmd && 0xFF);
  digitalWrite (AS5047D_select_pin, HIGH);

  digitalWrite (AS5047D_select_pin, LOW);
  res_h = (SPI.transfer(0x00));
  digitalWrite (AS5047D_select_pin, HIGH);
  digitalWrite (AS5047D_select_pin, LOW);
  res_l = SPI.transfer(0x00);
  digitalWrite (AS5047D_select_pin, HIGH);

  res_h = res_h & 0x3F;

  SPI.endTransaction();

  Serial.print("REG: "); Serial.println(reg, HEX);
  Serial.print("CMD: "); Serial.println(cmd, HEX);
  Serial.print("res_h: "); Serial.println(res_h, HEX);
  Serial.print("res_l: "); Serial.println(res_l, HEX);
  result = ((res_h << 8) | res_l);
  Serial.print(" result: "); Serial.println(result,  HEX);
  return result;
}

void  writeRegister(uint16_t reg, uint16_t value) {
  uint16_t cmd, result;
  Serial.println("writeReg start:");

  cmd =  ( reg && ~(1 << 14));
  if (parity(cmd) != 0 )
  {
    cmd |= 1 << 15;
  }
  //first byte
  SPI.beginTransaction(settingsA);
  digitalWrite (AS5047D_select_pin, LOW);
  stat = SPI.transfer( cmd >> 8);
  result =  SPI.transfer(cmd && 0xFF);
  digitalWrite (AS5047D_select_pin, HIGH);
  //second byte
  digitalWrite (AS5047D_select_pin, LOW);
  stat = SPI.transfer( value >> 8);
  result =  SPI.transfer(value && 0xFF);
  digitalWrite (AS5047D_select_pin, HIGH);
  SPI.endTransaction();
  Serial.print("reg: "); Serial.print(reg, HEX);
  Serial.print(" value: "); Serial.println(value,  HEX);
  Serial.println("writeReg end");
}

//*******************check parity ******************************************
int parity(unsigned int x) {
  int parity = 0;
  while (x > 0) {
    parity = (parity + (x & 1)) % 2;
    x >>= 1;
  }
  return (parity);
}
