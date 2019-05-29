/*     Project 11 - roster.c    */
/* Name: Daniel Anzola Delgado */

/*This program maintains a roster for a sports team. 
Each player has a last name, first name, and a number. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "readline.h"
#include "player.h"

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
	  ", p for printing the roster d for deleting from roster; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
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
      case 'd': team_roster = delete_from_list(team_roster);
      			break;
      case 'q': clearList(team_roster);
		return 0;

      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}





