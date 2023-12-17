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

	for (i = 0; i < 17; i++)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (token == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", monty->line_num);
				exit(EXIT_FAILURE);
			}
			strcpy(global_value, token);
			if (monty->stk_or_que)
				instructions[16].f(&(monty->_stack), monty->line_num);
			else
				instructions[17].f(&(monty->_stack), monty->line_num);
			break;
		}
		else if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			if (i >= 5 && i != 14 && i != 15 && monty->_stack == NULL)
			{
				fprintf(stderr, "L%d: can't %s, stack too short\n",
						monty->line_num, opcode);
				exit(EXIT_FAILURE);
			}
			instructions[i].f(&(monty->_stack), monty->line_num);
			if (strncmp(global_value, "s", 1) == 0)
				monty->stk_or_que = 1;
			else if (strncmp(global_value, "q", 1) == 0)
				monty->stk_or_que = 0;
			break;
		}
		else
		{
			if (i == 16)
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
	strcpy(global_value, "NULL");

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
	instructions[16].opcode = "push";
	instructions[16].f = pushValue;
	instructions[17].opcode = "push";
	instructions[17].f = pushValueQueue;
	instructions[1].opcode = "pall";
	instructions[1].f = pall;
	instructions[2].opcode = "pint";
	instructions[2].f = pint;
	instructions[3].opcode = "pop";
	instructions[3].f = pop;
	instructions[0].opcode = "swap";
	instructions[0].f = swap;
	instructions[5].opcode = "add";
	instructions[5].f = add;
	instructions[4].opcode = "nop";
	instructions[4].f = nop;
	instructions[6].opcode = "sub";
	instructions[6].f = sub;
	instructions[7].opcode = "div";
	instructions[7].f = divide;
	instructions[8].opcode = "mul";
	instructions[8].f = mul;
	instructions[9].opcode = "mod";
	instructions[9].f = mod;
	instructions[10].opcode = "pchar";
	instructions[10].f = pchar;
	instructions[11].opcode = "pstr";
	instructions[11].f = pstr;
	instructions[12].opcode = "rotl";
	instructions[12].f = rotl;
	instructions[13].opcode = "rotr";
	instructions[13].f = rotr;
	instructions[14].opcode = "stack";
	instructions[14].f = stack;
	instructions[15].opcode = "queue";
	instructions[15].f = queue;
}
/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, exit(EXIT_FAILURE) on failure
 */
int main(int argc, char **argv)
{
	monty_t monty = {NULL, NULL, NULL, NULL, 1, 0};
	int c;
	int isComment = 0;
	char buffer[100] = {'\0'};
	instruction_t instructions[18];

	if (argc != 2)
	{
		fprintf(stderr, USAGE);
		exit(EXIT_FAILURE);
	}
	initializeInstructions(instructions);
	(void)argc;
	if (initializeMonty(&monty, argv) != 0)
		return (1);

	while ((c = fgetc(monty._file)) != EOF)
	{
		if (c == '#')
			isComment = 1;

		if (c == '\n')
		{
			if (isComment == 0)
			{
				monty.line_num++;
				processLine(&monty, buffer, instructions);
			}
			buffer[0] = '\0';
			isComment = 0;
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
