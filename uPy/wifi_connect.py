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
#  Filename : wifi_connect.py

from network import WLAN
from usocket import getaddrinfo
from machine import Timer, reset
import logging
import reqst

def splash_breaking_a(b_html):
    # read all bytes from socket
    print("<a> search...")
    # parse socket bytes
    a = []
    while b_html.find(b'<a') != -1:
        beg = b_html.find(b'<a')
        end = b_html.find(b'</a>')+4
        a.append(b_html[beg:end])
        b_html = b_html[end+1:]
    
    print(a)
    return a

def station_connected(station: WLAN, wifiLogger: Logger):
    #TODO: remove print
    print("Connected...Testing Access...")
    wifiLogger.info("Connected...Testing Access...")

    # test DNS -> GET Request and Handles Redirection
    [status, location] = reqst.test_dns_internet("https://www.example.com")

    # NO SPLASH PAGE
    if status == 200:
        return True

    # Redirection
    elif location and 300 <= status <= 309:
        [status,splashpage] = reqst.request_splash_page(location)
        # splashpage received
        if status == 200:
            print("Splashpage [OK]")
            print("Splashpage Length [{}]".format(len(splashpage)))
            
            print("Splashpage Breaking...")
            # <a> TAG Splash Page Breaking
            a = splash_breaking_a(splashpage)
            for v in a:
                [status, _ ] = reqst.get(v)
                if status == 200:
                    return True
            # -----------------------------
            return False
        else:
            print("Splashpage [Failed]")
            return False