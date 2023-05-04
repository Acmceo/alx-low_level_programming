#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 *print_binary - Prints the binary representation of a number
 * @n: The number to print in binary
 */
void print_binary(unsigned long int n)
{
unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
int flag = 0;

while (mask != 0) {
if ((n & mask) != 0)
putchar('1');
else if (flag == 1 || mask == 1)
putchar('0');
mask >>= 1;
flag = 1;
}
}
