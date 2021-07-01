#include <stdio.h>
#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list: list
 * @value: value
 * Return: Node of value or Null
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *jump, *save = NULL;

	if (!list)
		return (NULL);
	jump = list;
	while (jump->express)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       (jump->express)->index, (jump->express)->n);
		if ((jump->express)->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
			       jump->index, (jump->express)->index);
			break;
		}
		if ((jump->express)->express == NULL)
		{
			jump = jump->express;
			save = jump;
			while (save->next)
				save = save->next;
			printf("Value found between indexes [%lu] and [%lu]\n",
			       jump->index, save->index);
			break;
		}
		jump = jump->express;
	}
	while (jump->next)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       jump->index, jump->n);
		if (jump->n == value)
			return (jump);
		if (jump->n > value)
			return (NULL);
		jump = jump->next;
	}
	printf("Value checked at index [%lu] = [%i]\n", jump->index, jump->n);
	return (NULL);
}
