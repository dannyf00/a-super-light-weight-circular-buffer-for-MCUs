#ifndef CBUFFER_H_INCLUDED
#define CBUFFER_H_INCLUDED

#include <stdint.h>

//circular buffer configuration
#define cBUFF_SIZE		4		//must be power of 2
//end circular buffer configuration

//global defines
typedef char cbuff_t;			//data type to be held by buffer[]

typedef struct {
	cbuff_t buffer[cBUFF_SIZE];	//the actual buffer
	uint8_t writeIndex;			//current position -> increment before write
	uint8_t readIndex;			//current position -> increment before read
} CB_TypeDef;


//global variables


void cbInit(CB_TypeDef *buff);	//initialize circular buffer
char cbEmpty(CB_TypeDef *buff);	//returns true if buffer is empty
char cbFull(CB_TypeDef *buff);	//return true if buffer is full
cbuff_t cbWrite(CB_TypeDef *buff, cbuff_t dat);	//write data to buffer
cbuff_t cbRead(CB_TypeDef *buff);	//read data from buffer

#endif // CBUFFER_H_INCLUDED
