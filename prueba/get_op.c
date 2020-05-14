#include "monty.h"

void get_op(stack_t **stack, unsigned int line_number)
{
	size_t count;
	instruction_t op_codes[] = {
				{"push", push_file},
				{"pall", pall},
				{NULL, NULL}
	};

	for (count = 0; op_codes[count].opcode != NULL; count++)
	{
		if (strcmp(op_codes[count].opcode, tokens[0]) == 0)
		{
			op_codes[count].f(stack, line_number);
			return;
		}
	}
	
	dprintf(STDOUT_FILENO, "L%u: unknown instruction %s\n", line_number, tokens[0]);
	free_tokens();
	free_struct(*stack);
	exit(EXIT_FAILURE);
}