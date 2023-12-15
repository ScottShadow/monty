#include "monty.h"



stackk_t *createSNode(const int num)
{
    stackk_t *new;


    new = malloc(sizeof(stackk_t));
    if(!new)
        return (NULL);

    new->n = num;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}


int _deleteSNodeAt(stackk_t **head, unsigned int pos)
{
    unsigned int index = 0;
    stackk_t *curr = *head;

    if(!pos) /* index is top 0*/
    { /* advance the head to next*/    
        (*head) = curr->next;
        if((*head)->next)
        /* the new head node  */
            (*head)->next->prev = NULL;
        curr->next = NULL; /*detach the del node*/
        free(curr);
        return(_TRUE);
    }
    while (index < pos)
    {
        curr = curr->next;
        index++;
        if(!curr)
            return (_FALSE);
    }
    /* node is at pos, detach del node*/
    curr->prev->next  = curr->next;
    if (curr->next) /*reattached is not last */
        curr->next->prev = curr->prev;
    free(curr);
    return(_TRUE);

}








stackk_t *_prependSNode(stackk_t **head, const int num)
{
    stackk_t *top;


    if(!head)
        return (NULL);
    top = createSNode(num);
    if(top)
    {
    /* attach at start and point to the rest*/
    top->next = *head;

    if((*head))
    /*point the previous 1st node to the new 1st node*/
        (*head)->prev = top;
    *head = top;

    return (top);
    }
    return (NULL);
    

}






size_t _printStack(const stackk_t *head)
{
    size_t stack ;

    if(!head)
        return (0);

    for(stack = 0; head; head = head->next, stack++)
        printf("%d\n", head->n);

    return(stack);
}





stackk_t *_getSNodeAt(stackk_t *head, unsigned int pos)
{
    unsigned int index = 0;

    stackk_t * curr = head;

    if(!curr)
        return (NULL);
    
   for (;curr && index < pos; curr = curr->next, index++)
    ;
    return (curr? curr : NULL);
    
}
