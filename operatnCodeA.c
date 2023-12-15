#include "monty.h"

/**
 * pushValue - adds a node to the beginning of a list
 * @stack: head node of our list
 * @line_number: the current line number
 */
void _push(stackk_t **stack, UNUSED unsigned int line_number)
{

	stackk_t *new = NULL;
    int num = 0;

    if(!obj._tokens[1])
        instruction_err(PUSH_FAIL);

   
    num = atoi(obj._tokens[1]);

    if(obj.stk_or_que == stack_flg)
        new = _prependSNode(stack, num);
    else if (obj.stk_or_que == queue_flg)
        new = _appendSNode(stack, num);

    if (!new)
        memory_err();
}



void _pall(stackk_t **stack, UNUSED unsigned int line_num)
{
    if(*stack)
        _printStack(*stack);
}



void _pint(stackk_t **stack, UNUSED unsigned int line_num)
{
    stackk_t *head = *stack;
    if(!head)
        instruction_err(PINT_FAIL);
    printf("%d\n", head->n);
}



void _pop(stackk_t **stack, UNUSED unsigned int line_num)
{
    stackk_t *head = *stack;
    if(!head)
        instruction_err(POP_FAIL);
   _deleteSNodeAt(stack, 0);
}


void _swap(stackk_t **stack, UNUSED unsigned int line_num)
{
    int num;
    stackk_t *tmp = *stack, *node = NULL;

    if(sNodesLen(*stack) < 2)
        instruction_err(SWAP_FAIL);

    tmp = _getSNodeAt(*stack, 0);
    num = tmp->n;
    _deleteSNodeAt(stack, 0);
    node = _insertSNodeAt(stack, 1, num);
    if (!node)
        memory_err();
}



