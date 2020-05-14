#include "monty.h"

void func_token(char *args, char *line)
{
	char *op_dup = strdup(args);
	char *op;

	if(tokens)
	{
		free(tokens[0]);
		free(tokens);
	}
	tokens = malloc(sizeof(char *) * 5);
	if(!tokens)
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	op = strtok(op_dup, " \n\t\r");
	tokens[0] = op;
	op = strtok(NULL, " \n\t\r");
	tokens[1] = op;
	tokens[2] = NULL;
	tokens[3] = args;
	tokens[4] = line;
}