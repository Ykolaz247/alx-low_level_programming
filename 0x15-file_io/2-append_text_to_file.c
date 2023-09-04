#include "main.h"

/**
 * append_text_to_file - function that appends text at end of a file.
 * @filename: pointer to the filename.
 * @text_content: string to the printed file.
 *
 * Return: 1 on success otherwise -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, nwr, nlen = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (nlen = 0; text_content[nlen];)
			nlen++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	nwr = write(fd, text_content, nlen);

	if (fd == -1 || nwr == -1)
		return (-1);

	close(fd);

	return (1);
}
