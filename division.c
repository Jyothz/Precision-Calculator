/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
#include <stdlib.h>

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
    if(!(*head1) || !(*head2))
	return FAILURE;
    //take count of head2 / divisor
    Dlist *tempH2 = (*head2), *tempH1 = (*head1);
    int divisor_c = 1,divident_c = 1,res_c=1;
    while( tempH2->next != NULL)
    {
	divisor_c++;
	tempH2 = tempH2->next;
    }

    while(1)
    {
	tempH1 = (*head1);
	(*headR) = NULL;
	(*tailR) = NULL;
	//take count of updated head1 / divident
	divident_c = 1;
	while( tempH1->next != NULL)
	{
	    divident_c++;
	    tempH1 = tempH1->next;
	}

	if(divident_c > divisor_c)
	{
	    if(subtraction(head1,tail1,head2,tail2,headR,tailR) == FAILURE)
		return FAILURE;
	    //freeing old head1
	    res_c++;
	    while((*head1)->next != NULL)
	    {
		(*head1) = (*head1)->next;
		free((*head1)->prev);
	    }
	    //freeing last node and updating head1 and tail 1 with new list
	    free((*head1));
	    (*head1) = (*headR);
	    (*tail1) = (*tailR);
	}
	else if ( divident_c == divisor_c )
	{
	    if((*head1)->data > (*head2)->data)
	    {
		if(subtraction(head1,tail1,head2,tail2,headR,tailR) == FAILURE)
		    return FAILURE;

		res_c++;
		//freeing old head1
		while((*head1)->next != NULL)
		{
		    (*head1) = (*head1)->next;
		    free((*head1)->prev);
		}
		//freeing last node and updating head1 and tail 1 with new list
		free((*head1));
		(*head1) = (*headR);
		(*tail1) = (*tailR);

	    }
	    else
	    {
		break;
	    }
	}
	else
	{
	    break;
	}
    }

    return res_c;
}
