#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_ident(unsigned char *e_ident);
void print_header(Elf64_Ehdr *header);
void check_elf(unsigned char *e_ident);

/**
 * check_elf - to know if file is an ELF file.
 * @e_ident: pointer to file containing ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
		e_ident[index] != 'E' &&
		e_ident[index] != 'L' &&
		e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_ident - function that prints identification information of an ELF.
 * @e_ident: A pointer to file ELF identification information.
 *
 * Description: Prints magic numbers, class, data,
 * version, OS/ABI, and ABI version.
 */
void print_ident(unsigned char *e_ident)
{
	printf(" Magic: ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
	printf("%02x ", e_ident[i]);
	}
	printf("\n");
	printf(" Class: %s\n", e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf(" Data: %s\n", e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" : "2's complement, big endian");
	printf(" Version: %d (current)\n", e_ident[EI_VERSION]);
	printf(" OS/ABI: %s\n", e_ident[EI_OSABI] == ELFOSABI_SYSV ?
			"UNIX - System V" : "Other");
	printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_header - function that prints header information of an ELF.
 * @header: pointer to the file ELF header.
 *
 * Description: Prints the type and entry point address.
 */
void print_header(Elf64_Ehdr *header)
{
	printf(" Type: %s\n", header->e_type == ET_NONE ? "NONE (None)" :
			header->e_type == ET_REL ? "REL (Relocatable file)" :
			header->e_type == ET_EXEC ? "EXEC (Executable file)" :
			header->e_type == ET_DYN ? "DYN (Shared object file)" :
			header->e_type == ET_CORE ? "CORE (Core file)" : "Unknown");
	printf(" Entry point address: 0x%lx\n", header->e_entry);
}

/**
 * main - function that displays information of ELF.
 * @argc: The number of arguments printed.
 * @argv: pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the function fails - exit code 98.
 *
 */
int main(int__attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int op, nrd;

	op = open(argv[1], O_RDONLY);
	if (op == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
		if (header == NULL)
	{
		close(op);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	nrd = read(op, header, sizeof(Elf64_Ehdr));
	if (nrd == -1)
	{
		free(header);
		close(op);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_ident(header->e_ident);
	print_header(header);

	free(header);
	close(op);
	return (0);
}
