#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "lists.h"
#include <string.h>

/**
 *add_node - Adds a new node at the beginning of a list_t list.
 *@head: A pointer to a pointer to the first node of the list.
 *@str: The string to be stored in the new node.
 *Return: If memory allocation fails or head is NULL, NULL.
 *Otherwise, the address of the new node.
 */
list_t *add_node(list_t **head, const char *str)
{
list_t *new_node;

if (head == NULL)
return (NULL);

new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

new_node->str = strdup(str);
if (new_node->str == NULL)
{
free(new_node);
return (NULL);

}
new_node->len = strlen(str);
new_node->next = *head;
*head = new_node;

return (new_node);
}
