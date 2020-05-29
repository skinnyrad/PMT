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
# have a machine module



try:
    from os import popen

except (ModuleNotFoundError, ImportError) as err:
    print("Error: Import failed in machine.py")
    print(err)
    exit()


def reset():
    popen("sudo reboot")

#TODO
def proc_restart():
    # popen this same process the way you do on bootup
    exit()
