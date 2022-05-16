#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "bit_array.h"
#include "bit_operations.h"
#include <time.h>


void* xcalloc(size_t count, size_t size);

void testFunc1(void);
void testFunc2(void);
void testFunc3(void);


int main()
{
	//testFunc1();
	//testFunc2();
	testFunc3();
}


void* xcalloc(size_t count, size_t size)
{
	void* var = calloc(count, size);
	if (var == NULL)
	{
		printf("bad alloc in xcalloc");
		exit(-1);
	}
	return var;
}

void testFunc1(void)
{
	uint32_t nbits = 128;
	uint32_t nbytes = TO_BYTES(nbits);
	uint32_t* bit_array = (uint32_t*)xcalloc(nbytes, sizeof(uint32_t));

	printf("\n%d\n", nbytes);

	bitSet(bit_array, 0, nbits);
	bitSet(bit_array, 2, nbits);
	bitSet(bit_array, 6, nbits);
	bitSet(bit_array, 8, nbits);
	bitSet(bit_array, 9, nbits);
	bitSet(bit_array, 34, nbits);
	//bitSet(bit_array, 99);
	//bitSet(bit_array, 100);
	print_bitsf(bit_array, nbits);

	clearBit(bit_array, 0, nbits);
	clearBit(bit_array, 2, nbits);
	print_bitsf(bit_array, nbits);

	inverseBit(bit_array, 7, nbits);
	inverseBit(bit_array, 8, nbits);
	print_bitsf(bit_array, nbits);
}

void testFunc2(void)
{
	srand((unsigned)time(NULL));
	int N = 100;
	int* arr = (int*)xcalloc(N, sizeof(int));

	int field_size = TO_BYTES(N);
	uint32_t* bit_field = (uint32_t*)xcalloc(field_size, sizeof(uint32_t));

	for (int i = 0; i < N; ++i)
	{
		*(arr + i) = rand() % 100;
		if (isBitSet(bit_field, *(arr + i), N))
			printf("%d ", *(arr + i));
		else
			bitSet(bit_field, *(arr + i), N);
	}

	printf("\n\n");
	for (int i = 0; i < N; ++i)
		printf("%d ", *(arr + i));

	printf("\n\n");
	print_bitsf(bit_field, N);
}

void testFunc3(void)
{
	int a = 343, b = -46;

	printf("%d + %d = %d | = %d\n", a, b, sum(a, b), a + b);
	printf("%d - %d = %d | = %d\n", a, b, subs(a, b), a - b);
	printf("%d * %d = %d | = %d\n", a, b, multp(a, b), a * b);
	printf("%d / %d = %d | = %d\n", a, b, divd(a, b), a / b);
	printf("%d %% %d = %d | = %d\n", a, b, mod(a, b), a % b);
}

#endif