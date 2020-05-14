#include "monty.h"

var_global items = {NULL, NULL, NULL, NULL, NULL};

/**
 * main - function main
 * @argc: argument counter
 * @argv: argument vector
 * Return: exit success or exit failed
 */
int main(int argc, char *argv[])
{
	size_t len = 0;
	ssize_t res_get = 0;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	items.name_file = argv[1];
	items.monty_file = fopen(argv[1], "r");

	if (items.monty_file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		res_get = getline(&items.line, &len, items.monty_file);
		if (res_get == -1)
			break;
		if (!items.line || items.line[0] == '\n')
			continue;
		items.op_code = strtok(items.line, " \n\t");
		if (!items.op_code || items.op_code[0] == '#')
			continue;
		items.arguments = strtok(NULL, " \n\t"); /* strtok for argument (number)*/
		get_op(&stack, line_number);
		line_number++;
	}
	free_stack(&stack);
	exit(EXIT_SUCCESS);
}
