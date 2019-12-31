/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.

   PINOUT
        TX: 22 (connect to RX on slave) 
        RX: 21 (connect to TX on slave)
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_task_wdt.h"

#include "driver/uart.h"

void GPS_init(const int uart_num, int uart_rx_buffer_size, int uart_tx_buffer_size);
void get_GPS_data(uint8_t* data, int* bytesRead, bool* newPacket, const int uart_num, int uart_rx_buffer_size); //reset WDT
int stringSearch(char* buffer, int bufferSize, char* string, int stringSize); 

void app_main()
{
    // Configure UART0
    const int uart_num = UART_NUM_1;
    int uart_rx_buffer_size = 2048;
    int uart_tx_buffer_size = 2048;
    uint8_t data[uart_rx_buffer_size];
    bool newPacket = false;
    int bytesRead = 0;
    
    GPS_init(uart_num, uart_rx_buffer_size, uart_tx_buffer_size);
    
    printf("Begin Listening for packets...");
    while (true) {
        get_GPS_data(data, &bytesRead, &newPacket, uart_num, uart_rx_buffer_size);
        if (newPacket) {        // New Data Packet
            newPacket = false;
            //print the buffer contents
            for(int i = 0; i < bytesRead; i++) {
                // printf("%c",(unsigned int)data[i]);
                
            }
            // Parse and Write to SD card
        }  
    }

    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}

/* Searches for starting index of a string within a buffer */
int stringSearch(char* buffer, int bufferSize, char* string, int stringSize)
{
    int stringIndex;
    for (int i = 0, j = 0; i < bufferSize; i++) {
        if (string[j] == buffer[i]) {
            if (j == 0)				// First character correct
                stringIndex = i;	// Mark starting location of string
            j++;    				// Increment j for every correct character in sequence

            if (j == stringSize-1)	// If number of correct characters in sequence = length
                return stringIndex; // String found, return index location
        }
        else
            j = 0;					// If character in sequence is incorrect, reset sequence counter j
    }
    return -1;                      // String not found, return -1
}

void get_GPS_data(uint8_t* data, int* bytesRead, bool* newPacket, const int uart_num, int uart_rx_buffer_size) //reset WDT
    {
        esp_task_wdt_reset();
        static unsigned int prevLength = 0;
        static unsigned int newLength = 0;

        // Read data length from UART.
        prevLength = newLength;
        uart_get_buffered_data_len(uart_num, (size_t*)&newLength);
        
        //it is still sending
        if(newLength != prevLength){
            //delay for .1 second
            printf("\nReceiving... %d", newLength);
            vTaskDelay(200 / portTICK_PERIOD_MS);
            *newPacket = true;
        }

        //otherwise it must have stopped sending
        if(*newPacket){
            //get the buffer contents
            *bytesRead = uart_read_bytes(uart_num, data, newLength, 100);
            printf("\nUART%d received %d bytes:\n", uart_num, *bytesRead);
        }
    }

 void GPS_init(const int uart_num, int uart_rx_buffer_size, int uart_tx_buffer_size)
    {
        int err = 0;
        uart_config_t uart_config = {
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .rx_flow_ctrl_thresh = 122
        };
        // Configure UART parameters
        err = uart_param_config(uart_num, &uart_config);
        printf("param_config returned with code: %d\n", err);

        // Set UART pins(Tx, Rx, RTS, CTS)
        err = uart_set_pin(uart_num, 
                            22,     // TX = IO 22 
                            21,     // RX = IO 21
                            UART_PIN_NO_CHANGE, // RTS not used
                            UART_PIN_NO_CHANGE); // CTS not used
        printf("set_pin returned with code %d\n", err);

        //install new driver
        QueueHandle_t uart_queue;
        uart_driver_install(uart_num, uart_rx_buffer_size, \
                        uart_tx_buffer_size, 10, &uart_queue, 0);   
    }