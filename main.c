/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
#include <stdlib.h>

//create/insert linked list function
int insert_LL(Dlist **head,Dlist **tail ,int data);
int print_LL(Dlist *head, Dlist *tail);

int main()
{

    char option;

	do
	{

	    /* Declare the pointers */
	Dlist *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL, *headR=NULL,*tailR=NULL;
	char operator,*input;
	int i=0;


	    /* Code for reading the inputs */
	    printf("Enter the input : ");
	    scanf("%s",input);



	 /*inserting first number in linked list 1*/
	    while(input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/')
	    {
		if(insert_LL(&head1, &tail1,input[i]) == FAILURE)
		    return FAILURE;

		i++;
	    }
	    
	/* Function for extracting the operator */
	    operator = input[i];
	    i++;

	/*creating linked list 2 to add second number*/
	    while(input[i] != '\0')
	    {
		if(insert_LL(&head2, &tail2,input[i]) == FAILURE)
		    return FAILURE;

		i++;
	    
	    }

		switch (operator)
		{
			case '+':
				/* call the function to perform the addition operation */
			    if(addition(&head1, &tail1, &head2, &tail2, &headR,&tailR) == FAILURE)
				printf("INFO : Unable to do Addition\n");
			    else
			    {
				printf("Addition Success Result : ");
				//result LL printing
				if(print_LL(headR,tailR) == FAILURE)
				{
				    printf("List Empty\n");
				}
			    }


				break;
			case '-':	
				/* call the function to perform the subtraction operation */
				if(subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR) == FAILURE)
				    printf("INFO : Unable to do Subtraction\n");
				else
				{
				    printf("Substraction Succesfull : ");
				    //result printing
				    if(print_LL(headR,tailR) == FAILURE)
					printf("List Empty\n");
				}
				break;
			case '*':	
				/* call the function to perform the multiplication operation */
				if(multiplication(&head1,&tail1, &head2, &tail2,&headR,&tailR) ==  FAILURE)
				    printf("INFO : Unable to do multiplication\n");
				else
				{
				    //result printing
				    printf("Multipilcation Successfull : ");
				    if(print_LL(headR,tailR) == FAILURE)
					printf("List Empty\n");

				}
				break;
			case '/':
#if 0	
				/* call the function to perform the division operation */
				if(division(&head1,&tail1, &head2, &tail2, &headR, &tailR) == FAILURE)
				    printf("INFO : Unable to do division\n");
				else
				{
				    //result printing
				    printf("Division Successfull : ");
				    if(print_LL(headR,tailR) == FAILURE)
					printf("List Empty\n");

				}
#endif
				printf("result = %d\n",division(&head1,&tail1, &head2, &tail2, &headR, &tailR));
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
		printf("Want to continue? Press [yY | nN]: ");
		scanf("\n%c", &option);
	}while (option == 'y' || option == 'Y');

	return 0;
}


int insert_LL(Dlist **head,Dlist **tail ,int data)
{

    Dlist *new = malloc(sizeof(Dlist));
    if(!new)
	return FAILURE;

    new->data = data - 48;
    new->next = NULL;
    new->prev = NULL;
    if(!(*head))
    {
	(*head)=new;
	(*tail)=new;
	return SUCCESS;
    }
    (*tail)->next = new;
    new->prev = (*tail);
    (*tail)=new;
    return SUCCESS;
}

int print_LL(Dlist *head, Dlist *tail)
{
    if(!head)
	return FAILURE;

    while(head != NULL)
    {
	printf("%d",head->data);
	head = head->next;
    }
    putchar('\n');
    return SUCCESS;
}
