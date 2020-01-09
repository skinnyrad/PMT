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

import network
import machine
import urequests
import usocket
import ujson
import utime
import ubinascii

ap_blacklist = [b'xfinitywifi']

# HELPFUL 

## Get files in dir
# import os
# os.listdir()

## Run python script within REPL 
# execfile('<filename>')

# Create a station object to store our connection
station = network.WLAN(network.STA_IF)

# activate station
station.active(True)

# set post success flag
successful_post = False

# https request information
url = "https://pmtlogger.000webhostapp.com/api/write.php"
post_data = ujson.dumps([{
  "datetime": utime.localtime(),
  "id": ubinascii.hexlify(machine.unique_id()),
  "lat": "122.2",
  "lon": "32.6"
},{
  "datetime": utime.localtime(),
  "id": ubinascii.hexlify(machine.unique_id()),
  "lat": "122.2",
  "lon": "32.6"
}])
headers = {
    'Content-Type': 'application-json',
}

def post(_url, _headers, _post_data):
    return urequests.post(_url, headers=_headers, data=_post_data)

def station_connected():
    print("Connected...Testing Access...")
    resolved = usocket.getaddrinfo("www.google.com", 80)
    if resolved == []:
        print("No Internet Access")
        station.disconnect()
    else:
        print("Internet Accessible")
        response = post(url, headers, post_data)
        if response.status_code == 200:
            successful_post = True
            print("Post Request Successful")

while not station.isconnected() or not successful_post:
    if not station.isconnected():
        # @param nets: tuple of obj(ssid, bssid, channel, RSSI, authmode, hidden)
        nets = station.scan()

        # get only open nets
        openNets = [n for n in nets if n[4] == 0]

        for onet in openNets:
            print(onet)

        for onet in openNets:
            if onet[0] not in ap_blacklist:
                # Try to connect to WiFi access point
                apSSID = onet[0]
                print ("Connecting to "+str(onet[0],"utf-8")+" ...\n")
                station.connect(onet[0])
                while not station.isconnected():
                    utime.sleep(0.5)
                if station.isconnected():
                    station_connected()
                else:
                    print("Unable to Connect")

# https post request
