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