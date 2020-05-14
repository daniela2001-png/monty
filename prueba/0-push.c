#include "monty.h"

/**
 * validator - valide argument.
 * @args: argument.
 * 
 * Return: Always 0 or 1.
 */
int validator(void)
{
	int count, count_2;

	if (!tokens[1])
		return (1);
	for (count = 0; tokens[count]; count++)
	{
		if (tokens[1][0] == '-' && count == 0)
			continue;
		for (count_2 = 0; tokens[1][count_2]; count_2++)
		{
			if (isdigit(tokens[1][count_2]) == 0 && tokens[1][0] != '-')
			return (1);
		}
	}
	return (0);
}

void push_file(stack_t **stack, unsigned int line_number)
{
	int integer_a;

	if (tokens == NULL || (validator() == 1) || !tokens[1])
	{
		dprintf(STDOUT_FILENO, "L%u: usage: push integer\n", line_number);
		free_tokens();
		free_struct(*stack);
		exit(EXIT_FAILURE);
	}
	integer_a = atoi(tokens[1]);
	*stack = real_push(stack, integer_a);
	if (tokens[3])
		free(tokens[3]);
} 