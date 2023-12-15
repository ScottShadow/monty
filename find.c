# include "monty.h"





void (*find_opcode(char **parsed))(stackk_t **, unsigned int)
{
    int index;
    instruction_t func_arr[] ={
        {"push", _push},
	    {"pall", _pall},
        {"pint", _pint},
        {"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
        {"pchar", _pchar},
		{"pstr", _pstr},
        {"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{"nop", _nop},
        {NULL, NULL}
    };
    for (index = 0; func_arr[index].opcode != NULL ; index++)
        if (strcmp(func_arr[index].opcode, parsed[0]) == 0)
            return (func_arr[index].f);

    return (NULL);
}

