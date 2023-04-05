#include "lists.h"
#include <stdlib.h>

/**
  * add_nodeint - add node to  listint_t list.
  * @n: int
  * @head: Double pointer head
  * Return: If it fails return NULL
  */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *ptr;

	if (ptr == NULL)
		return (NULL);

	if (head == NULL)
		return (NULL);
	ptr = malloc(sizeof(listint_t));
	ptr->next = *head;
	ptr->n = n
	*head = ptr;
	return (ptr);
}
