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

import sys
import network
# import utime
# import urequests
import ubinascii
# HELFULL 

## Get files in dir
# import os
# os.listdir()


# Network settings
wifi_ssid = "PMT test"
wifi_password = ""

# Web page (non-SSL) to get
url = "http://example.com"

# Create a station object to store our connection
station = network.WLAN(network.STA_IF)

# activate station
station.active(True)
while True :
    #print ("#### All Networks ####\n")
    # tuple of obj(ssid, bssid, channel, RSSI, authmode, hidden)
    nets = station.scan()

    # get only open nets
    openNets = [n for n in nets if n[4] == 0]
    print ("#### openNets ####\n")
    print (*openNets, sep = "\n")
    # sort based on RSSI
    print ("#### -------- ####\n")
    for onet in openNets):
        # Try to connect to WiFi access point
        apSSID = onet.ssid
        print ("Connecting to "+str(onet.ssid,"utf-8")+" ...\n")
        station.connect( onet[0] ,auth= (0,""))
        if station.isconnected():
            print ("Connected")
    
    input()
# order list by strengh

# Returns list of tuples with the information about WiFi access points:
# (ssid, bssid, channel, RSSI, authmode, hidden)

