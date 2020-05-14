
#include "monty.h"

/**
* free_dlistint - free an linked list
* @head: the linked list
*/
void free_struct(stack_t *head)
{
	stack_t *aux_1, *aux_2;

	if (!head)
		return;
	aux_1 = head;
	aux_2 = aux_1->next;

	while (aux_2)
	{
		free(aux_1);
		aux_1 = aux_2;
		aux_2 = aux_1->next;
	}
	free(aux_1);
}

void free_tokens(void)
{
	if (tokens[0])
		free(tokens[0]); /*op*/
	if (tokens[3])
		free(tokens[3]); /*dup_line*/
	if (tokens[4])
		free(tokens[4]); /*line*/
	if (tokens)
		free(tokens);
}