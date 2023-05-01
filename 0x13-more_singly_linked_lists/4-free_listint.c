#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 *free_listint - frees a listint_t list
 *@head: pointer to the head of the list
 *This function frees the memory allocated for a listint_t list, starting from
 *the head of the list. It iterates through the list, freeing each node until
 *the end of the list is reached.
 */
void free_listint(listint_t *head)
{
listint_t *current;
while (head != NULL)
{
current = head;
head = head->next;
free(current);
}
}
