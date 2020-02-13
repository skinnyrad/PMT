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

# https request information
url = "https://pmtlogger.000webhostapp.com/api/post.php"

headers = {
    'Content-Type': 'application-json',
}

def post_data(post_data) -> bool:
    try:
        response = post(url, headers=headers, data=post_data)
        if response.status_code == 200:
            print("Post Request Successful")
            return True
        else:
            print("Post Request Unsuccessful")
            return False
    except OSError as e:
        print("Warning: " + str(e))
