#include "monty.h"



int args_err(int argc)
{
    (argc != 2)? _TRUE: _FALSE;
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