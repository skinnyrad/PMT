/* Scan Connect Bypass Drop
   PMT Senior Design Team

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

/*
    In the All Channel Scan mode, the scan will end only after all the channels
    are scanned, and connection will start with the best network. The networks
    can be sorted based on Authentication Mode or Signal Strength. The priority
    for the Authentication mode is:  WPA2 > WPA > WEP > Open
*/
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event_loop.h"
#include "esp_event.h"
#include "nvs_flash.h"

// DNS includes
#include "lwip/inet.h"
#include "lwip/ip4_addr.h"
#include "lwip/dns.h"

// HTTP Client

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "lwip/netdb.h"
#include <string.h>

#define DEFAULT_SCAN_LIST_SIZE 4

static const char *TAG = "SCBD";

//static const char *REQUEST = "GET " WEB_URL " HTTP/1.0\r\n"
//    "Host: "WEB_SERVER"\r\n"
//    "Connection: keep-alive\r\n"
//    "Cache-Control: no-cache\r\n"
//    "Accept: */*\r\n"
//    "Accept-Encoding: gzip, deflate\r\n"
//    "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.97 Safari/537.36\r\n"
//    "\r\n";

ip_addr_t ip_Addr;
ip4_addr_t ip;
ip4_addr_t gw;
ip4_addr_t msk;
bool bConnected = false;
bool bDNSFound = false;
bool rescan = false;

//  SET WIFI CONFS
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

// FOR AP Scanning
uint16_t number = DEFAULT_SCAN_LIST_SIZE;
wifi_ap_record_t ap_info[DEFAULT_SCAN_LIST_SIZE];
uint16_t ap_count = 0;
bool isOpen [4] = {false,false,false,false};
// Start with position 0 from records
uint8_t connAp = 0;
static void print_auth_mode(int authmode)
{
    switch (authmode) {
    case WIFI_AUTH_OPEN:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_OPEN");
        break;
    case WIFI_AUTH_WEP:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WEP");
        break;
    case WIFI_AUTH_WPA_PSK:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA_PSK");
        break;
    case WIFI_AUTH_WPA2_PSK:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA2_PSK");
        break;
    case WIFI_AUTH_WPA_WPA2_PSK:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA_WPA2_PSK");
        break;
    case WIFI_AUTH_WPA2_ENTERPRISE:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_WPA2_ENTERPRISE");
        break;
    default:
        ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_UNKNOWN");
        break;
    }
}

static void print_cipher_type(int pairwise_cipher, int group_cipher)
{
    switch (pairwise_cipher) {
    case WIFI_CIPHER_TYPE_NONE:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_NONE");
        break;
    case WIFI_CIPHER_TYPE_WEP40:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_WEP40");
        break;
    case WIFI_CIPHER_TYPE_WEP104:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_WEP104");
        break;
    case WIFI_CIPHER_TYPE_TKIP:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_TKIP");
        break;
    case WIFI_CIPHER_TYPE_CCMP:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_CCMP");
        break;
    case WIFI_CIPHER_TYPE_TKIP_CCMP:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_TKIP_CCMP");
        break;
    default:
        ESP_LOGI(TAG, "Pairwise Cipher \tWIFI_CIPHER_TYPE_UNKNOWN");
        break;
    }

    switch (group_cipher) {
    case WIFI_CIPHER_TYPE_NONE:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_NONE");
        break;
    case WIFI_CIPHER_TYPE_WEP40:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_WEP40");
        break;
    case WIFI_CIPHER_TYPE_WEP104:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_WEP104");
        break;
    case WIFI_CIPHER_TYPE_TKIP:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_TKIP");
        break;
    case WIFI_CIPHER_TYPE_CCMP:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_CCMP");
        break;
    case WIFI_CIPHER_TYPE_TKIP_CCMP:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_TKIP_CCMP");
        break;
    default:
        ESP_LOGI(TAG, "Group Cipher \tWIFI_CIPHER_TYPE_UNKNOWN");
        break;
    }
}


static esp_err_t event_handler(void *ctx, system_event_t *event)
{
    switch (event->event_id) {
        case SYSTEM_EVENT_STA_START:
            ESP_LOGI(TAG, "SYSTEM_EVENT_STA_START");
            break;
        case SYSTEM_EVENT_STA_GOT_IP:
            ESP_LOGI(TAG, "SYSTEM_EVENT_STA_GOT_IP");
            
            ip = event->event_info.got_ip.ip_info.ip;
            gw = event->event_info.got_ip.ip_info.gw;
            msk = event->event_info.got_ip.ip_info.netmask;
            bConnected = true;
            
            ESP_LOGI(TAG, "Got IP: %s\n", ip4addr_ntoa( &ip ));
            // TEST CONNECTION TO INTERNET
            // DNS Resolving (TRUE = > DROP DATA, FALSE => SEE IF THERE IS SPLASH PORTAL)
            break;
        case SYSTEM_EVENT_STA_DISCONNECTED:
            // The most common event handle code for this event in application is to call esp_wifi_connect()
            // to reconnect the Wi-Fi. However, if the event is raised because esp_wifi_disconnect() is called,
            // the application should not call esp_wifi_connect() to reconnect. It’s application’s responsibility
            // to distinguish whether the event is caused by esp_wifi_disconnect() or other reasons.
            ESP_LOGI(TAG, "SYSTEM_EVENT_STA_DISCONNECTED");
            bDNSFound = false;
            bConnected = false;
            
            // Increment connAp for next round if fails
            if(connAp < ap_count) 
                connAp++;

            // TRY CONNECTING TO connAp NETWORK SSID FROM SCAN
            memcpy(wifi_config.sta.ssid, ap_info[connAp].ssid, 32);
            ESP_LOGI("DISC", "### Connecting to SSID \t\t%s ###", ap_info[connAp].ssid);
            
            
            // Set AP Configs
            ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));

            // START CONNECTING
            ESP_ERROR_CHECK(esp_wifi_connect());            
            break;
        default:
            break;
    }
    return ESP_OK;
}

/* Initialize Wi-Fi as sta and set scan method */
static void wifi_scan(void)
{
    // clear connAp
    connAp = 0;

    // inits struct for AP search information
    memset(ap_info, 0, sizeof(ap_info));

    // init stuff
    tcpip_adapter_init();
    // When Wi-Fi, Ethernet, or IP stack generate an event, this event is sent to a high-priority
    // event task via a queue. Application-provided event handler function is called in the context of this task.
    ESP_ERROR_CHECK(esp_event_loop_init(event_handler, NULL));
    // Creates the Wi-Fi driver task and initialize the Wi-Fi driver.
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

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

    
    // STAtion mode: 
    // in this mode, esp_wifi_start() will init the internal station data,
    // while the station’s interface is ready for the RX and TX Wi-Fi data.
    // After esp_wifi_connect() is called, the STA will connect to the target AP.
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));

    // SET WIFI CONFS
    // ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));

    // Starts Wi-Fi Driver
    ESP_ERROR_CHECK(esp_wifi_start());

    // START SCAN with scan configuations
    ESP_ERROR_CHECK(esp_wifi_scan_start(&wifi_scan_config, true));

    // Do not call esp_wifi_scan_get_ap_records() twice for a single scan-done event.
    // But call once because we need to free allocated memory for records
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&number, ap_info));
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(&ap_count));

    // OUTPUT SCANNED NETWORKS
    ESP_LOGI(TAG, "Total APs scanned = %u", ap_count);
    for (int i = 0; (i < DEFAULT_SCAN_LIST_SIZE) && (i < ap_count); i++) {
        // PRINT ONLY OPEN APs
        //if(ap_info[i].authmode == WIFI_AUTH_OPEN) {
            ESP_LOGI(TAG, "SSID \t\t%s", ap_info[i].ssid);
            ESP_LOGI(TAG, "RSSI \t\t%d", ap_info[i].rssi);
            print_auth_mode(ap_info[i].authmode);
            if (ap_info[i].authmode != WIFI_AUTH_WEP) {
                print_cipher_type(ap_info[i].pairwise_cipher, ap_info[i].group_cipher);
            }
            ESP_LOGI(TAG, "Channel \t\t%d\n", ap_info[i].primary);
        //}
    }
    
    // MUST DO!!! REMEMBER WHICH INDEXES APs are OPEN and try conecting to those
    // instead of going through all of them.

    // TRY CONNECTING TO FIRST NETWORK SSID FROM SCAN
    memcpy(wifi_config.sta.ssid, ap_info[connAp].ssid, 32);
    ESP_LOGI("CONN", "Connecting to SSID \t\t%s", ap_info[connAp].ssid);
    // Increment connAp for next round if fails
    // if(connAp < ap_count) 
    //     connAp++;
    // Set AP Configs
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));

    // START CONNECTING
    ESP_ERROR_CHECK(esp_wifi_connect());

}

void app_main()
{
    // Initialize NVS
    // Non-volatile storage (NVS) library is designed to store key-value pairs in flash.
    // https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/storage/nvs_flash.html
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK( ret );

    // SET UP WIFI
    if (!bConnected) wifi_scan();
}
