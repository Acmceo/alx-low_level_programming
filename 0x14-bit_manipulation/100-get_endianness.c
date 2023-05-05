#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 *get_endianness - checks the endianness of the system
 *Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
int num = 1;
char *endian = (char *)&num;

if (*endian == 1)
return (1);
else
return (0);
}
