#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 *add_nodeint_end - Adds a new node at the end of a listint_t list.
 *@head: Pointer to the pointer to the head node of the list.
 *@n: Integer value to store in the new node.
 *Return: Address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node, *last_node;

/* Create new node */
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
   return (NULL);
new_node->n = n;
new_node->next = NULL;

/* If list is empty, set new node as head */
if (*head == NULL) {
*head = new_node;
   return (new_node);
}

/* Otherwise, find last node and append new node */
last_node = *head;
while (last_node->next != NULL)
last_node = last_node->next;
last_node->next = new_node;
   return (new_node);
}
