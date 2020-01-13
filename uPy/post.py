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

from urequests import post

# https request information
url = "https://pmtlogger.000webhostapp.com/api/postCSV.php"

## "id","Longitude","Latitude","Date","Time"
dataCSV = [
"-86.6412163420141","34.722586539952","2019-10-14","14:30:00",
"-86.6411210245048","34.7232260242348","2019-10-15","14:30:10",
"-86.6420061571728","34.7235031028468","2019-10-16","14:30:20",
"-86.6421187854007","34.7242470342329","2019-10-17","14:30:30",
"-86.641940000026","34.7245409600879","2019-10-18","14:30:40",
"-86.6421847643798","34.7248047166302","2019-10-19","14:30:50",
"-86.6425906007074","34.7246067235775","2019-10-20","14:31:00",
"-86.6427949012338","34.724206185779","2019-10-21","14:31:10",
"-86.6431778066368","34.7240024430458","2019-10-22","14:31:20",
"-86.6436242447878","34.7239260217465","2019-10-23","14:31:30",
"-86.6439779020318","34.7241005807449","2019-10-24","14:31:40",
"-86.6439714392672","34.7245197489505","2019-10-25","14:31:50",
"-86.6439375447486","34.7249956102817","2019-10-26","14:32:00",
"-86.6439286316693","34.7253607985706","2019-10-27","14:32:10",
"-86.6438679842583","34.7257620487998","2019-10-28","14:32:20",
"-86.6435760632231","34.7260039358756","2019-10-29","14:32:30",
"-86.6425538064605","34.7263005486733","2019-10-30","14:32:40",
"-86.641839485347","34.7267437665668","2019-10-31","14:32:50",
"-86.6409493466223","34.7273238940422","2019-11-01","14:33:00",
"-86.6400003351475","34.7276064727814","2019-11-02","14:33:10",
"-86.6385770412927","34.7276646692817","2019-11-03","14:33:20",
"-86.6380048458353","34.7269783973773","2019-11-04","14:33:30",
"-86.6382245303282","34.7264934421783","2019-11-05","14:33:40",
"-86.6389299520553","34.7261097279809","2019-11-06","14:33:50"
]

headers = {
    'Content-Type': 'application-json',
}

def post_data(_post_data) -> bool:
    response = post(url, headers=headers, data=_post_data)
    if response.status_code == 200:
        print("Post Request Successful")
        return True
    else:
        print("Post Request Unsuccessful")
        return False
