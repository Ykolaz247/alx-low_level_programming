#include "lists.h"

/**
 * sum_listint - returns sum of all data(n) of a listint_t linked list
 * @head: pointer to the head of node in the linked list
 *
 * Return: returns the  sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}

	return (sum);
}
