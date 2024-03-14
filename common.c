/*
NAME : JYOTHISH B CHANDRAN
DATE :
DESCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
*/

#include<stdio.h>
#include<stdlib.h>
#include "apc.h"

//inserting at first for the result list
  int insert_first_LL(Dlist **headR, Dlist **tailR,int data)
  {
      //create new node
      Dlist *new = malloc(sizeof(Dlist));
      if(!new)
          return FAILURE;

      new->data = data;
      new->next = NULL;
      new->prev = NULL;

      if((*headR) == NULL)
      {
          (*headR) = new;
          (*tailR) = new;
          return SUCCESS;
      }
      new->data = new->data + ((*headR)->data / 10);
      (*headR)->data = (*headR)->data % 10;

      (*headR)->prev = new;
      new->next = (*headR);
      (*headR) = new;
      return SUCCESS;
  }

