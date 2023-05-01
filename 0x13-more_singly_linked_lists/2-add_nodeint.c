#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 *add_nodeint - adds a new node at the beginning of a listint_t list
 *@head: pointer to a pointer to the head of the list
 *@n: integer value to store in the new node
 *Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node;

/* Allocate memory for new node */
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

/* Initialize new node */
new_node->n = n;
new_node->next = *head;

/* Update head to point to new node */
*head = new_node;
return (new_node);
}
