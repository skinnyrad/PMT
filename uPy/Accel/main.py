from machine import Pin, I2C

# construct an I2C bus
i2c = I2C(scl=Pin(21), sda=Pin(22), freq=9800)

# i2c.readfrom(0x0f, 1)   # read 4 bytes from slave device with address 0x3a
# i2c.writeto(0x3a, '12') # write '12' to slave device with address 0x3a

#buf = bytearray(10)     # create a buffer with 10 bytes
# i2c.writeto(0x3a, buf)  # write the given buffer to the slave