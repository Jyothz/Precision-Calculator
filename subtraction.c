/*******************************************************************************************************************************************************************
  i
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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


int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
    if(!(*head1) || !(*head2))
    {
	return FAILURE;
    }

    /*
    if((*head2)->data == 0 && (*head2)->next == NULL)
    {
	(*headR)=(*head1);
	return SUCCESS;
    }
    else if((*head1)->data == 0 && (*head1)->next == NULL)
    {
	(*headR) = (*head2);
	return SUCCESS;
    }
    */

    Dlist *temp1 = (*tail1), *temp2 = (*tail2),*tempR = (*tailR),*carry;
    int res;

    //taking count of each linked list
    int count_LL1 = 0, count_LL2 = 0;

    while(temp1 != NULL || temp2 != NULL)
    {
	if(temp1)
	{
	    count_LL1++;
	    temp1 = temp1->prev;
	}
	if(temp2)
	{
	    count_LL2++;
	    temp2 = temp2->prev;
	}

    }
    if(count_LL1 >= count_LL2)
    {
    	temp1 = (*tail1);
    	temp2 = (*tail2);
    }else
    {
	temp1 = (*tail2);
	temp2 = (*tail1);
    }


    while(temp1 != NULL && temp2 != NULL)
    {

	//subracting corresponding node
	res = temp1->data - temp2->data;
	if(res < 0)
	{
	    carry = temp1;
	    while(1)
	    {
		carry = carry->prev;
		if(carry->data != 0)
		{
		    carry->data = carry->data - 1;
		    while(carry->next != temp1)
		    {
			carry = carry->next;
			carry->data = carry->data + 9;
		    }
		    break;
		}

	    }
	    temp1->data = temp1->data + 10;
	    res = temp1->data - temp2->data;
	}
	if(insert_first_LL(headR,tailR,res) == FAILURE)
	    return FAILURE;

	temp1 = temp1->prev;
	temp2 = temp2->prev;

    }

    if (temp1 != NULL)
    {

	while(temp1 != NULL)
	{
	if(insert_first_LL(headR,tailR,temp1->data) == FAILURE)
	    return FAILURE;
	temp1 = temp1->prev;
	}
    }

    //removing zero from first of the result
    while((*headR)->data == 0)
    {
	(*headR) = (*headR)->next;
	free((*headR)->prev);
	(*headR)->prev  = NULL;
    }

    if(count_LL2 > count_LL1)
    {
	(*headR)->data = (*headR)->data * (-1);
    }

    return SUCCESS;
}
 
