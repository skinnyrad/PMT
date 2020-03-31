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
import logging
from machine import reset, SDCard
from network import WLAN, STA_IF
from os import remove
from post import *
from utime import sleep
from uos import mount, umount
from wifi_connect import *
from gc import collect
from gdt import GDT

# import encry

ap_blacklist = ["xfinitywifi", "CableWiFi"]

# HELPFUL 

## Get files in dir
# import os
# os.listdir()

## Run python script within REPL 
# execfile('<filename>')

# if the SD card does not mount reset
# manually remove and reinsert SD card before reset to fix
# TODO: "Figure this out Ben you big dummy" - Ben
# sd_wdt = WDT(timeout=((5)*1000))

# Create a station object to store our connection
station = WLAN(STA_IF)

# activate station
station.active(True)

def sd_gdt_func(timer):
    print("SD card did not mount correctly")
    # TODO: add LED sigal from board to signify this
    try:
        umount("/sdcard")
    except OSError as e:
        # TODO: add LED signal from board to signify this
        print("Reinsert SD Card in SD Card reader")
        # TODO: remove sleep once LED signal is done
        # sleep gives time to read comment before reseting the board
        sleep(3)
    reset()

# mount SD card
sd_gdt = GDT(2, station, func=sd_gdt_func)
mount(SDCard(slot=3), "/sdcard")
sd_gdt.deinit_timer()
del sd_gdt
collect()

config_file = "/sdcard/pmt.conf"
default = "/sdcard/pmt.log"
wifi = "/sdcard/wifi.log"
archive = "/sdcard/data.log"
unsent = "/sdcard/buffer.log"
blacklist = "/sdcard/blacklist.log"
current_ap = "/sdcard/SSID.log"

# create file for initial read
with open(blacklist, "a+"):
    pass

defaultLogger = logging.getLogger("Default_Logger", default)
defaultLogger.setLevel(logging.DEBUG)

wifiLogger = logging.getLogger("WiFi_Connection_Logger", wifi)
wifiLogger.setLevel(logging.DEBUG)

archiveLogger = logging.getLogger("Archive", archive)
archiveLogger.setLevel(logging.DEBUG)

unsentLogger = logging.getLogger("Unsent", unsent)
unsentLogger.setLevel(logging.DEBUG)

blacklistLogger = logging.getLogger("Blacklist", blacklist)
blacklistLogger.setLevel(logging.DEBUG)

apLogger = logging.getLogger("Current_SSID", current_ap)
apLogger.setLevel(logging.DEBUG)

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
    post_url = "{0}/api/post.php".format(pmt_config['post_url'] if pmt_config['post_url'][-1] != "/" else pmt_config['post_url'][:-1])
    gps_interval = pmt_config['gps_interval']
    enc_key = pmt_config['encryption_key']
except KeyError as e:
    print(e)
    raise

posted = False

#setup core WDT for partial reset (temporary)
#TODO: change out with RWDT in esp32/panic.c
collect()
# wdt = WDT(timeout=((5+gps_interval)*1000))
gdt = GDT(5+gps_interval, station, logger=blacklistLogger)

while True:
    [GPSdata, speed] = gps.get_RMCdata(defaultLogger)
    if not (GPSdata == {}):
        b = []
        lat_pre = float(GPSdata['latitude'])
        lon_pre = float(GPSdata['longitude'])
        d_post = {}
        b.append(GPSdata)
        if (float(GPSdata['latitude']) > lat_pre+0.00007 or float(GPSdata['latitude']) < lat_pre-0.00007) and (float(GPSdata['longitude']) > lon_pre+0.00007 or float(GPSdata['longitude']) < lon_pre-0.00007):
            b.append()
            lat_pre = float(GPSdata['latitude'])
            lon_pre = float(GPSdata['longitude'])
        else:
            d_post = GPSdata
        if d_post != {}:
            b.append(d_post)
        for v in b:
            data=','.join(list(v.values()))+','
        #TODO: remove print
        print(data)
        archiveLogger.write(data)
        unsentLogger.write(data)
        defaultLogger.info(data)
    else:
        #TODO: remove print
        print("No GPS data.")
        defaultLogger.info("No GPS data.")
        data = ""

    if station.isconnected():
        if data != "":
            with open(unsent, "r") as file_ptr:
                raw_data = file_ptr.read()
                # enc_data = encry.encrypt(enc_key, rawData)
                posted = post_data(raw_data, post_url, station, defaultLogger)

                msg = "SSID: {0} Connected, POST: {1}\r\n".format(str(apSSID), posted)
                wifiLogger.write(msg)

                del raw_data
                # del enc_data
                collect()
                if posted:
                    remove(unsent)

    with open(blacklist, 'r') as fp:
        ap_list = fp.read()
        ap_list = ap_list.split("\n")
        ap_blacklist = ap_blacklist + list(set(ap_list[:-1]) - set(ap_blacklist))

    if (speed is not None) and (speed <= 10.00):
        if not station.isconnected():
            try:
                # @param nets: tuple of obj(ssid, bssid, channel, RSSI, authmode, hidden)
                nets = station.scan()
            except RuntimeError as e:
                #TODO: remove print
                print("Warning: {0}".format(str(e)))
                defaultLogger.warning(str(e)) 
            # get only open nets
            openNets = [n for n in nets if n[4] == 0]

            for onet in openNets:
                if onet[0].decode("utf-8") not in ap_blacklist:
                    # Try to connect to WiFi access point
                    apSSID = onet[0]
                    apLogger.overwrite(apSSID.decode("utf-8"))
                    #TODO: remove print
                    print ("Connecting to {0} ...\n".format(str(onet[0],"utf-8")))
                    wifiLogger.info("Connecting to {0} ...\n".format(str(onet[0],"utf-8")))
                    station.connect(onet[0])
                    while not station.isconnected():
                        sleep(0.5)
                    if station.isconnected():
                        connected = station_connected(station, post_url, gdt, wifiLogger)
                        if not connected:
                            blacklistLogger.write_line(apSSID.decode("utf-8"))
                            #TODO: remove print
                            print("Unable to Connect")
                            wifiLogger.warning("Unable to Connect")
                            break
    elif (speed is not None) and (speed > 10.00):
        remove(blacklist)

        # re-create file for initial read
        with open(blacklist, "a+"):
            pass

    sleep(gps_interval)

    #reset WDT to avoid Software Reset 0xc
    gdt.feed()
    print("Fed GDT in FSM")