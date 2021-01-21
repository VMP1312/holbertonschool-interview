#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: Pointer of head of linked list
 * length of list: Length of the list
 * Return: reveresed link list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *forward;
	listint_t *previous;
	listint_t *cnr;

	cnr = *head;
	previous = NULL;
	while (cnr)
	{
		forward = cnr->next;
		cnr->next = previous;
		previous = cnr;
		if (forward == NULL)
			break;

		cnr = forward;
	}
	return (cnr);
}

/**
 * is_palindrome - checks if linked list is a plaindrome
 * @head: pointer to head of the linked list
 * Return: if the linked list is not a palindrome 0, if it is 1
 */

int is_palindrome(listint_t **head)
{
	int cnt;
	listint_t *forw;
	listint_t *rever;
	listint_t *width;
	listint_t *md;

	if (*head == NULL || head == NULL)
		return (1);

	forw = *head;
	rever = *head;
	cnt = 0;
	while (frw->next)
	{
		cnt++;
		if (forw->next->next)
		{
			forw = forw->next;
			cnt++;
		}
		forw = forw->next;
		rever = rever->next;
	}
	if (forw)
		cnt++;

	md = reverse_listint(&rever);
	width = md;
	rever = *head;
	while (width)
	{
		if (width->n != rever->n)
			return (0);

		width = width->next;
		rever = rever->next;
	}
	return (1);
}
