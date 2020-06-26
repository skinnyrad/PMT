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
    print("\n<a> search...")
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
    
    print( "\t{}\n".format(a) )
    return a



def break_sp(gdt, host, location, recvd_headers, cookies, splashpage):
    gdt.feed()

    print("\nbreak_sp: Location:{}".format(location))

    # break with form resubmission
    #forms = get_objects(splashpage, "form")
    page = lxml.html.fromstring(splashpage)
    forms = page.forms

    # If there were forms in the page
    if len(forms) > 0:
        print("Using form resubmission")

        print("\nform[0]={}".format( forms[0].form_values() ))

        # generate response to form
        resp = urllib.parse.urlencode( forms[0].form_values() )
        print("reponse: {}".format(resp))


        # Determine location to send data to
        print("\nChecking for ACTION field...")
        if forms[0].action is not None: # If action is specified, definitely use it
            print("Action field found")
            if (forms[0].action)[0] == '/': # relative path
                print("\tREALATIVE PATH /")
                if page.base is not None:
                    location = "{0}{1}".format(page.base, forms[0].action)
            
            elif (forms[0].action)[0:2] == './': # relative path
                print("\tREALATIVE PATH ./")
                if page.base is not None:
                    location = "{0}{1}".format(page.base, (forms[0].action)[1:] )
 
            else: #absolute path
                print("\tABSOLUTE PATH")
                location = forms[0].action

        #elif page.base is not None: # If action is not specified, we have to use <base>
        #    print("ACTION not specified, using BASE")
        #    location = page.base
        #
        #elif page.base is None: # McDonalds specified base within a comment tag. How silly
        #    #This is gonna be a nasty workaround and should not be considered final
        #    print("ACTION & BASE not specified, attempting nasty search")
        #    html = lxml.html.tostring(page).decode('utf-8')
        #    i = html.find('base href="')
        #    j = html.find('"', i+11)
        #    location = html[i+11:j]

        del splashpage
        collect()


        # Add form resubmit specific headers
        new_headers = {}
        new_headers["Content-Type"] = "application/x-www-form-urlencoded"

        print("\nbreak_sp: Resubmitting form...")        
        gdt.feed()
        if forms[0].method is not None and forms[0].method == "POST":
            [addr, status, recvd_headers, cookies, body] = request.post(location, data=resp, headers=new_headers, cookies=cookies, timeout=10)
        elif forms[0].method is not None and forms[0].method == "GET":
            # Data must be appended to URL on GET resubmission
            location = "{0}?{1}".format(location, resp) #TODO, resp might need to not be urlencoded to work correctly
            [addr, status, recvd_headers, cookies, body] = request.get(location, data=None, headers=new_headers, cookies=cookies, timeout=10)
        
        gdt.feed()

        del resp
        del forms
        collect()

        return [addr, status, recvd_headers, cookies, body]

    
    # no forms, try following a-tags
    else:
        print("Using A-Tag following")
        #<a> TAG Splash Page Breaking
        a = splash_breaking_a(splashpage)
        for v in a:
            print("\tgoing to: {}".format(v))
            [addr, status, recvd_headers, cookies, body] = request.get(v, cookies=cookies, timeout=10, verify=False)
            #if status == 200:
            #    return True
        # -----------------------------


    print("\nPAGE BREAKING COMPLETE!")
    print("Testing connection to {} ...".format(host))
    
    # Test for open connection. DO NOT SEND THIS DATA BACK, you will only be backtracking to the inital page.
    try:
        [_, test_status, _, _, test_body] = request.get(host, gdt=gdt, timeout=10)
    except Exception as err:
        print("Exception: Exception in break_sp in wifi_connect: {}".format(err))
        return False
    
    gdt.feed()

    if test_status == 200 and test_body == "OK":
        print("Internet Access [OK]")
        return True
    
    return [addr, status, recvd_headers, cookies, body]



def station_connected(station, host, gdt, wifiLogger):
    # INITIAL CHECKS --------------------------------------------------------------------------------
    print("\nStation Connected [Testing Access]")
    wifiLogger.info("Connected [Testing Access]")

    # Must make initial request to posting page to start the process
    # of getting full internet access.
    gdt.feed()
    print("Fed GDT before requesting Host: {}".format(host))

    # test DNS -> GET Request and Handles Redirection
    try:
        [addr, status, recvd_headers, cookies, body] = request.get(host, cookies=None, timeout=10, verify=False, gdt=gdt)
    except Exception as err:
        print("default Exception 1 in station_connected: {}".format(err))
        return False
    if status is None: # something broke in the request
        return False

    gdt.feed()
    print("Fed GDT after DNS testing")


    # LOOPING THROUGH PAGES -------------------------------------------------------------------------
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
            if 'Location' in recvd_headers:
                redir_url = recvd_headers['Location']
            elif 'redirURL' in recvd_headers:
                redir_url = recvd_headers['redirURL']

            # Redirection Location but Status Code is 200
            if status == 200 :
                try:
                    [addr, status, recvd_headers, cookies, body] = request.get(redir_url, verify=False, timeout=10 )
                    continue
                except Exception as err:
                    print("\ndefault Exception 2 in station_connected: {}\n".format(err))
                    return False

        # Bypass Splashpage
        elif status == 200:

            gdt.feed()
            print("Fed GDT after splash page received")
            print("Splashpage Breaking...")

            try:
                ret_val = break_sp(gdt, host, addr, recvd_headers, cookies, body)
                
                if type(ret_val) is bool:
                    if ret_val == True:
                        return ret_val
                else:
                    [addr, status, recvd_headers, cookies, body] = ret_val

            except Exception as err:
                print("\ndefault Exception 3 in station_connected: {}\n".format(err))
                return False

    print("Splashpage [Failed]")
    return False