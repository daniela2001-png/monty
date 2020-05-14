#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

/**
 * struct var_global - variable global (struct)
 * @op_code: keyword
 * @arguments:counter[1] arguments of op_code
 * @name_file:name of file to open
 * @line:var equal to getline
 * @monty_file:FILE pointer
 * Description:This struct contains main items of the function
 * from a variable global
 */
typedef struct var_global
{
	char *op_code;
	char *arguments;
	char *name_file;
	char *line;
	FILE *monty_file;
} var_global;
extern var_global items;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void get_op(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
void push(stack_t **stack, unsigned int line_number);
int _isdigit(char *arguments);
void pall(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pop_f(stack_t **head, unsigned int line_number);
void pint_f(stack_t **stack, unsigned int line_number);

#endif