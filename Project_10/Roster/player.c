/*     Project 10 - player.c    */
/* Name: Daniel Anzola Delgado */

#include "player.h"
#include "readline.h"

/************************************************************
 * append_to_list: Prompts the user for information about a *
 * new player and then append the player into the end of the* 
 * list. Prints an error message and returns prematurely if *
 * the player already exists or space could not be allocated*
 * for the player. 					    *
 * **********************************************************/

struct player *append_to_list(struct player *roster){
  struct player *cur, *new_node;

  new_node = malloc(sizeof(struct player));
  if (new_node == NULL) {
    printf("Database is full; can't add more players.\n");
    return roster;
  }

  printf("Enter player number: ");
  scanf("%d", &new_node->number);

  for (cur = roster;cur != NULL;cur = cur->next)
  if (cur != NULL && new_node->number == cur->number) {
    printf("Player already exists.\n");
    free(new_node);
    return roster;
  }

  printf("Enter player last name: ");
  read_line(new_node->last_name, NAME_LEN);
  printf("Enter player first name: ");
  read_line(new_node->first_name, NAME_LEN);

  if(roster == NULL)
  {
	roster = new_node;
	return roster;
  }
  else{ 
   for(cur = roster; cur->next!= NULL; cur = cur->next);
     cur->next = new_node;
     new_node->next = NULL;
     return roster;
 }
}
/***********************************************************
 * find_player: Prompts the user to enter a player number, *
 * then looks up a player by number in the list.           *
 * Prints the player's last name and first name if found.  *
 * Otherwise, prints a message.				   *
 * ********************************************************/

void find_player(struct player *roster)
{
  int number;
  struct player *p;

  printf("Enter player number: ");
  scanf("%d", &number);
  
  for(p=roster;
       p != NULL && number != p->number;
       p = p->next)
    ;
  if (p != NULL && number == p->number)
  {
    printf("Player name: %s, ", p->last_name);
    printf("%s\n", p->first_name);
  } else
    printf("Player not found.\n");

}

/*************************************************************
 * printList: Prints a listing of all players in the list,   *
 * showing the player number, player last name, and player   *
 * first name.						     *
 * **********************************************************/

void printList(struct player *roster){
  struct player *p;

  printf("Player Number\tLast Name\t"
         "First Name\n");
  for (p = roster; p != NULL; p = p->next)
    printf("%d\t\t%s\t\t%s\n", p->number, p->last_name,
           p->first_name);

}

/* ***********************************************************
 * cleearList: Clears the entire linked list. It  begins at  *
 * the head of the list and frees the memory allocated for   *
 * each node of the linked list.                             *
 *************************************************************/

void clearList(struct player *roster)
{

  struct player *p;

  while(roster!=NULL)
  {
	 p = roster; 
	 roster = roster->next;
         if(p!=NULL)
	    free(p);
  }



}
