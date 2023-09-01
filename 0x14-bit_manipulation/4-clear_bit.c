#include "main.h"

/**
 * clear_bit - function that sets value of bit to 0 at a given index
 * @n: pointer to changed number
 * @index: the bit index to set to zero
 *
 * Return: if 1 -  success, otherwise failure, if -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
