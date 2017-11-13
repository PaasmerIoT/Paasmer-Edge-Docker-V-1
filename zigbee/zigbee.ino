/*for DHT sensor
Please download the DHT library from teh below link.

https://drive.google.com/file/d/0B1paTI5fzcHodno5azFOSVVDT0E/view?usp=sharing

Go to Sketch--> Include Library --> Add Zip File

Close the Arduino IDE and open it again tan you will find the library included.

*/

#include"config.h"  
#include "paasmer.h"

int feedLength;

void setup()
{

  Serial.begin(9600);
  int i;
  feedLength = sizeof(feedname)/sizeof(feedname[0]);
  for (i=0;i < feedLength;i++)
  {
    if (feedtype[i] == "sensor")
    {
      //Serial.println(sensortype[i]);
      if (sensortype[i] == "ultrasonic")
      {
        pinMode(feedpin[i][0], OUTPUT);
        pinMode(feedpin[i][1], INPUT);
      }
      else if (sensortype[i] == "Memsic2125")
      {
        pinMode(feedpin[i][0], INPUT);
      }
      else if (sensortype[i] == "digital")
      {
        pinMode(feedpin[i][0], INPUT);
      }
    }
    else
    {
      //Serial.println(feedpin[i][0]);
      pinMode(feedpin[i][0], OUTPUT);
    }
   //delay(1000);
  }
}

void loop()
{
  int b,j,i=0;
  String x,c,a,y;
  if (a=Serial.readStringUntil('*'))
   for (i=0;i < feedLength;i++)
   {
      if (a.startsWith(feedname[i]))
      {
        //Serial.println("substring is there");
        if (a.endsWith("read"))
        {
          if (sensortype[i] == "digital")
          {
            Serial.println(sensor_read(feedpin[i][0]));
          }
          else if (sensortype[i] == "analog")
          {
            Serial.println(int(analogRead(feedpin[i][0])));
          }
          else if (sensortype[i] == "ultrasonic")
          {
            //Serial.println("it is ultrasonic sensor");
            //Serial.println("the distance in cm is ");
            Serial.println(Readultrasonic(feedpin[i][0],feedpin[i][1]));
          }
          else if (sensortype[i] == "Memsic2125")
          {
            //Serial.println("it is memsic2125");
            Serial.println(ReadMemsic2125(feedpin[i][0]));
          }
          else if (sensortype[i] == "ADXL3xx")
          {
            //Serial.println("it is ADXL3xx");
            Serial.println(ReadADXL3xx(feedpin[i][0]));
          }
          else if (sensortype[i] == "photoresistor")
          {
            //Serial.println("it is photoresistor");
            Serial.println(int(Readphotoresistor(feedpin[i][0])));
          }
          else if (sensortype[i] == "LM35")
          {
            //Serial.println("it is LM35");
            Serial.println(ReadLM35(feedpin[i][0]));
          }
          else if (sensortype[i] == "DHT11humidity")
          {
            //Serial.println("it is DHT11humidity");
            Serial.println(ReadDHTHumidity(feedpin[i][0]));
          }
          else if (sensortype[i] == "DHT11temperature")
          {
            //Serial.println("it is DHT11temperature");
            Serial.println(ReadDHTTemp(feedpin[i][0]));
          }
          else if (sensortype[i] == "Thermister")
          {
            //Serial.println("it is thermister");
            Serial.println(int(ReadThermistor(analogRead(feedpin[i][0]))));
          }
            
        }
        else if (a.endsWith("on"))
        {
          sensor_write(feedpin[i][0],HIGH);
          //Serial.println(feedname[i]);
        }
        else if (a.endsWith("off"))
        {
          sensor_write(feedpin[i][0],LOW);
          //Serial.println(feedname[i]);
        }
        break;
      }
   }
   //delay(2000);
   delay(50);
}

int sensor_read(int pin)
{
  int a ;
  a=digitalRead(pin);
  return a;
}

void sensor_write(int pin,int state)
{
  digitalWrite(pin,state);
}
