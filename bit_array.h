#ifndef bit_array_h
#define bit_array_h


#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>


#define BYTE 8
#define TO_BITS(x) (sizeof(x) * BYTE)
#define TO_BYTES(x) (x / TO_BITS(x) + (x % TO_BITS(x) ? 1 : 0))
#define ON  "1|"
#define OFF "_|"


int getNumberInArray(uint32_t index, uint32_t size);
int getBitInNumber(uint32_t index, uint32_t size);
bool isBitSet(uint32_t* bit_array, uint32_t index, uint32_t size);
void bitSet(uint32_t* bit_array, uint32_t index, uint32_t size);
void clearBit(uint32_t* bit_array, uint32_t index, uint32_t size);
void inverseBit(uint32_t* bit_array, uint32_t index, uint32_t size);
void print_bitsf(uint32_t* bit_array, uint32_t size);


#endif
