#Session 6

##Liquic Crystal Character Display (LCD)

We'll be working with LCD Displays. The display is the RGB 16x2 display from Adafruit: https://www.adafruit.com/products/399

I'll have several available. We will solder the pins on to a header, place it in a breadboard, and then wire it up. We'll use the Arduino LCD library and adjust the red, green, blue background colors.

We need to get things set up like the previous session. Here's all the info on that.

##Data Sheet
[LCD Data Sheet](https://www.adafruit.com/datasheets/HD44780.pdf)

##Wiring Diagrams

* Fuabrino Mini
![Fuabrino Mini LCD Wiring Diagram](/session6/FubarinoMiniLCD_bb.png)
![Fuabrino Mini Full Breadboard LCD Wiring Diagram](/session6/FubarinoMiniLCDFullSize_bb.png)


* Fubarino SD
![Fuabrino SD LCD Wiring Diagram](/session6/)

##Concept


###Code Review
* Arduino LCD library https://www.arduino.cc/en/Reference/LiquidCrystal
* How to install the library
* Program the Hello World LCD sketch
* Debug the wiring
* Debug the code

###Custom Code
* Print characters and messages to the display
* Control the RGB background colors
* Print information from the serial interface to the screen
* Create custom characters
* Create simple animation
* Bonus: Add the texture adventure to use the display
