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
#  Filename : sd.py

# PINS Connections
#    MISO    PIN 2
#    MOSI    PIN 15
#    CLK     PIN 14
#    CS      PIN 13

from machine import SDCard
from uos import mount, umount

class SDWriter():
    def __init__(self, _sd_path="/sdcard", _filepath="data.txt"):
        self.sd_path = _sd_path
        self.filepath = self.sd_path + _filepath
        mount(SDCard(slot=3), _sd_path)
        self.file_ptr = open(self.filepath, "w")

    def __del__(self):
        self.file_ptr.close()
        umount(self.sd_path)

    def write(self, data):
        self.file_ptr.write(data)