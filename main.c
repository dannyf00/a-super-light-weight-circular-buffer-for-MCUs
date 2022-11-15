#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "cbuffer.h"			//we use circular buffer

//global defines

//global variables
CB_TypeDef buff1, buff2;


//print buff
void cbPrint(CB_TypeDef *buff) {
	int i;
	printf("w: %2d, r: %2d -> cb0..%2d=", buff->writeIndex, buff->readIndex, cBUFF_SIZE);
	for (i=0; i<cBUFF_SIZE; i++) printf("%2d | ", buff->buffer[i]);
	printf("...end\n\r");
}

int main()
{
	int i=-1;
    printf("Hello world!\n");
    cbInit(&buff1); cbInit(&buff2);

	for (i=0; i<20; i++) {
		if (cbEmpty(&buff1)) printf("No read from buff1[%5d] ", i); else printf("Read from buff1[%5d] ", cbRead(&buff1));
		if (cbFull(&buff1))  printf("No write to  buff1[%5d] ", i); else printf("Write to  buff1[%5d] ", cbWrite(&buff1, i));
		cbPrint(&buff1);
    }
    return 0;
}
