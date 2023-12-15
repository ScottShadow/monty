#include "monty.h"


 monty_t obj = INIT_OBJ;



void monty(char** argv)
{
    size_t len = 0;
    int read_bytes = 0;
    char ** tokens = NULL ;

    void (*execute_func)(stackk_t **, unsigned int);
    
    (void) read_bytes;


    obj._file = fopen(argv[1], "r");
    if(file_err(obj._file, argv[1]))
        exit(EXIT_FAILURE);
    
    while(!feof(obj._file))
    {
        obj.line_num +=1;
        getline(&(obj._line), &len, obj._file);
            tokens = _parser(obj._line);
            if(tokens)
            {
                obj._tokens = tokens;
                if(obj._tokens[0] == NULL || obj._tokens[0][0] == '#')
                {
                    garbageCollector(_FALSE);
                    continue;
                }

    
                execute_func = find_opcode(obj._tokens);
               
                if(!execute_func)
                    operatn_err();
                
                execute_func(&(obj._stack), obj.line_num);
               
                garbageCollector(_FALSE);
                
            }
        
    }
    
    garbageCollector(_TRUE);

}





int main(int argc, char **argv)
{

    if (args_err(argc))
    {
        dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
    }
    monty(argv);
    return (EXIT_SUCCESS);
}



