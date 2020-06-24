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
#  Filename : network.py

# This is an abstraction layer used in porting
# from micropython the python. As python does not 
# have a nework module

from time import sleep
#from reqst import test_dns_internet
from request import get

try:
    from wifi import Cell, exceptions
    from os import popen

except (ModuleNotFoundError, ImportError) as err:
    print("Error: wifi module not installed, or os module failed to load.\n\tInstall wifi module with: pip3 install wifi")
    print(err)
    exit()



location_wpa_sup_conf = "/etc/wpa_supplicant/wpa_supplicant.conf"



class Station():

    interface_is_up = False
    connected = False
    

    def __init__(self):
        self.interface_on()



    def interface_on(self):
        # ensure station is up
        ret = popen("sudo ip link set wlan0 up").read()
        if ret == '':
            self.interface_is_up = True
        else:
            print("restarting interface returned with:\n{}".format(ret))



    def interface_off(self):
        # ensure station is up
        ret = popen("sudo ip link set wlan0 down").read()
        if ret == '':
            self.interface_is_up = False
        else:
            print("restarting interface returned with:\n{}".format(ret))



    def scan_open_ssids(self):
        # interface must be up to scan
        if not self.interface_is_up:
            self.interface_on()

        # scan
        nets = []
        MAX_ATTEMPTS = 4
        count = 0
        while count < MAX_ATTEMPTS:
            try:
                count += 1
                nets = list(Cell.all('wlan0'))
                break
            except exceptions.InterfaceError:
                sleep(.1)

        # pull out open ssids
        free_ssids = []
        for cell in nets:
            if not cell.encrypted:
                free_ssids.append(cell.ssid)
        
        return free_ssids



    def connect_to_ssid(self, ssid = ''):

        if ssid == '':
            return

        # format new wpa_conf entry for open access point
        data_wpa_sup_conf = "network={" + "\n\tssid=\"{}\"".format(ssid) + "\n\tkey_mgmt=NONE\n}"
        
        # make the new conf file with the data
        try:
            self.make_new_conf( location_wpa_sup_conf, data_wpa_sup_conf)
        except FileNotFoundError as err:
            print("File not found! {}".format(err))
            exit(1)

        # remove old wpa_supplicant file
        ret = popen("sudo rm /var/run/wpa_supplicant/wlan0").read()
        if ret != '':
            print("removing old wpa_supplicant file returning with:")
            print(ret)
        
        # Remove old wp_supplicant process
        ret = popen("sudo pkill wpa_supplicant").read()
        if ret != '':
            print("removing old wpa_supplicant file returning with:")
            print(ret)

        # bring connection down and back up
        self.interface_off()
        self.interface_on()

        # start the new wpa_supplicant process
        ret = popen( "wpa_supplicant -B -i wlan0 -c '/etc/wpa_supplicant/wpa_supplicant.conf' && dhclient wlan0 " ).read()
        print("wpa_supplicant launch returned with:")
        print(ret)

    

    def is_connected(self):

        # If we have valid IP address, we're probably connected
        ret = popen('hostname -I').read()
        if ret == '':
            return False
        
        # get them individually
        ips = ret.split(' ')

        # check each IP, see if we have a valid one
        for ip in ips:

            octets = ip.split('.')

            if octets[0] in ['169', '\n']:
                continue

            else:
                return True
        
        # no ip in ip list was valid
        return False



    # Make a request to user's host url and check for OK
    def has_wan_access(self, url, body = "OK"):
        if not self.is_connected():
            return False

        # Request host/api/ should return OK in body
        MAX_RETRIES = 2
        current = 1
        while current < MAX_RETRIES:
            # try to test our known good "OK"
            try:
                current += 1
                [_, status, _, body] = get(url)
            
            # Sometimes DNS fails
            except ConnectionError as err:
                print("ConnectionError in has_wan_access: {}".format(err))
                if current < MAX_RETRIES:
                    print("Retrying...")

            # If we got access to the external page
            if status == 200 and body == "OK":
                return True
        
        return False


    
    def _get_header(self, file_name):
        file_wpa_sup_conf = open(location_wpa_sup_conf, 'rt')
        
        # file does not exist
        if not file_wpa_sup_conf:
            raise FileNotFoundError(location_wpa_sup_conf)

        header = []
        for line in file_wpa_sup_conf:
            header.append(line)
            if line == '\n' or line == '\r\n':
                break

        return header



    def make_new_conf(self, file_name, net_data):

        # get header info
        header = self._get_header(location_wpa_sup_conf)

        # overwrite the file with new data
        with open(file_name, 'wt') as file_wpa_sup_conf:
            for line in header:
                file_wpa_sup_conf.write(line)
            file_wpa_sup_conf.write('\n')
            file_wpa_sup_conf.write(net_data)
        
        # close it out
        file_wpa_sup_conf.close()

    

    def end_ip_lease(self):

        # drop the currently held IPs
        popen("sudo dhclient -r wlan0")

        # return true if no more valid IPs
        return ( not self.is_connected() )