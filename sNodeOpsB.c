#include "monty.h"


size_t sNodesLen(const stackk_t *head)
{
    size_t sNodes;
    const stackk_t *curr = head;

    if(!curr)
        return (0);
    
    for(sNodes = 0; curr; curr=curr->next, sNodes++)
        ;
    return (sNodes);
}






stackk_t *_appendSNode(stackk_t **head, const int num)
{
    stackk_t * new;
    stackk_t *curr = *head;


    if(!head)
        return (NULL);

    new = createSNode(num);
    if (new)
    {

        if(!(*head))
        {/*there is no sNode in list yet*/
            *head = new; /*new is top node*/
            return (new);
        }
        for (; curr->next != NULL; curr = curr->next)
            ; /*move to the last node*/
        
        curr->next = new;
        new->prev = curr;
        return (new);
    }
    return (NULL);
}






stackk_t *_insertSNodeAt(stackk_t **head, unsigned int pos, int num)
{
    unsigned int index;
    stackk_t * new;
    stackk_t *curr = *head;


    for (index = 0; curr && index < pos; index++, curr = curr->next)
    {
        if (index == pos - 1)
        {
            if(!(curr->next)) /* node is at last node*/
                return(_appendSNode(head, num));
            new = createSNode(num);
            if (!new || !head)
                return (NULL);

            new->next = curr->next; 
            new->prev = curr;

            curr->next->prev = new;
            curr->next = new;
            return(new);
        }


    }
    return (NULL);
}
