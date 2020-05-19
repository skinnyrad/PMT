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
#  Filename : gps.py

# Pins
# GPS TX => default TX for serial0
# GPS RX => default RX for serial0

from serial import Serial
import logging

class GPS():
    def __init__(self, port="/dev/serial0", _baudrate=9600):
        # create a new UART controller
        self.uart = Serial( port, _baudrate )
        
        # Used for finding new packets
        self.oldRXLength = 0
        self.currentRXLength = 0

        #make a dictionary for RMC data
        self.RMCdata = {}
        self.RMCfound = False
    

    def format_RMCdata(self, data):
        # Time
        self.RMCdata['time'] = data[1][0:2] + ':' + data[1][2:4] + ':' + data[1][4:6]

        # Latitude
        hhmm_mmmm = data[3]
        self.RMCdata['latitude'] = float(hhmm_mmmm[0:2])
        fraction = '.' + hhmm_mmmm[2:4] + hhmm_mmmm[5:9]
        self.RMCdata['latitude'] = self.RMCdata['latitude'] + float(fraction)*100/60
        # N = +     S = -
        if(data[4] == 'S'):
            self.RMCdata['latitude'] = self.RMCdata['latitude'] * -1
        self.RMCdata['latitude'] = str(self.RMCdata['latitude'])

        #Longitude
        hhmm_mmmm = data[5][1:]
        self.RMCdata['longitude'] = float(hhmm_mmmm[0:2])
        fraction = '.' + hhmm_mmmm[2:4] + hhmm_mmmm[5:9]
        self.RMCdata['longitude'] = self.RMCdata['longitude'] + float(fraction)*100/60
        # E = +     W = -
        if(data[6] == 'W'):
            self.RMCdata['longitude'] = self.RMCdata['longitude'] * -1
        self.RMCdata['longitude'] = str(self.RMCdata['longitude'])

        # TODO: Let's revisit this...
        # #Speed and Course
        self.RMCdata['speed'] = float(data[7])
        # self.RMCdata['course'] = float(data[8])

        #Date
        self.RMCdata['date'] = str(2000 + int(data[9][4:6])) + '-' + data[9][2:4] + '-' + data[9][0:2]

    def parse_RMCdata(self, rawData):
        # search each line for RMC data set
        for d in rawData:
            if (d[3:6] == 'RMC') and (d[-4:] == '\\r\\n'):
                self.RMCfound = True
                break #we found RMC data
        
        if self.RMCfound:
            self.RMCfound = False
            data = d.split(',')

            if not (data[2] == 'V'):
                self.format_RMCdata(data)
        
        else:
            self.RMCdata = {}

    def get_RMCdata(self, defaultLogger = None):
        self.oldRXLength = self.currentRXLength
        self.currentRXLength = self.uart.inWaiting() # how many bytes not read?

        #if not unread bytes
        if(self.currentRXLength == 0):
            self.RMCdata = {}
            return [self.RMCdata, None]

        #if more bytes received, check for RMC data
        else:
            data = self.uart.read(self.currentRXLength).decode('utf-8')
            rawData = list(d.replace('\r\n', '\\r\\n') for d in str(data).replace('\\r\\n', '\r\n').splitlines(True))
            try:
                self.parse_RMCdata(rawData)
            except Exception as e:
                self.RMCdata = {}
                #TODO: remove print
                print(e)
                if defaultLogger != None:
                    defaultLogger.warning(str(e))
            return self.RMCdata