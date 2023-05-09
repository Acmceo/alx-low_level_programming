#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "main.h"

/**
 *main - copies the content of a file to another file
 *@argc: number of arguments passed to the program
 *@argv: array of arguments passed to the program
 *Return: 0 on success, otherwise exit with a status code
 */
int main(int argc, char **argv)
{
int file_from, file_to, bytes_read, bytes_written;
char buffer[1024];

/*check for correct number of arguments*/
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

/*open file_from for reading*/
file_from = open(argv[1], O_RDONLY);
if (file_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

/*open file_to for writing (truncate it if it already exists)*/
file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (file_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);

exit(99);

}

/* copy contents of file_from to file_to */
while ((bytes_read = read(file_from, buffer, 1024)) > 0)
{
bytes_written = write(file_to, buffer, bytes_read);

if (bytes_written != bytes_read)

{

dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);

exit(99);

}

}

/* check for read error */
if (bytes_read == -1)
{

dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);

exit(98);

}
/* close files */
if (close(file_from) == -1)
{

dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);

exit(100);

}

if (close(file_to) == -1)
{

dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);

exit(100);

}
return (0);
}
