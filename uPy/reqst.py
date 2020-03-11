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

# def redirect(method, url, data=None, json=None, headers={}, stream=None, timeout=0.5, parseSplashPage=True):
#     # force garbage collection
#     gc.collect()
#     # global redirected
#     # redirected = False
#     try:
#         proto, dummy, host, path = url.split("/", 3)
#     except ValueError:
#         proto, dummy, host = url.split("/", 2)
#         path = ""
#     if proto == "http:":
#         port = 80
#     elif proto == "https:":
#         import ussl
#         port = 443
#     else:
#         raise ValueError("Unsupported protocol: " + proto)

#     if ":" in host:
#         host, port = host.split(":", 1)
#         port = int(port)

#     ai = usocket.getaddrinfo(host, port, 0, usocket.SOCK_STREAM)
#     ai = ai[0]
#     print("DNS_Lookup_Redirection: "+str(ai))
#     s = usocket.socket(ai[0], ai[1], ai[2])
#     # set timeout
#     s.settimeout(timeout)
#     # force gc
#     gc.collect()
#     try:
#         s.connect(ai[-1])
#         if proto == "https:":
#             s = ussl.wrap_socket(s, server_hostname=host)
#         s.write(b"%s /%s HTTP/1.0\r\n" % (method, path))
#         if not "Host" in headers:
#             s.write(b"Host: %s\r\n" % host)
#         # Iterate over keys to avoid tuple alloc
#         for k in headers:
#             s.write(k)
#             s.write(b": ")
#             s.write(headers[k])
#             s.write(b"\r\n")
#         if json is not None:
#             assert data is None
#             import ujson
#             data = ujson.dumps(json)
#             s.write(b"Content-Type: application/json\r\n")
#         if data:
#             s.write(b"Content-Length: %d\r\n" % len(data))
#         s.write(b"\r\n")
#         if data:
#             s.write(data)

#         l = s.readline()
#         print(l)
#         l = l.split(None, 2)
#         status = int(l[1])
#         reason = ""
#         if len(l) > 2:
#             reason = l[2].rstrip()
#         while True:
#             # splash page
#             l = s.readline()
#             if not l or l == b"\r\n":
#                 break
#             print(l)
#             if l.startswith(b"Transfer-Encoding:"):
#                 if b"chunked" in l:
#                     raise ValueError("Unsupported " + l)
#             elif l.startswith(b"Location:") and not 200 <= status <= 299:
#                 raise OSError("Redirect of Redirect not allowed")
#             #     location = str(l[10:])[2:-5]
#             #     print ("\n\n\n"+location+"\n\n\n")
#             #     # need to get the method from the redirection
#             #     return request('GET',location)
#     except OSError:
#         s.close()
#         raise

#     if parseSplashPage:
#         # read all bytes from socket
#         r = s.read()
#         print(r)
#         # parse socket bytes
#         # a = []
#         # while r.find(b'<a') != -1:
#         #     beg = r.find(b'<a')
#         #     end = r.find(b'</a>')+4
#         #     a.append(r[beg:end])
#         #     r = r[end+1:]
        
#         #free memory   
#         del r
#         # close socket
#         s.close()
#         del s
#         gc.collect()

#         # b = [a[i][3:a[i].find(b'>')] for i in range(len(a))]
#         # return b
#     else:
#         resp = Response(s)
#         s.close()
#         resp.status_code = status
#         resp.reason = reason
#         # resp.was_redirected = redirected

#         return resp

def request(method, url, data=None, json=None, headers={}, stream=None, timeout=500):
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
        print("DNS Lookup [OK]")
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
                # close socket (should prevent ENOMEM error)
                s.close()
                del s
                gc.collect()
                print ("Redirection ["+location+"]")
                # need to get the method from the redirection
                #redirected = True
                #return redirect('GET',location)
    except OSError as err:
        # if not s:
        #     s.close()
        raise
    if s:
        print("Status_Code [{}]".format(status))
        r = s.read()
        print(r)
        # parse socket bytes
        a = []
        while r.find(b'<a') != -1:
            beg = r.find(b'<a')
            end = r.find(b'</a>')+4
            a.append(r[beg:end])
            r = r[end+1:]

        print(a)

        #free memory   
        del r
        # close socket
        s.close()
        del s
        gc.collect()
    #resp = Response(s)
    #resp.status_code = status
    #resp.reason = reason
    # resp.was_redirected = redirected
    #return resp


# def head(url, **kw):
#     return request("HEAD", url, **kw)

def test_dns_internet(url, **kw):
    return request("GET", url, **kw)

# def post(url, **kw):
#     return request("POST", url, **kw)

# def put(url, **kw):
#     return request("PUT", url, **kw)

# def patch(url, **kw):
#     return request("PATCH", url, **kw)

# def delete(url, **kw):
#     return request("DELETE", url, **kw)
