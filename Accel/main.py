# Accelerometer Code
# PINOUT:
#           SCL -> pin 10
#           SDA -> pin 9

from machine import Pin, I2C
import machine
import uos
import math
import time
import esp32

SCL_PIN = 10
SDA_PIN = 9
motion = False
i2c = 0
slave_addr = 0

def main():
    global i2c, slave_addr, motion

    i2c = init_i2c_accel()     # initialize i2c communication for Accelerometer
    pin_INT1 = Pin(14, mode = Pin.IN) # Create an input pin on pin #18 for reading Interrupt
    esp32.wake_on_ext0(pin = pin_INT1, level = esp32.WAKEUP_ANY_HIGH)
    # pin_INT1.irq(trigger=Pin.IRQ_RISING, handler=handle_accel_interrupt) # Attach an interrupt to the pin by calling the irq() method

    if machine.reset_cause() == machine.DEEPSLEEP_RESET:
        print('Woke from deep sleep')

    # scan for slave devices
    devices = i2c.scan()             
    if len(devices) == 0:
        print("ERROR: No i2c device found!")
        return(1)
    else:
        print('i2c devices found:', devices)
        print('Connecting to device ', devices[0])

    slave_addr = devices[0] # Select first device found as slave address to communicate with

    status = get_accel_status()
    print(status)   # 0x00 = No data available, 0xff: data available

    accel_config()   # Configure Accelerometer settings
    INT1_status = get_accel_INT1_status()    # Reset interrupt by reading
    count = 0
    while True:
        print("Entering Deep Sleep...")
        machine.deepsleep()
        print("Motion detected! % d" % (count))
        INT1_status = get_accel_INT1_status()
        motion = False
        count = count + 1
        time.sleep_ms(10000)

#def handle_accel_interrupt(pin):
#    global motion, i2c, slave_addr
#    motion = True
#    INT1_status = get_accel_INT1_status()

def stop():
    uos.remove('main.py')

# Enable data transmission from accelerometer
def accel_config():       
    global i2c, slave_addr
    i2c.writeto_mem(slave_addr, 0x20, b'\x27')  # enable 10 Hz data transmission
    i2c.writeto_mem(slave_addr, 0x21, b'\x01')  # High Pass filter for INT1
    i2c.writeto_mem(slave_addr, 0x22, b'\x40')  # IA1 enable
    i2c.writeto_mem(slave_addr, 0x23, b'\x10')  # Scale of 4g
    i2c.writeto_mem(slave_addr, 0x24, b'\x08')  # INT1 pin latched until register read
    i2c.writeto_mem(slave_addr, 0x30, b'\x2a')  # OR, X,Y,Z higher than threshold. 
    i2c.writeto_mem(slave_addr, 0x32, b'\x02')  # 64 mg threshold, 0x01 can be close to noise so interrupt would be triggered by noise
    i2c.writeto_mem(slave_addr, 0x33, b'\x05')  # 0.5s to activate interrupt

# Get status from accelerometer
def get_accel_status():
    global i2c, slave_addr    
    memaddr = 0x07             
    reg_size_bytes = 1
    status = i2c.readfrom_mem(slave_addr,memaddr,reg_size_bytes) 
    return status
# Get status from accelerometer
def get_accel_INT1_status(): 
    global i2c, slave_addr   
    memaddr = 0x31             
    reg_size_bytes = 1
    status = i2c.readfrom_mem(slave_addr,memaddr,reg_size_bytes) 
    return status
# Initialize I2C for Accelerometer
def init_i2c_accel():
    global i2c
    i2c = I2C(1, scl=Pin(SCL_PIN), sda=Pin(SDA_PIN), freq=100000)  # construct a hardware I2C bus
    return i2c

main()