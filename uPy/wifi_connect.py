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

import logging
import reqst

def station_connected(station: WLAN, Logger: wifiLogger):
    wifiLogger.info("Connected...Testing Access...")
    resolved = getaddrinfo("pmtlogger.000webhostapp.com", 80)
    if resolved == []:
        #TODO: remove print
        print("No Internet Access")
        wifiLogger.debug("No Internet Access")
        station.disconnect()
    else:
        #TODO: remove print
        print("Internet Accessible")
        wifiLogger.debug("Internet Accessible")
        
