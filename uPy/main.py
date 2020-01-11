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

from network import WLAN, STA_IF
from utime import sleep
from wifi_connect import *

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

while not station.isconnected() or not successful_post:
    if not station.isconnected():
        # # @param nets: tuple of obj(ssid, bssid, channel, RSSI, authmode, hidden)
        # nets = station.scan()

        # # get only open nets
        # openNets = [n for n in nets if n[4] == 0]

        # for onet in openNets:
        #     print(onet)

        # for onet in openNets:
        #     if onet[0] not in ap_blacklist:
        #         # Try to connect to WiFi access point
        #         apSSID = onet[0]
        #         print ("Connecting to "+str(onet[0],"utf-8")+" ...\n")
        #         station.connect(onet[0])
        #         while not station.isconnected():
        #             sleep(0.5)
        #         if station.isconnected():
        #             succesful_post = station_connected(station)
        #         else:
        #             print("Unable to Connect")
        station.connect("Ben's iPhone", "5t4ydi4g3g1uz")
        sleep(0.5)
        succesful_post = station_connected(station)