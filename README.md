# MewPro Iliad 3plusB
Sync Generator/Controller for Hero 3+ Black and MewPro.

### Supported MewPro boards

All MewPro boards including older MewPro 1 w/ Arduino Pro Mini or Teensy or GR-Kurumi, and newer MewPro 2 or MewPro Cable work with MewPro Iliad.

### Supported video modes

All the video modes that GoPro Hero 3+ Black can shoot are supported. Also timelapse photography is supported with genlock.

# How To Update Iliad Software

MewPro Iliad uses Seeed Studio's Seeeduino Mega (Arduino Mega 2560 enhanced clone). We implemented these sync functionality to Arduino environment simply because it's very popular and very well-documented especially in entry-level tutorials.  So before asking something to us please google your question by yourself.

The following is a brief guide on how to update Iliad.

- Step 1. Download Arduino IDE from <https://www.arduino.cc/en/main/software>. For installation instructions please refer [the Getting Started page](https://www.arduino.cc/en/Guide/HomePage) in this same site.
- Step 2. Download Iliad source code from our GitHub repo <https://github.com/orangkucing/MewPro_Iliad>, and unzip it to some folder/directory.
- Step 3. Download the following Arduino libraries:
 * **IRremote library** at <https://github.com/z3t0/Arduino-IRremote>. (_Note: The IRremote library conflicts with RobotIRremote library in the standard Arduino IDE. So please delete_ "your IDE installation folder"_/Contents/Java/libraries/RobotIRremote_)
 * **RTClib** at <https://learn.adafruit.com/adafruit-ds3231-precision-rtc-breakout/wiring-and-test>.
- Step 4. Install the above downloaded libraries (To install Arduino Library please refer [this page](https://www.arduino.cc/en/Guide/Libraries)).
- Step 5. Compile Iliad source code and upload it to Seeeduino Mega. (In Arduino IDE, set [Tools]->[Board] to "Arduino/Genuino Mega or Mega 2560", [Tools]->[Processor] to "Atmega2560 (Mega 2560)", [Tools]->[Port] to your serial port that Seeeduino Mega is connected.)
- Step 6. Enjoy!
