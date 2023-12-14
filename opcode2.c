#include "monty.h"

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
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tempHead = *stack;
	stack_t *tempNext = tempHead->next;

	int sum;

	(void)line_number;
	sum = tempHead->n + tempNext->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	printf("\n------nope------\n");
}