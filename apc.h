#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

//function for addition of 2 linked list
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);

//function to substract 2 linked list
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);

//function to multiplicating 2 linked list
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

//function to division of 2 linked list
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);

//function to modulus 2 linked list

//function to power of 2 linked list

//insert function to result list
int insert_first_LL(Dlist **headR, Dlist **tailR,int data);

#endif
