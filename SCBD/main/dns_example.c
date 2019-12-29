#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "lwip/inet.h"
#include "lwip/ip4_addr.h"
#include "lwip/dns.h"

#define DEMO_STA_SSID      "<< SSID >>
#define DEMO_STA_PASSWORD "<< Password >>" 

char szURL[] = "api.thingspeak.com";
ip_addr_t ip_Addr;

ip4_addr_t ip;
ip4_addr_t gw;
ip4_addr_t msk;

bool bConnected = false;
bool bDNSFound = false;

esp_err_t wifi_event_cb(void *ctx, system_event_t *event)
{
    if( event->event_id == SYSTEM_EVENT_STA_GOT_IP ) {
        ip = event->event_info.got_ip.ip_info.ip;
        gw = event->event_info.got_ip.ip_info.gw;
        msk = event->event_info.got_ip.ip_info.netmask;
        bConnected = true;
    }
    
    return ESP_OK;
}

void dns_found_cb(const char *name, const ip_addr_t *ipaddr, void *callback_arg)
{
    ip_Addr = *ipaddr;

    bDNSFound = true;
}

void mainTask(void *pvParameters)
{
    esp_event_set_cb(wifi_event_cb, NULL);
        
    printf("Set mode to STA\n");
    esp_wifi_set_mode(WIFI_MODE_STA);
	
    wifi_config_t config;
    memset(&config,0,sizeof(config));
	
    strcpy( config.sta.ssid, DEMO_STA_SSID );
    strcpy( config.sta.password, DEMO_STA_PASSWORD );
    
    printf("Set config\n");
    esp_wifi_set_config( WIFI_IF_STA, &config );
    
    printf("Start\n");
    esp_wifi_start();
    
    printf("Connect\n");
    esp_wifi_connect();
    
    while( !bConnected )
        ;
        
    printf("Got IP: %s\n", inet_ntoa( ip ) );
    printf("Net mask: %s\n", inet_ntoa( msk ) );
    printf("Gateway: %s\n", inet_ntoa( gw ) );

    IP_ADDR4( &ip_Addr, 0,0,0,0 );

    printf("Get IP for URL: %s\n", szURL );
    dns_gethostbyname(szURL, &ip_Addr, dns_found_cb, NULL );

    while( !bDNSFound )
        ;
        
    printf( "DNS found: %i.%i.%i.%i\n", 
        ip4_addr1(&ip_Addr.u_addr.ip4), 
        ip4_addr2(&ip_Addr.u_addr.ip4), 
        ip4_addr3(&ip_Addr.u_addr.ip4), 
        ip4_addr4(&ip_Addr.u_addr.ip4) );
        
    while (1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        //printf("ping\n");
    }
}

void app_main()
{
    // xTaskCreatePinnedToCore( pvTaskCode, pcName, usStackDepth, pvParameters, 
    //     uxPriority, pxCreatedTask, xCoreID )
    xTaskCreatePinnedToCore(&mainTask, "mainTask", 2048, NULL, 5, NULL, 0);
}
