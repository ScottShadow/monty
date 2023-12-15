#include "monty.h"





int (*fn(int flag))(int)
{
    return ((flag)? isalpha : isdigit);
}




int char_start(char *line, int flag)
{
    int index;

    int(*char_check)(int);
    if (!line)
        return (0);

    char_check = fn(flag);
    for (index = 0; line[index]; index++)
        if(char_check(line[index]))
            return(index);
    
    return (0);
}




int count_token_char(char *line, int flag)
{
    int index, count = 0;

    int(*char_check)(int);

    if (!line)
        return (0);

    char_check = fn(flag);
    for (index = 0; line[index]; index++)
    {
        if(char_check(line[index]))
        {
            do
                count++, index++;
            while(char_check(line[index]));
            return (count);
        }
    }
    return (0);
}



char ** _parser(char *line)
{
    char* tok;
    char** tokens;
    int name_count, arg_count;

    if (!line)
        return (NULL);
    
    
    tokens = (char **)malloc(sizeof(char*) * (3));
    name_count = count_token_char(line, CHAR_F);
    arg_count = count_token_char(line, NUM_F);


    if(!tokens)
        return (NULL);

    tokens[0] = NULL;
    tokens[1] = NULL;
    tokens[2] = NULL;

    if(name_count)
    {
        tok = strtok(line, " ");
        tokens[0] = copy_token(name_count, CHAR_F, tok);

        if(tok != NULL)
            if(arg_count)
            { 
                tok = strtok(NULL, " ");
                tokens[1] = copy_token(arg_count, NUM_F, tok);
               
            }
        return (tokens);
    }
   
    free(tokens);
    return(NULL);
}




char * copy_token(int len, int flag, char* tok)
{
    int index;
    char *token;
    int (*char_check) (int);

    token = (char *)malloc(sizeof(char)* (len + 1));
    if(!token)
        return (NULL);
    char_check = fn(flag);

    for (index = 0; char_check(tok[index]); index++)
        token[index] = tok[index];
    token[index] = '\0';
    return (token);
}
