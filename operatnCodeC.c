#include "monty.h"


/**
 * _mod - the modulus instruction
 * @stack: pointer to the stack 
 * @line_num: number of the line in the file
 */
void _mod(stackk_t **stack, UNUSED unsigned int line_num)
{
	int mod = 0;
	stackk_t *node0 = NULL, *node1 = NULL, *new = NULL;

    if(sNodesLen(*stack) < 2)
       instruction_err(MOD_FAIL);

    node0 = _getSNodeAt(*stack, 0);
	node1 = _getSNodeAt(*stack, 1);


	if (node0->n == 0)
        instruction_err(DIV_ZERO);

	mod = node1->n % node0->n;

	_deleteSNodeAt(stack, 0);
	_deleteSNodeAt(stack, 0);
	new = _prependSNode(stack, mod);
	if (!new)
        memory_err();
}


/**
 * _rotl- the rotl instruction
 * @stack: pointer to the stack
 * @line_num: number of the line in the file
 */
void _rotl(stackk_t **stack,UNUSED unsigned int line_num)
{
    int num  = 0;
	stackk_t *tmp = *stack;
	

	if (!(*stack) )
		return;

	tmp = _getSNodeAt(*stack, 0);
	num = tmp->n;
	_deleteSNodeAt(stack, 0);
	_appendSNode(stack, num);
}

/**
 * _rotr - rotr instruction
 * @stack: pointer to the stack
 * @line_num: number of the line in the file
 */
void _rotr(stackk_t **stack, UNUSED unsigned int line_num)
{
    int len,  num = 0;
	stackk_t *tmp = *stack;

	len = sNodesLen(*stack);


	if (!(*stack ))
		return;

	tmp = _getSNodeAt(*stack, len - 1);
	num = tmp->n;
	_deleteSNodeAt(stack, len - 1);
	_prependSNode(stack, num);
}

/**
 * _stack - Stack instruction
 * @stack: pointer to the stack 
 * @line_num: number of the line in the file
 */
void _stack( UNUSED stackk_t **stack, UNUSED unsigned int line_num)
{
	obj.stk_or_que = stack_flg;
}


/**
 * queue_handler - Queue instruction
 * @stack: pointer to the stack 
 * @line_num: number of the line in the file
 */
void _queue(UNUSED stackk_t **stack, UNUSED unsigned int line_num)
{
	obj.stk_or_que = queue_flg;
}
