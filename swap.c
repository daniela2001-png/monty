#include "monty.h"
/**
* swap -  swaps the top two elements of the stack
* @stack: double pointer to linked list
* @line_number:line of file
* Return:void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int count = 0;

	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	if (count > 2)
	{
		(*stack)->prev = (*stack)->next;
		(*stack)->next->next->prev = (*stack);
		(*stack)->next = (*stack)->next->next;
		tmp->next = (*stack);
		tmp->prev = NULL;
		(*stack) = tmp;
	}
	else
	{
		(*stack)->prev = (*stack)->next;
		(*stack)->next->next = (*stack);
		tmp->prev = NULL;
		(*stack)->next = NULL;
		(*stack) = tmp;
	}
}