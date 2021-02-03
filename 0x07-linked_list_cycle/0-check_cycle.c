#include "lists.h"
/**
 * check_cycle - Checks if a single link list has a cycle in it.
 * @list: List.
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 *
 */

int check_cycle(listint_t *list)
{
	listint_t *slow;
	listint_t *fast;

	if (list == NULL)
		return (0);
	slow = list;
	fast = list;
	while (slow->next != NULL && fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
