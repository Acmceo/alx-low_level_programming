#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 *pop_listint - Deletes the head node of a listint_t linked list
 *and returns its data (n).
 *@head: Pointer to pointer to the first node of the list.
 *Return: The data (n) of the deleted node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
listint_t *temp;
int data;

if (*head == NULL)
return (0);

temp = *head;
data = temp->n;
*head = temp->next;
free(temp);

return (data);
}
