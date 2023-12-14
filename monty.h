#ifndef MONTY_H
#define MONTY_H

#include "macros.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char *global_value;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct monty_s
{
	char **_line;
	char **_words;
	stack_t *_stack;
	FILE *_file;
	int stk_or_que;
	int line_num;

} monty_t;

int file_err(FILE *file_ptr, char *arg);
int args_error(int argc);
size_t pall(const stack_t *h, unsigned int line_number);
stack_t *pushValue(stack_t **stack, unsigned int line_number);
void processLine(monty_t *monty, char *line);

#endif
