#include "monty.h"
/**
 * pall - print all
 * @stack:list reversed
 * @line_number: line of file
 * Return:void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = NULL;
	(void) line_number;

	head = *stack;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
