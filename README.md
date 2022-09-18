[![BR-M5 | Open-Source Bluetooth Remote for Canon DSLRs](./.github/cover.png)](https://youtu.be/Gh5uEc2dNJM "BR-M5 | Open-Source Bluetooth Remote for Canon DSLRs")

# BR-M5: An open-source Bluetooth Remote for Canon DSLRs

This Bluetooth remote aims to replicate Canon's BR-E1 behavior while adding key features like fully programable time-lapses that most Canon cameras lack! Fortunately, *M5Stack* proposes a nice little inexpensive development board that perfectly fits our needs, the [M5Stick-Cplus](https://m5stack.com/products/m5stickc-plus-esp32-pico-mini-iot-development-kit?variant=35275856609444).

The BR-M5 has been primarily developed for the Canon M50 Mark I, which misses a descent timelapse mode that can do long exposures. The shutter speed option in M50's timelapse mode is indeed limited to 1/30s. Furthermore, the M50 doesn't have any shutter release port to plug classic intervalometers. No official Bluetooth, WiFi, or tethering tools currently offer time-lapse capabilities.

## Installation

* Install [Visual Studio Code](https://code.visualstudio.com/download) and the [PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) extension.
* Clone this repository - ```git clone https://github.com/ArthurFDLR/br-m5``` -, open it as project in PlatformIO and upload - ```Ctrl+Alt+u``` - to a M5Stick-Cplus connected to your PC.

### Linux Installation

Download Arduio IDE zip from: https://www.arduino.cc/
In the arduino ide add 'aditional boards' (Instructions in https://docs.m5stack.com/en/quick_start/m5stickc_plus/arduino )
Add 'M5Stack' board and M5Stack library to Arduino IDE

Install any aditional python packages using linux package manager
e.g: serial
```
yay -S python-pyserial
```

#### No Permission to write to /dev/ttyUSB0
Arduino might throw permission issue while uploading to M5Stick cplus

Find the group using:
```
$ ls -l /dev/ttyUSB0
crw-rw---- 1 root uucp 188, 0 Sep 18 17:46 /dev/ttyUSB0
```

Add your username to the group
e.g
```
sudo usermod -a -G dialout <username>
```

#### Compiling in Arduino IDE

Add libraries

1. Lib1: https://github.com/rpolitex/ArduinoNvs
1a Download zip from github
1b Import in IDE using Sketch > import lib... > add lib...

2. Lib2: https://github.com/ArthurFDLR/BR-M5
2a. Copy all folders under /lib to ~/Arduino/libraries

## How-To-Use

Youtube Tutorial: https://www.youtube.com/watch?v=ZZdTl0400uM

* Power on by pressing the left-side button and power off with a 6 seconds press on the same button.
* Keep pressing BtnA (The main button below screen) to activate the bluetooth pairing mode.
* You can connect to your Canon DSLR as soon as the remote is powered on and displays *Pairing in progress*.
* Once connected, to use the remote the camera need to be in the right 'shooting mode'
  * Set to corret mode using: Menu > Camera > 4 > Drive Mode > remote icon
* To change the interval, press the right-side button for half a second and use the same button to increase and the center button to decrease the timelapse interval. Once set, press the right-side button for half a second again.
* Start and stop time-lapses using the center button. The remote takes single shots if the interval is set to 0 seconds.

## To-do

- [x] Fix connection reliability issues.
- [x] Auto connection to camera when remote start-up.
- [ ] Add battery level indication.

Feel free to contribute!
