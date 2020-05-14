#include "monty.h"

void get_op(stack_t **stack, unsigned int line_number)
{
	int count;
	instruction_t op_codes[] = {
				{"push", push},
				{"pall", pall},
				{"", nop},
				{"nop", nop},
				{NULL, NULL}
	};
	for (count = 0; op_codes[count].opcode != NULL; count++)
	{
		if (strcmp(op_codes[count].opcode, items.op_code) == 0)
		{
			op_codes[count].f(stack, line_number);
			return;
		}
	}
	dprintf(STDOUT_FILENO, "L%u: unknown instruction %s\n", line_number, items.op_code);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	if (*stack)
	{
		while(*stack)
		{
			*stack = (*stack)->next;
			free(tmp);
			tmp = *stack;
		}
	}
	free(items.line);
	fclose(items.monty_file);
}