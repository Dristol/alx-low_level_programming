#include "lists.h"

/**
 * get_nodeint_at_index -This returns the node at a certain index in a linked list
 * @head: first node in the linked list
 * @index: index of the node to return
 *
 * Return: pointer to the node we're looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temps =  head;

	while (temps && i < index)
	{
		temps = temps->next;
		i++;
	}

	return (temps ? temps : NULL);
}
