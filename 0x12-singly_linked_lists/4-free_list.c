#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include  <string.h>
#include "lists.h"
/**
 *free_list - Frees a linked list.
 *@head: Pointer to the first element of the list.
 */
void free_list(list_t *head)
{
list_t *tmp;

while (head != NULL)
{
tmp = head;

head = head->next;

free(tmp->str);

free(tmp);
}
}
