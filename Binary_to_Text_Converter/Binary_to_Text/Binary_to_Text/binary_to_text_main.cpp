// Binary_to_Text.cpp : Defines the entry point for the console application.

#include <stdio.h>
#include <string.h>
#include <iostream>

#define SD_READ_BUFFER_SIZE 64      // Read buffer size for reading each line of SD card


/* Struct for holding GPS Tracking Data */
struct GPS_Data {
	float latitude, longitude;
	uint16_t year;
	uint8_t month, day, hour, minute, second;
};

/* Funcion Prototypes */
void write_data_log_header(FILE* f);                    // Writes GPS Data Header to Log File 
void write_data_sample(FILE* f, struct GPS_Data data);  // Write GPS Data Sample to File 


int main()
{
	const char inputFileName[] = "D:/testfile.bin";
	const char outputFileName[] = "GPS_data.txt";
	FILE* outfile = fopen(outputFileName, "w");
	FILE* infile = fopen(inputFileName, "rb");

	if (infile == NULL) {
		printf("Failed to open input file\n");
		return 1;
	}
	else if (outfile == NULL) {
		printf("Failed to open input file\n");
		return 1;
	}

	/* Read from File */
	struct GPS_Data GPS_Data;

	while (fread(&GPS_Data, sizeof(struct GPS_Data), 1, infile) == 1)
		write_data_sample(outfile, GPS_Data);  // Write GPS Data Sample to File 

											   /* Close files */
	fclose(infile);
	fclose(outfile);

	return 0;
}

/* Writes GPS Data Header to Log File */
void write_data_log_header(FILE* f)
{
	fprintf(f, "Latitude \tLongitude \tYYYY:MM:DD  hh:mm:ss \n");
}

/* Write GPS Data Sample to File */
void write_data_sample(FILE* f, struct GPS_Data data)
{
	fprintf(f, "%3.6f \t %3.6f \t%.4u:%.2d:%.2d  %.2d:%.2d:%.2d \n",
		data.latitude, data.longitude,
		data.year, data.month, data.day,
		data.hour, data.minute, data.second
	);
}
