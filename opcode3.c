#include "monty.h"
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *tempHead = *stack;
	stack_t *tempNext = tempHead->next;

	int div;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		div = tempHead->n / tempNext->n;
		pop(stack, line_number);
		(*stack)->n = div;
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tempHead = *stack;
	stack_t *tempNext = tempHead->next;

	int mul;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		mul = tempHead->n * tempNext->n;
		pop(stack, line_number);
		(*stack)->n = mul;
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tempHead = *stack;
	stack_t *tempNext = tempHead->next;

	int mod;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		mod = tempHead->n % tempNext->n;
		pop(stack, line_number);
		(*stack)->n = mod;
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}