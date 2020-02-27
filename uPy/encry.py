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
#  Filename : main.py

from ucryptolib import aes
import urequests
import network
import utime
import ubinascii
import uhashlib
# ORDER "Time":"13:07:32","Latitude":"34.73348","Longitude":"-86.63177","Date":"2020-02-19"

## MOCK DATA
dataCSV = ["13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
"13:07:32","34.722586539952","-86.6412163420141","2019-10-14",
]

# https request information
url = "https://pmtlogger.000webhostapp.com/api/postEnc.php"

def post(_url, _headers, _post_data):
    return urequests.post(_url, headers=_headers, data=_post_data)

# PKCS#7 for padding => 0x5F (ASCII _)
def pad_mod_16(_string):
    while not len(_string) % 16 == 0:
        _string = _string + '_'
    return _string

# Create a station object to store our connection
station = network.WLAN(network.STA_IF)

# activate station
station.active(True)

station.scan()

station.connect("ssid","password")
>>>>>>> b0b26634b9e85e1d5784f9b8461191257e064b66

while not station.isconnected():
    utime.sleep(1)

# AES 128 Encryption
# 16 bytes BLOCKS
# https://docs.micropython.org/en/latest/library/ucryptolib.html
# 2 = MODE_CBC
# Key size % 16
# message size % 16
# IV must be 16 bytes

key = '1234567890abcdef'
iv = b"1234567890123456"

# Any sequnece of chars works, kinda like this one and also 16 bytes long.
# DEFINITION: a ringing or tinkling sound.
delimiter = "TINTINNABULATION"
print ('KEY: '+pad_mod_16(key)+'\n')

# ended up not hasing the key, just pad it, make sure it's 16 bytes
cryptor = aes(pad_mod_16(key),2,iv)
# append chunk delimiter string before base64 encoding
ciphertext = cryptor.encrypt(str.encode(pad_mod_16(','.join(dataCSV)+',')))
# encode to base 64 for sending
ciphertext_b64 = ubinascii.b2a_base64(ciphertext)

headers = {
    'Content-Type': 'text/html; charset=UTF-8',
}   
# Send encrypted data to server
# append chunk delimiter string to base64 encoding
res = post(url,headers,ciphertext_b64+delimiter)
print ('Post Status Code: '+ str(res.status_code))
