#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 *delete_nodeint_at_index - Deletes the node at index index of a listint_t
 *linked list.
 *@head: Pointer to the first node of the list.
 * @index: Index of the node that should be deleted. Index starts at 0.
 *Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *temp, *prev;
unsigned int i;

if (!head || !*head)
return (-1);

if (index == 0)
{
temp = *head;
*head = temp->next;
free(temp);
return (1);
}

prev = NULL;
temp = *head;

for (i = 0; temp && i < index; i++)
{
prev = temp;
temp = temp->next;
}

if (!temp)
return (-1);

prev->next = temp->next;
free(temp);
return (1);
}

int delete_nodeint_at_index_wrapper(listint_t **head, unsigned int index)
{
if (!head || !*head)
return (-1);

if (index >= listint_len(*head))
return (-1);

return (delete_nodeint_at_index head, index);
}
}
