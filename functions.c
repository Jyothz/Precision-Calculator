#include "apc.h"
#include <stdio.h>
#include <stdlib.h>
void print_list(Dlist *head)
{
    printf("in\n");
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
    }
}


char findOperator(char *s)
 {
     int i=0 ;
      while(s[i] != '\0')
     {
         if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
         {
              return s[i];
          }
         i++;
      }
  }

int insertElements(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *s)
  {
   int i=0;
 
    while(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
    {
       //create node
      Dlist *new = malloc(sizeof(Dlist));
      if(new== NULL)
      {
	  return FAILURE;
      }
       new->data = s[i]-48;
       if(*head1 == NULL)
         {
           *head1 = new;
           *tail1 = new;
           new->prev = NULL;
           new->next = NULL;
         }
         (* tail1)->next = new;
         new->prev = (*tail1);
         new->next = NULL;
         *tail1 = new;
  
         i++;
  
     }
     i++;
     while(s[i] !='\0')
     {
          Dlist *new = malloc(sizeof(Dlist));
         new->data = s[i] - 48;
         if(*head2 == NULL)
         {
           *head2 = new;
           *tail2 = new;
           new->prev = NULL;
           new->prev = NULL;
         }
         (* tail2)->next = new;
         new->prev = (*tail2);
         new->next = NULL;
         *tail2 = new;
  
         i++;
  
  
     }
     return SUCCESS;
  
  }

