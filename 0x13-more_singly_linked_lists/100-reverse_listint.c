#include "lists.h"

/**
 * reverse_listint - Reverses a singly linked list.
 * @head: Double pointer to the head node of the list.
 *
 * Return: Pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev_node, *next_node;

	if (head == NULL || *head == NULL)
		return (NULL);

	if ((*head)->next == NULL)
		return (*head);

	prev_node = NULL;

	while (*head != NULL)
	{
		next_node = (*head)->next;
		(*head)->next = prev_node;
		prev_node = *head;
		*head = next_node;
	}

	*head = prev_node;

	return (*head);
}
