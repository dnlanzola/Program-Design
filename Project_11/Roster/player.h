/*     Project 11 - player.h    */
/* Name: Daniel Anzola Delgado */

#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
struct player *delete_from_list(struct player*roster);


#endif