#include "monty.h"
#include <string.h>
int main(void)
{
	FILE *file = fopen("000.m", "r");
	int c;
	char buffer[100] = {'\0'};
	char *token;
	char *opcode;
	char *value;
	stack_t *stack;
	int line_number = 1;

	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}
	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
		return (0);
	opcode = malloc(MAX_OPCODE_LENGTH);
	if (opcode == NULL)
	{
		perror("Error allocating memory for opcode");
		free(stack);
		return (0);
	}
	value = malloc(MAX_VALUE_LENGTH);
	if (value == NULL)
	{
		perror("Error allocating memory for value");
		free(stack);
		free(opcode);
		return (0);
	}
	printf("before while called\n");
	while ((c = fgetc(file)) != EOF)
	{
		if (c == '\n')
			line_number++;
		token = strtok(buffer, " ");
		if (c == '$')
		{
			token = strtok(buffer, " ");
			if (token != NULL)
			{
				strcpy(opcode, token);
				token = strtok(NULL, " ");
				if (token != NULL)
				{
					strcpy(value, token);
					buffer[0] = '\0';
					if (strcmp(opcode, "push") == 0)
						pushValue(&stack, line_number, atoi(value));
					else if (strcmp(opcode, "pall") == 0)
						pall(stack);
				}
			}
		}
		else if (c != '\n' && c != '\t')
			strncat(buffer, (char *)&c, 1);
	}
	fclose(file);
	free(stack);
	free(opcode);
	free(value);
	return (0);
}
