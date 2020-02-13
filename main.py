# SD Card Module

# PINS Connections
#    MISO    PIN 2
#    MOSI    PIN 15
#    CLK     PIN 14
#    CS      PIN 13


import machine
import uos
import json

# Struct for holding GPS Tracking Data
GPS_Data = {
    'latitude': 0,
    'longitude': 0,
    'year': 2020,
    'month': 1,
    'day': 11, 
    'hour':11, 
    'minute': 15,
    'second': 0
}

def main():
    SD_Card_UNIT_TEST()


# Unit Test for SD Card using Mock Data
def SD_Card_UNIT_TEST():

    uos.mount(machine.SDCard(slot=3), "/sdcard")  # Mount SD Card and use SPI peripheral 
    # Open File for Writing
    myFileName = "/sdcard/testfile.bin"
    f = open(myFileName, "wb")

    # Increment parameters
    GPS_Data['latitude'] = 0
    GPS_Data['longitude'] = 0
        
    GPS_Data['year'] = 0  
    GPS_Data['month'] = 0
    GPS_Data['day'] = 0

    GPS_Data['hour'] = 0
    GPS_Data['minute'] = 0
    GPS_Data['second'] = 0

    # Write to File
    sampleLength = 100
    write_log_header(f)
    for i in range(0, sampleLength-1):
        # Write data sample
        write_data_sample(f, GPS_Data)

        latitude = GPS_Data['latitude']
        longitude = GPS_Data['longitude']
        year = GPS_Data['year']
        month = GPS_Data['month']
        day = GPS_Data['day']
        hour = GPS_Data['hour']
        minute = GPS_Data['minute']
        second = GPS_Data['second'] 
        
        # Increment parameters
        GPS_Data['latitude'] += 1.1
        GPS_Data['longitude'] -= .1
        
        GPS_Data['year'] = 2020   
        GPS_Data['month'] = 1
        GPS_Data['day'] = 12

        GPS_Data['hour'] = 8
        GPS_Data['minute'] = 35
        GPS_Data['second'] += 1
    
    f.close()

    print(open('/sdcard/testfile.bin').read())       # Read File

    uos.umount("/sdcard")                         # Unmount SD Card
    print("File written")

 # Writes GPS Data Header to Log File
def write_log_header(f):
    f.write("Latitude \tLongitude \tYYYY:MM:DD  hh:mm:ss\n")


# Write GPS Data Sample to File
def write_data_sample(f, data):
    f.write("%3.6f \t %3.6f \t%.4u:%.2d:%.2d  %.2d:%.2d:%.2d \n" %(
		data['latitude'], data['longitude'],
		data['year'], data['month'], data['day'],
		data['hour'], data['minute'], data['second']
	))

main()