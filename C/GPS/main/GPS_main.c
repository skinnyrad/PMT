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
#include "string.h"

#include "driver/uart.h"

/* Struct for holding GPS Tracking Data */
struct GPS_Data {
    float latitude, longitude;
    uint8_t year, month, day, hour, minute, second;
};

/* Function Prototypes */
void GPS_init(const int uart_num, int uart_rx_buffer_size, int uart_tx_buffer_size);
void get_GPS_data(uint8_t* data, int* bytesRead, bool* newPacket, const int uart_num, int uart_rx_buffer_size); //reset WDT
bool prepare_GNRMC_data(uint8_t* data, int bytesRead, uint8_t* GNRMC_data, int* GNRMC_data_length);             // Reads data packets until GNRMC data sample fully read
int stringSearch(uint8_t* buffer, int bufferSize, const char* string, int stringSize, int startReadingIndex);   // Searches a buffer for "String"
void print_data_sample(struct GPS_Data data);   // Print GPS Data to terminal 
void parse_UTC_time(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize);  // Parse Universal time from GPS: hh:mm:ss
void parse_latitude(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize);  // Parse Latitude: ddmm.mmmm 
void parse_longitude(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize); // Parse Longitude: dddmm.mmmm
void parse_date(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize);      // Parse Date: ddmmyy

void parse_all_data(struct GPS_Data *GPS_Data, uint8_t* data, int dataLength);                  // Parse All GPS Data 

void app_main()
{
    // Configure UART0
    const int uart_num = UART_NUM_1;
    int uart_rx_buffer_size = 2048;
    int uart_tx_buffer_size = 2048;
    uint8_t data[uart_rx_buffer_size];
    uint8_t GNRMC_data[100];
    int GNRMC_data_length = 0;  
    bool newPacket = false;
    int bytesRead = 0;
    struct GPS_Data GPS_Data;
    
    GPS_init(uart_num, uart_rx_buffer_size, uart_tx_buffer_size);
    
    printf("Begin Listening for packets...\n");
    while (true) 
    {
        get_GPS_data(data, &bytesRead, &newPacket, uart_num, uart_rx_buffer_size); // Read raw data from GPS
        if (newPacket) 
        {    
            newPacket = false; // Packet received, reset flag
            
            /* Reads data packets until GNRMC data sample fully read. The GPS sends incomplete packets. 
               So, the entire line of GNRMC data must be received before processing  */
            bool dataReady = prepare_GNRMC_data(data, bytesRead, GNRMC_data, &GNRMC_data_length);             
           
            if (dataReady)
            {
                parse_all_data(&GPS_Data, GNRMC_data, GNRMC_data_length);     // Parse All GPS Data
                print_data_sample(GPS_Data);                                  // Print GPS Data to terminal    
                GNRMC_data_length = 0;                                        // Reset GNRMC data length                   
            }
        }  
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}

/* Concatenates Multiple GPS data packets to make a complete GNRMC data sample */
bool prepare_GNRMC_data(uint8_t* data, int bytesRead, uint8_t* GNRMC_data, int* GNRMC_data_length)
{
    static bool startFound, stopFound = false;   // Flags for checking if the "GNRMC" line has been found within the GPS data
    static int stringIndexStart, stringIndexStop = 0;
    if (!startFound)
    {
        stringIndexStart = stringSearch(data, bytesRead, "GNRMC", 5, 0);    // Search for GNRMC in buffer
        if (stringIndexStart != -1)     // Found start of GNRMC data
        {   
            startFound = true;          
            stringIndexStop = stringSearch(data, bytesRead, "\n", 1, stringIndexStart); // Search for '\n' in buffer
            if (stringIndexStop != -1)  // Found all GNRMC data in 1 packet
            {
                stopFound  = true;      
                *GNRMC_data_length = 0;
                for (int i = stringIndexStart; i <= stringIndexStop; i++, *GNRMC_data_length = *GNRMC_data_length+1)   
                {
                    GNRMC_data[*GNRMC_data_length] = data[i];
                }
            }
            else   // Found start, but did not find end of GNRMC data
            {
                *GNRMC_data_length = 0;
                for (int i = stringIndexStart; i < bytesRead; i++, *GNRMC_data_length = *GNRMC_data_length+1)  
                {
                    GNRMC_data[*GNRMC_data_length] = data[i];        // Copy start of GNRMC data
                }
            }
        }
    }
    else            // Start of GNRMC data has already been found in a previous data packet
    {       
        stringIndexStop = stringSearch(data, bytesRead, "\n", 1, stringIndexStart); // Search for '\n' in buffer

        if (stringIndexStop != -1)  // Found last piece of data
        {
            stopFound  = true;     
            for (int i = stringIndexStart; i <= stringIndexStop; i++, *GNRMC_data_length = *GNRMC_data_length+1)   
            {
                GNRMC_data[*GNRMC_data_length] = data[i];
            }
        }
        else   // Found start, but did not find end of GNRMC data
        {
            // GNRMC_data_length keeps from previous value and accumulates
            for (int i = stringIndexStart; i < bytesRead; i++, *GNRMC_data_length = *GNRMC_data_length+1)  
            {
                GNRMC_data[*GNRMC_data_length] = data[i];        // Copy start of GNRMC data
            }
        }
    }

    if (startFound && stopFound)
    {                  
        startFound = false;                                           // Reset startFound
        stopFound = false;                                            // Reset stopFound  
        return true;            // Data packet ready for processing
    }
    else
        return false;           // Data packet not yet complete
}

/* Parse All GPS Data */
void parse_all_data(struct GPS_Data *GPS_Data, uint8_t* data, int dataLength)
{         
    // Reset GPS Data struct
    GPS_Data->latitude = 0; GPS_Data->longitude = 0;
    GPS_Data->year = 0; GPS_Data->month = 0; GPS_Data->day = 0;
    GPS_Data->hour = 0; GPS_Data->minute = 0; GPS_Data->second = 0;  

    int nextIndex = 5 + 1; // GNRMC + comma      

    parse_UTC_time(&nextIndex, GPS_Data, data, dataLength);      // Parse UTC Time

    if (data[nextIndex] == 'A')                                  // If GPS Data Valid, keep data. 'V' = Invalid Data
    {
        nextIndex = nextIndex + 2;                               // Skip "Valid Data character" and comma

        parse_latitude(&nextIndex, GPS_Data, data, dataLength);  // Parse Latitude: ddmm.mmmm 
        if (data[nextIndex] == 'S')
            GPS_Data->latitude *= -1;                             // Make latitude negative if on South Pole
                                                                    // skip comma
        nextIndex = nextIndex + 2;                               // Skip N/S and comma    

        parse_longitude(&nextIndex, GPS_Data, data, dataLength); // Parse Longitude: dddmm.mmmm
        if (data[nextIndex] == 'W')
            GPS_Data->longitude *= -1;                            // Make longitude negative if on West of Prime Meridian
                                                                    // skip comma
        nextIndex = nextIndex + 2;                               // Skip E/W and comma   

        while (data[nextIndex] != ',')    nextIndex++;           // Skip unwanted data
        nextIndex++;                                             // skip comma
        while (data[nextIndex] != ',')    nextIndex++;           // Skip unwanted data
        nextIndex++;                                             // skip comma 

        parse_date(&nextIndex, GPS_Data, data, dataLength);      // Parse Date: ddmmyy
    }    
}
/* Parse Longitude: dddmm.mmmm  */
void parse_longitude(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize)
{
    int i = *nextIndex;
    int j = 0;     
    while (data[i] != ',')       
    {
        // Longitude: dddmm.mmmm 
        switch (j) 
        {
            case 0: GPS_Data->longitude += (data[i] - '0') * 10000;  break; 
            case 1: GPS_Data->longitude += (data[i] - '0') * 1000;   break;
            case 2: GPS_Data->longitude += (data[i] - '0') * 100;    break;
            case 3: GPS_Data->longitude += (data[i] - '0') * 10;     break;
            case 4: GPS_Data->longitude += (data[i] - '0');          break;
            case 5: /* Decimal point. Do nothing */                  break;
            case 6: GPS_Data->longitude += (data[i] - '0') * 0.1;    break;
            case 7: GPS_Data->longitude += (data[i] - '0') * 0.01;   break;
            case 8: GPS_Data->longitude += (data[i] - '0') * 0.001;  break;
            case 9: GPS_Data->longitude += (data[i] - '0') * 0.0001; break;
        }
        i++; j++;
    }  
    GPS_Data->longitude *= 0.01; // Shift result 2 decimal places left: ddd.mmmmmm ;
    *nextIndex = i+1;  // return current location of character pointer in buffer
}

/* Parse Latitude: ddmm.mmmm */
void parse_latitude(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize)
{
    int i = *nextIndex;
    int j = 0;     
    while (data[i] != ',')       
    {
        // Latitude: ddmm.mmmm 
        switch (j) 
        {
            case 0: GPS_Data->latitude += (data[i] - '0') * 1000;          break; 
            case 1: GPS_Data->latitude += (data[i] - '0') * 100;           break;
            case 2: GPS_Data->latitude += (data[i] - '0') * 10;            break;
            case 3: GPS_Data->latitude += (data[i] - '0');                 break;
            case 4: /* Decimal point. Do nothing */                        break;
            case 5: GPS_Data->latitude += (data[i] - '0') * 0.1;    break;
            case 6: GPS_Data->latitude += (data[i] - '0') * 0.01;   break;
            case 7: GPS_Data->latitude += (data[i] - '0') * 0.001;  break;
            case 8: GPS_Data->latitude += (data[i] - '0') * 0.0001; break;
        }
        i++; j++;
    }  
    GPS_Data->latitude *= 0.01; // Shift result 2 decimal places left: dd.mmmmmm 
    *nextIndex = i+1;  // return current location of character pointer in buffer
}

/* Parse Date: ddmmyy*/
void parse_date(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize)
{
    int i = *nextIndex;
    int j = 0;     
    while (data[i] != ',')      
    {
        // Date: ddmmyy
        switch (j) 
        {
            case 0: GPS_Data->day += (data[i] - '0')   * 10; break;   
            case 1: GPS_Data->day += data[i] - '0';          break;
            case 2: GPS_Data->month += (data[i] - '0') * 10; break;
            case 3: GPS_Data->month += data[i] - '0';        break;
            case 4: GPS_Data->year += (data[i] - '0')  * 10; break;
            case 5: GPS_Data->year += data[i] - '0';         break;
        }
        i++; j++;
    }  
    *nextIndex = i+1;  // return current location of character pointer in buffer
}

/* Parse Universal time from GPS: hhmmss.sss  */
void parse_UTC_time(int* nextIndex, struct GPS_Data *GPS_Data, uint8_t* data, int bufferSize)
{
    int i = *nextIndex;
    int j = 0;     
    while (data[i] != ',')       
    {
        // UTC Time: hhmmss.sss 
        switch (j) 
        {
            case 0: GPS_Data->hour +=   (data[i] - '0') * 10; break;   
            case 1: GPS_Data->hour +=   data[i] - '0';        break;
            case 2: GPS_Data->minute += (data[i] - '0') * 10; break;
            case 3: GPS_Data->minute += data[i] - '0';        break;
            case 4: GPS_Data->second += (data[i] - '0') * 10; break;
            case 5: GPS_Data->second += data[i] - '0';        break; 
        }
        i++; j++;
    }     

    *nextIndex = i+1;  // return current location of character pointer in buffer
}


/* Searches for starting index of a string within a buffer */
int stringSearch(uint8_t* buffer, int bufferSize, const char* string, int stringSize, int startReadingIndex)

{
    int stringIndex;
    for (int i = startReadingIndex, j = 0; i < bufferSize; i++) 
    {
        if (string[j] == buffer[i]) {
            if (j == 0)				// First character correct
                stringIndex = i;	// Mark starting location of string
            j++;    				// Increment j for every correct character in sequence

            if (j == stringSize)	// If number of correct characters in sequence = length
            {   
                return stringIndex; // String found, return index location
            }
        }
        else
            j = 0;					// If character in sequence is incorrect, reset sequence counter j
    }
    return -1;                      // String not found, return -1
}

/* Print GPS Data to terminal */
void print_data_sample(struct GPS_Data data)
{
	printf("%2.6f \t %3.6f \t%.2d:%.2d:%.2d  %.2d:%.2d:%.2d \n",
		data.latitude, data.longitude,
		data.month, data.day, data.year,
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
        if(*newPacket)
        {
            //get the buffer contents
            *bytesRead = uart_read_bytes(uart_num, data, newLength, 100);
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