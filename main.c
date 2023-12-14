#include "monty.h"
char *global_value;

void processLine(monty_t *monty, char *line, instruction_t *instructions)
{
    char *token;
    char *opcode;
    int i;

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
        /*printf("OPCODE : %s\n", opcode);*/
        token = strtok(NULL, " ");

        for (i = 0; i < 10; i++)
        {
            if (token != NULL && strcmp(opcode, "push") == 0)
            {
                strcpy(global_value, token);
                /*printf("VALUE : %s\n", global_value);*/
                instructions[10].f(&(monty->_stack), monty->line_num);
                /* printf("push called success\n\n"); */
                break;
            }
            else if (strcmp(opcode, instructions[i].opcode) == 0)
            {
                instructions[i].f(&(monty->_stack), monty->line_num);
                /* printf("\n%s called success\n", opcode); */
                break;
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

    return (0);
}
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
int main(int argc, char **argv)
{
    monty_t monty = {NULL, NULL, NULL, NULL, 0, 0};
    int c;
    char buffer[100] = {'\0'};
    instruction_t instructions[11];

    initializeInstructions(instructions);
    (void)argc;
    if (initializeMonty(&monty, argv) != 0)
        return 1;

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
    garbageCollector(&monty);

    return (0);
}