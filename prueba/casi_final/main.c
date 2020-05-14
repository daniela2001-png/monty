#include "monty.h"

var_global items = {NULL, NULL, NULL, NULL, NULL};

int main(int argc, char *argv[])
{
	size_t len = 0;
	ssize_t res_get = 0;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		dprintf(STDOUT_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	items.name_file = argv[1];
	items.monty_file = fopen(argv[1], "r");

	if (items.monty_file == NULL)
	{
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		res_get = getline(&items.line, &len, items.monty_file);
		if (res_get == -1)
			break;
		items.op_code = strtok(items.line, " \n\t");
		items.arguments = strtok(NULL, " \n\t"); /* strtok for argument (number)*/
		get_op(&stack, line_number);
		line_number++;
	}
	free_stack(&stack);
	exit(EXIT_SUCCESS);
}