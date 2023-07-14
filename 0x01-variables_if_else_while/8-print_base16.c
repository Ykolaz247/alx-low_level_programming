#include <stdio.h>

/**
 * main - The Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	int g;
	char c;

	for (g = 0; g < 10; g++)
	{
		putchar(g + '0');
	}
	for (c = 'a'; c <= 'f'; c++)
	{
		putchar(c);
	}
	putchar('\n');
	return (0);
}
