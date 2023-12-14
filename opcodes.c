#include "monty.h"

/**
 * pushValue - adds a node to the beginning of a list
 * @stack: head node of our list
 * @line_number: the current line number
 */
void pushValue(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

	int value = atoi(global_value);
	(void)line_number;
	if (stack)
	{
		newNode = malloc(sizeof(stack_t));
		/*if (newNode == NULL)*/
		/*return (NULL);*/

		newNode->n = value;
		newNode->next = *stack;
		if (*stack)
			(*stack)->prev = newNode;

		*stack = newNode;
		/*return (newNode);*/
	}
}

/**
 * pall - prints the whole list
 * @stack:the list to print
 * @line_number: the current line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	const stack_t *h = (const stack_t *)*stack;
	(void)line_number;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

void pint(stack_t **stack, unsigned int line_number)
{
	const stack_t *h = (const stack_t *)*stack;
	(void)line_number;
	if (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
