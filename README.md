# Arduino Core for Theia Space's ESAT Boards (STM32L4)

These are the support files needed to use Theia Space's STM32L4-based ESAT boards with Arduino.

Use Arduino 1.8.0 or newer.


## Supported boards

ESAT ADCS.


## Installing

### Board Manager

 1. [Download and install the Arduino IDE](https://www.arduino.cc/en/Main/Software) (at least version v1.6.8)
 2. Start the Arduino IDE
 3. Go into Preferences
 4. Add ```http://www.theiaspace.com/wp-content/uploads/ESAT/package_esat_index.json``` as an "Additional Board Manager URL"
 5. Open the Boards Manager from the Tools -> Board menu and install "Theia Space's ESAT boards (STM32L4)"
 6. Select your board from the Tools -> Board menu

#### OS Specific Setup

##### Linux

 1. Go to ~/.arduino15/packages/ESAT/hardware/stm32l4/```<VERSION>```/drivers/linux/
 2. sudo cp *.rules /etc/udev/rules.d

#####  Windows

###### USB Serial driver setup for Tlera Corp boards (Window XP / Windows 7 only)

 1. Go to ~/AppData/Local/Arduino15/packages/ESAT/hardware/stm32l4/```<VERSION>```/drivers/windows
 2. Right-click on ```dpinst_x86.exe``` (32 bit Windows) or ```dpinst_amd64.exe``` (64 bit Windows) and select ```Run as administrator```
 3. Click on ```Install this driver software anyway``` at the ```Windows Security``` popup as the driver is unsigned

## Credits

This core is a fork of the [Arduino Core for STM32L4 based boards by Thomas Roell](), which is based on [Arduino SAMD Core](https://github.com/arduino/ArduinoCore-samd)

