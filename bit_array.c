#include "bit_array.h"


int getNumberInArray(uint32_t index, uint32_t size)
{
	if (index >= size)
	{
		printf("index %d is out of bound: size is %d", index, size);
		exit(-1);
	}
	return index / TO_BITS(index);
}

int getBitInNumber(uint32_t index, uint32_t size)
{
	if (index >= size)
	{
		printf("index %d is out of bound: size is %d", index, size);
		exit(-1);
	}
	return index % TO_BITS(index);
}

bool isBitSet(uint32_t* bit_array, uint32_t index, uint32_t size)
{
	return *(bit_array + getNumberInArray(index, size)) & (0b1 << getBitInNumber(index, size));
}

void bitSet(uint32_t* bit_array, uint32_t index, uint32_t size)
{
	*(bit_array + getNumberInArray(index, size)) |= (0b1 << getBitInNumber(index, size));
}

void clearBit(uint32_t* bit_array, uint32_t index, uint32_t size)
{
	*(bit_array + getNumberInArray(index, size)) &= ~(0b1 << getBitInNumber(index, size));
}

void inverseBit(uint32_t* bit_array, uint32_t index, uint32_t size)
{
	*(bit_array + getNumberInArray(index, size)) ^= (0b1 << getBitInNumber(index, size));
}

void print_bitsf(uint32_t* bit_array, uint32_t size)
{
	printf("bit field\n");
	for (uint32_t i = 0; i < size; ++i)
	{
		printf(i % TO_BITS(i) ? "" : !(i % TO_BITS(i)) && i / TO_BITS(i) ? "\n|" : "|");
		printf(isBitSet(bit_array, i, size) ? ON : OFF);
	}
	putchar('\n');
}