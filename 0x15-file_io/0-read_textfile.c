#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - function that reads a text file and
 * prints it to the POSIX standard output.
 * @filename: pointer to text file to read
 * @letters: numbers of letter to print
 * Return: actual number of bytes printed
 * 0 when fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t nrd, nwr;
char *buff;

if (!filename)
	return (0);

fd = open(filename, O_RDONLY);

if (fd == -1)
	return (0);

buff = malloc(sizeof(char) * letters);

if (buff == NULL)
	return (0);

nrd = read(fd, buff, letters);
nwr = write(STDOUT_FILENO, buff, nrd);

		close(fd);
	free(buff);

if (nrd == -1)
	return (0);

return (nwr);
}
