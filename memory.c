#include "monty.h"

/**
 * free_stack - frees doubly linked lists
 * @head: the head node of the list to free
 */
void free_stack(stack_t *head)
{
	stack_t *tempPointer;
	stack_t *currentPointer = head;

	while (currentPointer != NULL)
	{
		tempPointer = currentPointer->next;
		free(currentPointer);
		currentPointer = tempPointer;
	}
}
void garbageCollector(monty_t *monty)
{
	free_stack(monty->_stack);
}

void free_arr_strs(char **arr)
{
	int index;

	if (!arr)
		return;

	for (index = 0; arr[index] != NULL; index++)
		free(arr[index]);
	free(arr);
}