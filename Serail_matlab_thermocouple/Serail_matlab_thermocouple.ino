#include <SPI.h>
#include "Adafruit_MAX31855.h"

// Default connection is using software SPI, but comment and uncomment one of
// the two examples below to switch between software SPI and hardware SPI:

// Example creating a thermocouple instance with software SPI on any three
// digital IO pins.
#define DO   3
#define CS   4
#define CLK  5
Adafruit_MAX31855 thermocouple(CLK, CS, DO);

// Example creating a thermocouple instance with hardware SPI (Uno/Mega only)
// on a given CS pin.
//#define CS   4
//Adafruit_MAX31855 thermocouple(CS);

void setup() {
  Serial.begin(9600);
  delay(500);
}

void loop() {
   // basic readout test, just print the current temp
   //Serial.print("Internal Temp = ");
   //Internal temperature
   //Serial.println(thermocouple.readInternal());
   double c = thermocouple.readCelsius();
   if (isnan(c)) {
     Serial.println("Something wrong with thermocouple!");
   } else {
     //Serial.print("C = "); 
     Serial.println(c);
   }
   //Serial.print("F = ");
   //Serial.println(thermocouple.readFarenheit());
 
   delay(1000);
}
