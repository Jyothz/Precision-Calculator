/*******************************************************************************************************************************************************************
 *Title			: Multiplication
 *Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
 *Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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

//insert to result list function
int insert_LL_mul(Dlist **headR, Dlist **tailR,Dlist **tempTR, int data);

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    /* Definition goes here */

    //if both list empty return failure
    if(!(*head1) || !(*head2))
	return FAILURE;

    /*
    //check for one list empty then return the other
    if(!(*head1) && (*head2))
    {
    (*headR) = (*head2);
    return SUCCESS;
    }
    else if((*head1) && !(*head2))
    {
    (*headR) = (*head1);
    return SUCCESS;
    }

     */

    //declare required variables
    Dlist *temp1 = (*tail1), *temp2 = (*tail2), *tempHR = (*headR),*tempTR = (*tailR),*tempTR2;
    int res;


    //outer loop for 1 number to multiply with all numbers of the other list
    while(temp1 != NULL)
    {
	//updating initiale list node to multiply
	temp2 = (*tail2);
	tempTR2 = tempTR;
	//loop to to traverse the 2nd list and insert in result list
	while(temp2 != NULL)
	{
	    res = temp1->data * temp2->data;
	    if(insert_LL_mul(headR,tailR,&tempTR2,res) == FAILURE)
		return FAILURE;
	    temp2 = temp2->prev;
	    if(!tempTR)
		tempTR = (*tailR);
	    if(tempTR2)
		tempTR2 = tempTR2->prev;

	}

	//traversing outer list and next starting position for multiplication
	temp1 = temp1->prev;
	tempTR = tempTR->prev;
    } 
    //removing zero from first of the result
    while((*headR)->data == 0 && (*headR)->next != NULL)
    {
	(*headR) = (*headR)->next;
	free((*headR)->prev);
	(*headR)->prev  = NULL;
    }
    return SUCCESS;
}

//function to insert mul result in result list
int insert_LL_mul(Dlist **headR,Dlist **tailR, Dlist **tempTR, int data)
{
    //if starting node in null then create a node and update
    if(!(*tempTR))
    {
	//create new node and add data and link
	Dlist *new = malloc(sizeof(Dlist));
	if(!new)
	    return FAILURE;

	new->data = data;
	new->prev = NULL;
	new->next = NULL;

	//if list empty the update head and tail
	if(!(*headR))
	{
	    (*headR) = new;
	    (*tailR) = new;
	    return SUCCESS;
	}
	//else update new node to the head
	else
	{
	    new->next = (*headR);
	    (*headR)->prev = new;
	    (*headR) = new;
	    (*headR)->data = (*headR)->data + (((*headR)->next)->data /10);
	    ((*headR)->next)->data = ((*headR)->next)->data % 10;

	}
    }
    //else append the new data in the already existing node
    else
    {
	(*tempTR)->data = (*tempTR)->data + data + (((*tempTR)->next)->data /10);
	((*tempTR)->next)->data = ((*tempTR)->next)->data % 10;
    }
    return SUCCESS;
}
