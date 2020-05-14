#include "monty.h"
/**
 * pop_f - function that deletes a node
 * @stack: double list reversed
 * @line_number: line of file
 * Return:
 */
void pop_f(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *aux, *node_delete;
	(void) line_number;
	temp = *head;

	if (temp != NULL)
	{
		aux = temp->next;
		node_delete = temp;
	if (aux != NULL)
		aux->prev = NULL;
	free(node_delete);
	*head = aux;
	}
}
