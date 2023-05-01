#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 *free_listint2 - Frees a listint_t list and sets the head to NULL
 *@head: Pointer to the head of the list
 */
void free_listint2(listint_t **head)
{
listint_t *current, *next;
if (head == NULL || *head == NULL)
return;

current = *head;
while (current != NULL)
{
next = current->next;
free(current);
current = next;
}
*head = NULL;
}
