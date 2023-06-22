#include "monty.h"

/**
 * add_nodeint_end - adds a node at the end of a list
 * @head: first node
 * @n: data for new node
 * Return: address or NULL
 */

stack_t *add_nodeint_end(stack_t **head, const int n)
{
	stack_t *endnode;
	stack_t *tail;

	endnode = malloc(sizeof(stack_t));
	if (endnode == NULL)
		return (NULL);
	endnode->n = n;
	if (*head == NULL)
		*head = endnode;
	else
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = endnode;
		endnode->prev = tail;
		endnode->next = NULL;
		endnode = tail;
	}
	return (endnode);
}

