#include<string.h>
#include<stdlib.h>
#include<stdio.h>

// A function to display an error message and then exit
void fatal(char *message) {
	char error_message[100];
	strcpy(error_message, "[!!] Fatal Error ");
	strncat(error_message, message, 83);
	perror(error_message);
	exit(-1);
}



void dump(const unsigned char *data_buffer, const unsigned int length) {
	unsigned char byte;
	unsigned int i, j;
	for(i=0; i < length; i++) {
		byte = data_buffer[i];
		printf("%02x ", data_buffer[i]); // Display byte in hex.
		if(((i%16)==15) || (i==length-1)) {
			for(j=0; j < 15-(i%16); j++)
				printf(" ");
			printf("| ");
			for(j=(i-(i%16)); j <= i; j++) { // Display printable bytes from line.
				byte = data_buffer[j];
				if((byte > 31) && (byte < 127)) // Outside printable char range
					printf("%c", byte);
				else
					printf(".");
			}
			printf("\n"); // End of the dump line (each line is 16 bytes)
		} // End if
	} // End for
}
