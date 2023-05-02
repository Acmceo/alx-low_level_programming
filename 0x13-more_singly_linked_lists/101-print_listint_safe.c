#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 *print_listint_safe - Prints a listint_t linked list safely.
 *@head: A pointer to the head of the list.
 *Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
size_t count = 0;
const listint_t *tmp = head, *loop_node = NULL;

while (tmp != NULL)
{

count++;

printf("[%p] %d\n", (void *) tmp, tmp->n);


if (tmp > tmp->next)

loop_node = tmp->next;


tmp = tmp->next;


if (loop_node != NULL && (tmp == loop_node || tmp == head))

{

printf("-> [%p] %d\n", (void *) loop_node, loop_node->n);


break;
																										}
								}

if (loop_node == head)
count++;
else if (loop_node != NULL)

count--;

return (0);
}
