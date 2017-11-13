String feedname[]={"feed4","feed6","feed7","feed5"};

String feedtype[]={"sensor","actuator","sensor","sensor"};

String connectiontype[]= {"zigbee","zigbee","zigbee","zigbee"};

String sensortype[] = {"digital","digital","Thermister","photoresistor"};

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
