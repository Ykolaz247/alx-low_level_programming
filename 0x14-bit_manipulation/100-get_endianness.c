#include "main.h"

/**
 * get_endianness - function that checks the endianness
 * Return: if bit - 0, otherwise - 1 if little
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
