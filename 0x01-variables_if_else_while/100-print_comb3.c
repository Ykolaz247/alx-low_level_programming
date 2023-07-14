#include <stdio.h>

/**
 * main - The Entry point
 * Return: Always 0 (Success)
 */

int main(void)
{
	int n = '0';
	int m = '0';

	for (m = '0'; m <= '9'; m++)
	{
		for (n = '0'; n <= '9'; n++)
		{
			if (!((n == m) || (m > n)))
			{
				putchar(m);
				putchar(n);
				if (!(n == '9' && m == '8'))
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}

	putchar('\n');
	return (0);
}
