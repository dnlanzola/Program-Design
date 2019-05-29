/*     Project 11 - sort_commands.c    */
/* Name: Daniel Anzola Delgado */

/* This program sorts a series of words as 
   command-line arguments.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_compare (const void * a, const void * b);

int main(int argc, char *argv[])
{
	int i = 0;
	int len = argc - 1;
	char *words[len];

	//COPIES ELEMENTS FROM COMMAND LINE
	while(i < len)
	{
		words[i]=argv[i+1];
		i++;
	}

	//SORTS WORDS
	qsort(words, len, sizeof(char *), string_compare);
	
	//PRINTS SORTED WORDS
	i=0;
	while(i < len)
	{
		printf("%s ",words[i]);
		i++;
	}	
	return 0;

}

int string_compare (const void * a, const void * b)
{
	return strcmp(*(char **)a, *(char**)b);
}
