#Session 5

##More Fast LED strips the Dotstar and apa102x

The goal for this session is to learn to use Arrays. Configure common led strips. Then use arrays to create custom animations for the holidays or incorporate into your own projects.

We need to get things set up like the previous session. Here's all the info on that.

##Data Sheet
[Dotstar/Apa102 Data Sheet](/week4/APA102.pdf)

##Wiring Diagrams

* Fuabrino Mini
![GitHub Logo](/week4/FubarinoMiniDotStarWiring_bb.png)

* Fubarino SD
![GitHub Logo](/week4/FubarinoSDDotStarWiring_bb.png)

##Concept ARRAYS

A movie is a collection of still images called frames. In order to animate the
LED strips we need to create a frame of leds and their settings. Then we need to load the next frame of led states. We need to know how many items are in a frame. Like how many pixels are in a single frame. Pixels in a frame are a collection of red, green, and blue. The combination of brightness of of each color is mixed to show an image.

Last time we used the apa102c led strips. We load the color values for each led in the strip. We used a for loop to change the colors of each. We used a manually method of building the frame via shiftOUT and then a library that allows us to just build the game and refresh the list.

TO create an animation we'll create a frame using and array. Each entry in the array will correspond to a pixel. The array will the store the color of each pixel. Then to create the animation we'll refresh the led strip with colors stored in the array.

Array details:

1. They can hold any data type
2. They start at 0 and end at define integer
3. They can be multi dimensional
4. They can hold custom data type like structures and objects

How do we declare an array?



###Code Review
* Adafruit Dotstar library https://learn.adafruit.com/adafruit-dotstar-leds/overview
* How to install the library
* Program the test strip sketch
* Debug the strip
  * SoftSPI and Hardware SPI
  * Determine number of LEDS

###Custom Code
* Light leds in various patterns
* Control the colors
* Create animations
