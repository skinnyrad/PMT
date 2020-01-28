# Accelerometer Code
# PINOUT:
#           SCL -> pin 10
#           SDA -> pin 9

from machine import Pin, I2C
import math
Accel_data = {
    "X": -127,
    "Y": -127,
    "Z": -127,
    "MAGNITUDE": 127
}

SCL_PIN = 10
SDA_PIN = 9

def main():
    i2c = init_i2c_accel()     # initialize i2c communication for Accelerometer

    # scan for slave devices
    devices = i2c.scan()             
    if len(devices) == 0:
        print("ERROR: No i2c device found!")
        return(1)
    else:
        print('i2c devices found:', devices)
        print('Connecting to device ', devices[0])

    slave_addr = devices[0] # Select first device found as slave address to communicate with

    status = get_accel_status(i2c, slave_addr)
    print(status)   # 0x00 = No data available, 0xff: data available

    accel_enable(i2c, slave_addr)   # Enable data transmission from accelerometer

    while True:
        Accel_data = get_all_axis_data(i2c, slave_addr) # Read Axis Data
        print_accel_data(Accel_data)                    # Print Data

# Calculate magnitude = sqrt(x^2 + y^2 + z^2)
def calculate_magnitude(data):
    magnitude = math.sqrt(pow(data['X'], 2) + pow(data['Y'], 2) + pow(data['Z'], 2))
    return magnitude

# Enable data transmission from accelerometer
def accel_enable(i2c, slave_addr):
    memaddr = 0x20
    data_write = b'\x27'                             # enable 10 Hz data transmission
    i2c.writeto_mem(slave_addr, memaddr, data_write) 

# Get status from accelerometer
def get_accel_status(i2c, slave_addr):    
    memaddr = 0x07             
    reg_size_bytes = 1
    status = i2c.readfrom_mem(slave_addr,memaddr,reg_size_bytes) 
    return status

# Initialize I2C for Accelerometer
def init_i2c_accel():
    i2c = I2C(1, scl=Pin(SCL_PIN), sda=Pin(SDA_PIN), freq=400000)  # construct a hardware I2C bus
    return i2c

# Print Accelerometer Data
def print_accel_data(data):
    offset = 5 # Offset value for detecting movement. Higher offset = less sensitive to movement, lower offset = more sensitive to movement

    if data["MAGNITUDE"] < 62-offset or data["MAGNITUDE"] > 62+offset: 
        movement_flag = "MOVEMENT"
    else:
        movement_flag = ""
    
    print("X: % 4d \tY: % 4d \tZ: % 4d \tMAG: % 4d \t%s " %(data["X"], data["Y"], data["Z"], data["MAGNITUDE"], movement_flag))

# get all axis data from accelerometer
def get_all_axis_data(i2c, slave_addr):
    Accel_data["X"] = get_x_axis_data(i2c, slave_addr)
    Accel_data["Y"] = get_y_axis_data(i2c, slave_addr)
    Accel_data["Z"] = get_z_axis_data(i2c, slave_addr)
    Accel_data["MAGNITUDE"] = calculate_magnitude(Accel_data)
    return Accel_data
    
# get x-axis data from accelerometer
def get_x_axis_data(i2c, slave_addr):
    memaddr = 0x29
    reg_size_bytes = 1
    data_x = i2c.readfrom_mem(slave_addr,memaddr,reg_size_bytes) # read 1 byte from X-Axis Acceleration Data
    data_x = byte_to_signed_int(data_x)                          # Convert from byte to signed int
    return data_x

# get y-axis data from accelerometer
def get_y_axis_data(i2c, slave_addr):
    memaddr = 0x2B
    reg_size_bytes = 1
    data_y = i2c.readfrom_mem(slave_addr,memaddr,reg_size_bytes) # read 1 byte from Y-Axis Acceleration Data
    data_y = byte_to_signed_int(data_y)                          # Convert from byte to signed int
    return data_y

# get z-axis data from accelerometer
def get_z_axis_data(i2c, slave_addr):
    memaddr = 0x2D
    reg_size_bytes = 1
    data_z = i2c.readfrom_mem(slave_addr,memaddr,reg_size_bytes) # read 1 byte from Z-Axis Acceleration Data
    data_z = byte_to_signed_int(data_z)                          # Convert from byte to signed int
    return data_z

# Convert from byte to signed int
def byte_to_signed_int(byte):
    byte = int.from_bytes(byte, 'big', True) # Convert byte data to unsigned int
    if byte > 127:                             # Convert unsigned int (8 bits) to signed int
        byte = (256-byte) * (-1)
    return byte

main()