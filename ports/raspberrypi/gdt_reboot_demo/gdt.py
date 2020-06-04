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
import os
import machine

class GDT():
    timer = None
    timeout = None
    func = None
    logger = None
    wifi_station = None
    pid = None

    def __init__(self, timeout, pid=None, logger=None, wifi_station=None):
        self.set_timeout(timeout)
        self.set_pid(pid)
        self.set_func()
        self.set_logger(logger)
        self.set_wifi_station(wifi_station)
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
    
    def set_pid(self, pid):
        self.pid=pid

    def set_func(self, func=None):
        if func is None:
            self.func = self.timer_exp_func
        else:
            self.func = func

    def set_logger(self, logger=None):
        self.logger = logger
    
    def set_wifi_station(self, wifi_station=None):
        self.wifi_station = wifi_station

    def reset_timer(self):
        self.deinit_timer()
        self.init_timer()

    def feed(self):
        self.reset_timer()

    def timer_exp_func(self):
        print("Guard func running")
        if self.logger is not None:
            from logging import runtime_dir
            # If the SSID file exists, read the current SSID we are connected to and blacklist it
            if os.access( os.path.join(runtime_dir, "SSID.log"), os.F_OK ):
                with open( os.path.join(runtime_dir, "SSID.log"), "rt") as fp:
                    self.logger.write_line(fp.read())
        # Try rebooting the process
        try:
            print("Rebooting process")
            machine.proc_restart(self.pid)
        # If proc_reboot fails then reboot board
        except Exception as err:
            print(err)
            #print("Rebooting board")
            machine.reset()
