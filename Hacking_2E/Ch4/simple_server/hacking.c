#include "hacking.h"
#include <stdio.h>

/* Function dumps raw memory in hex byte & printable split format */
void dump(const unsigned char *data_buffer, const unsigned int len)
{
    unsigned char byte;
    int i,j;

    for(i=0; i < len; i++) {
        byte = data_buffer[i];
        printf("%02x ", data_buffer[i]); // Display byte in hex.
        if(((i%16) == 15) || (i==len-1)) {
            for(j=0; j < 15 - (i%16); j++)
                printf("   ");
            printf("| ");
            for(j=(i-(i%16)); j <= i; j++) {
                byte = data_buffer[j];
                if((byte > 31) && (byte < 127)) // Outside printable char range.
                    printf("%c", byte);
                else
                    printf(".");
            }
            printf("\n"); // End of the dump line (each line is 16 bytes).
        } // End if
    } // End for
}
