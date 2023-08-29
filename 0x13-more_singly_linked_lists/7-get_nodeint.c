#include "lists.h"

/**
 * get_nodeint_at_index - returns nth node of a listint_t linked list
 * @head: pointer to the head of node in linked list
 * @index: the index to return
 *
 * Return: pointer to locate, if not exist - NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp ? temp : NULL);
}
