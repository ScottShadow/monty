#include "monty.h"
/**
 * divide - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the head of the stack
 * @line_number: Current line number in the Monty script
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *tempHead = *stack;
	stack_t *tempNext = tempHead->next;

	int div;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		div = tempNext->n / tempHead->n;
		pop(stack, line_number);
		(*stack)->n = div;
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * mul - Multiplies the top two elements of the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: Current line number in the Monty script
 */
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
/**
 * mod - Computes the remainder of the division of the second top element by
 * the top element of the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: Current line number in the Monty script
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tempHead = *stack;
	stack_t *tempNext = tempHead->next;

	int mod;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		mod = tempNext->n % tempHead->n;
		pop(stack, line_number);
		(*stack)->n = mod;
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
