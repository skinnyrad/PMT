/* SD card and FAT filesystem example.
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.

PINS Connections
    MISO    PIN 2
    MOSI    PIN 15
    CLK     PIN 14
    CS      PIN 13

*/

#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_vfs_fat.h"
#include "driver/sdmmc_host.h"
#include "driver/sdspi_host.h"
#include "sdmmc_cmd.h"

static const char *TAG = "example";

/* Struct for holding GPS Tracking Data */
struct GPS_Data {
    float latitude, longitude;
    uint16_t year;
    uint8_t month, day, hour, minute, second;
};

/* Function Prototypes */
void SD_Card_init();                                    // Initialize SD Card
void SD_Card_UNIT_TEST();                               // Unit Test for SD Card using Mock Data 
void write_data_log_header(FILE* f);                    // Writes GPS Data Header to Log File 
void write_data_sample(FILE* f, struct GPS_Data data);  // Write GPS Data Sample to File 

void app_main(void)
{
    SD_Card_init();                  // Initialize SD Card

    struct GPS_Data GPS_Data;
    bool newPacket = false;

    /* Open binary file for writing */
    const char myFileName[] = "/sdcard/testfile.bin";
    FILE* f = fopen(myFileName, "wb");

    ESP_LOGI(TAG, "Opening file");

    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for writing");
        return;
    }

    /* Write data sample with every new packet from GPS */
    while (1) {
        if (newPacket) {
            write_data_sample(f, GPS_Data);    // Write GPS Data Sample to Log File
        }
    }
    
    /* All done, unmount partition and disable SDMMC or SPI peripheral */
    esp_vfs_fat_sdmmc_unmount();     // Deinitialize SD Card
    ESP_LOGI(TAG, "Card unmounted");
}

/* Writes GPS Data Header to Log File */
void write_data_log_header(FILE* f)
{
    fprintf(f, "Latitude \tLongitude \tYYYY:MM:DD  hh:mm:ss \n");
}

/* Write GPS Data Sample to File */
void write_data_sample(FILE* f, struct GPS_Data data)
{
    fwrite(&data, sizeof(struct GPS_Data), 1, f);
}

/* Unit Test for SD Card using Mock Data */
void SD_Card_UNIT_TEST()
{
    struct GPS_Data GPS_Data;

 /* Open File for Writing */
    const char myFileName[] = "/sdcard/testfile.bin";
    FILE* f = fopen(myFileName, "wb");

    ESP_LOGI(TAG, "Opening file");

    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for writing");
        return;
    }

    /* Write to File */
    uint64_t sampleLength = 100;

    for (uint64_t i = 0; i < sampleLength; i++)
    {
        // Parameters for Tracking
        static float latitude, longitude = 50;
        static uint16_t year = 0;
        static uint8_t month, day, hour, minute, second = 0;
        
        // Write data sample

        GPS_Data.latitude = latitude; GPS_Data.longitude = longitude;
        GPS_Data.year = year; GPS_Data.month = month; GPS_Data.day = day;
        GPS_Data.hour = hour; GPS_Data.minute = minute; GPS_Data.second = second;
        
        write_data_sample(f, GPS_Data);    // Write GPS Data Sample to Log File
        
        // Increment parameters
        latitude += .01;
        longitude -= .02;
        
        year = 2019;    
        month = 12;
        day = 18;

        hour = 8;
        minute = 35;
        second += 1;
    }
    
    fclose(f);
    ESP_LOGI(TAG, "File written");
}

/* Initialize SD Card using SDMMC or SPI Peripheral */
void SD_Card_init()
{
     ESP_LOGI(TAG, "Initializing SD card");

     // Enable I/O Interrupts to accept SDIO Interrupts
        sdmmc_host_io_int_enable(SDMMC_HOST_SLOT_1);

        ESP_LOGI(TAG, "Using SDMMC peripheral");
        sdmmc_host_t host = SDMMC_HOST_DEFAULT();

        // This initializes the slot without card detect (CD) and write protect (WP) signals.
        // Modify slot_config.gpio_cd and slot_config.gpio_wp if your board has these signals.
        sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();

        // To use 1-line SD mode, uncomment the following line:
        slot_config.width = 1;

        // GPIOs 15, 2, 4, 12, 13 should have external 10k pull-ups.
        // Internal pull-ups are not sufficient. However, enabling internal pull-ups
        // does make a difference some boards, so we do that here.
        gpio_set_pull_mode(15, GPIO_PULLUP_ONLY);   // CMD, needed in 4- and 1- line modes   (MOSI)
        gpio_set_pull_mode(2, GPIO_PULLUP_ONLY);    // D0, needed in 4- and 1-line modes     (MISO)
        gpio_set_pull_mode(4, GPIO_PULLUP_ONLY);    // D1, needed in 4-line mode only
        gpio_set_pull_mode(12, GPIO_PULLUP_ONLY);   // D2, needed in 4-line mode only
        gpio_set_pull_mode(13, GPIO_PULLUP_ONLY);   // D3, needed in 4- and 1-line modes     (CS)

        // Options for mounting the filesystem.
        // If format_if_mount_failed is set to true, SD card will be partitioned and
        // formatted in case when mounting fails.
        esp_vfs_fat_sdmmc_mount_config_t mount_config = {
            .format_if_mount_failed = false,
            .max_files = 5,
            .allocation_unit_size = 16 * 1024
        };

        // Use settings defined above to initialize SD card and mount FAT filesystem.
        // Note: esp_vfs_fat_sdmmc_mount is an all-in-one convenience function.
        // Please check its source code and implement error recovery when developing
        // production applications.
        sdmmc_card_t* card;
        esp_err_t ret = esp_vfs_fat_sdmmc_mount("/sdcard", &host, &slot_config, &mount_config, &card);

        if (ret != ESP_OK) {
            if (ret == ESP_FAIL) {
                ESP_LOGE(TAG, "Failed to mount filesystem. "
                    "If you want the card to be formatted, set format_if_mount_failed = true.");
            } else {
                ESP_LOGE(TAG, "Failed to initialize the card (%s). "
                    "Make sure SD card lines have pull-up resistors in place.", esp_err_to_name(ret));
            }
            return;
        }

        // Card has been initialized, print its properties
        sdmmc_card_print_info(stdout, card);
    }