#Circuit Sunday 1

Circuit Sunday week 1

 The goal of Circuit Sunday week 1 is  to become familiar with the Arduino environment and to become familiar with the Fubarino boards, http://fubarino.org,  these boards are Arduino compatible boards that were designed here at Fubar Labs and in conjunction with Brian Schmalz. They are part of the chipKIT project. The chipKIT project is an arduino-compatible environment that uses the pic32 chip from Microchip.
 
So first thing you want to do is go to the Arduino main page http://arduino.cc once there you need to download the Arduino IDE. This is the integrated development environment that allows you to compile the code and uploaded it on to any Arduino compatible board.

This environment is compatible with Mac, Linux, and Windows.  Once Arduino is installed on your machine. We have to go get the chipKIT core.  This core can be found at http://chipkit.net/wiki. 

The chipKIT core needs to be extract into your Documents/arduino/hardware folder. If that folder not available you will have to create it and then extract core into it.

Now that the software is in place we need to check out the physical hardware.   For this workshop we use the Fubarino boards. They are the Fubarino Mini or the Fubarino SD boards both can be used for the class.  everything is arduino-compatible so what you learn can be used on any arduino-compatible board with the Arduino IDE. 

The boards have an on board LED and on board programming button.  The first project is going to be blinking the onboard led. This is the equivalent of Hello world. It tells us that the hardware is working and that we can program a sketch onto the board.  the next thing we want to look at is the onboard button and bored button is used to take input from the real world and we figure out from there how to take input that's digital like off and on and perform actions.

* Blink Sketch
* Button Sketch

The last portion is using the board to talk serial information. We learn how to send information from the computer to the board and from the board back to the human on the computer.

* HelloSerial Sketch

That's it for today. next week will do input and output with serial and we'll start integrating our board with electronics.

