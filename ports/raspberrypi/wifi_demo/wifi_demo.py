# wifi_demo.py
# note must be run as sudo

from wifi import Cell
import os

location_wpa_sup_conf = "/etc/wpa_supplicant/wpa_supplicant.conf"

def scan_and_connect():
    # scan
    nets = list(Cell.all('wlan0'))

    # display them
    i=0
    for cell in nets:
        i += 1
        print("{0}) SSID: {1}".format(i, cell.ssid) )

    #zero networks found
    if not i:
        print("Zero networks found! Make sure you are running python as sudo...")

    # Which to conect to?
    i = int( input("Select Choice 1 through {} ... ".format(i)) )

    # Get specific network requested
    cell = nets[i-1]
    ssid = cell.ssid
    print("Choice: {}".format(i))
    print("SSID: {0}\n\tEncrypted: {1}\n\tChannel: {2}\n\tAddress: {3}\n\tMode: {4}".format(cell.ssid, cell.encrypted, cell.channel, cell.address, cell.mode))

    # Password required?
    password = None
    if cell.encrypted:
        print("!PASSWORDS NOT CURRENTLY TESTED!")
        password = input("Please provide Password: ")
        data_wpa_sup_conf = os.popen( "wpa_passphrase \'{0}\' \'{1}\'".format(ssid, password) ).read()

    else:
        data_wpa_sup_conf = "network={" + "\n\tssid=\"{}\"".format(ssid) + "\n\tkey_mgmt=NONE\n}"

    # make the new conf file with the data
    try:
        make_new_conf(location_wpa_sup_conf, data_wpa_sup_conf)
    except FileNotFoundError as err:
        print("File not found! {}".format(err))
        exit(1)

    # display debugging data
    print("wpa_supplicant.conf data being fed in through command line:")
    print(data_wpa_sup_conf)

    # remove old wpa_supplicant
    ret = os.popen("sudo rm /var/run/wpa_supplicant/wlan0").read()
    print("removing old wpa_supplicant returning with:")
    print(ret)

    # bring connection down and back up
    ret = os.popen("sudo ip link set wlan0 down && sudo ip link set wlan0 up").read()
    print("restarting interface returned with:")
    print(ret)

    print("\nAttempting connection...")

    # start the new wpa_supplicant
    ret = os.popen( "wpa_supplicant -B -i wlan0 -c '/etc/wpa_supplicant/wpa_supplicant.conf' && dhclient wlan0 " ).read()
    print("wpa_supplicant launch returned with:")
    print(ret)
    


def get_header(file_name):
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



def make_new_conf(file_name, net_data):

    # get header info
    header = get_header(location_wpa_sup_conf)

    # overwrite the file with new data
    with open(file_name, 'wt') as file_wpa_sup_conf:
        for line in header:
            file_wpa_sup_conf.write(line)
        file_wpa_sup_conf.write('\n')
        file_wpa_sup_conf.write(net_data)
    
    # close it out
    file_wpa_sup_conf.close()