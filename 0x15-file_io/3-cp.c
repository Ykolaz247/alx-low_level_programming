#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);
/**
 * create_buffer - define 1024 bytes for buffer.
 * @file: pointer to filename of buffer.
 *
 * Return: pointer to the new buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - exit file descriptors.
 * @fd: pointer to file descriptor to close.
 */
void close_file(int fd)
{
	int cl;

	cl = close(fd);

	if (cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of the file to another file.
 * @argc: counts arguments.
 * @argv: pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If count is not correct - exit code 97.
 * If file_from not exist or cannot be read - exit code 98.
 * If file_to cannot be created or cannot write to - exit code 99.
 * If file_to or file_from cannot exit - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, nrd, nwr;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	nrd = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || nrd == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		nwr = write(to, buffer, nrd);
		if (to == -1 || nwr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		nrd = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (nrd > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
