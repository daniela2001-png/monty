#include "monty.h"

/**
 * add - this function add two nodes
 * @stack: double list reversed
 * @line_number: line of file
 * Return:
 */
void add(stack_t **stack, unsigned int line_number)
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
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n;
	sum += (*stack)->next->n;
	pop_f(stack, line_number);
	(*stack)->n = sum;
}