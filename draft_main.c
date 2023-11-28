#include "main.h"

/**
        * flip_bits - unsigned int func
        * Description: returns the number of bits to get from n to m
        * @n: number 1 (donor)
        * @m: number 2 (destination)
        * Return: number of bits flipped
    	*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int bit1 = 0;
	unsigned int bit2 = 0;
	unsigned long int flips = 0;
	int i;

	for (i = 0; i <= 31; i++)
	{
		bit1 = n & (1 << i);
		bit2 = n & (1 << i);
		if (bit1 != bit2)
			flips++;
	}
	return flips;
}