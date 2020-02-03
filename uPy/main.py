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
import utime
from wifi_connect import *
from machine import SDCard
from uos import mount

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
filepath = "/sdcard/data.txt"
filepath_logger = "/sdcard/log.txt"
# PINS Connections
#    MISO    PIN 2
#    MOSI    PIN 15
#    CLK     PIN 14
#    CS      PIN 13

# instantiate GPS class
#gps = GPS()



while True:
    while not station.isconnected():
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
                    utime.sleep(0.5)
                if station.isconnected():
                    # store ssid for logger
                    global ssid_conn 
                    ssid_conn = str(onet[0],"utf-8")
                    # test connection
                    global req, start, et
                    start = utime.ticks_us()
                    [req, logger_errs] = station_connected(station)
                    et = utime.ticks_diff(utime.ticks_us(), start)
                else:
                    print("Unable to Connect") 

    while station.isconnected():
        # GPSdata = gps.get_RMCdata()
        # if not (GPSdata == {}):
        #     data = ','.join(list(v for v in GPSdata.values()))
        #     data = data + "\n"
        #     with open(filepath, "a+") as file_ptr:
        #         file_ptr.write(data)
        #     successful_post = post_data(data)
        if req.was_redirected == True:
            with open(ssid_conn, "a+") as file_ptr:
                file_ptr.write(req.content)
                file_ptr.close()
                # not redirected but got internet connection
        if req.status_code == 200:
            with open(filepath_logger, "a+") as file_ptr:
                file_ptr.write(ssid_conn+" | " + "Successful Connection"+" | " +et+"\n")
                file_ptr.close()
        # something went wrong
        else:
             with open(filepath_logger, "a+") as file_ptr:
                file_ptr.write(ssid_conn+" | " + "BAD!!\n")
                file_ptr.close()
        utime.sleep(5)
