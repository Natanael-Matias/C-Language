/*
*
*
*
*
*
*/

#ifndef INC_UTILS_H_
#define INC_UTILS_H_

#include <stdio.h>
#include <string.h>

#define SetBit(PORT, bit)			((PORT) |= (1 << bit))
#define ClrBit(PORT, bit)			((PORT) &= !(1 << bit))
#define ToggleBit(PORT, bit)		((PORT) ^= (1 << bit))
#define TstBit(PORT, bit)			((PORT) & (1 << bit))

typedef enum{
	FALSE = 0,
	TRUE,
} Bool;

typedef struct{
	unsigned bit : 1;
	unsigned reserved : 31;
} Bit;

void dec2bin(int dec, Bit *bin);

#endif