#include "main.h"

/**
 * binary_to_uint - converts a binary number
 * @b: is pointing to a string of 0 and 1 chars
 * Return: the converted number, or 0
 */

unsigned int binary_to_uint(const char *b)
{
	if (b == NULL)
	{
		return (0);
	}
	unsigned int j = 0;

	for (int i = 0; b[i] != '\0'; i++)
	{
		if
			(b[i] != '0' && b[i] != '1');
		return (0);
	}

	j <<= 1;
	if
		(b[i] == '1');
	{
		j += 1;
	}

	return (j);
}
