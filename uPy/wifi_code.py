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

station.active(True)
while True :
    # Scan for the available wireless networks.
    print ("#### All Networks ####\n")
    nets = station.scan()
    
    print (*nets, sep = "\n")
    print ("#### ------------ ####\n")
    # print (*sortedOpenNets, sep = "\n")
    # get only open nets
    
    openNets = [n for n in nets if n[4] == 0]
    print ("#### openNets ####\n")
    print (*openNets, sep = "\n")
    # sort based on RSSI
    print ("#### -------- ####\n")
    # print ("#### Sorted openNets ####\n")
    # sortedOpenNets = sorted(openNets,key=lambda l:l[3])
    # print (*sortedOpenNets, sep = "\n")
    # print ("#### --------------- ####\n")
    # Continually try to connect to WiFi access point
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
# while True:
#     scannedAPs = station.scan()
#     for i in range(len(scannedAPs)): 
#         print(scannedAPs[i]) 
# Continually try to connect to WiFi access point
# while not station.isconnected():

#     # Try to connect to WiFi access point
#     # print("Connecting...")
#     station.connect(wifi_ssid, wifi_password)

# # Continually print out HTML from web page as long as we have a connection
# while station.isconnected():

#     # Display connection details
#     print("Connected!")
#     print("My IP Address:", station.ifconfig()[0])

#     # Perform HTTP GET request on a non-SSL web
#     response = urequests.get(url)

#     # Display the contents of the page
#     print(response.text)


# If we lose connection, repeat this main.py and retry for a connection
# print("Connection lost. Trying again.")
