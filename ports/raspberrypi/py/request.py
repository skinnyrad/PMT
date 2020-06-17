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

# The base request function
def py_request(url, method, headers={}, data=None, timeout=10, gdt=None ):

    attempts = 1
    MAX_ATTEMPTS = 2
    while attempts <= MAX_ATTEMPTS:
        print("Connection attempt {0}/{1}".format(attempts,MAX_ATTEMPTS))
        
        if gdt is not None:
            gdt.feed()

        try:
            if method == 'GET':
                r = requests.get(url, headers=headers, data=data, timeout=timeout)
            elif method == 'POST':
                r = requests.post(url, headers=headers, data=data, timeout=timeout )
            break

        except ConnectionError as err:
            print("ConnectionError in py_request: {}".format(err))
            if attempts >= MAX_ATTEMPTS:
                raise ConnectionError


    addr = r.url
    status = r.status_code
    recvd_headers = r.headers
    body = r.text
    r.close()

    if gdt is not None:
        gdt.feed()

    # <head> redirects not natively supported. Handled here
    if body.find('<head') > -1:
        
        #head_str = html_parser.get_tags('head')
        #head_list = html_parser.breakup_tag(head_str)
        #head_dicts = html_parser.tag_internals_to_dict(head_list)
        #head_obj = html_parser.construct_object_from_tag_internals(head_dict)

        head_objects = html_parser.get_objects(body, 'head')
        print( "HEAD objects: {}".format(head_objects) )

        for head in head_objects:
            if 'inside' in head:
                for tag in head['inside']:
                    if (tag["tag_type"] == "meta") and ('http-equiv' in tag) and (tag['http-equiv'] == 'refresh') and ('content' in tag):
                            i = tag['content'].find('url=')
                            if i > -1:
                                url = tag['content'][i+4:]
                                print("head object redirection to url={}".format(url))

                                try:
                                    r = requests.get(url, timeout=timeout)
                                    addr = r.url
                                    status = r.status_code
                                    recvd_headers = r.headers
                                    body = r.text
                                    r.close()

                                except ConnectionError as err:
                                    print("ConnectionError in py_request: {}".format(err))
                                    if attempts >= MAX_ATTEMPTS:
                                        raise ConnectionError
                                
                                

    return [addr, status, recvd_headers, body]


# replacing the original request function, must keep same parameters
# It'd be more efficient in all respects to only have one base requests function,
# but changing the parameters would cause too many issues, and would take to long to debug
def request(method, url, data=None, json=None, headers={}, timeout=None, gdt=None):

    if json is not None:
        assert data is None
        from json import dumps
        data = dumps(json) # set the data
        headers["Content-Type"] = "application/json" # add the header

    return py_request(url, method, headers=headers, data=data, timeout=timeout, gdt=gdt)



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