#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: Current line number in the Monty script
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tempHead = *stack;
	stack_t *tempNext;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		tempNext = tempHead->next;

		tempHead->next = tempNext->next;
		tempHead->prev = tempNext;
		tempNext->next = tempHead;
		tempNext->prev = NULL;
		*stack = tempNext;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: Current line number in the Monty script
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tempHead = *stack;
	stack_t *tempNext = tempHead->next;

	int sum;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		sum = tempHead->n + tempNext->n;
		pop(stack, line_number);
		(*stack)->n = sum;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * nop - Does nothing.
 * @stack: Pointer to the head of the stack
 * @line_number: Current line number in the Monty script
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* printf("\n------nope------\n"); */
}
/**
 * sub - Subtracts the second top element from the top element of the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: Current line number in the Monty script
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tempHead = *stack;
	stack_t *tempNext = tempHead->next;

	int sub;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		sub = tempHead->n - tempNext->n;
		pop(stack, line_number);
		(*stack)->n = sub;
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
