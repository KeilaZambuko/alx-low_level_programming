#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* check97 - This function, check97, verifies that the number of arguments passed to it is correct.
*@param argc: The number of arguments passed to the function.
*Return: This function does not return anything (void).
*/
void check97(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}


