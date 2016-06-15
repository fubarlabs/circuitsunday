
#include <Adafruit_DotStar.h>
#include <SPI.h>         //comment out for softwareSPI
//#include <SoftSPI.h> //uncomment to use non standard pins

#define DATAPIN    MISO
#define CLOCKPIN   MOSI
#define NUMPIXELS 30 // Number of LEDs in strip

#define red  0xFF0000
#define green  0x00FF00
#define blue  0x0000FF

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

  for (int ii = 0; ii < NUMPIXELS; ii++) {
    if (ii == 0)
    {
      frame[ii] = 0xFFFFFF;
      strip.setPixelColor(ii, frame[ii]);
      strip.show();
      delay(100);
    }
    else
    {
      frame[ii - 1] = 0x000000;
      frame[ii] = 0xFFFFFF;
      strip.setPixelColor(ii - 1, frame[ii - 1]);
      strip.setPixelColor(ii, frame[ii]);
      strip.show();
      delay(100);
    }


    for (int ii = NUMPIXELS; ii < 0; ii--) {
      if (ii == 30)
      {
        frame[ii] = 0xFFFFFF;
        strip.setPixelColor(ii, frame[ii]);
        strip.show();
        delay(100);
      }
      else
      {
        frame[ii + 1] = 0x000000;
        frame[ii] = 0xFFFFFF;
        strip.setPixelColor(ii + 1, frame[ii + 1]);
        strip.setPixelColor(ii, frame[ii]);
        strip.show();
        delay(100);
      }
    }
  }
}

