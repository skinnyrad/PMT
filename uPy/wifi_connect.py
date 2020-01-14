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

def station_connected(station: WLAN):
    print("Connected...Testing Access...")
    resolved = getaddrinfo("www.google.com", 80)
    if resolved == []:
        print("No Internet Access")
        station.disconnect()
    else:
        print("Internet Accessible")
