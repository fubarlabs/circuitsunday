#Session 7

##Dallas One Wire Temperature

We'll be working with Dallas One Wire Temperature Sensor: Maxim MAX31820. Details on the sesnor are here: https://www.maximintegrated.com/en/products/analog/sensors-and-sensor-interface/MAX31820.html

I'll have several available. We will solder the pins on to a header, place it in a breadboard, and then wire it up. We'll use the Arduino LCD library and adjust the red, green, blue background colors.

Last part of the workshop is show the Temperature on the display is the RGB 16x2 display from Adafruit: https://www.adafruit.com/products/399


##Data Sheet
[Dallas OneWire 3v Temperature Sensor](https://www.maximintegrated.com/en/products/analog/sensors-and-sensor-interface/MAX31820.html#popuppdf)

##Wiring Diagrams

* Fuabrino Mini
![Fuabrino Mini MAX31820 Wiring Diagram](/session7/)

* Fubarino SD
![Fuabrino SD MAX31820 Wiring Diagram](/session7/)

##Concept


###Code Review
* Paul Stoffregen OneWire library https://github.com/PaulStoffregen/OneWire
* How to install the library
* Program the Hello World  sketch
* Debug the wiring
* Debug the code

###Custom Code
* Show temperature data on an LCD Display
* Trigger events based on various temperatures
