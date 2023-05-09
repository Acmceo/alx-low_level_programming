#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 *create_file - creates a file with the given filename and writes the given
 *text content to it
 *@filename: the name of the file to create
 *@text_content: the text content to write to the file
 *Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
int fd, ret = 1;
ssize_t bytes_written;

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
if (fd == -1)
return (-1);

if (text_content != NULL)
{
bytes_written = write(fd, text_content, strlen(text_content));
if (bytes_written == -1)

ret = -1;
}

if (close(fd) == -1)
ret = -1;

return (ret);
}
