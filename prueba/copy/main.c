#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *fp = fopen(argv[1], "r");
	char *line = NULL, *dup_line = NULL;
	size_t len = 0;
	unsigned int l_nbr = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		dprintf(STDOUT_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (fp == NULL)
	{
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	while (getline(&line, &len, fp) != -1)
	{
		dup_line = shortener(line);
		func_token(dup_line, line);
		if (tokens != NULL && tokens[0][0] != '#')
		{
			get_op(&stack, l_nbr);
		}
		l_nbr++;
		
	}
	fclose(fp);
	if (tokens != NULL)
		free_tokens();
	else
	{
		free(line);
	}
	free_struct(stack);
	exit (EXIT_SUCCESS);
}