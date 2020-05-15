#include "monty.h"

/**
 * pstr_f - function that print the top in the satck
 * @stack: is a double list reversed
 * @line_number: line of file
 * Return: top of stack
 */

void pstr_f(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int count = 0, count_2;

	while (temp)
	{
		temp = temp->next;
		count++;
	}

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	(void)line_number;

	temp = *stack;
	for (count_2 = 0; count_2 < count; count_2++)
	{
		printf("%c", temp->n);
		if (temp->n < 0 || temp->n > 255 || temp->n == 0)
		{
			break;
		}
		temp = temp->next;
	}
	putchar('\n');
}