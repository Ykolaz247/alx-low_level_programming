#include "main.h"

/**
 * set_bit - function that sets value of a bit to 1 at given index
 * @n: pointer to the changed number
 * @index: the bit index
 *
 * Return: if 1 -  success, otherwise failure, if -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
