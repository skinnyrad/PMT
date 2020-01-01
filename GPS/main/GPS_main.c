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

/* Struct for holding GPS Tracking Data */
struct GPS_Data {
    float latitude, longitude;
    uint8_t year, month, day, hour, minute, second;
};

/* Function Prototypes */
void GPS_init(const int uart_num, int uart_rx_buffer_size, int uart_tx_buffer_size);
void get_GPS_data(uint8_t* data, int* bytesRead, bool* newPacket, const int uart_num, int uart_rx_buffer_size); //reset WDT
int stringSearch(uint8_t* buffer, int bufferSize, const char* string, int stringSize); 
void print_data_sample(struct GPS_Data data);   // Print GPS Data to terminal 
void parse_UTC_time(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize);  // Parse Universal time from GPS: hh:mm:ss
void parse_latitude(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize);  // Parse Latitude: ddmm.mmmm 
void parse_longitude(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize); // Parse Longitude: dddmm.mmmm
void parse_date(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize);      // Parse Date: ddmmyy

void app_main()
{
    // Configure UART0
    const int uart_num = UART_NUM_1;
    int uart_rx_buffer_size = 2048;
    int uart_tx_buffer_size = 2048;
    uint8_t data[uart_rx_buffer_size];
    bool newPacket = false;
    int bytesRead = 0;
    struct GPS_Data GPS_Data;
    
    
    GPS_init(uart_num, uart_rx_buffer_size, uart_tx_buffer_size);
    
    printf("Begin Listening for packets...\n");
    while (true) 
    {
        get_GPS_data(data, &bytesRead, &newPacket, uart_num, uart_rx_buffer_size);
        if (newPacket) {        // New Data Packet
            newPacket = false;
        
        /*
            for (int i = 0, j = 0; i < bytesRead; i++) 
            {
                printf("%c", data[i]);
            }
        */
            int stringIndex = stringSearch(data, bytesRead, "GNRMC", 5);    // Search for GNRMC in buffer
            if (stringIndex != -1) 
            {
                /* Parse Data */

                // Reset GPS Data struct
                 GPS_Data.latitude = 0; GPS_Data.longitude = 0;
                 GPS_Data.year = 0; GPS_Data.month = 0; GPS_Data.day = 0;
                 GPS_Data.hour = 0; GPS_Data.minute = 0; GPS_Data.second = 0;  

                int nextIndex = stringIndex + 5 + 1; // stringIndex + length + comma      

                parse_UTC_time(&nextIndex, &GPS_Data, data, bytesRead);  // Parse UTC Time
                nextIndex++;                                             // skip comma
                while (data[nextIndex] != ',')    nextIndex++;           // Skip unwanted data
                nextIndex++;                                             // skip comma

                parse_latitude(&nextIndex, &GPS_Data, data, bytesRead);  // Parse Latitude: ddmm.mmmm 
                nextIndex++;                                             // skip comma         
                while (data[nextIndex] != ',')    nextIndex++;           // Skip unwanted data
                nextIndex++;                                             // skip comma

                parse_longitude(&nextIndex, &GPS_Data, data, bytesRead); // Parse Longitude: dddmm.mmmm
                
                nextIndex++;                                             // skip comma
                while (data[nextIndex] != ',')    nextIndex++;           // Skip unwanted data
                nextIndex++;                                             // skip comma
                while (data[nextIndex] != ',')    nextIndex++;           // Skip unwanted data
                nextIndex++;                                             // skip comma
                while (data[nextIndex] != ',')    nextIndex++;           // Skip unwanted data
                nextIndex++;                                             // skip comma 

                parse_date(&nextIndex, &GPS_Data, data, bytesRead);      // Parse Date: ddmmyy       
                
                print_data_sample(GPS_Data);   // Print GPS Data to terminal            
            }
        }  
    }

    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}

/* Parse Longitude: dddmm.mmmm */
void parse_longitude(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize)
{
    int i = *nextIndex;
    int j = 0;     
    while (data[i] != ',')       // Start at location 5 + 1(comma)
    {
        // Longitude: dddmm.mmmm 
        switch (j) 
        {
            case 0: GPS_Data->longitude += (data[i] - '0') << 4;            break; 
            case 1: GPS_Data->longitude += (data[i] - '0') << 3;            break;
            case 2: GPS_Data->longitude += (data[i] - '0') << 2;            break;
            case 3: GPS_Data->longitude += (data[i] - '0') << 1;            break;
            case 4: GPS_Data->longitude += (data[i] - '0');                 break;
            case 5: /* Decimal point. Do nothing */                         break;
            case 6: GPS_Data->longitude += (float)(data[i] - '0') * 0.1;    break;
            case 7: GPS_Data->longitude += (float)(data[i] - '0') * 0.01;   break;
            case 8: GPS_Data->longitude += (float)(data[i] - '0') * 0.001;  break;
            case 9: GPS_Data->longitude += (float)(data[i] - '0') * 0.0001; break;
        }
        i++; j++;
    }  

    *nextIndex = i;  // return current location of character pointer in buffer
}

/* Parse Latitude: ddmm.mmmm */
void parse_latitude(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize)
{
    int i = *nextIndex;
    int j = 0;     
    while (data[i] != ',')       // Start at location 5 + 1(comma)
    {
        // Latitude: ddmm.mmmm 
        switch (j) 
        {
            case 0: GPS_Data->latitude += (data[i] - '0') << 3;            break; 
            case 1: GPS_Data->latitude += (data[i] - '0') << 2;            break;
            case 2: GPS_Data->latitude += (data[i] - '0') << 1;            break;
            case 3: GPS_Data->latitude += (data[i] - '0');                 break;
            case 4: /* Decimal point. Do nothing */                        break;
            case 5: GPS_Data->latitude += (float)(data[i] - '0') * 0.1;    break;
            case 6: GPS_Data->latitude += (float)(data[i] - '0') * 0.01;   break;
            case 7: GPS_Data->latitude += (float)(data[i] - '0') * 0.001;  break;
            case 8: GPS_Data->latitude += (float)(data[i] - '0') * 0.0001; break;
        }
        i++; j++;
    }  

    *nextIndex = i;  // return current location of character pointer in buffer
}

/* Parse Date: ddmmyy*/
void parse_date(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize)
{
    int i = *nextIndex;
    int j = 0;     
    while (data[i] != ',')       // Start at location 5 + 1(comma)
    {
        // Date: ddmmyy
        switch (j) 
        {
            case 0: GPS_Data->day += (data[i] - '0') << 1;     break;   
            case 1: GPS_Data->day += data[i] - '0';            break;
            case 2: GPS_Data->month += (data[i] - '0') << 1;   break;
            case 3: GPS_Data->month += data[i] - '0';          break;
            case 4: GPS_Data->year += (data[i] - '0') << 1;   break;
            case 5: GPS_Data->year += data[i] - '0';          break;
        }
        i++; j++;
    }  

    *nextIndex = i;  // return current location of character pointer in buffer
}

/* Parse Universal time from GPS: hh:mm:ss */
void parse_UTC_time(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize)
{
    int i = *nextIndex;
    int j = 0;     
    while (data[i] != ',')       // Start at location 5 + 1(comma)
    {
        // UTC Time: hhmmss.sss 
        switch (j) 
        {
            case 0: GPS_Data->hour += (data[i] - '0') << 1;     break;   
            case 1: GPS_Data->hour += data[i] - '0';            break;
            case 2: GPS_Data->minute += (data[i] - '0') << 1;   break;
            case 3: GPS_Data->minute += data[i] - '0';          break;
            case 4: GPS_Data->second += (data[i] - '0') << 1;   break;
            case 5: GPS_Data->second += data[i] - '0';          break;
        }
        i++; j++;
    }  

    *nextIndex = i;  // return current location of character pointer in buffer
}


/* Searches for starting index of a string within a buffer */
int stringSearch(uint8_t* buffer, int bufferSize, const char* string, int stringSize)
{
    int stringIndex;
    for (int i = 0, j = 0; i < bufferSize; i++) 
    {
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

/* Print GPS Data to terminal */
void print_data_sample(struct GPS_Data data)
{
	printf("%3.6f \t %3.6f \t%.2d:%.2d:%.2d  %.2d:%.2d:%.2d \n",
		data.latitude, data.longitude,
		data.day, data.month, data.year,
		data.hour, data.minute, data.second
	);
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
            // printf("\nReceiving... %d", newLength);
            vTaskDelay(200 / portTICK_PERIOD_MS);
            *newPacket = true;
        }

        //otherwise it must have stopped sending
        if(*newPacket){
            //get the buffer contents
            *bytesRead = uart_read_bytes(uart_num, data, newLength, 100);
            // printf("\nUART%d received %d bytes:\n", uart_num, *bytesRead);
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