/*     Project 11 - readline.c    */
/* Name: Daniel Anzola Delgado */

#include "readline.h"

/**********************************************************
 *  read_line: Skips leading white-space characters, then  *
 * 	       reads the remainder of the input line and   *
 *             stores it in str. Truncates the line if its *
 *             length exceeds n. Returns the number of     *
 *             characters stored.                          *
 ***********************************************************/

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