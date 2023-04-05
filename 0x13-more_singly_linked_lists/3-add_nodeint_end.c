#include "lists.h"
#include <stdlib.h>

/**
  * add_nodeint - adds a node at the beginning of the list
  * @head: double pointer head
  * @n: int add 
  * Return: If it fails return NULL
  */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *ptr;

	if (head == NULL)
		return (NULL);
	ptr = malloc(sizeof(listint_t));
	if (ptr == NULL)
		return (NULL);
	ptr->n = n;
	ptr->next = *head;
	*head = ptr;
	return (ptr);
