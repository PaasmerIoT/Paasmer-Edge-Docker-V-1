#include <dht.h>
#include <math.h>

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
} 
int Readultrasonic(int trig,int echo)
{
 long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  //pinMode(pingPin, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  //pinMode(pingPin, INPUT);
  duration = pulseIn(echo, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  //Serial.print(inches);
  //Serial.print("in, ");
  //Serial.print(cm);
  //Serial.print("cm");
  //Serial.println();

  //delay(100);
  return int(cm);
}

int ReadMemsic2125(int pin){
  
  int pulse,acceleration;

  pulse = pulseIn(pin, HIGH);
  
  acceleration = ((pulse / 10) - 500) * 8;

  return int(acceleration);
}

float ReadADXL3xx(int pin){
  return int(analogRead(pin));
}
float Readphotoresistor(int pin){
  return int(analogRead(pin));
}
float ReadLM35(int pin){
  int val = analogRead(pin);
  float mv = (val/1024.0)*5000;
  float cel = mv/10;
  return int(cel);
}
float ReadDHTHumidity(int pin){
  dht DHT;
  int chk = DHT.read11(pin);
  return int(DHT.humidity);
}
float ReadDHTTemp(int pin){
  dht DHT;
  int chk = DHT.read11(pin);
  return int(DHT.temperature);
}
double ReadThermistor(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
//         =log(10000.0/(1024.0/RawADC-1)) // for pull-up configuration
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;            // Convert Kelvin to Celcius
 //Temp = (Temp * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
 return int(Temp);
}

