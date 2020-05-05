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
#  Filename : gdt.py

from machine import SDCard, Timer, reset
from uos import umount

class GDT():
    timer = Timer(0)
    timeout = None
    station = None
    func = None
    logger = None

    def __init__(self, timeout, station, func=None, logger=None):
        self.set_timeout(timeout)
        self.set_station(station)
        self.set_func(func)
        self.set_logger(logger)
        self.init_timer()

    def init_timer(self):
        self.timer.init(period=self.timeout, mode=Timer.ONE_SHOT, callback=self.func)

    def deinit_timer(self):
        self.timer.deinit()

    def set_timeout(self, timeout):
        self.timeout = timeout*1000
        self.reset_timer()

    def set_station(self, station):
        self.station = station
        self.reset_timer()

    def set_func(self, func=None):
        if func is None:
            self.func = self.timer_exp_func
        else:
            self.func = func
        self.reset_timer()

    def set_logger(self, logger=None):
        self.logger = logger

    def reset_timer(self):
        self.deinit_timer()
        self.init_timer()

    def feed(self):
        self.reset_timer()

    def timer_exp_func(self, timer):
        self.station.active(False)
        if self.logger is not None:
            with open("/sdcard/SSID.log", "r") as fp:
                self.logger.write_line(fp.read())
        umount("/sdcard")
        reset()
