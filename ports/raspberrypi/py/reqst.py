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
#  Filename : reqst.py
#
#  uRequest extension
#  + Socket timeout
#  + HTTP Redirection
#  + Tag Parsing

import socket
import gc
from machine import proc_restart
import ssl
from io import StringIO
from os import getpid


MAX_DNS_COUNT = 2


def recv_all(soc):
    fragments = []
    while True: 
        chunk = soc.recv(10240)
        if not chunk: 
            break
        fragments.append(chunk)

    return b''.join(fragments)



# Returns Tuple of information from URL
def breakdown_url(url):
    try:
        proto, dummy, host, path = url.split("/", 3)
        path = "/{}".format(path) # Wireshark observation
    except ValueError:
        proto, dummy, host = url.split("/", 2)
        path = ""
    if proto == "http:":
        port = 80
    elif proto == "https:":
        port = 443
    else:
        raise ValueError("Unsupported protocol: " + proto)

    if ":" in host:
        host, port = host.split(":", 1)
        port = int(port)

    return [proto, dummy, host, path, port]



def handlerTimer(timer):
    print("DNS_Lookup_Test: Timer Timeout")
    #Resets the device in a manner similar to pushing the external RESET button.
    proc_restart(getpid())



# Initial check for open internet or splash page redirection
# Return Value: 5 value list: [addr, status, location, body, headers]
def request_dns_internet(method, url, data=None, json=None, headers={}, stream=None, gdt=None, timeout=3000):
    print("\n--------------")
    print("request_dns_internet @ {}".format(url))
    
    # Get stuff from URL
    _, dummy, host, _, _ = breakdown_url(url)
    # No need to check if Host is IP. It's first request we
    # do after connection

    location = None
    addr = None
    status = None
    body = None
    recvd_headers = None

    # DNS Resolve
    dns_count = 0
    while dns_count <= MAX_DNS_COUNT:
        try:
            dns_count += 1
            print("Testing DNS attempt {0}/{1}".format(dns_count,MAX_DNS_COUNT))
            ai = socket.getaddrinfo(host, 80, 0, socket.SOCK_STREAM)
            if ai != []:
                break
            else:
                print("DNS Lookup [Failed]")
                return [None,584,None,None,None]

        except socket.gaierror as err:
            print("socket.gaierror in request_dns_internet: {}".format(err))
            if dns_count >= MAX_DNS_COUNT:
                raise socket.gaierror

        except Exception as err:
            print("Default Exception in request_dns_internet: {}".format(err))
            return None


    if ai != []:
        print( "DNS address info: {}".format(str(ai[0])) )
        print("DNS Lookup [OK]")
    else:
        print("DNS Lookup [Failed]")
        return [None,584,None,None,None]
    

    # Optionally feed guard-dog timer
    if gdt is not None:
        gdt.feed()


    ai = ai[0]
    addr = ai[-1]
    recvd_headers = {}
    s = socket.socket(ai[0], ai[1], ai[2])
    try:
        print("Attempting connection to {}...".format(ai[-1]))
        s.connect(ai[-1])
        #if proto == "https:":
        #    s = ssl.wrap_socket(s, server_hostname=host)
        s.sendall( "{} /api/ HTTP/1.0\r\n".format(method).encode() )
        if not "Host" in headers:
            s.sendall( "Host: {}\r\n".format(host).encode() )
        # Iterate over keys to avoid tuple alloc
        for k in headers:
            s.sendall( "{0}: {1}\r\n".format(k,headers[k]).encode() )
        if json is not None:
            assert data is None
            from json import dumps
            data = dumps(json)
            s.sendall("Content-Type: application/json\r\n")
        if data:
            s.sendall( "Content-Length: {}\r\n".format(len(data)).encode() )
        s.sendall(b"\r\n") # end headers
        if data:
            s.sendall(data)


        data = recv_all(s).decode('utf-8')
        data = StringIO(data)
        l = data.readline().rstrip()
        print(l)
        l = l.split(None, 2)
        status = int(l[1])
        print("Status_Code [{}]".format(status))
        reason = ""
        if len(l) > 2:
            reason = l[2].rstrip()
        # Dealing with headers
        while True:
            l = data.readline()
            if not l or l == "\r\n":
                break
            #print(l)
            # Pull all headers
            colon = l.find(':')
            if colon != -1:
                key = l[0:colon]
                val = l[colon+1:].strip()
                print("Header (key:val) {0}:{1}".format(key,val))
                recvd_headers[key]=val
            # Currently not supporting chunked transfer
            if l.startswith("Transfer-Encoding:"):
                if "chunked" in l:
                    s.close()
                    del s
                    raise ValueError("Unsupported " + l)
            # check for redirection
            elif l.startswith("Location:"): # and not 200 <= status <= 299:
                location = recvd_headers["Location"]
                print("Redirection [{}]".format(location))
                # need to get the method from the redirection
        
        # the rest is the body
        body = data.read()

    except (OSError, TypeError) as e:
        print("request_dns_internet Error: {0}".format(str(e)))

    s.close()
    del s
    gc.collect()
    print("Returning from request_dns_internet with:")
    return [addr, status, location, body, recvd_headers]



def request_splash_page(method, url, data=None, json=None, headers={}, gdt=None, stream=None, timeout=3000):
    print("\n---------------")
    print("request_splash_page @ {}".format(url))
    
    # Get stuff from URL
    proto, dummy, host, path, port = breakdown_url(url)
    
    # DNS Host or IPv4
    is_ipv4 = False
    eight_bits = host.split(".")[0]
    # check 8 bits is enought
    try:
        if 0 < int(eight_bits) < 255:
            is_ipv4 = True
    except ValueError:
        # not an IP
        pass

    #DNS Resolving Test
    if not is_ipv4:
        dns_count = 0
        while dns_count <= MAX_DNS_COUNT:
            try:
                dns_count += 1
                print("Testing DNS attempt {0}/{1}".format(dns_count,MAX_DNS_COUNT))
                ai = socket.getaddrinfo(host, port, 0, socket.SOCK_STREAM)
                if ai != []:
                    print("DNS Lookup [OK]")
                    ai = ai[0]
                    break
                else:
                    print("DNS Lookup [Failed]")
                    return [584,None]
                
                dns_count += 1

            except socket.gaierror as err:
                print("socket.gaierror in request_dns_internet: {}".format(err))
                if dns_count >= MAX_DNS_COUNT:
                    raise socket.gaierror

            except Exception as err:
                print("Default Exception in request_dns_internet: {}".format(err))
                return None

    else:
        # Is IPv4
        print("DNS Lookup [Skipped]\n")
        # socket settings
        ai = [2,1,0,(host,port)]


    # Optionally feed guard-dog timer
    if gdt is not None:
        gdt.feed()


    print(str(ai))
    addr = ai[-1]
    recvd_headers = {}
    s = socket.socket(ai[0], ai[1], ai[2])
    try:
        
        if proto == "https:":
            print("Wrapping SSL/TLS socket...")
            s = ssl.wrap_socket(s)#, server_hostname=host)
        print("Attempting connection to {}".format(ai[-1]))
        s.connect(ai[-1])

        s.sendall("{0} /{1} HTTP/1.0\r\n".format(method, path).encode())
        if not "Host" in headers:
            s.sendall("Host: {}\r\n".format(host).encode())
        # Iterate over keys to avoid tuple alloc
        for k in headers:
            s.sendall( "{0}: {1}\r\n".format(k,headers[k]).encode() )
        if json is not None:
            assert data is None
            import json
            data = json.dumps(json)
            s.sendall(b"Content-Type: application/json\r\n")
        if data:
            s.sendall( "Content-Length: {}\r\n".format(len(data)).encode() )
        s.sendall(b"\r\n")
        if data:
            s.sendall(data)


        data = recv_all(s).decode('utf-8')
        data = StringIO(data)
        l = data.readline().rstrip()
        print(l)
        l = l.split(None, 2)
        status = int(l[1])
        reason = ""
        if len(l) > 2:
            reason = l[2].rstrip()
        while True:
            l = data.readline()
            if not l or l == "\r\n":
                break
            #print(l)
            colon = l.find(':')
            if colon != -1:
                key = l[0:colon]
                val = l[colon+1:].strip()
                print("Header (key:val) {0}:{1}".format(key,val))
                recvd_headers[key]=val
            if l.startswith("Transfer-Encoding:"):
                if "chunked" in l:
                    s.close()
                    del s
                    raise ValueError("Unsupported " + l)
            elif l.startswith("Location:") and not 200 <= status <= 299:
                location = recvd_headers["Location"]          
                print("L2 Location [{}]".format(location))

        page = data.read()

    except OSError as err:
        print(str(err))
        s.close()
        del s
        gc.collect()
        raise
    
    print("Status_Code [{}]".format(status))

    s.close()
    del s
    gc.collect()
    return [addr,status,page,recvd_headers]



def request(method, url, data=None, json=None, headers={}, stream=None, gdt=None, timeout=0.5):
    print("\n--------------")
    print("request method={0}   URL={1}".format(method, url))

    # If string data, make into bytes
    if type(data) is str:
        data = data.encode()

    # DNS Host or IPv4
    is_ipv4 = False
    eight_bits = url.split(".")[0]
    # check 8 bits is enought
    try:
        if 0 < int(eight_bits) < 255:
            is_ipv4 = True
    except ValueError:
        # not an IP
        pass


    #DNS Resolving Test
    if not is_ipv4:

        # Get stuff from URL
        proto, dummy, host, path, port = breakdown_url(url)
        print("breakdown url returned: host:{0} port:{1} path:{2}".format(host,port,path))

        dns_count = 0
        while dns_count <= MAX_DNS_COUNT:
            try:
                dns_count += 1
                print("Testing DNS attempt {0}/{1}".format(dns_count,MAX_DNS_COUNT))
                ai = socket.getaddrinfo(host, port, 0, socket.SOCK_STREAM)
                if ai != []:
                    print("DNS Lookup [OK]")
                    ai = ai[0]
                    break
                else:
                    print("DNS Lookup [Failed]")
                    return [584,None]

            except socket.gaierror as err:
                print("socket.gaierror in request_dns_internet: {}".format(err))
                if dns_count >= MAX_DNS_COUNT:
                    raise socket.gaierror

            except Exception as err:
                print("Default Exception in request_dns_internet: {}".format(err))
                return None

    else:
        # Is IPv4
        print("URL breakdown & DNS Lookup [Skipped]\n")
        # socket settings
        ai = [2,1,0,(host,port)]
    

    # Optionally feed guard-dog timer
    if gdt is not None:
        gdt.feed()


    addr = ai[-1]
    recvd_headers = {}

    s = socket.socket(ai[0], ai[1], ai[2])
    # set timeout
    s.settimeout(timeout)
    try:
        print("Connecting to {} ...".format(ai[-1]))
        s.connect(ai[-1])
        if proto == "https:":
            s = ssl.wrap_socket(s)#, server_hostname=host)
        s.sendall("{0} /{1} HTTP/1.0\r\n".format(method, path).encode() )
        print("{1} /{0} HTTP/1.0\r\n".format(method, path).encode() )
        if not "Host" in headers:
            s.sendall("Host: {}\r\n".format(host).encode() )
        # Iterate over keys to avoid tuple alloc
        print("Sending Headers...")
        for k in headers:
            s.sendall( "{0}: {1}\r\n".format(k, headers[k]).encode() )
            print("{0}: {1}".format(k,headers[k]))
        if json is not None:
            assert data is None
            from json import dumps
            data = dumps(json)
            s.sendall(b"Content-Type: application/json\r\n")
        if data:
            s.sendall( "Content-Length: {}\r\n".format(len(data)).encode() )
            print( "Content-Length: {}\r\n".format(len(data)).encode() )
        s.sendall(b"\r\n")
        print("Headers Sent... \\r\\n")
        print("Sending body...")
        if data:
            s.sendall(data)
            print(data)
        
        data = recv_all(s).decode('utf-8')
        data = StringIO(data)
        l = data.readline().rstrip()
        print(l)
        l = l.split(None, 2)
        status = int(l[1])
        reason = ""
        if len(l) > 2:
            reason = l[2].rstrip()
        while True:
            l = data.readline()
            if not l or l == "\r\n":
                break
            l=l[0:-2] # remove newline chars
            colon = l.find(':')
            if colon != -1:
                key = l[0:colon]
                val = l[colon+1:].strip()
                print("Header (key:val) {0}:{1}".format(key,val))
                recvd_headers[key]=val
            #print(l)
            if l.startswith("Transfer-Encoding:"):
                if "chunked" in l:
                    raise ValueError("Unsupported " + l)
            elif l.startswith("Location:") and not 200 <= status <= 299:
                location = str(l[10:])[2:-5]
                print("Post Request Location [{}]".format(location))
                # close socket (should prevent ENOMEM error)
                s.close()
                del s
                gc.collect()
                print("Post Request Redirection")
                # need to get the method from the redirection
                return request_splash_page("GET",location)
    except OSError as err:
        print("OSError: {}".format(err))
        s.close()
        del s
        gc.collect()
        raise

    print("Status_Code [{}]".format(status))
    
    page = data.read()
    s.close()
    del s
    gc.collect()
    return [addr, status, recvd_headers, page]



def test_dns_internet(url, **kw):
    return request_dns_internet("GET", url, **kw)

def get_splash_page(url, **kw):
    return request_splash_page("GET", url, **kw)

def get(url, **kw):
    return request("GET", url, **kw)

def post(url, **kw):
    return request("POST", url, **kw)
