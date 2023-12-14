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
/**
 * garbageCollector - Frees the memory allocated for the Monty interpreter.
 * @monty: Pointer to the Monty interpreter structure
 */
void garbageCollector(monty_t *monty)
{
	free_stack(monty->_stack);
}
/**
 * free_arr_strs - Frees the memory allocated for an array of strings.
 * @arr: Pointer to the array of strings
 */
void free_arr_strs(char **arr)
{
	int index;

	if (!arr)
		return;

	for (index = 0; arr[index] != NULL; index++)
		free(arr[index]);
	free(arr);
}
