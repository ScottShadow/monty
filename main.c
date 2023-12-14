#include "monty.h"
char *global_value;

void processLine(monty_t *monty, char *line, instruction_t *instructions)
{
	char *token;
	char *opcode;

	opcode = malloc(sizeof(char) * 100);
	if (opcode == NULL)
	{
		perror("Error allocating memory for opcode");
		free(monty->_stack);
		free(opcode);
		exit(EXIT_FAILURE);
	}

	global_value = malloc(sizeof(char) * 100);
	if (global_value == NULL)
	{
		perror("Error allocating memory for value");
		free(monty->_stack);
		free(opcode);
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " ");
	if (token != NULL)
	{
		strcpy(opcode, token);
		printf("OPCODE : %s\n", opcode);
		token = strtok(NULL, " ");

		if (strncmp(opcode, "pall", 3) == 0)
		{
			instructions[1].f(&(monty->_stack), monty->line_num);
			printf("\npall called success\n");
		}
		else if (strncmp(opcode, "pint", 3) == 0)
		{
			instructions[2].f(&(monty->_stack), monty->line_num);
			printf("\npint called success\n");
		}
		else if (token != NULL)
		{
			strcpy(global_value, token);
			printf("VALUE : %s\n", global_value);
			if (strcmp(opcode, "push") == 0)
			{
				instructions[0].f(&(monty->_stack), monty->line_num);
				printf("push called success\n\n");
			}
		}
	}

	free(opcode);
	free(global_value);
}

int initializeMonty(monty_t *monty, char **argv)
{
	monty->_file = fopen(argv[1], "r");

	if (monty->_file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	monty->_stack = malloc(sizeof(stack_t));
	if (monty->_stack == NULL)
	{
		perror("Error allocating memory for stack");
		return (1);
	}
	return (0);
}
void initializeInstructions(instruction_t *instructions)
{
	instructions[0].opcode = "push";
	instructions[0].f = pushValue;
	instructions[1].opcode = "pall";
	instructions[1].f = pall;
	instructions[2].opcode = "pint";
	instructions[2].f = pint;
}
int main(int argc, char **argv)
{
	monty_t monty;
	int c;
	char buffer[100] = {'\0'};
	instruction_t instructions[3];

	initializeInstructions(instructions);
	(void)argc;

	initializeMonty(&monty, argv);
	if (initializeMonty(&monty, argv) != 0)
		return 1;
	printf("before while called\n");
	while ((c = fgetc(monty._file)) != EOF)
	{
		if (c == '\n')
			monty.line_num++;
		if (c == '$')
		{
			processLine(&monty, buffer, instructions);
			buffer[0] = '\0';
		}
		else if (c != '\n' && c != '\t')
		{
			strncat(buffer, (char *)&c, 1);
		}
	}

	fclose(monty._file);
	free(monty._stack);

	return (0);
}