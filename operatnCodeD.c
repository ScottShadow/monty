#include "monty.h"


/**
 * _pchar - pchar instruction
 * @stack: double pointer to the stack 
 * @line_numr: number of the line in the file
 */
void _pchar(stackk_t **stack, UNUSED unsigned int line_num)
{
	stackk_t *node = *stack;

	if (!node)
    instruction_err(PCHAR_FAIL);

	if (node->n < 0 || node->n > 127)
        instruction_err(PCHAR_RANGE);
	_putchar(node->n);
	_putchar('\n');
}

/**
 * _pstr - pstr instruction
 * @stack: pointer to the stack 
 * @line_num: number of the line in the file
 */
void _pstr(stackk_t **stack, UNUSED unsigned int line_num)
{
	stackk_t *node = *stack;


	if (!node)
	{
		_putchar('\n');
		return;
	}
	while (node && node->n != 0 && node->n >= 0 && node->n <= 127)
	{
		_putchar(node->n);
		node = node->next;
	}
	_putchar('\n');
}