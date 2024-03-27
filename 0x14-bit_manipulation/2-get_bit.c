#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 *get_bit - Returns the value of a bit at a given index
 *@n: The number containing the bit
 *@index: The index of the bit to get
 *Return: The value of the bit at the specified index
 * or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
if (index >= (sizeof(unsigned long int) * 8))
return (-1);

return ((n >> index) & 1);
}