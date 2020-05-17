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
#  Filename : machine.py

# This is an abstraction layer used in porting
# from micropython the python. As python does not 
# have a machine class



try:
    from wifi import Cell, exceptions
    from os import popen
    from time import sleep

except (ModuleNotFoundError, ImportError) as err:
    print("Error: wifi module not installed, or os module failed to load.\n\tInstall wifi module with: pip3 install wifi")
    print(err)
    exit()



location_wpa_sup_conf = "/etc/wpa_supplicant/wpa_supplicant.conf"



def reset():
    popen("sudo reboot")



def scan_open_ssids():
    
    # ensure station is up
    ret = popen("sudo ip link set wlan0 up").read()
    if ret != '':
        print("restarting interface returned with:\n{}".format(ret))

    # scan
    nets = []
    try:
        nets = list(Cell.all('wlan0'))
    except exceptions.InterfaceError:
        sleep(.1)
        nets = list(Cell.all('wlan0'))



    # pull out open ssids
    free_ssids = []
    for cell in nets:
        if not cell.encrypted:
            free_ssids.append(cell.ssid)
    
    return free_ssids



def connect_to_ssid(ssid = ''):

    if ssid == '':
        return

    # format new wpa_conf entry for open access point
    data_wpa_sup_conf = "network={" + "\n\tssid=\"{}\"".format(ssid) + "\n\tkey_mgmt=NONE\n}"
    
    # make the new conf file with the data
    try:
        make_new_conf(location_wpa_sup_conf, data_wpa_sup_conf)
    except FileNotFoundError as err:
        print("File not found! {}".format(err))
        exit(1)

    # remove old wpa_supplicant process
    ret = popen("sudo rm /var/run/wpa_supplicant/wlan0").read()
    if ret != '':
        print("removing old wpa_supplicant returning with:")
        print(ret)

    # bring connection down and back up
    ret = popen("sudo ip link set wlan0 down && sudo ip link set wlan0 up").read()
    if ret != '':
        print("restarting interface returned with:")
        print(ret)

    # start the new wpa_supplicant process
    ret = popen( "wpa_supplicant -B -i wlan0 -c '/etc/wpa_supplicant/wpa_supplicant.conf' && dhclient wlan0 " ).read()
    print("wpa_supplicant launch returned with:")
    print(ret)



def _get_header(file_name):
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
    header = _get_header(location_wpa_sup_conf)

    # overwrite the file with new data
    with open(file_name, 'wt') as file_wpa_sup_conf:
        for line in header:
            file_wpa_sup_conf.write(line)
        file_wpa_sup_conf.write('\n')
        file_wpa_sup_conf.write(net_data)
    
    # close it out
    file_wpa_sup_conf.close()