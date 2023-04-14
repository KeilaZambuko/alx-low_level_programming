#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the first node of the list
 * @index: index of the node to be returned
 *
 * Return: pointer to the nth node of the list
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	if (head == NULL)
		return (NULL);

	unsigned int i = 0;

	while (i < index && head != NULL)
	{
		head = head->next;
		i++;
	}

	if (i != index)
		return (NULL);

	return (head);
}
