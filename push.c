#include "monty.h"
/**
* push - add node to stack
* @stack: double pointer to linked list
* @line_number:line of file
* Return:void
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (items.arguments == NULL)
	{
		dprintf(STDOUT_FILENO, "L%u: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (*items.arguments != '0' && _isdigit(items.arguments) &&
	items.arguments[0] != '-')
	{
		dprintf(STDOUT_FILENO, "L%u: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		free_stack(stack);
		free(new);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(items.arguments);
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
/**
* _isdigit - verificate if a string contains a digit
* @arguments:items.argumnets
* Return:a integer
*/
int _isdigit(char *arguments)
{
	int count;

	for (count = 0; arguments[count]; count++)
	{
		if (isdigit(arguments[count]) == 0)
			return (1);
	}
	return (0);
}
/**
* nop - does nothing
* @stack: double pointer to linked list
* @line_number:line of file
* Return:void
*/

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
