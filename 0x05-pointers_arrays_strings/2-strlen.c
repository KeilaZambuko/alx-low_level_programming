#include "main.h"

/**
 * _strlen - returns the lenghth of a string
 * @s: character being checked
 * Description: this will return the length of a string
 * Return: 0
 */


int _strlen(char *s)
{
	int a = 0;

	for (; *s++;)
		a++;
	return (a);
}
