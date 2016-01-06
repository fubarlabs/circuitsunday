
#include <Adafruit_DotStar.h>
#include <SPI.h>         //comment out for softwareSPI
//#include <SoftSPI.h> //uncomment to use non standard pins

#define DATAPIN    25
#define CLOCKPIN   26
#define NUMPIXELS 30 // Number of LEDs in strip

#define red  0xFF0000
#define green  0x00FF00
#define blue  0x0000FF

int upindex = 0;
int downindex = 30;

uint32_t frame[NUMPIXELS];
uint32_t colors[3] = {green, red, blue };

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);



void setup() {
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP

  //initialize strip array
  for (int ii = 0; ii < NUMPIXELS; ii++) {
    frame[ii] = 0xFF0000; //initialize all to red
    strip.setPixelColor(ii, frame[ii]);
  }
  strip.show();

}

void loop() {
  /*
    for (int ii = 0; ii < NUMPIXELS; ii++) {
     frame[ii] = colors[ii % 3]; //initialize all to red
     strip.setPixelColor(ii, frame[ii]);
    }
    strip.show();
  */

  if (upindex > NUMPIXELS)
  {
    upindex = 0;
  }
  if (downindex < 0)
  {
    downindex = NUMPIXELS;
  }
  upindex++;
  downindex--;

  frame[upindex - 1] = 0x000000;
  frame[upindex] = 0xFFFFFF;
  strip.setPixelColor(upindex - 1, frame[upindex - 1]);
  strip.setPixelColor(upindex, frame[upindex]);


  frame[downindex + 1] = 0x000000;
  frame[downindex] = 0xFFFFFF;
  strip.setPixelColor(downindex + 1, frame[downindex + 1]);
  strip.setPixelColor(downindex, frame[downindex]);

  strip.show();
  delay(100);



}
