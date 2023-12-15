#include "monty.h"
/**
 * processLineHelper - Helper function for processing Monty instructions.
 * @monty: Pointer to the Monty interpreter structure
 * @opcode: The opcode of the Monty instruction
 * @token: The token associated with the opcode (if any)
 * @instructions: Array of Monty instruction structures
 */
void processLineHelper(monty_t *monty,
					   char *opcode, char *token, instruction_t *instructions)
{
	int i;

	for (i = 0; i < 11; i++)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (token == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", monty->line_num);
				exit(EXIT_FAILURE);
			}
			strcpy(global_value, token);
			instructions[10].f(&(monty->_stack), monty->line_num);
			break;
		}
		else if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(&(monty->_stack), monty->line_num);
			break;
		}
		else
		{
			if (i == 10)
			{
				fprintf(stderr, UNKNOWN, monty->line_num, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}
}
/**
 * processLine - Process a line of Monty instructions.
 * @monty: Pointer to the Monty interpreter structure
 * @line: The line containing Monty instructions
 * @instructions: Array of Monty instruction structures
 */
void processLine(monty_t *monty, char *line, instruction_t *instructions)
{
	char *token;
	char *opcode;

	opcode = malloc(sizeof(char) * 100);
	if (opcode == NULL)
	{
		perror("Error allocating memory for opcode");
		free(monty->_stack);
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
		token = strtok(NULL, " ");
		processLineHelper(monty, opcode, token, instructions);
	}

	free(opcode);
	free(global_value);
}
/**
 * initializeMonty - Initializes the Monty interpreter structure.
 * @monty: Pointer to the Monty interpreter structure
 * @argv: Array of command-line arguments
 * Return: 0 on success, exit(EXIT_FAILURE) on failure
 */
int initializeMonty(monty_t *monty, char **argv)
{
	monty->_file = fopen(argv[1], "r");

	if (monty->_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (0);
}
/**
 * initializeInstructions - Initializes the array of Monty
 * instruction structures.
 * @instructions: Array of Monty instruction structures
 */
void initializeInstructions(instruction_t *instructions)
{
	instructions[10].opcode = "push";
	instructions[10].f = pushValue;
	instructions[1].opcode = "pall";
	instructions[1].f = pall;
	instructions[2].opcode = "pint";
	instructions[2].f = pint;
	instructions[3].opcode = "pop";
	instructions[3].f = pop;
	instructions[0].opcode = "swap";
	instructions[0].f = swap;
	instructions[4].opcode = "add";
	instructions[4].f = add;
	instructions[5].opcode = "nop";
	instructions[5].f = nop;
	instructions[6].opcode = "sub";
	instructions[6].f = sub;
	instructions[7].opcode = "div";
	instructions[7].f = divide;
	instructions[8].opcode = "mul";
	instructions[8].f = mul;
	instructions[9].opcode = "mod";
	instructions[9].f = mod;
}
/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, exit(EXIT_FAILURE) on failure
 */
int main(int argc, char **argv)
{
	monty_t monty = {NULL, NULL, NULL, NULL, 0, 0};
	int c;
	char buffer[100] = {'\0'};
	instruction_t instructions[11];

	if (argc != 2)
	{
		fprintf(stderr, USAGE);
		exit(EXIT_FAILURE);
	}
	initializeInstructions(instructions);
	(void)argc;
	if (initializeMonty(&monty, argv) != 0)
		return (1);

	monty.line_num++;
	while ((c = fgetc(monty._file)) != EOF)
	{
		if (c == '\n')
			monty.line_num++;
		if (c == '\n')
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
	garbageCollector(&monty);

	return (0);
}
