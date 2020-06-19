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
#  Filename : wifi_connect.py

from gc import collect
from gdt import GDT
import request
from html_parser import get_objects, get_tags, breakup_tag, tag_internals_to_dict, form_response
import lxml.html
import urllib.parse


def splash_breaking_a(b_html):
    # read all bytes from socket
    print("<a> search...")
    # parse socket bytes
    a = []
    while b_html.find('<a') != -1:
        beg = b_html.find('<a')
        end = b_html.find('</a>')+4
        a_tag = tag_internals_to_dict(breakup_tag(b_html[beg:end]))
        print(a_tag)
        if "href" in a_tag:
            a.append(a_tag["href"])
        b_html = b_html[end+1:len(b_html)] #Regions Guest thinks its a string
    
    print(a)
    return a



def break_sp(gdt, host, location, recvd_headers, splashpage):
    gdt.feed()

    print("break_sp: Location:{}".format(location))

    # break with form resubmission
    #forms = get_objects(splashpage, "form")
    page = lxml.html.fromstring(splashpage)
    forms = page.forms
    print("forms:{}".format( lxml.html.tostring(forms) ))

    # If there were forms in the page
    if len(forms) > 0:

        # generate response to form
        resp = urllib.parse.urlencode( forms[0].form_values() )
        print("reponse: {}".format(resp))

        # Add form resubmit specific headers
        recvd_headers["Content-Type"] = "application/x-www-form-urlencoded"


        # Determine location to send data to
        if forms[0].action is not None: # If action is specified, definitely use it
            
            if (forms[0].action)[0] == '/': # relative path
                print("REALATIVE PATH /")
                if page.base is not None:
                    location = "{0}{1}".format(page.base, forms[0].action)
            
            elif (forms[0].action)[0:2] == './': # relative path
                print("REALATIVE PATH ./")
                if page.base is not None:
                    location = "{0}{1}".format(page.base, (forms[0].action)[1:] )
 
            else: #absolute path
                print("ABSOLUTE PATH")
                location = forms[0].action

        elif page.base is not None: # If action is not specified, we have to use <base>
            print("ACTION not specified, using BASE")
            location = page.base

        #update header
        #recvd_headers["Host"] = "{}".format(page.base)


        del splashpage
        collect()

        print("break_sp: Resubmitting form.\nLocation:{0}\n".format(location))
        
        gdt.feed()
        if forms[0].method is not None and forms[0].method == "POST":
            [dns_addr, status, recvd_headers, recvd_page] = request.post(location, data=resp, headers=recvd_headers, timeout=10)
        elif forms[0].method is not None and forms[0].method == "GET":
            # Data must be appended to URL on GET resubmission
            location = "{0}?{1}".format(location, resp) #TODO, resp might need to not be urlencoded to work correctly
            [dns_addr, status, recvd_headers, recvd_page] = request.get(location, data=None, headers=recvd_headers, timeout=10)
        
        gdt.feed()

        del resp
        del forms
        collect()
        print("New page after resubmitting forms:")
        print("status:{}".format(status))
        print("headers:{}".format(recvd_headers))
        print("page:{}\n".format(recvd_page))

        return [dns_addr, status, recvd_headers, recvd_page]

    
    # no forms, try following a-tags
    else:
        print("Using A-Tag following")
        #<a> TAG Splash Page Breaking
        a = splash_breaking_a(splashpage)
        for v in a:
            print("going to: {}".format(v))
            [addr, status, recvd_headers, page] = request.get(v)
            if status == 200:
                return True
        # -----------------------------


    print("PAGE BREAKING COMPLETE!")
    print("Testing connection to {} ...".format(host))
    
    # Test for open connection. DO NOT SEND THIS DATA BACK, you will only be backtracking to the inital page.
    try:
        [_, test_status, _, test_body] = request.get(host, gdt=gdt, timeout=10)
    except ConnectionError as err:
        print("Exception: ConnectionError in break_sp in wifi_connect: {}".format(err))
        return False
    except Exception as err:
        print("Exception: Exception in break_sp in wifi_connect: {}".format(err))
        return None
    
    gdt.feed()
    print("Status: {0}\nBody: {1}".format(test_status, test_body))

    if test_status == 200 and test_body == "OK":
        print("Internet Access [OK]")
        return True
    
    return [dns_addr, status, recvd_headers, recvd_page]



def station_connected(station, host, gdt, wifiLogger):
    #TODO: remove print
    print("Connected [Testing Access]")
    wifiLogger.info("Connected [Testing Access]")

    # Must make initial request to posting page to start the process
    # of getting full internet access.
    gdt.feed()
    print("Fed GDT before requesting Host: {}".format(host))

    # test DNS -> GET Request and Handles Redirection
    try:
        [dns_addr, status, recvd_headers, body] = request.get(host)
        print("status={0}\nheaders={1}\nbody={2}".format(status,recvd_headers,body))
    except ConnectionError as err:
        print("ConnectionError in station_connected: {}".format(err))
        station.end_ip_lease()
        return False
#    except Exception as err:
#        print("default Exception in station_connected: {}".format(err))
#        return None

    if status is None: # something broke in the request
        return None

    gdt.feed()
    print("Fed GDT after DNS testing")


    MAX_DEPTH = 10 # How many pages are we willing to bypass before giving up?
    depth = 0
    while depth <= MAX_DEPTH:
        depth += 1
        print("Page breaking depth: {}".format(depth))
        print("Status={}".format(status))

        # NO SPLASH PAGE
        if status == 200 and body == "OK":
            print("Internet Access [OK]")
            return True

        # Normal redirections (status: 300s) are handled by request
        #If we received the Location:http... header
        elif 'Location' in recvd_headers or 'redirURL' in recvd_headers:
            print("Location header found, redirecting...")

            # Redirection Location but Status Code is 200
            if status == 200 :
                try:
                    [dns_addr, status, recvd_headers, body] = request.get(recvd_headers['Location'])
                    continue
                except ConnectionError as err:
                    print("socket.gaierror in station_connected: {}".format(err))
                    station.end_ip_lease()
                    return False
                except Exception as err:
                    print("default Exception in station_connected: {}".format(err))
                    return None



        # Bypass Splashpage
        elif status == 200:

            gdt.feed()
            print("Fed GDT after splash page received")

            print("splashpage={}".format(body) )

            print("Splashpage [OK]")
            print("Splashpage Length [{}]".format(len(body)))
            print("Splashpage Breaking...")

            try:
                ret_val = break_sp(gdt, host, dns_addr, recvd_headers, body)
                
                if type(ret_val) is bool:
                    if ret_val == True:
                        return ret_val
                else:
                    [dns_addr, status, recvd_headers, body] = ret_val

            except ConnectionError as err:
                print("ConnectionError in station_connected: {}".format(err))
                print("Dropping IP and moving on")
                station.end_ip_lease()
                return False
            except Exception as err:
                print("default Exception in station_connected: {}".format(err))
                print("Dropping IP and moving on")
                station.end_ip_lease()
                return False


    print("Splashpage [Failed]")
    return False