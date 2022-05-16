#include "bit_operations.h"


int sum(int num1, int num2)
{
	int res = 0b0, tr = 0b0;

	res = num1 ^ num2;
	tr = (num1 & num2) << 0b1;
	while (tr)
	{
		int tmp = res;
		res ^= tr;
		tr = (tmp & tr) << 0b1;
	}

	return res;
}

static int neg(int num)
{
	return sum(~num, 0b1);
}

int subs(int num1, int num2)
{
	return sum(num1, neg(num2));
}

static int getSign(int num)
{
	return num >> 31;
}

static int abslt(int num)
{
	return (getSign(num) & 0b1) ? neg(num) : num;
}

int multp(int num1, int num2) 
{
	int res = 0;

	bool is_negative = (getSign(num1) ^ getSign(num2)) ? true : false;
	num1 = abslt(num1), num2 = abslt(num2);

	//while (num2) //works faster
	//{
	//	if (num2 & 0b1)
	//		res = sum(res, num1);
	//	num1 <<= 0b1, num2 >>= 0b1;
	//}

	int counter = 0b0;
	while (counter ^ num2)
	{
		res = sum(res, num1);
		counter = sum(counter, 0b1);
	}

	return (is_negative) ? neg(res) : res;
}

int divd(int num1, int num2)
{
	if (!num2)
	{
		printf("devision by zero\n");
		exit(-1);
	}
	int res = 0;

	bool is_negative = (getSign(num1) ^ getSign(num2)) ? true : false;
	num1 = abslt(num1), num2 = abslt(num2);
	
	while ((getSign(subs(num1, num2)) ^ 0b1) & 0b1 || !subs(num1, num2)) 
	{
		res = sum(res, 0b1);
		num1 = subs(num1, num2);
	}

	return (is_negative) ? neg(res) : res;
}

int mod(int num1, int num2)
{
	return subs(num1, multp(divd(num1, num2), num2));
}