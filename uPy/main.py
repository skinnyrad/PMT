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
    "id": 1,
    "Longitude": -86.6412163420141,
    "Latitude": 34.722586539952,
    "Date": "2019-10-14",
    "Time": "14:30:00"
},{
    "id": 2,
    "Longitude": -86.6411210245048,
    "Latitude": 34.7232260242348,
    "Date": "2019-10-15",
    "Time": "14:30:10"
},{
    "id": 3,
    "Longitude": -86.6420061571728,
    "Latitude": 34.7235031028468,
    "Date": "2019-10-16",
    "Time": "14:30:20"
},{
    "id": 4,
    "Longitude": -86.6421187854007,
    "Latitude": 34.7242470342329,
    "Date": "2019-10-17",
    "Time": "14:30:30"
},{
    "id": 5,
    "Longitude": -86.641940000026,
    "Latitude": 34.7245409600879,
    "Date": "2019-10-18",
    "Time": "14:30:40"
},{
    "id": 6,
    "Longitude": -86.6421847643798,
    "Latitude": 34.7248047166302,
    "Date": "2019-10-19",
    "Time": "14:30:50"
},{
    "id": 7,
    "Longitude": -86.6425906007074,
    "Latitude": 34.7246067235775,
    "Date": "2019-10-20",
    "Time": "14:31:00"
},{
    "id": 8,
    "Longitude": -86.6427949012338,
    "Latitude": 34.724206185779,
    "Date": "2019-10-21",
    "Time": "14:31:10"
},{
    "id": 9,
    "Longitude": -86.6431778066368,
    "Latitude": 34.7240024430458,
    "Date": "2019-10-22",
    "Time": "14:31:20"
},{
    "id": 10,
    "Longitude": -86.6436242447878,
    "Latitude": 34.7239260217465,
    "Date": "2019-10-23",
    "Time": "14:31:30"
},{
    "id": 11,
    "Longitude": -86.6439779020318,
    "Latitude": 34.7241005807449,
    "Date": "2019-10-24",
    "Time": "14:31:40"
},{
    "id": 12,
    "Longitude": -86.6439714392672,
    "Latitude": 34.7245197489505,
    "Date": "2019-10-25",
    "Time": "14:31:50"
},{
    "id": 13,
    "Longitude": -86.6439375447486,
    "Latitude": 34.7249956102817,
    "Date": "2019-10-26",
    "Time": "14:32:00"
},{
    "id": 14,
    "Longitude": -86.6439286316693,
    "Latitude": 34.7253607985706,
    "Date": "2019-10-27",
    "Time": "14:32:10"
},{
    "id": 15,
    "Longitude": -86.6438679842583,
    "Latitude": 34.7257620487998,
    "Date": "2019-10-28",
    "Time": "14:32:20"
},{
    "id": 16,
    "Longitude": -86.6435760632231,
    "Latitude": 34.7260039358756,
    "Date": "2019-10-29",
    "Time": "14:32:30"
},{
    "id": 17,
    "Longitude": -86.6425538064605,
    "Latitude": 34.7263005486733,
    "Date": "2019-10-30",
    "Time": "14:32:40"
},{
    "id": 18,
    "Longitude": -86.641839485347,
    "Latitude": 34.7267437665668,
    "Date": "2019-10-31",
    "Time": "14:32:50"
},{
    "id": 19,
    "Longitude": -86.6409493466223,
    "Latitude": 34.7273238940422,
    "Date": "2019-11-01",
    "Time": "14:33:00"
},{
    "id": 20,
    "Longitude": -86.6400003351475,
    "Latitude": 34.7276064727814,
    "Date": "2019-11-02",
    "Time": "14:33:10"
},{
    "id": 21,
    "Longitude": -86.6385770412927,
    "Latitude": 34.7276646692817,
    "Date": "2019-11-03",
    "Time": "14:33:20"
},{
    "id": 22,
    "Longitude": -86.6380048458353,
    "Latitude": 34.7269783973773,
    "Date": "2019-11-04",
    "Time": "14:33:30"
},{
    "id": 23,
    "Longitude": -86.6382245303282,
    "Latitude": 34.7264934421783,
    "Date": "2019-11-05",
    "Time": "14:33:40"
},{
    "id": 24,
    "Longitude": -86.6389299520553,
    "Latitude": 34.7261097279809,
    "Date": "2019-11-06",
    "Time": "14:33:50"
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
