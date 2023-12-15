#include "monty.h"




int count_word(char *str, char delim)
{
    int  index = 0, word_c = 0;

    /*skip any leading empty space*/
    while(str[index] == ' ' || str[index]== delim)
        index++;

    for(; str[index] != '\0'; index++)
    {
        while (str[index]!= delim && str[index] != '\0')
            index++;
        word_c += 1;
        while(str[index]== delim && str[index] != '\0' )
            index++;
    }
    return (word_c);
}




/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

