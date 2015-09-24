clear all
close all

%%User input for a COM port
prompt = ('Enter the COM port on which Arduino is connected, for ex. COM5 (include colons)');
port = input(prompt);
arduino = serial(port); %%Arduino board COM port
fopen(arduino); %%Open the port

%%Open a file and a plot for recording data
h = 'plotrealtime';
path = 'C:\Users\Nakul\Documents\temperaturelog\';
file = 'temperature log';

test = fscanf(arduino);
pause(2);

j = 1;
while(true);
    Log.timestamp(j, :) = clock; %%Timestamp including date and time
    Log.date(j, :) = date; %%Get a string variable for the date
    Log.time(j, :) = Log.timestamp(1, 4:6); %%Read the time
    serial_temp = fscanf(arduino); %%Read the temperature in C
    Log.temperature(j, :) = serial_temp;
%     if strcmp(h,'plotrealtime')
%                 plot(Log.time(j, :),Log.temperature(j, :), '.r', 'MarkerSize',10);
%                 hold on;
%                 xlabel('Time (seconds)')
%                 ylabel('Data')
%                 drawnow
%     end
    j = j + 1;
    pause(1);
end