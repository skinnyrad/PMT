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
#  Filename : wifi_connect.py

from network import WLAN
from usocket import getaddrinfo
from machine import Timer, reset
from gc import collect
from gdt import GDT
import logging
import reqst
from html import get_forms

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
    
    print(a)
    return a


def form_response(form):
    resp = ""
    content = form["inside"]

    if( len(content) > 0 ):
        # key1=val1&key2=val2
        for tag in content:
            resp = "{0}{1}={2}&".format(resp, tag["name"], tag["value"])
        
        return resp[0:len(resp)-1] #remove final &, simpler code this way



def break_sp(gdt, host, splashpage, location, recvd_headers):
    gdt.feed()

    print("break_sp: Location:{}".format(location))

    # break with form resubmission
    forms = get_forms(splashpage)
    gdt.feed()
    collect()
    print(forms)

    if(len(forms) > 0):
        del splashpage
        collect()

        resp = form_response(forms[0])
        print("reponse: {}".format(resp))


        # convert from dns address to usable URL
        if type(location) is list and len(location) == 2:
            if location[1] == 80:
                location = "http://{}".format(location[0])
            elif location[1]==443:
                location = "https://{}".format(location[0])


        # new location specified
        if "action" in forms[0]:
            
            if forms[0]["action"][0] == '/' or forms[0]["action"][0] == './': # relative path
                print("REALATIVE PATH")
                location = "{0}{1}".format(location, forms[0]["action"]) #append to location
            
            else: #absolute path
                print("ABSOLUTE PATH")
                location = forms[0]["action"]

        print("break_sp: Resubmitting form.\nLocation:{0}\n".format(location))
        collect()
        gdt.feed()
        [_, status, recvd_page, headers] = reqst.post(location, data=resp, headers=recvd_headers, timeout=3000)
        gdt.feed()
        del resp
        collect()

    
    # no forms, try following a-tags
    else:
         #<a> TAG Splash Page Breaking
         a = splash_breaking_a(splashpage)
         for v in a:
             [status, _ ] = reqst.get(v)
             if status == 200:
                 return True
        # -----------------------------

    
    # test DNS -> GET Request and Handles Redirection
    [addr, status, location, body, headers] = reqst.test_dns_internet(host)
    gdt.feed()

    # NO SPLASH PAGE
    if status == 200 and body == "OK":
        print("Internet Access [OK]")
        return ["", location, headers] #success

    # Redirection
    elif location and 300 <= status <= 309:
        gdt.feed()
        print("Fed GDT before requesting splash page")

        [status,recvd_page,headers] = reqst.get_splash_page(location)
        # splashpage received
    
    return [status,recvd_page,headers]



def station_connected(station: WLAN, host: String, gdt: GDT, wifiLogger: Logger):
    #TODO: remove print
    print("Connected [Testing Access]")
    wifiLogger.info("Connected [Testing Access]")

    gdt.feed()
    print("Fed GDT before DNS testing")

    # test DNS -> GET Request and Handles Redirection
    [addr, status, location, body, headers] = reqst.test_dns_internet(host)
    print("status={0}\nheaders={1}\nlocation={2}\nbody={3}".format(status,headers,location,body))

    gdt.feed()
    print("Fed GDT after DNS testing")

    # NO SPLASH PAGE
    if status == 200 and body == "OK":
        print("Internet Access [OK]")
        return True

    # Redirection Location but Status Code is 200
    elif status == 200 and location is not None:
        # should handle requests prior to redirection
        return station_connected(station, location, gdt, wifiLogger)

    # Status Code 200 but not connected to internet yet
    # Make another request to get redirection information
    #elif status == 200:
    #    # should handle requests prior to redirection
    #    return station_connected(station, host, gdt, wifiLogger)

    # Redirection
    elif (status == 200) or (location and 300 <= status <= 309):
        gdt.feed()
        print("Fed GDT before requesting splash page")

        #splashpage not received yet
        if status == 200:
           splashpage = body
           location = addr

        #300s redirection
        else:
            [status,splashpage,headers] = reqst.get_splash_page(location)
            # splashpage received

        gdt.feed()
        print("Fed GDT after splash page received")

        print(splashpage)

        print("Splashpage [OK]")
        print("Splashpage Length [{}]".format(len(splashpage)))
        
        print("Splashpage Breaking...")

        while splashpage != "":
            [splashpage, location, headers] = break_sp(gdt, host, splashpage, location, headers)

        print("Splashpage Not Broken Unless Implemented Above...")
        print("Splashpage [Failed]")
        del splashpage
        collect()

        #TODO: When You know you broke the page and allow DATA SENDING
        # return True
        return False

    elif 500 <= status <= 599:
        """
            station.active(False) seems to flush wifi module

            board output:
                I (35596) wifi: flush txq
                I (35596) wifi: stop sw txq
                I (35596) wifi: lmac stop hw txq
        """
        station.active(False)
        station.active(True)
        return False

    # any error code not caught above
    else:
            print("Splashpage [Failed]")
            return False
