# uRequest extension
# + Socket timeout
# + HTTP Redirection
# + Tag Parsing
# David Tougaw & Ben Compton


import usocket
# garbage collector
import gc
from machine import reset,Timer
import ussl

# Returns Tuple of information from URL
def breakdown_url(url):
    try:
        proto, dummy, host, path = url.split("/", 3)
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
    reset()

def request_dns_internet(method, url, data=None, json=None, headers={}, stream=None, timeout=3000):
    # Get stuff from URL
    proto, dummy, host, path, port = breakdown_url(url)
    # No need to check if Host is IP. It's first request we
    # do after connection
    # TODO: Uncomment if we decide it's needed
    # init harware timer
    # timer = Timer(0)
    # TODO: Uncomment this for solution
    #timer.init(period=3000, mode=Timer.ONE_SHOT,callback=handlerTimer)
    location = None

    ai = usocket.getaddrinfo(host, port, 0, usocket.SOCK_STREAM)
    #TODO: Uncomment this for solution
    #timer.deinit()
    if ai != []:
        print(str(ai))
        print("DNS Lookup [OK]")
    else:
        print("DNS Lookup [Failed]")
        return [584,None,None]

    ai = ai[0]
    s = usocket.socket(ai[0], ai[1], ai[2])
    try:
        s.connect(ai[-1])
        if proto == "https:":
            s = ussl.wrap_socket(s, server_hostname=host)
        s.write(b"%s / HTTP/1.0\r\n" % (method))
        if not "Host" in headers:
            s.write(b"Host: %s\r\n" % host)
        # Iterate over keys to avoid tuple alloc
        for k in headers:
            s.write(k)
            s.write(b": ")
            s.write(headers[k])
            s.write(b"\r\n")
        if json is not None:
            assert data is None
            import ujson
            data = ujson.dumps(json)
            s.write(b"Content-Type: application/json\r\n")
        if data:
            s.write(b"Content-Length: %d\r\n" % len(data))
        s.write(b"\r\n")
        if data:
            s.write(data)

        l = s.readline()
        print(l)
        l = l.split(None, 2)
        status = int(l[1])
        reason = ""
        if len(l) > 2:
            reason = l[2].rstrip()
        while True:
            l = s.readline()
            if not l or l == b"\r\n":
                break
            print(l)
            if l.startswith(b"Transfer-Encoding:"):
                if b"chunked" in l:
                    raise ValueError("Unsupported " + l)
            elif l.startswith(b"Location:"): # and not 200 <= status <= 299:
                location = str(l[10:])[2:-5]
                #print("Location [{}]".format(location))
                # close socket (should prevent ENOMEM error)
                # s.close()
                # del s
                # gc.collect()
                print("Redirection [{}]".format(location))
                # need to get the method from the redirection
    except (OSError, TypeError) as e:
        #TODO: remove print
        print("Warning: {0}".format(str(e)))

    print("Status_Code [{}]".format(status))
    body = s.read()
    s.close()
    del s
    gc.collect()
    return [status, location, body.decode("utf-8")]

def splash_breaking_a(b_html):
    # read all bytes from socket
    print("<a> search...")
    # parse socket bytes
    a = []
    while b_html.find(b'<a') != -1:
        beg = b_html.find(b'<a')
        end = b_html.find(b'</a>')+4
        a.append(b_html[beg:end])
        b_html = b_html[end+1:]
    
    #print(a)
    return a

def request_splash_page(method, url, data=None, json=None, headers={}, stream=None, timeout=3000):
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
        ai = usocket.getaddrinfo(host, port, 0, usocket.SOCK_STREAM)
        if ai != []:
            print("DNS Lookup [OK]")
            ai = ai[0]
        else:
            print("DNS Lookup [Failed]")
            return [584,None]
    else:
        # Is IPv4
        print("DNS Lookup [Skipped]")
        # socket settings
        ai = [2,1,0,(host,port)]

    print(str(ai))
    s = usocket.socket(ai[0], ai[1], ai[2])
    try:
        s.connect(ai[-1])
        if proto == "https:":
            s = ussl.wrap_socket(s, server_hostname=host)
        s.write(b"%s /%s HTTP/1.0\r\n" % (method, path))
        if not "Host" in headers:
            s.write(b"Host: %s\r\n" % host)
        # Iterate over keys to avoid tuple alloc
        for k in headers:
            s.write(k)
            s.write(b": ")
            s.write(headers[k])
            s.write(b"\r\n")
        if json is not None:
            assert data is None
            import ujson
            data = ujson.dumps(json)
            s.write(b"Content-Type: application/json\r\n")
        if data:
            s.write(b"Content-Length: %d\r\n" % len(data))
        s.write(b"\r\n")
        if data:
            s.write(data)

        l = s.readline()
        print(l)
        l = l.split(None, 2)
        status = int(l[1])
        reason = ""
        if len(l) > 2:
            reason = l[2].rstrip()
        while True:
            l = s.readline()
            if not l or l == b"\r\n":
                break
            #print(l)
            if l.startswith(b"Transfer-Encoding:"):
                if b"chunked" in l:
                    raise ValueError("Unsupported " + l)
            elif l.startswith(b"Location:") and not 200 <= status <= 299:
                location = str(l[10:])[2:-5]
                
                print("L2 Location [{}]".format(location))
                # close socket (should prevent ENOMEM error)
                s.close()
                del s
                gc.collect()
                print("L2 Redirection")
                # need to get the method from the redirection
                res = test_dns_internet(location)[0:1]
                return [res[0], res[-1]]
    except OSError as err:
        print(str(err))
        raise
    
    print("Status_Code [{}]".format(status))

    page = s.read()
    s.close()

    #-------DUNKIN-------
    # a = splash_breaking_a(page)
    # for v in a:
    #     print (str(v).split("\"")[1])   
    #     [status, _ ] = get(str(v).split("\"")[1])
    #     if status == 200:
    #         return [status, _ ]
    #--------------------


    del s
    gc.collect()
    return [status,page]

def request(method, url, data=None, json=None, headers={}, stream=None, timeout=0.5):

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
        ai = usocket.getaddrinfo(host, port, 0, usocket.SOCK_STREAM)
        if ai != []:
            print("DNS Lookup [OK]")
            ai = ai[0]
        else:
            print("DNS Lookup [Failed]")
            return [584,None]
    else:
        # Is IPv4
        print("DNS Lookup [Skipped]")
        # socket settings
        ai = [2,1,0,(host,port)]
    
    s = usocket.socket(ai[0], ai[1], ai[2])
    # set timeout
    s.settimeout(timeout)
    try:
        s.connect(ai[-1])
        if proto == "https:":
            s = ussl.wrap_socket(s, server_hostname=host)
        s.write(b"%s /%s HTTP/1.0\r\n" % (method, path))
        if not "Host" in headers:
            s.write(b"Host: %s\r\n" % host)
        # Iterate over keys to avoid tuple alloc
        for k in headers:
            s.write(k)
            s.write(b": ")
            s.write(headers[k])
            s.write(b"\r\n")
        if json is not None:
            assert data is None
            import ujson
            data = ujson.dumps(json)
            s.write(b"Content-Type: application/json\r\n")
        if data:
            s.write(b"Content-Length: %d\r\n" % len(data))
        s.write(b"\r\n")
        if data:
            s.write(data)
        l = s.readline()
        print(l)
        l = l.split(None, 2)
        status = int(l[1])
        reason = ""
        if len(l) > 2:
            reason = l[2].rstrip()
        while True:
            l = s.readline()
            if not l or l == b"\r\n":
                break
            #print(l)
            if l.startswith(b"Transfer-Encoding:"):
                if b"chunked" in l:
                    raise ValueError("Unsupported " + l)
            elif l.startswith(b"Location:") and not 200 <= status <= 299:
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
        #s.close()
        raise

    print("Status_Code [{}]".format(status))
    
    # No need to read
    #page = s.read()
    s.close()
    del s
    gc.collect()
    return [status,None]


def test_dns_internet(url, **kw):
    return request_dns_internet("GET", url, **kw)

def get_splash_page(url, **kw):
    return request_splash_page("GET", url, **kw)

def get(url, **kw):
    return request("GET", url, **kw)

def post(url, **kw):
    return request("POST", url, **kw)
