# ---------------------------------------
#  _____  __  __ _______        __   ___  
# |  __ \|  \/  |__   __|      /_ | / _ \ 
# | |__) | \  / |  | |    __   _| || | | |
# |  ___/| |\/| |  | |    \ \ / / || | | |
# | |    | |  | |  | |     \ V /| || |_| |
# |_|    |_|  |_|  |_|      \_/ |_(_)___/ 
# ----------------------------------------
#  Version 1.0
#  Raspbian Lite version February 2020
#  Python 3.7
#  Filename : main.py

import os
# Check if in correct directory
code_dir = '/home/{}/PMT/ports/raspberrypi/py'.format(os.getlogin())
if os.getcwd() != code_dir:
    print("This program must be run from: {}\nExiting...".format(code_dir))
    exit(1)

import logging
from gps import GPS
from machine import reset, scan_open_ssids, connect_to_ssid
from network import Station
from post import *
from time import sleep
from wifi_connect import *
from gc import collect
from gdt import GDT
# import encry


ap_blacklist = ["xfinitywifi", "CableWiFi", "Omni10_Setup_B3B", "Regions Guest", "lululemonwifi", "Google Home.k"]


# pmt.conf is kept in the PMT git repo, go there
logging.openPMTDir()

with open("pmt.conf", 'rt') as fp:
    pmt_config = eval(fp.read())

try:
    host_url = pmt_config['post_url']
    post_url = "{0}/api/post.php".format(pmt_config['post_url'] if pmt_config['post_url'][-1] != "/" else pmt_config['post_url'][:-1])
    gps_interval = pmt_config['gps_interval']
    enc_key = pmt_config['encryption_key']
except KeyError as e:
    print(e)
    raise


# These files should be placed in runtime directory
runtime_dir = '/home/{}/runtime/'.format(os.getlogin())

default = os.path.join(runtime_dir,"pmt.log")
wifi = os.path.join(runtime_dir,"wifi.log")
archive = os.path.join(runtime_dir,"data.log")
unsent = os.path.join(runtime_dir,"buffer.log")
blacklist = os.path.join(runtime_dir,"blacklist.log")
current_ap = os.path.join(runtime_dir,"SSID.log")
unsent_buffer_ptr = os.path.join(runtime_dir,"buffer_pointer.log")

# create file should it not already exist,
# append mode should it already contain contents
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

pointerLogger = logging.getLogger("BufferPointer", unsent_buffer_ptr)
pointerLogger.setLevel(logging.DEBUG)


# GPS PINOUT:
# TODO: Insert pinout
# instantiate GPS class
gps = GPS()
data = ""


# Accelerometer PINOUT:
# TODO: Insert pinout


# Set up wireless station
station = Station()


collect()
# setup core WDT for partial reset (temporary)
# wdt = WDT(timeout=((5+gps_interval)*1000))
gdt = GDT(20+gps_interval, logger=blacklistLogger)

while True:

    # Sample GNSS data
    GPSdata = gps.get_RMCdata(defaultLogger)
    speed = GPSdata['speed']
    print("speed={}".format(speed))

    # Store the data
    if not (GPSdata == {}):
        data=','.join( list(GPSdata.values()) )+','

        #TODO: remove print
        print(data)
        archiveLogger.write(data)
        unsentLogger.write("{0}{1}".format(len(data), data))
        defaultLogger.info(data)
        
    else:
        #TODO: remove print
        print("No GPS data.")
        defaultLogger.info("No GPS data.")
        data = ""


    # If we are not parked, then remove the list of SSIDs that didn't work
    if (speed is not None) and (speed > 10.00):
        os.remove(blacklist)

        # re-create file for initial read
        with open(blacklist, "a+"):
            pass


    # If our speed is slow enough we should try connecting to an Access Point
    elif (speed is not None) and (speed <= 5.00):
        if not station.is_connected():
            try:
                openNets = station.scan_open_ssids() # gets list of open SSIDS
            except Exception as e:
                #TODO: remove print
                print("Warning: {0}".format(str(e)))
                defaultLogger.warning(str(e))

            # Update working blacklist with running list of bad APs in area
            with open(blacklist, 'r') as fp:
                ap_list = fp.read()
                ap_list = ap_list.split("\n")
                ap_blacklist = ap_blacklist + list(set(ap_list[:-1]) - set(ap_blacklist))

            # try each SSID
            for onet in openNets:
                if onet not in ap_blacklist:
                    # Try to connect to WiFi access point
                    apLogger.overwrite(onet)
                    #TODO: remove print
                    print ( "Connecting to {0} ...\n".format(onet) )
                    wifiLogger.info( "Connecting to {0} ...\n".format(onet[0]) )
                    station.connect_to_ssid(onet)

                    # Wait for connection
                    while not station.is_connected():
                        sleep(0.5)
                    
                    if station.is_connected():
                        connected = station_connected(station, post_url, gdt, wifiLogger)
                        if not connected:
                            blacklistLogger.write_line(onet)
                            #TODO: remove print
                            print("Unable to Connect")
                            wifiLogger.warning("Unable to Connect")
                            break
    

    # If we have WAN access, post data
    if station.has_wan_access(host_url):
        # enc_data = encry.encrypt(enc_key, rawData)
        posted = post_data(data, post_url, station, defaultLogger) # Send most recent data point
        wifiLogger.write( "SSID: {0} Connected, POST: {1}\r\n".format(str(onet), posted) )
        # del enc_data
        # collect()

        # unsent_buffer_ptr file just stores the number of bytes that have been sent off,
        # use it as an offset to find the beginning of the unset data.
        data_points = ""
        with open(unsent_buffer_ptr, 'r') as fp:
            total_bytes_read = fp.read()
            total_bytes_read = int(total_bytes_read) if total_bytes_read != '' else 0

        with open(unsent, 'r') as fp:
            for i in range(15):
                fp.seek(total_bytes_read)
                size = fp.read(2)
                size = int(size) if size != '' else 0

                if size == 0:
                    os.remove(unsent)
                    total_bytes_read = 0
                    pointerLogger.overwrite(str(total_bytes_read))
                    break
                
                raw_data = fp.read(int(size))
                total_bytes_read+=(2+size)

                if data == raw_data:
                    continue
                else:
                    data_points = "{0}{1}".format(data_points, raw_data)
                    del raw_data
                    collect()

            gdt.feed()
            print("Fed GDT after reading from buffer")

            if data_points != "":
                # enc_data = encry.encrypt(enc_key, rawData)
                posted = post_data(data_points, post_url, station, defaultLogger)

                msg = "SSID: {0} Connected, POST: {1}\r\n".format(str(onet), posted)
                wifiLogger.write(msg)
                # del enc_data

            if posted:
                pointerLogger.overwrite(str(total_bytes_read))

            del data_points
            collect()


    sleep(gps_interval)

    #reset WDT to avoid Software Reset 0xc
    gdt.feed()
    print("Fed GDT in FSM")