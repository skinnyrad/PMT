# ESP32 Scan. Connect. Bypass. Drop data

This example shows how to use scan of ESP32.
All channel scan : scan will end after checked all the channel, it will store four of the whole matched AP, you can set the sort method base on rssi or authmode, after scan, it will choose the best one and try to connect. Because it need malloc dynamic memory to store match AP, and most of cases is to connect to better signal AP, so it needn't record all the AP matched. The number of matches is limited to 4 in order to limit dynamic memory usage. Four matches allows APs with the same SSID name and all possible auth modes - Open, WEP, WPA and WPA2.
