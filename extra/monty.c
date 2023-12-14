#include "monty.h"



void monty(char** argv, monty_t *obj)
{
    size_t len = 0;
    int line = 0;

    obj->_file = fopen(argv[1], "r");
    if(file_err(obj->_file, argv[1]))
        exit(EXIT_FAILURE);
    
    while(_TRUE)
    {

    }


}





int main(int argc, char **argv)
{
    monty_t obj = {INIT_OBJ};

    if (args_error(argc))
    {
        dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
    }
    monty(argv, &obj);
    return (EXIT_SUCCESS);
}



