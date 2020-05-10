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

from socket import getaddrinfo
from machine import reset
from gc import collect
from gdt import GDT
import logging
import reqst
from html_parser import get_forms, get_tags, breakup_tag, tag_internals_to_dict

def splash_breaking_a(b_html):
    # read all bytes from socket
    print("<a> search...")
    # parse socket bytes
    a = []
    while b_html.find(b'<a') != -1:
        beg = b_html.find(b'<a')
        end = b_html.find(b'</a>')+4
        a.append(b_html[beg:end])
        b_html = b_html[end+1:len(b_html)] #Regions Guest thinks its a string
    
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



def break_sp(gdt, host, location, recvd_headers, splashpage):
    gdt.feed()

    print("break_sp: Location:{}".format(location))

    # break with form resubmission
    forms = get_forms(splashpage)
    gdt.feed()
    collect()
    print(forms)

    if(len(forms) > 0):

        # generate response to form
        resp = form_response(forms[0])
        print("reponse: {}".format(resp))

        # Add from resubmit specific headers
        recvd_headers["Content-Type"] = "application/x-www-form-urlencoded"
        recvd_headers["Accept"] = "*/*"
        recvd_headers["Cache-Control"]= "no-cache"
        recvd_headers["Accept-Encoding"]= "gzip, deflate, br"
        recvd_headers["Connection"]= "keep-alive"

        # convert from dns address to usable URL
        if type(location) is tuple and len(location) == 2:
            
            #Another necessary header
            recvd_headers["Host"] = "{}".format(location[0])
            
            # URL conversion
            if location[1] == 80:
                location = "http://{}".format(location[0])
            elif location[1]==443:
                location = "https://{}".format(location[0])

        # new location specified
        if "action" in forms[0]:
            
            if forms[0]["action"][0] == '/': # relative path
                print("REALATIVE PATH /")
                
                # relative links append to <base ...> tag
                base_tag = tag_internals_to_dict( breakup_tag( get_tags(splashpage, "base")[0] ) ) #relative paths must have a base specified
                base_url = base_tag["href"]
                [proto, dummy, base, _, _] = reqst.breakdown_url(base_url)
                
                location = "{0}//{1}{2}".format(proto, base, forms[0]["action"]) #append to location

                #update header
                recvd_headers["Host"] = "{}".format(base)
            
            elif forms[0]["action"][0:2] == './': # relative path
                print("REALATIVE PATH ./")

                # relative links append to <base ...> tag
                base_tag = tag_internals_to_dict( breakup_tag( get_tags(splashpage, "base")[0] ) ) #relative paths must have a base specified
                base_url = base_tag["href"]
                [proto, dummy, base, _, _] = reqst.breakdown_url(base_url)

                location = "{0}//{1}{2}".format(proto, base, forms[0]["action"][1:]) #append to location

                #update header
                recvd_headers["Host"] = "{}".format(base)
            
            else: #absolute path
                print("ABSOLUTE PATH")
                location = forms[0]["action"]

        del splashpage
        del forms
        collect()

        #test
        resp = 'apname=%7B%7B%20apname%20%7D%7D&clmac=%7B%7B%20clmac%20%7D%7D'

        print("break_sp: Resubmitting form.\nLocation:{0}\n".format(location))
        gdt.feed()
        [dns_addr, status, recvd_page, recvd_headers] = reqst.post(location, data=resp, headers=recvd_headers, timeout=3000)
        gdt.feed()
        del resp
        collect()
        print("New page after resubmitting forms:")
        print("status:{}".format(status))
        print("headers:{}".format(recvd_headers))
        print("page:{}\n".format(recvd_page))

    
    # no forms, try following a-tags
    #else:
    #     #<a> TAG Splash Page Breaking
    #     a = splash_breaking_a(splashpage)
    #     for v in a:
    #         [status, _ ] = reqst.get(v)
    #         if status == 200:
    #             return True
        # -----------------------------


    # Possible Redirection on new page
    gdt.feed()
    print("Fed GDT before requesting splash page")
    if "Location" in recvd_headers and 300 <= status <= 309:
        [dns_addr, status, recvd_page, recvd_headers] = reqst.get_splash_page(recvd_headers["Location"])
        # new splashpage received
    elif "redirURL" in recvd_headers and 300 <= status <= 309:
        [dns_addr, status, recvd_page, recvd_headers] = reqst.get_splash_page(recvd_headers["redirURL"])
        # new splashpage received

    print("PAGE BREAKING COMPLETE!")
    host = "http://pmtlogger.000webhostapp.com/api/"
    print("Testing connection from {} ...".format(host))
    
    # test DNS -> GET Request
    # Test for open connection. DO NOT SEND THIS DATA BACK, you will only be backtracking to the inital page.
    [_, dns_status, _, dns_body, _] = reqst.test_dns_internet(host)
    gdt.feed()
    print("Status: {0}\nBody: {1}".format(dns_status, dns_body))

    if dns_status == 200 and dns_body == "OK":
        print("Internet Access [OK]")
        return True
    
    return [dns_addr, status, recvd_headers, recvd_page]



def station_connected(host, gdt, wifiLogger):
    #TODO: remove print
    print("Connected [Testing Access]")
    wifiLogger.info("Connected [Testing Access]")

    gdt.feed()
    print("Fed GDT before DNS testing")

    # test DNS -> GET Request and Handles Redirection
    [dns_addr, status, location, body, headers] = reqst.test_dns_internet(host)
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
        return station_connected(location, gdt, wifiLogger)

    # Status Code 200 but not connected to internet yet
    # Make another request to get redirection information
    #elif status == 200:
    #    # should handle requests prior to redirection
    #    return station_connected(station, host, gdt, wifiLogger)
    if location and 300 <= status <= 309:
        #300s redirection
        gdt.feed()
        print("Fed GDT before requesting splash page")
        [dns_addr, status, body, headers] = reqst.get_splash_page(location)
        # splashpage received, move on to bypassing it


    # Bypass Splashpage
    if status == 200:

        # dns_Addr is IP where the page came from, acquired from DNS lookup within previous activity


        gdt.feed()
        print("Fed GDT after splash page received")

        print(body)

        print("Splashpage [OK]")
        print("Splashpage Length [{}]".format(len(body)))
        
        location = dns_addr

        print("Splashpage Breaking...")

        # continue hopping from one page received to the next until we have access to host
        while True:
            [dns_addr, status, headers, body] = break_sp(gdt, host, dns_addr, headers, body)
            if status == 200 and body == "OK":
                return True

        print("Splashpage Not Broken Unless Implemented Above...")
        print("Splashpage [Failed]")
        del body
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
        return False

    # any error code not caught above
    else:
            print("Splashpage [Failed]")
            return False
