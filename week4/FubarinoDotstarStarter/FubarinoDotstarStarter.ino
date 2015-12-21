
#include <Adafruit_DotStar.h>
#include <SPI.h>         //comment out for softwareSPI
//#include <SoftSPI.h> //uncomment to use non standard pins

#define DATAPIN    27
#define CLOCKPIN   29
#define NUMPIXELS 30 // Number of LEDs in strip

uint32_t stripcolors[NUMPIXELS];
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);


void setup() {
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP

  //initialize strip array
  for (int ii = 0; ii < NUMPIXELS; ii++) {
    stripcolors[ii] = 0xFF0000; //initialize all to red
  }
}

void loop() {
  for (int ii = 0; ii <  NUMPIXELS; ii++) {  
    strip.setPixelColor(ii, stripcolors[ii]); 
  }
  strip.show();                     // Refresh strip
  delay(20);
}
