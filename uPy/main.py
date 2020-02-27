# ---------------------------------------
#  _____  __  __ _______        __   ___  
# |  __ \|  \/  |__   __|      /_ | / _ \ 
# | |__) | \  / |  | |    __   _| || | | |
# |  ___/| |\/| |  | |    \ \ / / || | | |
# | |    | |  | |  | |     \ V /| || |_| |
# |_|    |_|  |_|  |_|      \_/ |_(_)___/ 
# ----------------------------------------
#  Version 1.0
#  microPython Firmware esp32spiram-idf3-20191220-v1.12
#  Filename : main.py

from gps import GPS
from network import WLAN, STA_IF
from post import *
from utime import sleep
from wifi_connect import *
from machine import SDCard
from uos import mount
from os import remove

ap_blacklist = [b'xfinitywifi']

# HELPFUL 

## Get files in dir
# import os
# os.listdir()

## Run python script within REPL 
# execfile('<filename>')

# Create a station object to store our connection
station = WLAN(STA_IF)

# activate station
station.active(True)

# set post success flag
successful_post = False

# mount SD card
mount(SDCard(slot=3), "/sdcard")
archive = "/sdcard/data.csv"
unsent = "/sdcard/buffer.csv"

# SD Card PINOUT:
#    MISO    PIN 2
#    MOSI    PIN 15
#    CLK     PIN 14
#    CS      PIN 13

# GPS PINOUT:
#   GPS TX => Pin 21 (Master RX)
#   GPS RX => Pin 22 (Master TX)

# Accelerometer PINOUT:
#   SCL -> pin 10
#   SDA -> pin 9

# instantiate GPS class
gps = GPS()
data = ""

while True:
    GPSdata = gps.get_RMCdata()
    if not (GPSdata == {}):
        b = []
        lat_pre = float(GPSdata[0]['latitude'])
        lon_pre = float(GPSdata[0]['longitude'])
        d_post = {}
        b.append(GPSdata[0])
        for d in GPSdata:
            if (float(d['latitude']) > lat_pre+0.00007 or float(d['latitude']) < lat_pre-0.00007) and (float(d['longitude']) > lon_pre+0.00007 or float(d['longitude']) < lon_pre-0.00007):
                b.append(d)
                lat_pre = float(d['latitude'])
                lon_pre = float(d['longitude'])
            else:
                d_post = d
        if d_post != {}:
            b.append(d_post)
        for v in b:
            data+=','.join(list(v.values()))+','
        with open(archive, "a+") as file_ptr:
            file_ptr.write(data)
        with open(unsent, "a+") as file_ptr:
            file_ptr.write(data)
        print(data)
    else:
        print("No GPS data.")
        data = ""

    if station.isconnected():
        if data != "":
            with open(unsent, "r") as file_ptr:
                post_data(file_ptr.read())
            remove(unsent)

    else:
        # @param nets: tuple of obj(ssid, bssid, channel, RSSI, authmode, hidden)
        nets = station.scan()

        # get only open nets
        openNets = [n for n in nets if n[4] == 0]

        for onet in openNets:
            if onet[0] not in ap_blacklist:
                # Try to connect to WiFi access point
                apSSID = onet[0]
                print ("Connecting to "+str(onet[0],"utf-8")+" ...\n")
                station.connect(onet[0])
                while not station.isconnected():
                    sleep(0.5)
                if station.isconnected():
                    station_connected(station)
                    sleep(1)
                else:
                    print("Unable to Connect")
    sleep(5)