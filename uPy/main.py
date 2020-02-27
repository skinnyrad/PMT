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
from machine import SDCard
from network import WLAN, STA_IF
from os import remove
from post import *
from utime import sleep
from uos import mount
from wifi_connect import *

# import logging

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

# mount SD card
mount(SDCard(slot=3), "/sdcard")
config_file = "/sdcard/pmt.conf"
archive = "/sdcard/data.csv"
unsent = "/sdcard/buffer.csv"

# logging.basicConfig(filename="pmt.log", level=logging.DEBUG,
#                     format='%(asctime)s %(message)s', datefmt='%m/%d/%Y %H:%M:%S')
# defaultLogger = logging.getLogger("Default_Logger")
# wifiLogger = logging.getLogger("WiFi_Connection_Logger")
# archiveLogger = logging.getLogger("Archive")
# archiveLogger.level(logging.DEBUG)
# archiveLogger.addHandler(logging.FileHandler(archive))
# unsentLogger = logging.getLogger("Unsent")
# unsentLogger.level(logging.DEBUG)
# unsentLogger.addHandler(logging.FileHandler(unsent))

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

with open(config_file, 'r') as fp:
    pmt_config = eval(fp.read())

try:
    post_url = pmt_config['post_url']
    gps_interval = pmt_config['gps_interval']
except KeyError as e:
    print(e)
    raise

while True:
    GPSdata = gps.get_RMCdata()#defaultLogger)
    if not (GPSdata == {}):
        b = []
        lat_pre = float(GPSdata['latitude'])
        lon_pre = float(GPSdata['longitude'])
        d_post = {}
        b.append(GPSdata)
        if (float(GPSdata['latitude']) > lat_pre+0.00007 or float(GPSdata['latitude']) < lat_pre-0.00007) and (float(GPSdata['longitude']) > lon_pre+0.00007 or float(GPSdata['longitude']) < lon_pre-0.00007):
            b.append(d)
            lat_pre = float(GPSdata['latitude'])
            lon_pre = float(GPSdata['longitude'])
        else:
            d_post = GPSdata
        if d_post != {}:
            b.append(d_post)
        for v in b:
            data+=','.join(list(v.values()))+','
        #TODO: remove print
        print(data)
        # archiveLogger.info(data)
        # unsentLogger.info(data)
        # defaultLogger.info(data)
    else:
        #TODO: remove print
        print("No GPS data.")
        # defaultLogger.info("No GPS data.")
        data = ""

    if station.isconnected():
        if data != "":
            with open(unsent, "r") as file_ptr:
                post_data(file_ptr.read(), post_url) #, defaultLogger)
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
                #TODO: remove print
                print ("Connecting to "+str(onet[0],"utf-8")+" ...\n")
                # wifiLogger.info("Connecting to "+str(onet[0],"utf-8")+" ...\n")
                station.connect(onet[0])
                while not station.isconnected():
                    sleep(0.5)
                if station.isconnected():
                    station_connected(station) #, wifiLogger)
                    sleep(1)
                else:
                    #TODO: remove print
                    print("Unable to Connect")
                    # wifiLogger.warning("Unable to Connect")
    sleep(gps_interval)
