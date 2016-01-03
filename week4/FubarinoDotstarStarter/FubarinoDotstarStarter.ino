
#include <Adafruit_DotStar.h>
#include <SPI.h>         //comment out for softwareSPI
//#include <SoftSPI.h> //uncomment to use non standard pins

#define DATAPIN    27
#define CLOCKPIN   29
#define NUMPIXELS 30 // Number of LEDs in strip

uint32_t stripcolors[NUMPIXELS];
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);


typedef struct rgbColor
{
  uint8_t red, green, blue;
} rgbColor;

rgbColor color;

//Issue convert RGB to Hex and Hex to RGB
//http://stackoverflow.com/questions/3723846/convert-from-hex-color-to-rgb-struct-in-c
rgbColor colorConverter(int hexValue)
{
  //struct RGB rgbColor;
  color.red = ((hexValue >> 16) & 0xFF) / 255.0;  // Extract the RR byte
  color.green = ((hexValue >> 8) & 0xFF) / 255.0;   // Extract the GG byte
  color.blue = ((hexValue) & 0xFF) / 255.0;        // Extract the BB byte

  return color;
}

uint32_t rgb2hex (rgbColor color) {
  uint32_t hexVal;
  char tmp = {color.green, color.blue, color.red};
  hexVal = 
  return hexval;
}

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

