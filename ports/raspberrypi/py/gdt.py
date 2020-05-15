# ---------------------------------------
#  _____  __  __ _______        __   ___  
# |  __ \|  \/  |__   __|      /_ | / _ \ 
# | |__) | \  / |  | |    __   _| || | | |
# |  ___/| |\/| |  | |    \ \ / / || | | |
# | |    | |  | |  | |     \ V /| || |_| |
# |_|    |_|  |_|  |_|      \_/ |_(_)___/ 
# ----------------------------------------
#  Version 1.0
#  Raspbian Lite version February 2020
#  Python 3.7
#  Filename : gdt.py

from threading import Timer
from os import system

class GDT():
    timer = None
    timeout = None
    station = None
    func = None
    logger = None

    def __init__(self, timeout, station, logger=None):
        self.set_timeout(timeout)
        self.set_station(station)
        self.set_func()
        self.set_logger(logger)
        self.init_timer()

    def init_timer(self):
        if self.timer is not None:
            del self.timer
        self.timer = Timer(self.timeout, self.func)
        self.timer.start()

    def deinit_timer(self):
        if self.timer is not None:
            self.timer.cancel()

    def set_timeout(self, timeout):
        self.timeout = timeout

    def set_station(self, station):
        self.station = station

    def set_func(self, func=None):
        if func is None:
            self.func = self.timer_exp_func
        else:
            self.func = func

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
            with open("SSID.log", "rt") as fp:
                self.logger.write_line(fp.read())
        system('sudo reboot')
