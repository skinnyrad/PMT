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
#import urequests
import usocket
import ujson
import utime
import ubinascii
import ssl

import reqst



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

r = str(reqst.get(url))

# get link and try connection
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
        req = reqst.get(proto+"//"+host+"/"+path)
        print("A LINKS \n")
        print(req)
        if req.status_code == 200:
            req = reqst.get("https://pmtlogger.000webhostapp.com/api/testConnection.php")
            print("Content: \t"+req.content+"\n")
            print("Successful GET!!!! ***** Fireworks *****")
            
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
    