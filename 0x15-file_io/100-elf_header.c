#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "main.h"

/**
 *print_error - prints an error message to standard error
 *@msg: the error message to print
 */
void print_error(char *msg)
{
dprintf(STDERR_FILENO, "%s\n", msg);
exit(98);
}
/**
 *print_elf_header - displays the information contained in the ELF header
 *@header: pointer to the ELF header
 */
void print_elf_header(Elf64_Ehdr *header)
{
int i;

printf("ELF Header:\n");
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
printf("%02x ", header->e_ident[i]);
printf("\n");
printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2MSB ? "big endian" : "little endian");
printf("  Version:                           %d\n", header->e_ident[EI_VERSION]);
printf("  OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
printf("  Type:                              %d\n", header->e_type);
printf("  Entry point address:               %lx\n", header->e_entry);
}
/**
 *main - displays the information contained in the ELF header of a file
 *@argc: number of arguments
 *@argv: array of arguments
 *Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
int fd;
Elf64_Ehdr header;

if (argc != 2)
print_error("Usage: elf_header elf_filename");

fd = open(argv[1], O_RDONLY);
if (fd == -1)
print_error("Error: cannot read file");

if (read(fd, &header, sizeof(header)) != sizeof(header))
print_error("Error: cannot read file");

if (header.e_ident[EI_MAG0] != ELFMAG0 ||
header.e_ident[EI_MAG1] != ELFMAG1 ||

header.e_ident[EI_MAG2] != ELFMAG2 ||

header.e_ident[EI_MAG3] != ELFMAG3)
print_error("Error: not an ELF file");

print_elf_header(&header);

if (close(fd) == -1)
print_error("Error: cannot close file");

return (0);
}
