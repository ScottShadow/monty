#include "monty.h"


void garbageCollector(monty_t* obj,int total)
{


}


void free_arr_strs(char **arr)
{
    int index;

    if(!arr)
        return;

    for (index = 0; arr[index] != NULL; index++)
        free(arr[index]);
    free(arr);
}