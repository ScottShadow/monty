#ifndef MONTY_H
#define MONTY_H

#include "macros.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
char *global_value;
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

/**
 * struct monty_s - Monty interpreter structure
 * @_line: Array of strings representing the current line
 * @_words: Array of strings representing the current line's words
 * @_stack: Pointer to the top of the stack
 * @_file: Pointer to the currently opened file
 * @stk_or_que: Flag indicating whether the Monty
 * interpreter is in stack or queue mode
 * @line_num: Current line number being processed
 *
 * Description:
 * This structure represents the state of the Monty interpreter
 * and includes
 * essential components such as the current line, stack, file,
 * and instructions.
 * The instruction structure provides information about
 * available opcodes and their
 * corresponding functions for stack, queues, LIFO, FIFO operations.
 */
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
void pall(stack_t **h, unsigned int line_number);
void pushValue(stack_t **stack, unsigned int line_number);
void processLine(monty_t *monty, char *line, instruction_t *instructions);
void processLineHelper(monty_t *monty,
					   char *opcode, char *token, instruction_t *instructions);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void swap(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);
void garbageCollector(monty_t *obj);
void free_arr_strs(char **arr);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

#endif
