#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 for a given index.
 * @n: number  of i
 * @index: starts from 0 of the bit you want to set
 * Return: 1 on sucess, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	i = ~(1 << index);
	*n = *n & i;

	return (1);
}
