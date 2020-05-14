#include "monty.h"

/**
 * pint_f - function that print the top in the satck
 * @stack: is a double list reversed
 * @line_number: line of file
 * Return: top of stack
 */

void pint_f(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		dprintf(STDOUT_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	(void)line_number;
	printf("%d\n", temp->n);
}
