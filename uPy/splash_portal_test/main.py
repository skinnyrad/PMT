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
#  Filename : main.py

import network
import machine
import urequests
import usocket
import ujson
import utime
import ubinascii
import ssl

import reqst

# Returns the number of seconds, as an integer, since the Epoch,
# assuming that underlying RTC is set and maintained as described above.
# If an RTC is not set, this function returns number of seconds since a
# port-specific reference point in time (for embedded boards without a
# battery-backed RTC, usually since power up or reset). If you want to develop
# portable MicroPython application, you should not rely on this function to 
# provide higher than second precision.
# -------------------------
# Microsecond ticks elapsed



target_host = "www.google.com"
url = "http://%s" % target_host
target_port = 80
# Create a station object to store our connection
station = network.WLAN(network.STA_IF)



# activate station
station.active(True)
station.scan()
station.connect("Dunkin' Donuts Guest","")
while not station.isconnected():
    utime.sleep(1)

start = utime.ticks_us()
r = str(reqst.get(url))
print(str(r))
#get link and try connection
for a in r.split('"'):
    try:
        proto, dummy, host, path = a.split("/", 3)
    except ValueError:
        try:
            proto, dummy, host = a.split("/", 2)
            path = ""
        except ValueError:
            # not an url, move on
            continue
    if proto == "http:" or proto == "https:":
        print("URL Found: "+proto+"//"+host+"/"+path)
        req = urequests.get(proto+"//"+host+"/"+path)
        print("A LINKS \n")
        print(req.status_code)
        if req.status_code == 200:
            req = urequests.get("https://pmtlogger.000webhostapp.com/api/testConnection.php")
            print("Content: \t"+req.content+"\n")
            print("Successful GET!!!! ***** Fireworks *****")
            break
et = utime.ticks_diff(utime.ticks_us(), start)
print("ET (us): "+str(et))
        #     break
    # else:
    #     raise ValueError("Unsupported protocol: " + proto)

# # Create STREAM TCP socket
# sock = usocket.socket(usocket.AF_INET,usocket.SOCK_STREAM)

# # time in seconds
# sock.settimeout(0.5)

# # address resolving
# sockaddr = usocket.getaddrinfo(targetgit _host, target_port)

# path = '/'
# # send some data 
# startRequest = "GET %s HTTP/1.1\r\nHost:%s\r\n\r\n" % (path ,target_host)
# try:
#     sock.connect(sockaddr[0][-1])
#     utime.sleep(1)
#     sock.send(startRequest.encode()) 
#     # receive some data 
#     response = sock.recv(4096)  
#     http_response = repr(response)

#     httpHeaders = http_response.split('\\r\\n')
#     url = ""
#     # find redirect url
#     for h in httpHeaders:
#         if h[0:8] == "Location":
#             #Location url found
#             url = h.split('//')
#             break
#     if url:
#         urlArray = url.split('/',3)
#         host = urlArray[0]
#         sockaddr = usocket.getaddrinfo(host, 80)
#         sock.connect(sockaddr[0][-1])
#         utime.sleep(1)
#         sock.send(startRequest.encode()) 
#         # receive some data 
#         response = sock.recv(4096)  
#         http_response = repr(response)

#         target_host = urlArray[2]
#         path = urlArray[3]
#         req = "GET /%s HTTP/1.1\r\nHost:%s\r\n\r\n" % (path ,target_host)
    
    
#     print(str(http_response[0:14]))
# except OSError as e:
#     print(e)
    