#include "lists.h"

/**
 * listint_len - returns number of elements in a linked listint_t lists
 * @h: pointer to the head of type listint_t to traverse
 *
 * Return: number of nodes in the listint_t lists
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}

	return (num);
}
