from machine import UART
from utime import sleep

def GNSS_parse(data):
    return data
​
def GNSS_UART_ISR():
    #disable UART ISR
    nothing = 0
​
    #Enable Timer ISR
​
def GNSS_TIMER_ISR():
    oldRXLength = currentRXLength
    currentRXLength = uart1.any()
​​
# create a new UART controller
uart1 = UART(1,9600, tx=22, rx=21, txbuf=1024, rxbuf=1024)
​
# Used for finding new packets
oldRXLength = 0
currentRXLength = 0
​
#make a dictionary for RMC data
RMCdata = {}
RMCfound = False
​
while(True):
    oldRXLength = currentRXLength
    currentRXLength = uart1.any()
​
    # Don't print nothing
    if(currentRXLength == 0):
        continue
​
    # Packet still sending
    if(oldRXLength != currentRXLength):
        sleep(0.2)
        continue
​
    else:
        data = uart1.read(currentRXLength)
        lines = str(data).split('\\r\\n')
        #for line in lines:
        #    print(line)
​
        # search each line for RMC data set
        for line in lines:
            if(line[3:6] == 'RMC'):
                RMCfound = True
                print(line)
                break #we found RMC data
        
        if RMCfound:
            RMCfound = False
            fields = line.split(',')
​
            #fill out RMC dataclass
            RMCdata['status'] = fields[2]
            #if data is invalid, throw it away
            if(RMCdata['status'] == 'V'):
                continue
            
            # Time
            time = fields[1]
            RMCdata['hour'] = time[0:2]
            RMCdata['minute'] = time[2:4]
            RMCdata['second'] = time[4:6]
​
            # Latitude
            hhmm_mmmm = fields[3]
            RMCdata['latitude'] = float(hhmm_mmmm[0:2])
            fraction = '.' + hhmm_mmmm[2:4] + hhmm_mmmm[5:9]
            RMCdata['latitude'] = RMCdata['latitude'] + float(fraction)*100/60
            # N = +     S = -
            if(fields[4] == 'S'):
                RMCdata['latitude'] = RMCdata['latitude'] * -1
​
            #Longitude
            hhmm_mmmm = fields[5][1:]
            RMCdata['longitude'] = float(hhmm_mmmm[0:2])
            fraction = '.' + hhmm_mmmm[2:4] + hhmm_mmmm[5:9]
            RMCdata['longitude'] = RMCdata['longitude'] + float(fraction)*100/60
            # E = +     W = -
            if(fields[6] == 'W'):
                RMCdata['longitude'] = RMCdata['longitude'] * -1
​
            #Speed and Course
            RMCdata['speed'] = float(fields[7])
            RMCdata['course'] = float(fields[8])
​
            #Date
            RMCdata['day'] = fields[9][0:2]
            RMCdata['month'] = fields[9][2:4]
            RMCdata['year'] = fields[9][4:6]
​
            print(RMCdata)