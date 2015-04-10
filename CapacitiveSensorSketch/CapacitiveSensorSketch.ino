#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil


const int numReadings = 40;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
int inputPin = A0;



void setup()                    
{
  //cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
}

void loop()                    
{

reflectivesensor = analogRead(inputPin); 

  long start = millis();
  long total1 =  cs_4_2.capacitiveSensor(30);
  
  
//   // subtract the last reading:
//  total= total - readings[index];         
//  // read from the sensor:  
//  readings[index] = total1; 
//  // add the reading to the total:
//  total= total + readings[index];       
//  // advance to the next position in the array:  
//  index = index + 1;                    
//
//  // if we're at the end of the array...
//  if (index >= numReadings)              
//    // ...wrap around to the beginning: 
//    index = 0;                           
//
//  // calculate the average:
//  average = total / numReadings;         
//  // send it to the computer as ASCII digits
  Serial.print("\t"); 
  Serial.print("\t"); 
   Serial.print ("average:  ");
  Serial.println(reflectivesensor);  



  //Serial.print(millis() - start);        // check on performance in milliseconds
 // Serial.print("\t");                    // tab character for debug windown spacing

  //int mappedvalue = (total1,71000,80000,0,100); 
  Serial.print ("raw data:  ");
  Serial.println(total1);                  // print sensor output 1
 // Serial.print("\t");
  // print sensor output 2
 // Serial.print("\t");
  // print sensor output 3

  delay(50);                             // arbitrary delay to limit data to serial port 
}

