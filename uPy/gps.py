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
#  Filename : gps.py

# Pins
# GPS TX => Pin 21 (Master RX)
# GPS RX => Pin 22 (Master TX)

##########################################################
# TX Ability: UBX protocol
#   UBX protocol (ordered):
#   SyncChar1 = 181 (base 10)(always)
#   SyncChar2 = 98 (base 10)(always)
#   CLASS = (1 byte)
#   ID = (1 byte)
#   LENGTH = (2 byte) (little endian) (send byte 1 then byte 0)
#   PAYLOAD = (LENGTH bytes)
#   Checksum A = (1 byte) (calculated over CLASS through PAYLOAD)
#   Checksum B = (1 byte) (calculated over CLASS through PAYLOAD)

# Checksum calculation:
#   CK_A = 0, CK_B = 0
#   For(I=0;I<N;I++)
#   {
#       CK_A = CK_A + Buffer[I]
#       CK_B = CK_B + CK_A
#   }

##########################################################

from machine import UART
from utime import sleep

class GPS():
    def __init__(self, mac=1, _baudrate=9600, _tx=22, _rx=21, _txbuf=1024, _rxbuf=1024):
        # create a new UART controller
        self.uart = UART(mac, _baudrate, tx=_tx, rx=_rx, txbuf=_txbuf, rxbuf=_rxbuf)
        
        # Used for finding new packets
        self.oldRXLength = 0
        self.currentRXLength = 0

        #make a dictionary for RMC data
        self.RMCdata = {}
        self.RMCfound = False
    
    def __del__(self):
        self.uart.deinit()

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
        # self.RMCdata['speed'] = float(data[7])
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

    def get_RMCdata(self):
        self.oldRXLength = self.currentRXLength
        self.currentRXLength = self.uart.any()

        # Don't print nothing
        if(self.currentRXLength == 0):
            self.RMCdata = {}
            return self.RMCdata

        else:
            data = self.uart.read(self.currentRXLength)
            rawData = list(d.replace('\r\n', '\\r\\n') for d in str(data).replace('\\r\\n', '\r\n').splitlines(True))
            try:
                self.parse_RMCdata(rawData)
            except Exception as e:
                self.RMCdata = {}
                print("Warning: " + str(e))
            return self.RMCdata

    # Sends a message according to the UBX protocol over the UART connection
    # CLASS = integer
    # ID    = integer
    # PAYLOAD = bytearray (not string)
    def sendUBX(self, CLASS, ID, PAYLOAD):

        if(not self.uart):
            print("Error: Cannot send. UART not initialized")
            return -1 #cannot send if UART not set up

        #length of payload is referenced a lot
        payload_len = len(bytearray(PAYLOAD))

        #construct the message to send
        msg = bytearray(6 + payload_len) 

        msg[0] = 181
        print("syn1[0]:"+ hex(msg[0]))

        msg[1] = 98
        print("syn2[1]:"+ hex(msg[1]))

        msg[2] = CLASS
        print("CLASS[2]:"+ hex(msg[2]))

        msg[3] = ID
        print("ID[3]:"+ hex(msg[3]) )

        #length is below
        if(payload_len > 65535):
            print("Error: Payload too large")
            return -2
        
        #length is Little Endian
        length_arr = bytearray(2)
        length_arr[1] = payload_len % 256 #upper byte second
        length_arr[0] = payload_len - (payload_len % 256) #lower byte first
        msg[4:6] = length_arr
        print("LENGTH[4:6]:"+ str(int.from_bytes(msg[4:6], 'little', 0)) )


        msg[6:] = bytearray(PAYLOAD)
        print("PAYLOAD[6:]:"+ str(PAYLOAD))
        #for i in msg[6:]:
        #    print( hex(msg[i]) )

        #calculate checksum
        # !!do not include sync bytes!!
        checksum = self._calculateChecksum(msg[2:])
        print("CHECKSUM:"+ hex(checksum[0])+ " "+ hex(checksum[1]))

        #add checksum to end
        msg = bytearray(msg+checksum)
        print("Complete Message:"+ str(msg))
        #for i in msg[0:]:
        #    print( hex(msg[i]) )

        #send
        len_written = self.uart.write(msg)
        
        if(len_written != len(msg)):
            print("Warning: bytes sent unequal to messaage length")


        #wait for and process reply
        reply = self._processReply(3000)
        WhatsAfter = self._processReply()


    
    
    # Returns a length 2 bytearray checksum for the UBX protocol
    # [0]=CK_A, [1]=CK_B
    # Support function, not to be called externally
    #Confirmed Correct implementation - Curran Hyde Feb 15 2020
    def _calculateChecksum(self, msg):
        checksum = bytearray(2)
        for i in range(0,len(msg)):
            checksum[0] += msg[i]
            checksum[1] += checksum[0]
        return checksum


    # waits to recieve either ACK or NACK.
    #   timeout: specify in milliseconds how long to wait for a reply
    #       or 0 to wait infinitely
    #   returns a byte array of the message received
    #   returns -1 for timeout
    def _processReply(self,timeout=0):
        import utime
        start = utime.ticks_ms()

        #messge incoming
        msg = bytearray()

        #state machine based
        state = 0
        
        #incoming message
        sync = bytearray(2)
        sync[0] = 181  
        sync[1] = 98

        print("__entering loop")
        while(True):
            
            length = self.uart.any()
            
            #no sync characters received
            if(state == 0 and length):
                data = bytearray(self.uart.read(1))
                print( str(data[0]) )
                if(data[0] == sync[0]):
                    print("REPLY_INFO: FIRST SYNC RECVD")
                    state = 1
                        
           
           #first sync character received
            elif(state == 1 and length):
                data = bytearray(self.uart.read(1))
                if(data[0] == sync[1]):
                    print("REPLY_INFO: SECOND SYNC RECVD")
                    state = 2
                elif(data[0] == sync[0]): # it may be possible to receive two of the first sync.
                    print("REPLY_INFO: FIRST SYNC RECVD")
                    state = 1
                else:
                    print("REPLY_INFO: SECOND SYNC NOT SEEN RETURNING TO S0")
                    state = 0
            

            #both sync characters recvd.
            #wait until 4 bytes of header received
            elif(state == 2 and length >= 4):
                data = bytearray(self.uart.read(4))
                CLASS = data[0]
                print("REPLY_INFO: CLASS: "+ hex(CLASS))

                ID = data[1]
                print("REPLY_INFO: ID: "+ hex(ID))

                if(CLASS == 0x05 and ID == 0x00):
                    print("REPLY_INFO: NACK RECEIVED")
                elif(CLASS == 0x05 and ID == 0x01):
                    print("REPLY_INFO: ACK RECEIVED")

                LENGTH = int.from_bytes(data[2:4],'little',0)
                print("REPLY_INFO: LENGTH:"+ hex(LENGTH))
                msg = bytearray(msg+sync+data)
                state = 3
            
            #header has been received
            # wait until LENGTH bytes of paylaod received
            elif(state == 3 and length >= LENGTH+2):
                #get payload
                payload = bytearray(self.uart.read(LENGTH))
                print("Payload: ")
                for i in payload:
                    print( hex(payload[i]) )

                #get checksum
                ck_a = bytearray(self.uart.read(1))
                ck_b = bytearray(self.uart.read(1))
                msg = bytearray(msg+ payload)
                
                #verify checksum
                my_ck = self._calculateChecksum(msg[2:])
                if(my_ck[0] != ck_a[0] or
                    my_ck[1] != ck_b[0]):
                    print("REPLY_INFO: !WARNING! checksum verification failed (or checksum generator written wrong) :(")
                else:
                    print("REPLY_INFO: Checksum successfully verified")

                #append their checksum to end of message
                msg = bytearray(msg+ ck_a+ ck_b)
                print("FULL_MESSAGE:"+ str(msg))
                #for i in msg:
                #    print( hex(msg[i]) )
                
                return msg


            #check for timeout
            if(timeout):
                now = utime.ticks_ms()
                if(utime.ticks_diff(now,start) >= timeout
                    and state == 0):
                    print("TIMEOUT")
                    return bytearray("TIMEOUT")

        


