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
#  Filename : post.py

from reqst import post
import logging
# https request information
headers = {
    'Content-Type': 'application-json',
}

def handlerTimer(timer):
    print("Post: Timer Timeout")
    #Resets the device in a manner similar to pushing the external RESET button.
    #reset()

def post_data(post_data, post_url, station, logger) -> bool:
    try:
        # init harware timer
        #timer = Timer(0)
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
        if str(e) == "[Errno 113] EHOSTUNREACH":
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
