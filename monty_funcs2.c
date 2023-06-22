#include "monty.h"

/**
 * m_add - adds  the value from top two elements
 * @stack: double pointer to a stack
 * @line_number: ln count for errors
 * Return: void
 */

void m_add(stack_t **stack, unsigned int line_number)
{
	stack_t *itr = *stack, *prev = NULL;
	int value_a = 0, value_b = 0;

	if ((*stack == NULL) || (itr->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		first->error_code = -1;
		return;
	}
	for (; itr->next != NULL; itr = itr->next)
		;
	value_a = itr->n;
	prev = itr->prev;
	value_b = prev->n;
	prev->n = value_a + value_b;
	m_pop(stack, line_number);
}

/**
 * m_nope - doesn't do a thing
 * @stack: double pointer to stack
 * @line_number: ln count for errors
 * Return: void
 */
void m_nope(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void)line_number;

}

/**
* m_sub - substracts the value from top two elements
* @stack: double pointer to a stack
* @line_number: ln count for errors
* Return: void
*/

void m_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *itr = *stack, *prev = NULL;
	int value_one = 0, value_two = 0;

	if ((*stack == NULL) || (itr->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		first->error_code = -1;
		return;
	}
	for (; itr->next != NULL; itr = itr->next)
		;
	value_one = itr->n;
	prev = itr->prev;
	value_two = prev->n;
	prev->n = value_two - value_one;
	m_pop(stack, line_number);
}

/**
 * m_mull - multiplies top two numbers and pop top of stack
 * @stack: head of stack
 * @line_number: line number in file
 * Return: void
 */

void m_mull(stack_t **stack, unsigned int line_number)
{
	stack_t *itr = *stack, *prev = NULL;
	int value_one = 0, value_two = 0;

	if ((*stack == NULL) || (itr->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		first->error_code = -1;
		return;
	}
	for (; itr->next != NULL; itr = itr->next)
		;
	value_one = itr->n;
	prev = itr->prev;
	value_two = prev->n;
	prev->n = value_one * value_two;
	m_pop(stack, line_number);
}

/**
 * m_div - divides the value from top two elements
 * @stack: dbl ptr to a stack
 * @line_number: ln count for errors
 * Return: void
 */

void m_div(stack_t **stack, unsigned int line_number)
{
	stack_t *itr = *stack, *prev = NULL;
	int value_one = 0, value_two = 0;

	if ((*stack == NULL) || (itr->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	prev->n = value_two / value_one;
	m_pop(stack, line_number);
}
