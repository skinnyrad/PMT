# Accelerometer Code

from machine import Pin, I2C

# construct a software I2C bus
i2c = I2C(scl=Pin(21), sda=Pin(22), freq=100000)

# construct a hardware I2C bus
i2c = I2C(0)
i2c = I2C(1, scl=Pin(21), sda=Pin(22), freq=400000)

i2c.scan()              # scan for slave devices

slave_addr = 24
memaddr = 0x07
reg_size_bytes = 1
data = i2c.readfrom_mem(slave_addr,memaddr,reg_size_bytes) # read 4 bytes from slave device with address 0x3a
#print(data)

memaddr = 0x20
data_write = b'\x27' # Write 0x10 to enable 1 Hz data transmission
data = i2c.readfrom_mem(slave_addr,memaddr,reg_size_bytes) # read 4 bytes from slave device with address 0x3a
#print(data)
i2c.writeto_mem(slave_addr, memaddr, data_write)

# Read X axis acceleration data
while True:
    memaddr = 0x29
    data = i2c.readfrom_mem(slave_addr,memaddr,reg_size_bytes) # read 4 bytes from slave device with address 0x3a
    data = int.from_bytes(data, 'big', True) # Convert byte data to signed int
    if data > 127:
        data = (256-data) * (-1)
    
    print(data)