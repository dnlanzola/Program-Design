/*     Project 9 - roster.c    */
/* Name: Daniel Anzola Delgado */

/*This program maintains a roster for a sports team. 
Each player has a last name, first name, and a number. */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NAME_LEN 30
struct player{
	int number;
	char first_name[NAME_LEN+1];
	char last_name[NAME_LEN+1];
	struct player *next;
};


struct player *append_to_list(struct player *roster);
void find_player(struct player *roster);
void printList(struct player *roster);
void clearList(struct player *roster);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct player *team_roster = NULL;  
  printf("Operation Code: a for appending to the roster, f for finding a player"
	  ", p for printing the roster; q for quit.\n");
  for (;;) {
    printf("Enter operation code: \n");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': team_roster = append_to_list(team_roster);
                break;
      case 'f': find_player(team_roster);
                break;
      case 'p': printList(team_roster);
                break;
      case 'q': clearList(team_roster);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}


/* Function: append_to_list.
   Description: This function appends a new player to the list.
   Parameters:
   		- roster (struct player): roster that contains all players.
*/ 
struct player *append_to_list(struct player *roster)
{
	struct player *p;
	struct player *aux_p = (struct player *)malloc(sizeof(struct player));
	int player_num = 0;
	char last[NAME_LEN+1];
	char first[NAME_LEN+1];
	int player_exists = 0;
	
	p = roster;

	//ASKS FOR PLAYER NUMBER
	printf("Enter player number: \n");
	scanf("%i", &player_num);

	while(p != NULL)
	{
		if(p->number == player_num)
			player_exists = 1;
		
		p = p->next;
	}

	if(player_exists)
	{
		//PRINTS ERROR WHEN PLAYER NUMBER IS ALREADY ASSIGNED
		printf("ERROR: Entered number already assigned to another player.\n");
		return roster;
	}
	else
	{
		//ASKS FOR PLAYER LAST NAME
		printf("Enter player last name: \n");
		scanf("%s", last);
		//ASKS FOR PLAYER FIRST NAME
		printf("Enter player first name: \n");
		scanf("%s", first);

		aux_p->number = player_num;
		strcpy(aux_p->last_name, last);	
		strcpy(aux_p->first_name, first);
		aux_p->next = NULL;

		if(roster != NULL)
		{
			p = roster;

			while(p->next != NULL)
				p = p->next;
			
			p->next = aux_p;
			return roster;
		}
		else
			return aux_p;
	}
}

/* Function: find_player.
   Description: This function finds a player in the list.
   Parameters:
   		- roster (struct player): roster that contains all players.
*/ 

void find_player(struct player *roster)
{
	int player_num;

	//ASKS FOR PLAYER NUMBER USER WANTS TO FIND
	printf("Enter player number: \n");
	scanf("%i", &player_num);

	while(roster != NULL)
	{
		if(roster->number == player_num)
		{
			printf("Player name: %s, %s", roster->last_name, roster->first_name);
			break;
		}

		roster = roster->next;
	}
	
	if(roster == NULL)
		//PRINTS ERROR IF PLAYER DOES NOT EXIST
		printf("ERROR: This player does not exist.\n");

}

/* Function: printList.
   Description: This function prints a list with all players.
   Parameters:
   		- roster (struct player): roster that contains all players.
*/ 

void printList(struct player *roster)
{
	//PRINTS HEADER
	printf("Player number \t Last Name \t First Name\n");
	//PRINTS ALL PLAYERS
	while(roster != NULL)
	{
		printf("%i \t \t %s \t \t %s\n", roster->number, roster->last_name, roster->first_name);
		roster = roster->next;
	}
	
}

/* Function: clearList.
   Description: This function clears the list.
   Parameters:
   		- roster (struct player): roster that contains all players.
*/ 
void clearList(struct player *roster)
{
	struct player *p;

	while(roster != NULL)
	{
		p = roster;
		roster = roster->next;
		free(p);
	}

}


int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
 }
