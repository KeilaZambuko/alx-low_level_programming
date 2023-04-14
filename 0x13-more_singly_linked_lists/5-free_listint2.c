#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - function that frees a listint_t list
 * @head: a double pointer of lists
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *current_node, *temp;

	if (head == NULL)
		return;

	current_node = *head;

	while (current_node != NULL)
	{
		temp = current_node->next;
		free(current_node);
		current_node = temp;
	}

	*head = NULL;
}
