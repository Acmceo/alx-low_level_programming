#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 *sum_listint - Returns the sum of all the data (n) of a listint_t linked list.
 *@head: Pointer to the head of the linked list.
 *Return: The sum of all the data (n) of the listint_t linked list.
 *If the list is empty, return 0.
 */
int sum_listint(listint_t *head)
{
int sum = 0;

while (head)
{
sum += head->n;
head = head->next;
}

return (sum);
}
