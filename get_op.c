#include "monty.h"
/**
 * get_op - function that get from keyword
 * @stack:double list reversed
 * @line_number:line of file
 * Return:void
 */

void get_op(stack_t **stack, unsigned int line_number)
{
	int count = 0;
	instruction_t op_codes[] = {
				{"push", push},
				{"pall", pall},
				{"pint", pint_f},
				{"pop", pop_f},
				{"", nop},
				{"nop", nop},
				{"swap", swap},
				{"add", add},
				{"sub", sub},
				{"div", div_f},
				{"mul", mul_f},
				{"mod", module},
				{"pchar", pchar_f},
				{"pstr", pstr_f},
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
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
	line_number, items.op_code);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
/**
 * free_stack - function that free a stack
 * @stack: double list reversed
 * Return:void
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	if (*stack)
	{
		while (*stack)
		{
			*stack = (*stack)->next;
			free(tmp);
			tmp = *stack;
		}
	}
	free(items.line);
	fclose(items.monty_file);
}
/**
 * pstr_f - function that free a stack
 * @stack: double list reversed
 * @line_number:lineaaa
 * Return:void
 */

void pstr_f(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = *stack;
	int c;
	(void) line_number;

	while (temp)
	{
		c = temp->n;
		if (!isascii(c) || c == 0)
			break;
		putchar(c);
		temp = temp->next;

		if (*stack == temp)
			break;
	}
	putchar('\n');
}
