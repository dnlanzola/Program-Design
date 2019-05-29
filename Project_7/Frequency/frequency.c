/*     Project 7 - frequency.c    */
/* Name: Daniel Anzola Delgado */

/* This program reads in a line of text and computes 
   the frequency of the words in the text.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_1 1000
#define SIZE_2 500

int read_line(char *str, int n);
int checkWord(char word[], char storedWords[][SIZE_2], int count);

int main()
{
	/* VARIABLES */
	//TEXT FROM USER
	char sentence[SIZE_1 + 1] = ""; 
	//STORE LIST OF WORDS
	char words[SIZE_1][SIZE_2];
	//STORE FREQUENCY OF WORDS
	int numberOfWords[SIZE_1];
	//COUNT CHARACTERS OF SENTENCE
	int numberOfChars = 0;
	//COUNT OF WORDS
	int countW = 0;
	char *pch;
	int i;
	int p;
	
	//SCANS SENTENCE FROM USER
	printf("Enter a sentence: ");
	numberOfChars = read_line(sentence, SIZE_1);
	
	//SEPARATES FIRST WORD
	pch = strtok(sentence,",.! ");
	
	while (pch != NULL)
	{
		//CHECKS IF WORD IS ALREADY STORED
		p = checkWord(pch, words, countW);
	
		//IF THE WORD IS NOT STORED
		if (p == -5)
		{
			strcpy(words[countW],pch);
			numberOfWords[countW] = 1;
			countW++;
		}
		else
			numberOfWords[p]++;
		
		pch = strtok(NULL,",.! ");
	}
	
	printf("Result:\n");
	
	for(i = 0; i < countW; i++)
		printf("%s      %d\n",words[i],numberOfWords[i]);
			
	return 0;
}


/* Function: checkWord.
   Description: The checks if the word is already stored in a vector.
   Parameters:
   		- word (char): word that was separated from the sentence.
   		- storedWords (char): vector of stored words.
   		- count (int): count of words. 
*/ 
int checkWord(char word[], char storedWords[][SIZE_2], int count)
{
	int i;
	
	for (i = 0; i < count; i++)
	{
		if(strcmp(word, storedWords[i]) == 0)
			return i;
	}
	
	return -5;
}


int read_line(char *str, int n) 
{           
	int ch; 
	int i = 0;
	
    while ((ch = getchar()) != '\n')           
    {  
    	if (i < n)              
    	{ 
    		*str++= ch;
      		i++;              
      	}   
    }           
    
    *str = '\0';   /* terminates string */           
    return i;        /* number of characters stored */ 
}