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
#  Filename : request.py

#####
# Below is an implimentation that uses urllib.request
#####

import requests
import html_parser
import lxml.html

# The base request function
def py_request(url, method, headers={}, cookies=None, data=None, timeout=10, verify=False, gdt=None ):

    attempts = 1
    MAX_ATTEMPTS = 2
    while attempts <= MAX_ATTEMPTS:
        print("\nConnection attempt {0}/{1}".format(attempts,MAX_ATTEMPTS))
        attempts += 1
        
        if gdt is not None:
            gdt.feed()

        try:
            if method == 'GET':
                r = requests.get(url, headers=headers, cookies=cookies, data=data, timeout=timeout, verify=verify)
            elif method == 'POST':
                r = requests.post(url, headers=headers, cookies=cookies, data=data, timeout=timeout, verify=verify )
            break

        except requests.exceptions.RequestException as err:
            print("RequestException in py_request: {}".format(err))
            if attempts >= MAX_ATTEMPTS:
                raise ConnectionError


    addr = r.url
    status = r.status_code
    cookies = r.cookies
    recvd_headers = r.headers
    body = r.text
    if 'Set-Cookie' in recvd_headers:
        del recvd_headers['Set-Cookie']
    
    r.close()

    if gdt is not None:
        gdt.feed()


    # Handle <head> redirects
    # <head> redirects not natively supported. Handled here
    url = html_parser.get_head_redir_url(r)
    print('Head URL={}'.format(url))

    if url is not None:
        print("head object redirection to url={}".format(url))

        attempts = 1
        while attempts <= MAX_ATTEMPTS:
            try:
                print("<head> redirect attempt {0}/{1}".format(attempts,MAX_ATTEMPTS))
                attempts += 1

                r = requests.get(url, timeout=timeout, cookies=cookies, verify=verify)
                addr = r.url
                status = r.status_code
                cookies = r.cookies
                recvd_headers = r.headers
                body = r.text
                if 'Set-Cookie' in recvd_headers:
                    del recvd_headers['Set-Cookie']
                break

            except requests.exceptions.RequestException as err:
                print("RequestException in py_request: {}".format(err))
                if attempts >= MAX_ATTEMPTS:
                    raise ConnectionError

    if gdt is not None:
        gdt.feed()
    

    # Debugging
    print("\nRequest--------------------------------")
    print("Sent to:{}".format(r.request.url))
    print("{0} {1}".format(r.request.method, r.request.path_url) )
    print(r.request.headers)
    print(r.request.body)
    
    print("\nSent from:{}".format(r.url))
    print("{0} {1}".format(r.status_code, r.reason) )
    print(r.headers)
    print(r.text)
    print("\n---------------------------------------")
    
    r.close()

    return [addr, status, recvd_headers, cookies, body]


# replacing the original request function, must keep same parameters
# It'd be more efficient in all respects to only have one base requests function,
# but changing the parameters would cause too many issues, and would take to long to debug
def request(method, url, data=None, json=None, headers={}, cookies=None, verify=False, timeout=10, gdt=None):

    if json is not None:
        assert data is None
        from json import dumps
        data = dumps(json) # set the data
        headers["Content-Type"] = "application/json" # add the header

    try:
        return py_request(url, method, headers=headers, cookies=cookies, data=data, timeout=timeout, verify=verify, gdt=gdt)
    except ConnectionError as err:
        print("\nConnection error in request: {}".format(err))
        # some APs reject https connections until splashpage broken. Try http
        if url[:5] == "https":
            url = "http{}".format(url[5:])
            print("trying http @ {}".format(url))
            return py_request(url, method, headers=headers, cookies=cookies, data=data, timeout=timeout, verify=verify, gdt=gdt)



# Here are the functions to call externally

def get(url, **kw):
    return request("GET", url, **kw)

def post(url, **kw):
    return request("POST", url, **kw)



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