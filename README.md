# Thermocouple: MATLAB + Arduino
A simple sketch to demonstrate an interface between an Arduino and MATLAB, specifically for data-logging in MATLAB. This particular example utilizes this for creating a thermometer.

# Framework:
Since we are using MATLAB to log (and maybe further manipulate) data, we need to use scripts on both sides. The Arduino script (Serial_matlab_thermocouple.ide) configures it to read temperature from the thermocouple (interfaced with an amplifier), and print it (in degree C) on the serial port. The MATLAB script (MATLAB_thermocouple.m) timestamps this incoming data, and stores it in an array. The codes are set to read, transmit and log data in an infinite loop, and Ctrl + C should be used in MATLAB to stop data logging. A simple circuit can be used to use a pushbutton to print something else on the serial port, which MATLAB recognizes as a break signal. 

# Bill of materials:
1. [Arduino (any model is fine, this uses Uno)](http://www.amazon.com/Arduino-UNO-board-DIP-ATmega328P/dp/B006H06TVG/ref=sr_1_2?ie=UTF8&qid=1443497146&sr=8-2&keywords=arduino)

2. [Thermocouple amplifier MAX31855](https://www.adafruit.com/products/269) To get cleaner, more accurate signal. Highly recommended

3. [K-junction thermocouple](https://www.adafruit.com/products/270) Investing in a glass-braided one is recommended if used for high temperature applications
4. [Momentary push button](http://www.amazon.com/Panel-Momentary-Tactile-Button-Switch/dp/B005YX046I/ref=sr_1_11?ie=UTF8&qid=1442873639&sr=8-11&keywords=momentary+push+button)

# Circuit:
Assemble the circuit according to the following schematics:
![TTL Trigger circuit](/Circuit/Thermocouple.png "Thermocouple with a MAX31855 breakout board")

# Calibration:
The MAX31855 is factory calibrated. See datasheet for calibration notes. Alternatively, a calibration curve is usually obtained by linearly fitting readings from boiling and ice water. 

# Further development: 
Something like a wifi module with arduino can unleash this simple setup into a wireless thermocouple, say to be used in sealed experiments!

