#include "lists.h"

/**
 * add_nodeint_end - function that adds new node at end of a listint_t list
 * @head: pointer to the first element in the listint_t list
 * @n: integer to insert in the new node
 *
 * Return: pointer to the new node, or  if it fails - NULL
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;

	return (new);
}
