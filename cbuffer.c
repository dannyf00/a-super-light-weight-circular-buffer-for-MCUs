#include "cbuffer.h"			//we use circular buffer

//global defines
#define cBUFF_SIZE_MASK	(cBUFF_SIZE - 1)

//global variables

//initialize circular buffer
void cbInit(CB_TypeDef *buff) {
	buff->writeIndex = buff->readIndex = 0;	//buffer is empty
}

//returns true if buffer is empty
char cbEmpty(CB_TypeDef *buff) {
	return (buff->writeIndex & 0xff) == (buff->readIndex & 0xff);
}

//return true if buffer is full
char cbFull(CB_TypeDef *buff) {
	return ((buff->writeIndex + 1) & cBUFF_SIZE_MASK) == (buff->readIndex & cBUFF_SIZE_MASK);
}

//write data to buffer
cbuff_t cbWrite(CB_TypeDef *buff, cbuff_t dat) {
	return buff->buffer[(++buff->writeIndex) & cBUFF_SIZE_MASK] = dat;
}

//read data from buffer
cbuff_t cbRead(CB_TypeDef *buff) {
	return buff->buffer[(++buff->readIndex) & cBUFF_SIZE_MASK];
}
