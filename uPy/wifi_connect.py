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
from gdt import GDT
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

def station_connected(station: WLAN, host: String, gdt: GDT, wifiLogger: Logger):
    #TODO: remove print
    print("Connected [Testing Access]")
    wifiLogger.info("Connected [Testing Access]")

    gdt.feed()
    print("Fed GDT before DNS testing")

    # test DNS -> GET Request and Handles Redirection
    [status, location, body] = reqst.test_dns_internet(host)

    gdt.feed()
    print("Fed GDT after DNS testing")

    # NO SPLASH PAGE
    if status == 200 and body == "OK":
        print("Internet Access [OK]")
        return True

    elif status == 200:
        # should handle requests prior to redirection
        return station_connected(station, host, wdt, wifiLogger)

    # Redirection
    elif location and 300 <= status <= 309:
        wdt.feed()
        print("Fed WDT before requesting splash page")

        [status,splashpage] = reqst.request_splash_page(location)
        # splashpage received

        wdt.feed()
        print("Fed WDT after splash page received")

        print(splashpage)
        if status == 200:
            print("Splashpage [OK]")
            print("Splashpage Length [{}]".format(len(splashpage)))
            
            print("Splashpage Breaking...")
            # <a> TAG Splash Page Breaking
            # a = splash_breaking_a(splashpage)
            # for v in a:
            #     [status, _ ] = reqst.get(v)
            #     if status == 200:
            #         return True
            # -----------------------------
            #TODO: When You know you broke the page and allow DATA SENDING
            # return True
            return False
            
        elif 500 <= status <= 599:
            """
                station.active(False) seems to flush wifi module

                board output:
                    I (35596) wifi: flush txq
                    I (35596) wifi: stop sw txq
                    I (35596) wifi: lmac stop hw txq
            """
            station.active(False)
            station.active(True)
            return False
        else:
            print("Splashpage [Failed]")
            return False

    elif 500 <= status <= 599:
        """
            station.active(False) seems to flush wifi module

            board output:
                I (35596) wifi: flush txq
                I (35596) wifi: stop sw txq
                I (35596) wifi: lmac stop hw txq
        """
        station.active(False)
        station.active(True)
        return False