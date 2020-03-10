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
#  Filename : post.py

from reqst import post
from machine import Timer, reset
import logging
# https request information
headers = {
    'Content-Type': 'application-json',
}

def handlerTimer(timer):
    print("Post: Timer Timeout")
    #Resets the device in a manner similar to pushing the external RESET button.
    reset()

def post_data(post_data, post_url, logger: Logger) -> bool:
    try:
        # init harware timer
        timer = Timer(0)
        #TODO: Uncomment this for solution
        #timer.init(period=3000, mode=Timer.ONE_SHOT,callback=handlerTimer)
        response = post(post_url, headers=headers, data=post_data)
        #TODO: Uncomment this for solution
        #timer.deinit()
        if response.status_code == 200:
            #TODO: remove print
            response.close()
            print("Post Request Successful")
            logger.info("Post Request Successful")
            return True
        else:
            #TODO: remove print
            response.close()
            print("Post Request Unsuccessful")
            logger.info("Post Request Unsuccessful")
            return False
    except OSError as e:
        #TODO: remove print
        print("Warning: " + str(e))
        logger.warning(str(e))
