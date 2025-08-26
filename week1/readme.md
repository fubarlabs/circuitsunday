# Circuit Sunday 1 - ESP32 Edition
## Session One: Kicking the Tires and Talking to Your Hardware

**Code Chat: Discord/Slack/Gitter IM**

The goal of Circuit Sunday week 1 is to become familiar with the Arduino environment and to get comfortable working with ESP32 development boards. The ESP32 is a powerful, low-cost microcontroller with built-in Wi-Fi and Bluetooth capabilities, making it perfect for IoT projects and general embedded development.

## Getting Started with Arduino IDE

First, go to the Arduino main page at https://arduino.cc and download the Arduino IDE. This is the integrated development environment that allows you to compile code and upload it to any Arduino-compatible board, including the ESP32.

The Arduino IDE is compatible with Mac, Linux, and Windows. Once Arduino is installed on your machine, we need to add ESP32 support.

## Adding ESP32 Support to Arduino IDE

To work with ESP32 boards, we need to install the ESP32 core:

1. Open Arduino IDE
2. Go to **File > Preferences**
3. In the "Additional Board Manager URLs" field, add:
   ```
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
   ```
4. Go to **Tools > Board > Board Manager**
5. Search for "ESP32" and install "esp32 by Espressif Systems"
6. After installation, you'll find ESP32 boards under **Tools > Board > ESP32 Arduino**

## Hardware Overview

For this workshop, we'll use ESP32 development boards (such as ESP32 DevKit, NodeMCU-32S, or similar). These boards are Arduino-compatible, so everything you learn can be applied to other Arduino-compatible boards as well.

Most ESP32 development boards feature:
- Built-in LED (usually connected to GPIO 2)
- Built-in BOOT button (GPIO 0) 
- EN (Reset) button
- USB-to-Serial converter for programming
- Wi-Fi and Bluetooth capabilities

## First Projects

### 1. Blink Sketch
Our first project will be blinking the onboard LED. This is the embedded equivalent of "Hello World" - it tells us that the hardware is working and we can successfully program the board.

The built-in LED is typically connected to GPIO 2 on most ESP32 boards.

### 2. Button Sketch  
Next, we'll work with the onboard BOOT button. This button allows us to take digital input from the real world (on/off states) and perform actions based on that input.

The BOOT button is connected to GPIO 0 and is pulled high by default (reads HIGH when not pressed, LOW when pressed).

### 3. HelloSerial Sketch
Finally, we'll learn to communicate with the board using serial communication. We'll send information from the computer to the board and from the board back to the computer, establishing two-way communication.

The ESP32 communicates over USB serial at 115200 baud by default.

## What's Next?

That's it for today! Next week we'll dive deeper into input and output operations, explore the ESP32's unique features like Wi-Fi connectivity, and start integrating our board with external electronics and sensors.

## Bonus: ESP32 Advantages
Unlike traditional Arduino boards, the ESP32 offers:
- Built-in Wi-Fi and Bluetooth
- Dual-core processor
- More GPIO pins
- Built-in DAC and ADC
- Touch-sensitive pins
- Hardware cryptographic acceleration

* HelloSerial Sketch

That's it for today. next week will do input and output with serial and we'll start integrating our board with electronics.

