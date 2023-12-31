#include "monty.h"

/**
 * pushValue - adds a node to the beginning of a list
 * @stack: head node of our list
 * @line_number: the current line number
 */
void pushValue(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;
	char *endptr;
	long value = strtol(global_value, &endptr, 10);

	if (*endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (stack)
	{
		newNode = malloc(sizeof(stack_t));
		if (newNode == NULL)
		{
			fprintf(stderr, "Memory allocation error\n");
			exit(EXIT_FAILURE);
		}

		newNode->n = value;
		newNode->next = *stack;

		if (*stack)
			(*stack)->prev = newNode;

		*stack = newNode;
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
/**
 * pint - prints the head of list
 * @stack:the list to print
 * @line_number: the current line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	const stack_t *h = (const stack_t *)*stack;
	(void)line_number;
	if (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pop - removes the first element in the list
 * @stack:the list to print
 * @line_number: the current line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack)
	{
		delete_dnodeint_at_index(stack, 0);
	}
	else
	{
		fprintf(stderr, POP_FAIL, line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * delete_dnodeint_at_index - deletes the node at index @index of
 * a stack_t linked list
 * @head: the pointer to the header node of the list
 * @index: the index with which to delete the element of
 * Return: 1(Success) else -1
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *tempPointer1;
	stack_t *tempPointer2 = NULL;
	unsigned int i;

	tempPointer1 = *head;

	if (tempPointer1 != NULL)
		while (tempPointer1->prev != NULL)
			tempPointer1 = tempPointer1->prev;

	i = 0;

	while (tempPointer1 != NULL)
	{
		if (i == index)
		{
			if (i == 0)
			{
				*head = tempPointer1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				tempPointer2->next = tempPointer1->next;

				if (tempPointer1->next != NULL)
					tempPointer1->next->prev = tempPointer2;
			}

			free(tempPointer1);
			return (1);
		}
		tempPointer2 = tempPointer1;
		tempPointer1 = tempPointer1->next;
		i++;
	}

	return (-1);
}
