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
		if (tempHead->n == 0)
		{
			fprintf(stderr, DIV_ZERO, line_number);
			exit(EXIT_FAILURE);
		}
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
		if (tempHead->n == 0)
		{
			fprintf(stderr, DIV_ZERO, line_number);
			exit(EXIT_FAILURE);
		}
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
/**
 * pchar - prints the head of list as character
 * @stack:the list to print
 * @line_number: the current line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	const stack_t *h = (const stack_t *)*stack;
	int l;

	(void)line_number;
	if (h)
	{
		l = h->n;
		if ((l >= 65 && l <= 90) || (l >= 97 && l <= 122))
			printf("%c\n", h->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
		h = h->next;
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pstr - prints the characters in a list
 * @stack:the list to print
 * @line_number: the current line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	const stack_t *h = (const stack_t *)*stack;
	int l;

	(void)line_number;
	while (h)
	{
		l = h->n;
		if ((l >= 65 && l <= 90) || (l >= 97 && l <= 122))
			printf("%c", h->n);
		else
		{
			printf("\n");
			break;
		}
		h = h->next;
	}
}