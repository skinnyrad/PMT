# uRequest extension
# + Socket timeout
# + HTTP Redirection
# + Tag Parsing
# David Tougaw & Ben Compton


import usocket
# garbage collector
import gc
from machine import reset,Timer

def handlerTimer(timer):
    print("DNS_Lookup_Test: Timer Timeout")
    #Resets the device in a manner similar to pushing the external RESET button.
    reset()

def request_dns_internet(method, url, data=None, json=None, headers={}, stream=None, timeout=3000):
    try:
        proto, dummy, host, path = url.split("/", 3)
    except ValueError:
        proto, dummy, host = url.split("/", 2)
        path = ""
    if proto == "http:":
        port = 80
    elif proto == "https:":
        import ussl
        port = 443
    else:
        raise ValueError("Unsupported protocol: " + proto)

    if ":" in host:
        host, port = host.split(":", 1)
        port = int(port)

    #DNS Resolving Test
    timer = Timer(0)
    timer.init(period=timeout, mode=Timer.ONE_SHOT,callback=handlerTimer)

    ai = usocket.getaddrinfo(host, port, 0, usocket.SOCK_STREAM)
    if ai != []:
        print("DNS Test Lookup [OK]")
        # deinit timer
        timer.deinit()

    ai = ai[0]
    print(str(ai))
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
            elif l.startswith(b"Location:") and not 200 <= status <= 299:
                location = str(l[10:])[2:-5]
                #print("Location [{}]".format(location))
                # close socket (should prevent ENOMEM error)
                s.close()
                del s
                gc.collect()
                print("Redirection [{}]".format(location))
                # need to get the method from the redirection
                return [status,location,None]
    except (OSError, TypeError) as err:
        # if not s:
        #     s.close()
        raise
    
    print("Status_Code [{}]".format(status))
    body = s.read()
    s.close()
    del s
    gc.collect()
    return [status,None,body.decode("utf-8")]

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
    try:
        proto, dummy, host, path = url.split("/", 3)
    except ValueError:
        proto, dummy, host = url.split("/", 2)
        path = ""
    if proto == "http:":
        port = 80
    elif proto == "https:":
        import ussl
        port = 443
    else:
        raise ValueError("Unsupported protocol: " + proto)

    if ":" in host:
        host, port = host.split(":", 1)
        port = int(port)

    #DNS Resolving Test
    timer = Timer(0)
    timer.init(period=timeout, mode=Timer.ONE_SHOT,callback=handlerTimer)

    ai = usocket.getaddrinfo(host, port, 0, usocket.SOCK_STREAM)
    if ai != []:
        print("DNS Redirect Lookup [OK]")
        # deinit timer
        timer.deinit()

    ai = ai[0]
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
                return test_dns_internet(location)
    except OSError as err:
        # if not s:
        #     s.close()
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
    try:
        proto, dummy, host, path = url.split("/", 3)
    except ValueError:
        proto, dummy, host = url.split("/", 2)
        path = ""
    if proto == "http:":
        port = 80
    elif proto == "https:":
        import ussl
        port = 443
    else:
        raise ValueError("Unsupported protocol: " + proto)
    if ":" in host:
        host, port = host.split(":", 1)
        port = int(port)
    #default value
    #redirected = False
    ai = usocket.getaddrinfo(host, port, 0, usocket.SOCK_STREAM)
    ai = ai[0]
    print(str(ai))
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
