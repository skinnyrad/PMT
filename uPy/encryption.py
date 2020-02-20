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

dataCSV = ["-86.6412163420141","34.722586539952","2019-10-14","14:30:00",
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

# https request information
url = "https://pmtlogger.000webhostapp.com/api/postEncrypted.php"

# def array_tostring(array_data):
#     _string = ""
#     for _array in array_data:
#         _string = _string + chr(_array)
#         return _string
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
station.connect("SardisTel 6832","KTFujP23")
while not station.isconnected():
    utime.sleep(1)

key = '1234567890abcdef'
iv = b"1234567890123456"

print ('KEY: '+pad_mod_16(key)+'\n')
# AES 128 Encryption
# 16 bytes BLOCKS
# https://docs.micropython.org/en/latest/library/ucryptolib.html
# 2 = MODE_CBC
# Key size % 16
# message size % 16
# IV looks like won't work if more than 16 bytes

# Hashing will pad for us.

cryptor = aes(uhashlib.sha256(key).digest(),2,iv)
ciphertext = cryptor.encrypt(str.encode(pad_mod_16(','.join(dataCSV)+',')))

#ciphertext = cryptor.encrypt(ubinascii.b2a_base64(','.join(dataCSV)+','))

headers = {
    #'Content-Type': 'text/html; charset=UTF-8',
}

ciphertext_b64 = ubinascii.b2a_base64(ciphertext)
# Send encrypted data to server
res = post(url,headers,ciphertext_b64)
print ('Post Status Code: '+ str(res.status_code))
## can't use the same aes object for en/decryption
# decryptor = aes(key,2,iv)

# deciphertext = decryptor.decrypt(ubinascii.a2b_base64(ciphertext_b64))