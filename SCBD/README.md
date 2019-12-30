# ESP32 Scan. Connect. Bypass. Drop data
## SCANNING MODE - All Channel Scan
All Channel Scan : scan ends after all the channel are checked, it will store DEFAULT_SCAN_LIST_SIZE of the whole matched AP. The number of matches is limited to DEFAULT_SCAN_LIST_SIZE = 4 in order to limit dynamic memory usage. Four matches allows APs with the same SSID name and all possible auth modes - Open, WEP, WPA and WPA2.

Once scan completes, DEFAULT_SCAN_LIST_SIZE Access Point records are read from WIFI module (default .sort_method = WIFI_CONNECT_AP_BY_SIGNAL = 0) and isOpen (array of flags) is set based on if network has encryption or not.

Wifi module is then configured with first isOpen network and then connection is started. If SYSTEM_EVENT_STA_DISCONNECTED, next isOpen network is configured or new scan begins.
