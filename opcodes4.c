#include "monty.h"
/**
 * rotl - first becomes last, second becomes first
 * @stack: Pointer to the head of the stack
 * @line_number: Current line number in the Monty script
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *temp = NULL;

	(void)line_number;
	if (head)
	{
		temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = head;
		temp->next->prev = temp;
		*stack = head->next;
		(*stack)->prev = NULL;
		temp->next->next = NULL;
	}
}
/**
 * rotr - rotates the list on its head
 * @stack: Pointer to the head of the stack
 * @line_number: Current line number in the Monty script
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *temp = NULL;

	(void)line_number;
	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if (temp != NULL)
	{
		(*stack) = temp->prev;
	}
}
/**
 * pushValueQueue - adds a node to the end of the list
 * @stack: head node of our list
 * @line_number: the element to store in the node
 */
void pushValueQueue(stack_t **stack, unsigned int line_number)
{
	stack_t *tempPointer;
	stack_t *newNode;
	char *endptr;
	long value = strtol(global_value, &endptr, 10);

	if (*endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		exit(EXIT_FAILURE);

	newNode->n = value;

	if (*stack == NULL)
	{
		newNode->prev = NULL;
		newNode->next = NULL;

		*stack = newNode;
	}
	else
	{
		tempPointer = *stack;
		while (tempPointer->next != NULL)
		{
			tempPointer = tempPointer->next;
		}
		newNode->prev = tempPointer;
		newNode->next = NULL;
		tempPointer->next = newNode;
	}
}
/**
 * stack - sets list to stack
 * @stack:the list to set
 * @line_number: the current line number
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	strcpy(global_value, "s"); /*choose to use global value*/
}

/**
 * queue - sets list to queue
 * @stack:the list to set
 * @line_number: the current line number
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	strcpy(global_value, "q");
}
