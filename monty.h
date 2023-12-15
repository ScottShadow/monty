#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "macros.h"

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
} stackk_t;





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
        void (*f)(stackk_t **stack, unsigned int line_number);
} instruction_t;




/**
 * struct monty_s - Monty interpreter structure
 * @_line: Array of strings representing the current line
 * @_tokens: Array of strings representing the current line's words
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
        char *_line;
        char **_tokens;
        stackk_t *_stack;
        FILE *_file;
        int stk_or_que;
        int line_num;

} monty_t ;



extern monty_t obj;



int (*fn(int flag))(int);
int count_token_char(char *line, int flag);
char ** _parser(char *line);
int _putchar(char c);

void free_arr_strs(char **arr);
void garbageCollector(int total);
void (*find_opcode(char **parsed))(stackk_t **, unsigned int);
void freeSNode(stackk_t *head);

int file_err(FILE *file_ptr, char *arg);
int args_err(int argc);
void operatn_err(void);
void instruction_err(char * msg);
void memory_err(void);


char * copy_token(int len, int flag, char* tok);


stackk_t *createSNode(const int num);
int _deleteSNodeAt(stackk_t **head, unsigned int pos);
stackk_t *_appendSNode(stackk_t **head, const int num);
stackk_t *_prependSNode(stackk_t **head, const int num);
size_t _printStack(const stackk_t *head);
stackk_t *_getSNodeAt(stackk_t *head, unsigned int pos);
size_t sNodesLen(const stackk_t *head);
stackk_t *_insertSNodeAt(stackk_t **head, unsigned int pos, int num);


void _pall(stackk_t **stack, UNUSED unsigned int line_num);
void _push(stackk_t **stack, UNUSED unsigned int line_number);
void _pint(stackk_t **stack, UNUSED unsigned int line_num);
void _pop(stackk_t **stack, UNUSED unsigned int line_num);
void _swap(stackk_t **stack, UNUSED unsigned int line_num);
void _nop(stackk_t **stack, UNUSED unsigned int line_num);
void _add(stackk_t **stack, UNUSED  unsigned int line_num);
void _sub(stackk_t **stack, UNUSED unsigned int line_num);
void _div(stackk_t **stack, UNUSED unsigned int line_num);
void _mul(stackk_t **stack, UNUSED unsigned int line_num);
void _mod(stackk_t **stack, UNUSED unsigned int line_num);
void _rotl(stackk_t **stack,UNUSED unsigned int line_num);
void _rotr(stackk_t **stack, UNUSED unsigned int line_num);
void _stack( UNUSED stackk_t **stack, UNUSED unsigned int line_num);
void _queue(UNUSED stack_t **stack, UNUSED unsigned int line_num);
void _pchar(stackk_t **stack, UNUSED unsigned int line_num);
void _pstr(stackk_t **stack, UNUSED unsigned int line_num);

#endif
