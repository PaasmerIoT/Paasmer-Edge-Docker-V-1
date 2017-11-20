# Paasmer-Edge-Docker-V-1
**Paasmer-Edge-Docker-V-1** for Raspberry-pi Running **Paasmer OS**.

## Overview

The **Paasmer-Edge-Docker-V-1** for Raspberry-pi Running **Paasmer OS** is a collection of Docker containers that enables you to do some analytics on edge and to connect to the Paasmer IoT Platform. This **Paasmer-Edge-Docker-V-1** is equipped with Zigbee support along with Board GPIO's.

## Paasmer OS
**Paasmer OS** is an attempt to make container based services available for embedded IoT devices. Currently, we only support the Raspberry-Pi. Support for other devices coming soon.

## Paasmer Edge Analytics 
**Paasmer Edge Analytics** is the key feature in Paasmer-Docker which provides you to do analytics on the sensor data. Presently we are providing filter algorithm, where you can filter your sensor data based on your filter condition. Support for More algorithms on analytics coming soon.

## Pre Requisties
Registration on the [PAASMER portal](http://developers.paasmer.co) is necessary to connect the devices to the **Paasmer IoT Platform**.

##  Optional Requisites
In order to use the Zigbee the following is required.

* Raspberry-Pi

* Arduino UNO Board.

* 2 ZigBee modules.

* XCTU Software installed on your system for ZigBee configuration. [XCTU software](https://www.digi.com/products/xbee-rf-solutions/xctu-software/xctu)

* Lastest version of Arduino IDE to installed on your computer. [Arduino software](https://www.arduino.cc/en/main/software)

# Installation

## ZigBee Configuration (Optional)

To establish, the ZigBee protocol the 2 ZigBee modules are to configured as a Coordinator and a Router. The ZigBee at the Raspberry-Pi side is to be configured as a Coordinator and the one at the Arduino side as a Router. Use XCTU software to Configure the ZigBee's as explained in the `ZigBEE_config.pdf` file.

The installation part is to be done in two parts, like

* Arduino 

* Raspberry-Pi
 
## Arduino 

* Open a new Sketch, Copy and Paste from the `ZigBee.ino` file in `<Arduino Sketch_DIR>/`.

* Connect the Arduino UNO board to your system, open the Arduino IDE and click on the `TOOLS` icon, select the `Board` as **Arduino/Genuino UNO** and select the port in which the board is connected in the `Port` option. 

* Also edit the `Config.h` in the Arduino Sketch similar to our `config.py` file in Single Board Computer. The code sample is as below,

```
String feedname[]={"feed4","feed6","feed7","feed5"};

String feedtype[]={"sensor","actuator","sensor","sensor"};

String connectiontype[]= {"zigbee","zigbee","zigbee","zigbee"};

String sensortype[] = {"temperature","digital","Thermister","photoresistor"};

int feedpin[][2]={{2},{4},{A0},{A1}};

/*
 * it supports few sensor types.
 * they are "digital, analog, ultrasonic, Memsic2125, ADXL3xx, photoresistor, LM35, DHT11humadity, DHT11temperature, Thermister"
 */

/* for DHT sensor
Please download the DHT library from teh below link.

https://drive.google.com/file/d/0B1paTI5fzcHodno5azFOSVVDT0E/view?usp=sharing

Go to Sketch--> Include Library --> Add Zip File

Close the Arduino IDE and open it again tan you will find the library included.
 */
```
* Save and Run the code in Arduino UNO.
* Connect the ZigBee Router device to the Arduino UNO as give below

| Arduino   | XBee |
| --------- | -----|
| 5V        | 5V   |
| GND       | GND  |
| TX        | RX   |
| RX        | TX   |

## Raspberry-Pi Installation

### OS Image Downloading

#### For Windows
* Download the zip file [click here](https://s3-us-west-2.amazonaws.com/paasmer-docker/paasmerOS.zip) and extract it.

#### For Linux
* Download the run file.[click here](https://s3-us-west-2.amazonaws.com/paasmer-docker/paasmerOS) to download.

* Run the file using the command.
```
$ sh paasmerOS
```
This will extract the customized Paasmer OS image to your home directory.

### Docker Initialization

* Flash the SD card with the ISO image.

* Insert the card into the Raspberry-Pi and boot it. Login with `Username: pi` and `Password: raspberry`

* Get started with RaspberryPi and [click here](https://thepihut.com/blogs/raspberry-pi-tutorials/83502916-how-to-setup-wifi-on-raspbian-jessie-lite) to setup WiFi connection.

* Navigate to paasmer-docker folder using the command.
```
cd /home/pi/paasmer-docker
```
* Edit the config.py file with feed details as root user.
```c
feedname=["feed7","Feed2","Feed4"]  # Modify with the required feednames, do not provide space in the feedname.

feedtype=["sensor","sensor","actuator"] # Mention the feedtype as sensor/ actuator

sensortype = ["Thermister","digital","digital"] # Mention the sensor type you used. RaspberryPi GPIO supports only digital.Zigbee supports the following. Use the below given string for your sensor type.
#"digital, analog, ultrasonic, Memsic2125, ADXL3xx, photoresistor, LM35, DHT11humadity, DHT11temperature, Thermister"

feedpin=[[2],[22],[7]] # Enter the pins numbers. Use Physical pins for RaspberryPi. If Zigbee use Arduino pin number(for analog pins please give 0-5).

connectiontype = ["zigbee","GPIO","GPIO"] # Mention the connection type either "zigbee" or "GPIO"

analytics = ["filter","none","none"] # Change the analytics to "filter" for Analytics or put "none" Note: Presently we are supporting filter for Alaytics. Further Analytics wil be delivered in the upcoming releases.

analyticsCondition = ["function(x) x > 3.0","",""] # Mention your analytics Condition example: "function(x) x < 8.0"

timePeriod = 5 #change the time delay(in seconds) as you required for sending sensor values to paasmer cloud

ser = 0 

ser = serial.Serial("/dev/ttyUSB0",9600) # Specify the port in which ZigBee is connected ( Un comment this line Only if Zigbee is used)
```
* Connect the ZigBee Coordinator device to the Single Board Computer through the USB2.0 cable. (Only if ZigBee is used)

* Run the start.sh
```
$ sudo ./start.sh
```
* This will ask for the UserName and DeviceName. The UserName is what you used in developers.paasmer.co for registration and give a unique DeviceName for your device and that must be alphanumeric without any spaces[a-z A-Z 0-9].

* Wohooo! Thats all. Your device should be connected to the Paasmer platform.

## Support

The support forum is hosted on the GitHub, issues can be identified by users and the Team from Paasmer would be taking up requests and resolving them. You could also send a mail to support@paasmer.co with the issue details for quick resolution.

## Note

* The Paasmer OS utilizes the features provided by raspbian OS and Docker engine.

