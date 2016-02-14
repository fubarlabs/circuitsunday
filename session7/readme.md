#Session 7

##Dallas One Wire Temperature

We'll be working with Dallas One Wire Temperature Sensor: Maxim MAX31820. Details on the sesnor are here: https://www.maximintegrated.com/en/products/analog/sensors-and-sensor-interface/MAX31820.html

Review of the OneWire protocol. What kinds of devices in addtiion to temperature sensors can be used. Then focus on the Dallas OneWire sensor.


##Data Sheet
[Dallas OneWire 3v Temperature Sensor](https://www.maximintegrated.com/en/products/analog/sensors-and-sensor-interface/MAX31820.html#popuppdf)

##Wiring Diagrams

* Fuabrino Mini
![Fuabrino Mini MAX31820 Wiring Diagram](/session7/FubarinoMiniOneWire_bb.png)

* Fubarino SD
![Fuabrino SD MAX31820 Wiring Diagram](/session7/FubarinoSDOneWire_bb.png)

##Concept


###Code Review
* OneWire library https://github.com/PaulStoffregen/OneWire
* Dallas Temperature Control Library: http://milesburton.com/Main_Page?title=Dallas_Temperature_Control_Library
* How to install the libraries
* Program the Hello World  sketch
* Debug the wiring
* Debug the code
* SerialExplorer for the temparuter sensors
 * Find all the sensors in the chain
 * Select a sensor and print it's temperaure
 

###Custom Code
* Show temperature data on an LCD Display
* Trigger events based on various temperatures
* Possible MQTT data format for the output

