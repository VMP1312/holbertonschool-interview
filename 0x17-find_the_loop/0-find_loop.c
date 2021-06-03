#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: head
 * Return: Loop start
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *trtl, *hare;

	for (trtl = hare = head; hare && hare->next;)
	{
		trtl = trtl->next;
		hare = hare->next->next;

		if (trtl == hare)
		{
			for (trtl = head; trtl != hare; trtl = trtl->next, hare = hare->next)
				continue;

			return (trtl);
		}
	}
	return (NULL);
}
