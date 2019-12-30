# ESP32 Scan. Connect. Bypass. Drop data
## SCANNING MODE - All Channel Scan
All channel scan : scan will end after checked all the channel, it will store four of the whole matched AP, you can set the sort method base on rssi or authmode, after scan, it will choose the best one and try to connect. Because it need malloc dynamic memory to store match AP, and most of cases is to connect to better signal AP, so it needn't record all the AP matched. The number of matches is limited to DEFAULT_SCAN_LIST_SIZE = 4 in order to limit dynamic memory usage. Four matches allows APs with the same SSID name and all possible auth modes - Open, WEP, WPA and WPA2.

Once scan is complete, DEFAULT_SCAN_LIST_SIZE Access Point records are read from WIFI module (default SORT-METHOD -> signal strength) and isOpen (array of flags) is set based on if network has encryption or not.

Wifi module is then configured with first isOpen network and then connection is started. If SYSTEM_EVENT_STA_DISCONNECTED, next isOpen network is configured or new scan begins.
