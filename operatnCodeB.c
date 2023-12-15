#include "monty.h"


void _nop(stackk_t **stack, UNUSED unsigned int line_num)
{
    (void) stack;
    (void) line_num;
}





void _add(stackk_t **stack, UNUSED unsigned int line_num)
{
    int sum = 0;
	stackk_t *node0 = NULL, *node1 = NULL, *new = NULL;

    if(sNodesLen(*stack) < 2)
       instruction_err(ADD_FAIL);
    
    node0 = _getSNodeAt(*stack, 0);
    node1 = _getSNodeAt(*stack, 1);


    sum = node0->n + node1->n;

    _deleteSNodeAt(stack, 0);
    _deleteSNodeAt(stack, 0);
    new = _prependSNode(stack, sum);
    if(!new)
        memory_err();
}




/**
 * _sub -  subtraction instruction
 * @stack: double pointer to the stack 
 * @line_num: number of the line in the file
 */
void _sub(stackk_t **stack, UNUSED unsigned int line_num)
{
	int sub = 0;
	stackk_t *node0 = NULL, *node1 = NULL, *new = NULL;

    if(sNodesLen(*stack) < 2)
       instruction_err(SUB_FAIL);

	node0 = _getSNodeAt(*stack, 0);
	node1 = _getSNodeAt(*stack, 1);

	sub = node1->n - node0->n;
	_deleteSNodeAt(stack, 0);
	_deleteSNodeAt(stack, 0);
	new = _prependSNode(stack, sub);
	if (!new)
        memory_err();
}




/**
 * _div - divsion instruction
 * @stack: double pointer to the stack 
 * @line_num: number of the line in the file
 */
void _div(stackk_t **stack, UNUSED unsigned int line_num)
{
	int div = 0;
	stackk_t *node0 = NULL, *node1 = NULL, *new = NULL;

    if(sNodesLen(*stack) < 2)
       instruction_err(DIV_FAIL);

    node0 = _getSNodeAt(*stack, 0);
	node1 = _getSNodeAt(*stack, 1);


	if (node0->n == 0)
         instruction_err(DIV_ZERO);
	

	div = node1->n / node0->n;

	_deleteSNodeAt(stack, 0);
	_deleteSNodeAt(stack, 0);
	new = _prependSNode(stack, div);
	if (!new)
        memory_err();
}



/**
 * _mul-  multiply instruction
 * @stack: double pointer to the stack 
 * @line_num: number of the line in the file
 */
void _mul(stackk_t **stack, UNUSED unsigned int line_num)
{

    int mul = 0;
	stackk_t *node0 = NULL, *node1 = NULL, *new = NULL;

    if(sNodesLen(*stack) < 2)
       instruction_err(MUL_FAIL);

    node0 = _getSNodeAt(*stack, 0);
	node1 = _getSNodeAt(*stack, 1);

	
	mul = node0->n * node1->n;
	_deleteSNodeAt(stack, 0);
	_deleteSNodeAt(stack, 0);
	new = prependSNode(stack, mul);
	if (!new)
        memory_err();
}




