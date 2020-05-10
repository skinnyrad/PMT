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
#  Filename : encry.py
# -------------------------------
# AES 128 Encryption
# 16 bytes BLOCKS
# https://docs.micropython.org/en/latest/library/ucryptolib.html
# 2 = MODE_CBC
# Key size % 16
# message size % 16
# IV must be 16 bytes

# ORDER "Time":"13:07:32","Latitude":"34.73348","Longitude":"-86.63177","Date":"2020-02-19"

from ucryptolib import aes
import ubinascii
import uhashlib


iv = b"PharmacyPMT01546"

# PKCS#7 for padding => 0x5F (ASCII _)
def pad_mod_16(_string):
    while not len(_string) % 16 == 0:
        _string = _string + '_'
    return _string


# Any sequnece of chars works, kinda like this one and also 16 bytes long.
# DEFINITION: a ringing or tinkling sound.
delimiter = "TINTINNABULATION"

# Function that returns ciphertext+delimiter
def encrypt(key,data):

    # ended up not hasing the key, just pad it, make sure it's 16 bytes
    cryptor = aes(pad_mod_16(key),2,iv)
    # append chunk delimiter string before base64 encoding
    ciphertext = cryptor.encrypt(pad_mod_16(str.encode(data)))
    # encode to base 64 for sending
    ciphertext_b64 = ubinascii.b2a_base64(ciphertext)

    return ciphertext_b64+delimiter
