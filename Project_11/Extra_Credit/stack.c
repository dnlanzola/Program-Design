/*     Project 11 - stack.c    */
/* Name: Daniel Anzola Delgado */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node* push(struct node* top, int i)
{
   struct node *new_node;
   new_node = malloc(sizeof(struct node));
   if(new_node == NULL)
   {
	printf("malloc failed");
        return top;
   }
   
   new_node->value = i;
   new_node->next = top;
   return new_node;

}

/* make_empty - Function
		Clears the list.
*/
struct node *make_empty(struct node *top)
{
  return NULL;
}

struct node *pop(struct node *top, int *i)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
   
	if (new_node == NULL) 
	{
    	printf("malloc failed");
    	return top;
	} 

   *i = top->value;
   new_node = top;
   top = top->next;
   free(new_node);
   
   return top;
}

/* roll - Function
		When called, it rolls the top three items on the stack.
*/
struct node *roll(struct node *top)
{
	struct node *aux1=top->next;
	struct node *aux2=aux1->next;

	aux1->next=aux2->next;
	aux2->next=top;

	top=aux2;

	return top;
}


/* print_stack - Function
		Prints stack.
*/
void print_stack(struct node *top)
{
   struct node *p;
   if(top != NULL){
      for(p = top; p !=NULL; p=p->next)
	printf("%d\n", p->value);
      printf("\n");
   }
   else
      printf("stack is empty\n");
}
