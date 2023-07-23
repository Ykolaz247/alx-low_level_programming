#include "main.h"

/**
 * _isalpha - function for alphabetic order
 *
 * @c: alpabet to be checked
 *
 * Return: 1 if c is a letter, 0 otherwise
 */

int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));

}
