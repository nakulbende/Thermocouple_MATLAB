%% Communicating with an Arduino. 
% This script uses an arduino programmed, and connected with a thermocouple
% using 'Serail_matlab_thermocouple.ino' you can find at
% "https://github.com/nakulbende/Thermocouple_MATLAB". 

% This logs the temperature in C, along with a timestamp.

%Updated by Nakul Bende
%24 Spet 2015

clear all
close all

%%User input for a COM port: Connect matlab with the arduino through serial
%%port communication
prompt = ('Enter the COM port on which Arduino is connected, for ex. ''COM5'' (include colons)');
port = input(prompt);
arduino = serial(port); %%Arduino board COM port
fopen(arduino); %%Open the port

test = fscanf(arduino);
pause(2);

j = 1;
while(true); %%This is a infinite loop, so press Ctrl + C to stop it, and access the data.
    Log.timestamp(j, :) = clock; %%Timestamp including date and time
    Log.date(j, :) = date; %%Get a string variable for the date
    Log.time(j, :) = Log.timestamp(1, 4:6); %%Read the time
    serial_temp = fscanf(arduino); %%Read the temperature in C
    Log.temperature(j, :) = serial_temp;
    j = j + 1;
    pause(1);
end