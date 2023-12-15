#include "monty.h"



int args_err(int argc)
{
   return((argc != 2)? _TRUE: _FALSE);
}




int file_err(FILE *file_ptr, char *arg)
{
    if(!file_ptr)
    {
        dprintf(STDERR_FILENO, FILE_ERROR, arg);
        return(_TRUE);
    }
    return (_FALSE);
}



void operatn_err(void)
{
    dprintf(STDERR_FILENO, UNKNOWN, obj.line_num, obj._tokens[0]);
    garbageCollector(_TRUE);
    exit(EXIT_FAILURE);
}


void instruction_err(char * msg)
{
    dprintf(STDERR_FILENO, msg, obj.line_num);
	garbageCollector(_TRUE);
	exit(EXIT_FAILURE);
}




void memory_err(void)
{
    dprintf(STDERR_FILENO, MALLOC_FAIL );
	garbageCollector(_TRUE);
	exit(EXIT_FAILURE);
}
