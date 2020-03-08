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

def handlerTimer(timer):
    print("Timer Timeout")
    #Resets the device in a manner similar to pushing the external RESET button.
    reset()

def station_connected(station: WLAN, wifiLogger: Logger):
    #TODO: remove print
    print("Connected...Testing Access...")
    wifiLogger.info("Connected...Testing Access...")
    # init harware timer
    timer = Timer(0)
    timer.init(period=3000, mode=Timer.ONE_SHOT,callback=handlerTimer)
    resolved = getaddrinfo("pmtlogger.000webhostapp.com", 80)
    timer.deinit()
    if resolved == []:
        #TODO: remove print
        print("No Internet Access")
        wifiLogger.debug("No Internet Access")
        station.disconnect()
    else:
        #TODO: remove print
        print("Internet Accessible")
        wifiLogger.debug("Internet Accessible")
