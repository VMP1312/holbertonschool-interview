#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: head
 * Return: Loop start
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *turtle, *hare;

	for (turtle = hare = head; hare && hare->next;)
	{
		turtle = turtle->next;
		hare = hare->next->next;

		if (turtle == hare)
		{
			for (turtle = head; turtle != hare; turtle = turtle->next, hare = hare->next)
				continue;

			return (turtle);
		}
	}
	return (NULL);
}
