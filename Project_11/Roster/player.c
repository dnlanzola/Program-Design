/*     Project 11 - player.c    */
/* Name: Daniel Anzola Delgado */

#include "player.h"
#include "readline.h"

/************************************************************
 * append_to_list: Prompts the user for information about a *
 * new player and then append the player into the end of the* 
 * list. Prints an error message and returns prematurely if *
 * the player already exists or space could not be allocated*
 * for the player. It orders alphabetically.			    *
 * **********************************************************/

struct player *append_to_list(struct player *roster){
  struct player *cur, *new_node;
  struct player *aux1, *aux2;
  int first = 1;
  int i = 0;

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
    new_node->next = NULL;
	roster = new_node;
	return roster;
  }
  else
  {
		cur=aux1=roster;
		i = 0;

		while(cur!=NULL)
		{	
			//IF COMPARES TO THE FIRST ELEMENT OF THE LIST & IS LESS OR EQUAL
			if (i == 0 && strcmp(cur->last_name,new_node->last_name)>=0)
			{
				//IF THE LAST NAME IS LESS
				if (strcmp(cur->last_name,new_node->last_name) > 0)
				{
					new_node->next = cur;
					roster = new_node;
					return roster;
				}	
                //IF THE LAST NAME ARE EQUALS
				if (strcmp(cur->last_name,new_node->last_name) == 0)
				{
					//IF FIRST NAME IS LESS
					if (strcmp(cur->first_name,new_node->first_name)>0)
					{
						new_node->next = cur;
						roster = new_node;
						return roster;
					}
					//IF FIRST NAME IS GREATER
					else
					{
						aux1 = cur->next;
						new_node->next = aux1;
						cur->next = new_node;
						roster = cur;
						return roster;
					}
				}
			}
			  
			i = 1;
			// IF THE LAST NAME IS LESS OR EQUAL 
            if (strcmp(cur->last_name,new_node->last_name)>=0)
            {
				//IF THE NEW LAST NAME IS LESS THAN THE CURRENT POSITION
                if (strcmp(cur->last_name,new_node->last_name)>0)
                {
					cur=aux1->next;
                  	aux1->next=new_node;
                  	new_node->next=cur;
                  	break;
                }
				
				//IF THE LAST NAMES ARE EQUAL
                if (strcmp(cur->last_name,new_node->last_name) == 0)
                {
					//IF THE NEW FIRST NAME IS LESS THAN CURRENT
                   	if (strcmp(cur->first_name,new_node->first_name)>0)
                    {
                    	cur=aux1->next;
                       	aux1->next=new_node;
                       	new_node->next=cur;
                       	break;
                    }
                   	//IF THE NAME IS GREATER
                   	else
                    {
                       	new_node->next=cur->next;
                       	cur->next=new_node;
                       	break;
                    }
                }
            }
            
			//REACHES THE END ADDS AT THE END
            if(cur->next == NULL)
            {
            	cur->next=new_node;
                break;
            }

			//AUX1 STORES THE PREVIOUS NODE
           	aux1=cur;
			
			cur=cur->next;
		}
		
   //RETURNS LIST        
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

/* ***********************************************************
 * delete_from_list: Deletes a player from the list.         *
 *************************************************************/

struct player *delete_from_list(struct player*roster) 
{
	struct player *aux;
	struct player *rosterAux;
	int playerNum = 0;

	printf("Enter player number to delete:\n");
	scanf("%d",&playerNum);   
	
	//IF THE LIST IS NOT EMPTY
	if (roster != NULL)
	{
		//CHECKS THE NUMBER OF PLAYER AT THE FIRST POSITION
		if (roster->number == playerNum)
		{
			aux = roster;
			roster = roster->next;
			free(aux);
		}
		//CHECKS THE REST OF THE LIST
		else
		{
			rosterAux = roster;
			
			//GOES THROUGH THE LIST UNTIL FINDS THE PLAYER
			while (rosterAux->next != NULL && rosterAux->next->number != playerNum)
				rosterAux = rosterAux->next;
				
			if (rosterAux->next != NULL)
			{
				aux = rosterAux->next;
				rosterAux->next = aux->next;
				free(aux);
			}
		}
	}
	
	return roster;

}


