#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 *find_listint_loop - Finds the node where the loop in a linked list starts
 *@head: Pointer to the head of the linked list
 *Return: The address of the node where the loop starts
 * NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *slow = head, *fast = head;

while (fast && fast->next)
{
slow = slow->next;

fast = fast->next->next;


if (slow == fast)

{

slow = head;

while (slow != fast)

{

slow = slow->next;


fast = fast->next;



}

return (slow);


}
return (NULL);
}
