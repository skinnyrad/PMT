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
import logging
# https request information
headers = {
    'Content-Type': 'application-json',
}

def post_data(post_data, post_url, logger: Logger) -> bool:
    try:
        response = post(post_url, headers=headers, data=post_data)
        if response.status_code == 200:
            #TODO: remove print
            print("Post Request Successful")
            logger.info("Post Request Successful")
            return True
        else:
            #TODO: remove print
            print("Post Request Unsuccessful")
            logger.info("Post Request Unsuccessful")
            return False
    except OSError as e:
        #TODO: remove print
        print("Warning: " + str(e))
        logger.warning(str(e))
        return False
