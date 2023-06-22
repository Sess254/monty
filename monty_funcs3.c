#include "monty.h"

/**
 * m_mod -modulus
 * @stack: double pointer to a stack
 * @line_number: ln count for errors
 * Return: void
 */

void m_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *itr = *stack, *prev = NULL;
	int value_one = 0, value_two = 0;

	if ((*stack == NULL) || (itr->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		first->error_code = -1;
		return;
	}
	for (; itr->next != NULL; itr = itr->next)
		;
	value_one = itr->n;
	prev = itr->prev;
	value_two = prev->n;
	if (value_one == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		first->error_code = -1;
		return;
	}
	prev->n = value_two % value_one;
	m_pop(stack, line_number);
}

/**
 * m_pchar -prints value at top of stack
 * @stack: double pointer to stack
 * @line_number: ln count for errors
 * Return: void
 */
void m_pchar(stack_t **stack, unsigned int line_number)
{
	int n = 0;
	stack_t *itr;
	(void) line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		first->error_code = -1;
		return;
	}
	for (itr = *stack; itr->next != NULL; itr = itr->next)
	;
	if (itr->n >= 0 && itr->n <= 127)
	{
		n = itr->n;
		putchar(n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		first->error_code = -1;
		return;
	}
}

/**
 * m_pstr - prints the ascii of an int
 * @stack: double pointer to stack
 * @line_number: ln count for errors
 * Return: void
 */
void m_pstr(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *itr;
	(void) line_number;

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	for (itr = *stack; itr->next != NULL; itr = itr->next)
		i++;
	i++;
	for (; i != 0; itr = itr->prev, i--)
	{
		if (itr->n == 0)
			break;
		if (itr->n < 0 || itr->n > 127)
			break;
		putchar(itr->n);
	}
	putchar('\n');
}


/**
 * m_rotl - rotates the stack to the top
 * @stack: double pointer to a stack
 * @line_number: ln count for error
 * Return: void
 */

void m_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *tail, *newtail;

	head = *stack;
	if (*stack == NULL)
		return;
	for (tail = head; tail->next != NULL; tail = tail->next)
		;
	if (tail == head)
		return;
	if (tail->prev == head)
	{
		m_swap(stack, line_number);
		return;
	}
	newtail = tail->prev;
	newtail->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	*stack = tail;
}


/**
 * m_rotr - rotates the stack to the bottom
 * @stack: double pointer to a stack
 * @line_number: ln count for error
 * Return: void
 */

void m_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *tail, *newhead;

	head = *stack;
	if (*stack == NULL)
		return;
	for (tail = head; tail->next != NULL; tail = tail->next)
		;
	if (tail == head)
		return;
	if (tail->prev == head)
	{
		m_swap(stack, line_number);
		return;
	}
	newhead = head->next;
	newhead->prev = NULL;
	head->next = NULL;
	head->prev = tail;
	tail->next = head;
	*stack = newhead;
}
