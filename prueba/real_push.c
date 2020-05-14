#include "monty.h"

/**
* add_dnodeint_end - add node in an linked list
* @head: double pointer to linked list
* @n: number
*
* Return: NUll or *head
*/
stack_t *real_push(stack_t **stack, const int n)
{
	stack_t *new, *aux;

	if(stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return (*stack);
	}

	aux = *stack;
	while (aux->next)
	{
		aux = aux->next;
	}
	aux->next = new;
	new->prev = aux;
	return (*stack);
}