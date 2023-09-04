#include "main.h"
#include <stdlib.h>

/**
 * create_file - function that creates a file
 * @filename: A pointer to filename to create.
 * @text_content: A pointer to file string printed.
 *
 * Return: If function fails -1 Otherwise 1 for success.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, nwr, nle = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (nle = 0; text_content[nle];)
			nle++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	nwr = write(fd, text_content, nle);

	if (fd == -1 || nwr == -1)
		return (-1);

	close(fd);

	return (1);
}
