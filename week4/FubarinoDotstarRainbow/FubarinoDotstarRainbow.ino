
#include <Adafruit_DotStar.h>
#include <SPI.h>         //comment out for softwareSPI
//#include <SoftSPI.h> //uncomment to use non standard pins

#define DATAPIN    27
#define CLOCKPIN   29
#define NUMPIXELS 30 // Number of LEDs in strip

uint32_t stripcolors[NUMPIXELS];
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);


typedef struct rgb_color
  {
    uint8_t red, green, blue;
  } rgb_color;

rgb_color colors[NUMPIXELS];


void setup() {
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
}

void loop() {
  uint8_t time = millis() >> 4;

  for (int ii = 0; ii <  NUMPIXELS; ii++) {  
     byte x = time - ii * 8;
     colors[ii] = hsvToRgb((uint32_t)x * 359 / 256, 255, 255);
     strip.setPixelColor(ii, colors[ii]); 
  }
  strip.show();                     // Refresh strip
  delay(20);
}

//From the APA 102 library rainbow example
// Converts a color from HSV to RGB.
// h is hue, as a number between 0 and 360.
// s is the saturation, as a number between 0 and 255.
// v is the value, as a number between 0 and 255.
rgb_color hsvToRgb(uint16_t h, uint8_t s, uint8_t v)
{
    uint8_t f = (h % 60) * 255 / 60;
    uint8_t p = (255 - s) * (uint16_t)v / 255;
    uint8_t q = (255 - f * (uint16_t)s / 255) * (uint16_t)v / 255;
    uint8_t t = (255 - (255 - f) * (uint16_t)s / 255) * (uint16_t)v / 255;
    uint8_t r = 0, g = 0, b = 0;
    switch((h / 60) % 6){
        case 0: r = v; g = t; b = p; break;
        case 1: r = q; g = v; b = p; break;
        case 2: r = p; g = v; b = t; break;
        case 3: r = p; g = q; b = v; break;
        case 4: r = t; g = p; b = v; break;
        case 5: r = v; g = p; b = q; break;
    }
    return (rgb_color){r, g, b};
}
