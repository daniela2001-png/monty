#include "monty.h"

/**
 * sub - this function sub two nodes
 * @stack: double list reversed
 * @line_number: line of file
 * Return:
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum, count = 0;

	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n;
	sum -= (*stack)->n;
	pop_f(stack, line_number);
	(*stack)->n = sum;
}

/**
 * div_f - this function div two nodes
 * @stack: double list reversed
 * @line_number: line of file
 * Return:
 */
void div_f(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum, count = 0, n;

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n;
	n = (*stack)->n;
	sum = sum / n;
	pop_f(stack, line_number);
	(*stack)->n = sum;
}

/**
 * mul_f - this function mulplicated two nodes
 * @stack: double list reversed
 * @line_number: line of file
 * Return:
 */
void mul_f(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum, count = 0;

	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n;
	sum *= (*stack)->n;
	pop_f(stack, line_number);
	(*stack)->n = sum;
}

/**
* module - function that put the module
* @head: double list reversed
* @line_number: line of file
* Return:
*/
void module(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum, count = 0, n;

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n;
	n = (*stack)->n;
	sum = sum % n;
	pop_f(stack, line_number);
	(*stack)->n = sum;
}