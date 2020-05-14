#include "monty.h"

/**
 * validator - valide argument.
 * @args: argument.
 * 
 * Return: Always 0 or 1.
 */
int validator(char *args)
{
	int count;

	for (count = 0; args[count]; count++)
	{
		if (args[count] == '-' && count == 0)
			continue;
		if (isdigit(args[count]) == 0)
			return (1):
	}
	return (0);
}

void push_file(stack_t **stack, unsigned int line_number)
{
	char *args;

	args = strtok(NULL , " \n\t\r");
}

