#include "monty.h"

/**
 * shortener - Function of delete space an begenning array.
 * @string: Pointer an string of commands.
 * Return: Duplicate string without space.
 */
char *shortener(char *string)
{
	int count, count_2 = 0, count_aux, size = 0;
	char *dup = NULL;

	for (count = 0; string[count] != '\n' && (string[count] == '\t' ||
						string[count] == ' ');
						count++)
	{
	}
	count_aux = count;
	while (string[count_aux])
	{
		size++;
		count_aux++;
	}
	dup = malloc(sizeof(char) * size + 1);
	if (!dup)
		return (NULL);
	while (string[count])
	{
		dup[count_2] = string[count];
		count_2++;
		count++;
	}
	dup[count_2] = '\0';
	return (dup);
}