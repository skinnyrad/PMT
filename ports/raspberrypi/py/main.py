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
import threading
# Check if in correct directory
code_dir = '/home/pi/PMT/ports/raspberrypi/py'
#if os.getcwd() != code_dir:
#    print("This program must be run from: {}\nExiting...".format(code_dir))
#    exit(1)

import pmt_logging as logging
from gps import GPS
from machine import reset
from network import Station
from post import post_data
import time
from wifi_connect import station_connected
from gc import collect
from gdt import GDT
# import encry

lck = threading.Lock()

ap_blacklist = ["", "xfinitywifi", "CableWiFi", "Omni10_Setup_B3B", "lululemonwifi", "Google Home.k"]

# pmt.conf is kept in the PMT git repo, go there
logging.openPMTDir()

with open("pmt.conf", 'rt') as fp:
    pmt_config = eval(fp.read())

try:
    host_url = "{}/api/".format(pmt_config['post_url'])
    post_url = "{0}/api/post.php".format(pmt_config['post_url'] if pmt_config['post_url'][-1] != "/" else pmt_config['post_url'][:-1])
    #gps_interval = pmt_config['gps_interval']
    # enc_key = pmt_config['encryption_key']
except KeyError as e:
    print(e)
    raise

# go back to raspberrypi\py directory for GDT rebooting purposes
os.chdir('ports/raspberrypi/py')


# These files should be placed in runtime directory
runtime_dir = '/home/pi/runtime/'

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

# Set up wireless station
station = Station()

collect()
gdt = GDT(30, pid=os.getpid(), logger=blacklistLogger)

#reset time in seconds, 1200
blacklist_reset_time=720

# instantiate GPS class
data = ''

#gps thread
def gps_main():
    gps = GPS()
    speed=0
    
    #makes data a global so newest data point can still be sent 
    global data
    
    #adjusts GPS acquisition based on speed of target
    while True:
    
        if(speed<5):
            time.sleep(30)
        elif((speed>=5) and (speed<20)):
            time.sleep(5)
        elif((speed>=20) and (speed<45)):
            time.sleep(10)
        elif((speed>=45) and (speed<70)):
            time.sleep(20)
        elif(speed>=70):
            time.sleep(40)

        # Sample GNSS data
        lck.acquire() #locks other threads out
        GPSdata = gps.get_RMCdata(defaultLogger)
        lck.release() #releases back to other threads
        
        # Store the data
        if not (GPSdata == {}):
        
            #converts speed to mph from knots
            speed = GPSdata['speed']*1.15078
            print("speed={}".format(speed))

            # Use when we support sending speed to host
            #data = ''
            #for val in GPSdata.values():
            #    data = "{0}{1}".format(data, val)
            #    data = '{},'.format(data)
            lck.acquire() #locks other threads out
            data = "{0},{1},{2},{3},".format(GPSdata['time'], GPSdata['latitude'], GPSdata['longitude'], GPSdata['date'] )
            print(data)
            archiveLogger.write(data)
            unsentLogger.write("{0}{1}".format(len(data), data))
            defaultLogger.info(data)
            lck.release() #releases files to others threads
        else:
            #TODO: remove print
            print("No GPS data.")
            lck.acquire()
            defaultLogger.info("No GPS data.")
            data = ""
            lck.release()
    
def wifi_main():
    ticks1=0
    while True:
        #Blacklist is based on time elapsed (blacklist_reset_time)
        #If enough time has elapsed, then reset the blacklist
        ticks2 = time.time()
        if ((ticks2-ticks1)>blacklist_reset_time):
            os.remove(blacklist)
            os.remove(current_ap)

            # re-create file for initial read
            with open(blacklist, "a+"):
                pass
            with open(current_ap, "a+"):
                pass
            
            ticks1=ticks2
            
            #APs are compared against a temp blacklist that is erased every blacklist_reset_time
            ap_blacklist_temp = ap_blacklist

        #attempt to connect to WiFi
        elif ((ticks2-ticks1)<=blacklist_reset_time):
            gdt.feed()

            # If not connected we need to connect
            if not station.is_connected():
                print("Scanning for SSIDS")

                try:
                    openNets = station.scan_open_ssids() # gets list of open SSIDS
                except Exception as e:
                    print("Warning: {0}".format(str(e)))
                    lck.acquire()
                    defaultLogger.warning(str(e))
                    lck.release()
                print(openNets)

                # Update working blacklist with running list of bad APs in area
                with open(blacklist, 'rt') as fp:
                    ap_list = fp.read()
                    ap_list = ap_list.split("\n")
                    ap_blacklist_temp = ap_blacklist + list(set(ap_list[:-1]) - set(ap_blacklist))
                # try each SSID
                for ssid in openNets:
                    # Extra filtering:
                    # Remove HP ssids (printers) and ensures that the AP being connected to is still around
                    if (len(ssid) > 2 and str(ssid[0:2]).lower() == 'hp') or (ssid not in station.scan_open_ssids()):
                        continue

                    if ssid not in ap_blacklist_temp:
                        # Try to connect to WiFi access point
                        apLogger.overwrite(ssid)

                        print ( "Connecting to {0} ...\n".format(ssid) )
                        wifiLogger.info( "Connecting to {0} ...\n".format(ssid) )
                        
                        gdt.feed()
                        station.connect_to_ssid(ssid)
                        gdt.feed()

                        # Wait for connection (aka valid IP)
                        count = 0
                        MAX_IP_WAIT = 15 # 15 seconds
                        while not station.is_connected():
                            print("No IP yet...")
                            gdt.feed()
                            time.sleep(1) # 1 Second
                            count+=1
                            #If we've waited long enough but no IP
                            if count >= MAX_IP_WAIT:
                                blacklistLogger.write_line(ssid)
                                os.system("sudo pkill wpa_supplicant")
                                break
                       
                        # If we are connected break from checking each SSID
                        # and move onto splashpage/posting
                        if station.is_connected():
                            ip_and_sub=os.popen("ip a | grep dynamic | grep -E -o \"([0-9]{1,3}[\.]){3}[0-9]{1,3}\"").read()
                            print("IP Address & Subnet:\n{0}\n".format(ip_and_sub))
                            wifiLogger.info("IP address & Subnet:\n{0}".format(ip_and_sub))
                            break
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
                    
                    # Case: RaspPi has incorrectly held onto a valid IP so long
                    # user had even wiped the SSID.log file
                    if ssid == "":
                        station.end_ip_lease()
                        continue # exit out, we are no longer connected


                gdt.feed()
                print("Connected to {}".format(ssid))
                wifiLogger.info("Connected to {}".format(ssid))
                connected = station_connected(station, host_url, gdt, wifiLogger)
                
                # Caught default Exception, normally from leaving AP range
                # dropping lease on any valid IP should be handled within station_connected
                if connected is None:
                    continue #run next cycle of main processing loop
                
                # WAN access failed
                elif not connected:
                    print("Unable to Connect")
                    print("blacklisting {} and dropping IP".format(ssid))
                    wifiLogger.warning("Unable to Connect")
                    wifiLogger.warning("blacklisting {} and dropping IP".format(ssid))
                    blacklistLogger.write_line(ssid) # Blacklist the SSID until we get moving again
                    station.end_ip_lease() # Drop the IP given by the AP
                    continue

                # So long as we have WAN access, post data
                print("Checking WAN access")
                post_fail_count = 0

                lck.acquire()
                while connected:
                    # enc_data = encry.encrypt(enc_key, rawData)
                    
                    #if wifi is acquired before the latest GPS point, this 'if' comes in handy
                    if not (data == ''):
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
                        for i in range(50):
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
                        else:
                            break #if there are no more data points, then jump out and relinquish the lock

                        if posted:
                            pointerLogger.overwrite(str(total_bytes_read))

                        del data_points
                        collect()
                lck.release() #release the lock
                
                #Provides an amount of time for some GPS points to be acquired before attempting to re-upload
                #time.sleep(15)
        #reset WDT to avoid Software Reset 0xc
        gdt.feed()
        print("Fed GDT in FSM")

#Start gps thread
gps_thread = threading.Thread(target = gps_main)
wifi_thread = threading.Thread(target = wifi_main)
gps_thread.start()
wifi_thread.start()