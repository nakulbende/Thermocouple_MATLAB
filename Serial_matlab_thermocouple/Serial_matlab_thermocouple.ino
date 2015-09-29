/*
  MATLAB Thermocouple, to be used in conjugation with MATLAB. 

  This code when uploaded to an Arduino circuit, will print the temperature readout form a thermocouple to the serial port.
  The companion script for MATLAB https://github.com/nakulbende/Thermocouple_MATLAB can be used to log this into a timestamped datasheet.

  modified 09/24/2015
  by Nakul Bende
*/

#include <SPI.h>
#include "Adafruit_MAX31855.h" //Using the MAX31855 breakout board.

// Default connection is using software SPI, but comment and uncomment one of
// the two examples below to switch between software SPI and hardware SPI:

// Example creating a thermocouple instance with software SPI on any three
// digital IO pins. The CD, CLK pins will change according to what board you use.
#define DO   3
#define SDA  4 //for Uno
#define SCL  5 //for Uno
Adafruit_MAX31855 thermocouple(SCL, SDA, DO);

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
