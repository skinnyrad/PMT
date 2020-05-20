#Quick script to turn power off in various ways and then turn it back on
#The usb bus shutdown works really well for many USB clients but doesn't
#really produce a noticeable change with the USB U-Blox7 GPS module.

/usr/bin/tvservice -o > /dev/null #Turns off HDMI display [25mA]

sudo iwconfig wlan0 txpower off #Turns off WiFi transmit power [30mA]

echo 0 | sudo tee /sys/devices/platform/soc/20980000.usb/buspower >/dev/null #turns off usb bus [depends on device].

sleep 10 #sleep for 10 seconds

echo 1 | sudo tee /sys/devices/platform/soc/20980000.usb/buspower >/dev/null #turn on USB bus

sudo iwconfig wlan0 txpower auto > /dev/null 2>&1 #turns on wifi. produces an error but works.

/usr/bin/tvservice -p > /dev/null #turn on HDMI
