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
from machine import reset
from network import Station
from post import *
from time import sleep
from wifi_connect import *
from gc import collect
from gdt import GDT
# import encry


ap_blacklist = ["", "xfinitywifi", "CableWiFi", "Omni10_Setup_B3B", "lululemonwifi", "Google Home.k"]


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

# go back to raspberrypi\py directory for GDT rebooting purposes
os.chdir('ports/raspberrypi/py')


# These files should be placed in runtime directory
runtime_dir = '/home/{}/runtime/'.format(os.getlogin())

if not os.access(runtime_dir, os.F_OK): # if does not exist
    os.mkdir(runtime_dir) #make it

default = os.path.join(runtime_dir,"pmt.log")
wifi = os.path.join(runtime_dir,"wifi.log")
archive = os.path.join(runtime_dir,"data.log")
unsent = os.path.join(runtime_dir,"buffer.log")
blacklist = os.path.join(runtime_dir,"blacklist.log")
current_ap = os.path.join(runtime_dir,"SSID.log")
unsent_buffer_ptr = os.path.join(runtime_dir,"buffer_pointer.log")


# Creation of a logger also creates the file should it not already exist
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
data = ''


# Accelerometer PINOUT:
# TODO: Insert pinout


# Set up wireless station
station = Station()


collect()
gdt = GDT(30+gps_interval, pid=os.getpid(), logger=blacklistLogger)

while True:

    # Sample GNSS data
    GPSdata = gps.get_RMCdata(defaultLogger)
    speed = 0

    # Store the data
    if not (GPSdata == {}):

        speed = GPSdata['speed']
        print("speed={}".format(speed))

        # Use when we support sending speed to host
        #data = ''
        #for val in GPSdata.values():
        #    data = "{0}{1}".format(data, val)
        #    data = '{},'.format(data)
        data = "{0},{1},{2},{3},".format(GPSdata['time'], GPSdata['latitude'], GPSdata['longitude'], GPSdata['date'] )
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
        gdt.feed()

        # If not connected we need to connect
        if not station.is_connected():
            print("Scanning for SSIDS")

            try:
                openNets = station.scan_open_ssids() # gets list of open SSIDS
            except Exception as e:
                #TODO: remove print
                print("Warning: {0}".format(str(e)))
                defaultLogger.warning(str(e))

            print(openNets)

            # Update working blacklist with running list of bad APs in area
            with open(blacklist, 'rt') as fp:
                ap_list = fp.read()
                ap_list = ap_list.split("\n")
                ap_blacklist = ap_blacklist + list(set(ap_list[:-1]) - set(ap_blacklist))

            # try each SSID
            for ssid in openNets:
                if ssid not in ap_blacklist:
                    # Try to connect to WiFi access point
                    apLogger.overwrite(ssid)
                    #TODO: remove print
                    print ( "Connecting to {0} ...\n".format(ssid) )
                    wifiLogger.info( "Connecting to {0} ...\n".format(ssid[0]) )
                    gdt.feed()
                    station.connect_to_ssid(ssid)

                    # Wait for connection (aka valid IP)
                    count = 0
                    MAX_IP_WAIT = 12 # 12*0.25 = 3 seconds
                    while not station.is_connected():
                        print("No IP yet...")
                        gdt.feed()
                        sleep(0.25) # Quarter Second
                        count+=1
                        #If we've waited long enough but no IP
                        if count >= MAX_IP_WAIT:
                            break
                   
                    # If we are connected break from checking each SSID
                    # and move onto splashpage/posting
                    if station.is_connected():
                        break

                    
        # If we now have a valid IP
        if station.is_connected():
            
            # Case: after reboot rasperry pi wpa_supplicant.conf is already configured for SSID and connects automatically.
            # Therefore python may not have SSID defined. Need to recover from file.
            try:
                ssid=ssid
            except NameError as err:
                print("ssid not yet defined")
                with open(current_ap, 'rt') as fp:
                    ssid = fp.read()

            gdt.feed()
            print("Connected to {}".format(ssid))
            connected = station_connected(station, post_url, gdt, wifiLogger)
            if not connected:
                blacklistLogger.write_line(ssid)
                #TODO: remove print
                print("Unable to Connect")
                wifiLogger.warning("Unable to Connect")
                break

            # So long as we have WAN access, post data
            print("Checking WAN access")
            post_fail_count = 0

            while connected:
                # enc_data = encry.encrypt(enc_key, rawData)
                posted = post_data(data, post_url, station, defaultLogger) # Send most recent data point
                wifiLogger.write( "SSID: {0} Connected, POST: {1}\r\n".format(str(ssid), posted) )
                # del enc_data
                # collect()

                if not posted:
                    post_fail_count += 1
                else:
                    post_fail_count = 0
                
                # If we lost valid IP, move on
                # or If 3 fails, actively check connection (short circuit eval). If fail, move on
                if not station.is_connected() or ( (post_fail_count > 3) and not station.has_wan_access(host_url) ):
                    break

                # unsent_buffer_ptr file just stores the number of bytes that have been sent off,
                # use it as an offset to find the beginning of the unset data.
                data_points = ""
                with open(unsent_buffer_ptr, 'r') as fp:
                    total_bytes_read = fp.read()
                    total_bytes_read = int(total_bytes_read) if total_bytes_read != '' else 0

                with open(unsent, 'r') as fp:
                    for i in range(15):
                        # seek to unsent data
                        fp.seek(total_bytes_read)

                        # read size of data point
                        size = fp.read(2)
                        size = int(size) if size != '' else 0

                        # If we've sent all the data, update as such
                        if size == 0:
                            unsentLogger.overwrite('') # remove old data
                            total_bytes_read = 0
                            pointerLogger.overwrite(str(total_bytes_read))
                            break
                        
                        # Read the rest of the data point
                        raw_data = fp.read(int(size))
                        total_bytes_read+=(2+size)

                        # If the data read if the most recent data point,
                        # then don't send it again. Already sent above
                        if data == raw_data:
                            continue
                        # append this data point in with the others
                        else:
                            data_points = "{0}{1}".format(data_points, raw_data)
                            del raw_data
                            collect()

                    gdt.feed()
                    print("Fed GDT after reading from buffer")

                    if data_points != "":
                        # enc_data = encry.encrypt(enc_key, rawData)
                        posted = post_data(data_points, post_url, station, defaultLogger)

                        msg = "SSID: {0} Connected, POST: {1}\r\n".format(str(ssid), posted)
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