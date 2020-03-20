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
        [status, _] = post(post_url, headers=headers, data=post_data)
        #TODO: Uncomment this for solution
        #timer.deinit()
        if status == 200:
            #TODO: remove print
            print("Post Request [OK]")
            logger.info("Post Request [OK]")
            return True
        else:
            #TODO: remove print
            print("Post Request [Failed]")
            logger.info("Post Request [Failed]")
            return False
    except OSError as e:
        #TODO: remove print
        print("Warning: {0}".format(str(e)))
        logger.warning(str(e))
        if str(e) == "[Errno 113] EHOTSUNREACH":
            reset()
        return False
