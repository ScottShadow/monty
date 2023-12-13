#include "monty.h"
/**
 * pushValue - adds a node to the beginning of a list
 * @stack: head node of our list
 * @value: the element to store in the node
 * @line_number: the current line number
 * Return: address of new node
 */
stack_t *pushValue(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *newNode;

	(void)line_number;
	if (stack)
	{
		newNode = malloc(sizeof(stack_t));
		if (newNode == NULL)
			return (NULL);

		newNode->n = value;
		newNode->next = *stack;
		if (*stack)
			(*stack)->prev = newNode;

		*stack = newNode;
		return (newNode);
	}
	return (NULL);
}

/**
 * pall - prints the whole list
 * @h:header node of the list to print
 * Return: size of elements printed
 */
size_t pall(const stack_t *h)
{
	size_t size = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		size++;
	}
	return (size);
}
