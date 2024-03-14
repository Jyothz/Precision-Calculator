/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */

    //if both number are not present return failure
    if((*head1) == NULL || (*head2) == NULL)
    {
	return FAILURE;
    }
    //if one number not present then the result is the other number
    if((*head1)->data == 0 && (*head1)->next == NULL )
    {
	(*headR) = (*head2);
	 return SUCCESS;
    }
    else if((*head2)->data == 0 && (*head2)->next == NULL)
    {
	(*headR) = (*head1);
	return SUCCESS;
    }

    //take tail of the two numbers and and traverse till one reaches null
	Dlist *temp1 = (*tail1),*temp2 = (*tail2);


	while(temp1 != NULL && temp2 != NULL)
	{
	    //insert the sum of corresponding index node to new result node
	    if(insert_first_LL(headR,tailR,temp1->data + temp2->data) == FAILURE)
		return FAILURE;

	    temp1 = temp1->prev;
	    temp2 = temp2->prev;
	}
	//after one number reaches null the add the remaining digits of the other number as it is
	if(temp1 == NULL)
	{
	    while(temp2 != NULL)
	    {
	     if(insert_first_LL(headR,tailR,temp2->data) == FAILURE)
		return FAILURE;
	     temp2 = temp2->prev;
	    }
	}
	else
	{
	    while(temp1 != NULL)
	    {
	     if(insert_first_LL(headR,tailR,temp1->data) == FAILURE)
		return FAILURE;
	     temp1 = temp1->prev;
	    }


	}
	return SUCCESS;    
}
