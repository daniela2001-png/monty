#include "monty.h"

/**
 * print_dlistint - print elements in an linked lists
 * @h: list
 *
 * Return: numbers of elements
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *head;

	head = *stack;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
			return;
	}
}