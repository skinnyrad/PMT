# ESP32 Scan. Connect. Bypass. Drop data
## SCANNING MODE - All Channel Scan
All Channel Scan : scan ends after all the channel are checked, it will store DEFAULT_SCAN_LIST_SIZE of the whole matched AP. The number of matches is limited to DEFAULT_SCAN_LIST_SIZE = 4 in order to limit dynamic memory usage. Four matches allows APs with the same SSID name and all possible auth modes - Open, WEP, WPA and WPA2.

```c
// --- All-Channel Scan ---
// It scans all of the channels. 
// If the channel field of wifi_scan_config_t is set to 0,
// it is an all-channel scan.
wifi_scan_config_t wifi_scan_config = {
    //.sta = {
        .ssid = 0,
        .channel = 0, // All-Channel Scan
        // If commented, SCAN TYPE is Passive (Wait for Wifi beacon)
        .scan_type = WIFI_SCAN_TYPE_ACTIVE,

        // This field is used to control how long the scan dwells on each channel.
        // min=0, max=0: scan dwells on each channel for 120 ms.
        // If you want to improve the performance of the the scan, you can try to modify these two parameters.
        //.scan_time = 
    //},
};
```

## WIFI SCAN AP RECORDS
Once scan completes, DEFAULT_SCAN_LIST_SIZE Access Point records are read from WIFI module (default .sort_method = WIFI_CONNECT_AP_BY_SIGNAL = 0) and isOpen (array of flags) is set based on if network has encryption or not.

## CONNECTION
Wifi module is then configured with first isOpen network and then connection is started. If SYSTEM_EVENT_STA_DISCONNECTED, next isOpen network is configured or new scan begins.

```c
//  SET WIFI CONFS STRUCT
// DEFAULTS
wifi_config_t wifi_config = {
    // Station Mode
    .sta = {
        //.ssid = ssid,
        //.authmode = WIFI_AUTH_OPEN,
        //.scan_type = WIFI_SCAN_TYPE_ACTIVE,
        //.scan_method = WIFI_SCAN_TYPE_ACTIVE,
        // From Open to Protected APs
        // .sort_method = WIFI_CONNECT_AP_BY_SECURITY,
        // Default threshold, RSSI threshold is -127dBm.
        // the default authmode threshold is open.
        .threshold.rssi = 0,
        .threshold.authmode = 0,
    },
};
```
