#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: Head
 * @number: New data
 * Return: Index
 */

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new, *tmp;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        return (new);
    }

    if (new->n < (*head)->n)
    {
        new->next = *head;
        *head = new;
    }

    else
    {
        tmp = *head;

        while (tmp != NULL)
        {

            if (tmp->next == NULL || tmp->next->n > new->n)
            {
                new->next = tmp->next;
                tmp->next = new;
                break;
            }

            tmp = tmp->next;
        }
    }
    return (new);
}
