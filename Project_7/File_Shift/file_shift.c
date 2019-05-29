/*     Project 7 - selection_sort.c    */
/* Name: Daniel Anzola Delgado */

/* This program prompts the user to enter the name of a file 
    for the content to be shifted.  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_1 100
#define SIZE_2 10000

void shift(char *message,int shift_amount);

int main()
{
	/* VARIABLES */
	FILE *inputFile, *outputFile;
	char inputFileName[SIZE_1] = "";
	char outputFileName[SIZE_1] = "";
	char line[SIZE_2];
	char fileExtension[] = ".sft";
	int shift_number;
	
	//SCANS FILE NAME
	printf("Enter file name: ");
	scanf("%s", inputFileName);
	
	//SCANS SHIFT AMOUNT
	printf("Enter shift amount: ");
	scanf("%d", &shift_number);
	
	//ADDS EXTENSION ".stf" TO THE FILE NAME
	strcat(outputFileName, inputFileName);
	strcat(outputFileName, fileExtension);
	
	//OPEN FILES
	inputFile = fopen(inputFileName, "r");
	outputFile = fopen(outputFileName, "w");
	
	if (inputFile != NULL)
	{
		// OBTAINS FIRST LINE
		fgets(line, SIZE_2, inputFile);
		
		//WHILE NOT END OF FILE
		while (!feof(inputFile))
		{
			shift(line, shift_number);
			fprintf(outputFile, "%s", line);
			fgets(line, SIZE_2, inputFile);
		}

	}
	
	//CLOSES FILES
	fclose(inputFile);
	fclose(outputFile);
	
	return 0;
}

/* Function: shift.
   Description: The function expects message to point to a string 
                containing the message to be shifted.
   Parameters:
   		- *message (char): pointer to the message.
   		- shift_amount (int): represents the amount by which each 
   							 letter in the message to be shifted.
*/ 
void shift(char *message, int shift_amount)
{
	int i = 0;
	char letter = message[i];

	while (letter != '\0') 
	{
		if (letter >= 'A' && letter <= 'Z')
			letter = 'A' + (((letter - 'A') + shift_amount + 26) % 26);
		
		if (letter >= 'a' && letter <= 'z')
			letter = 'a' + (((letter - 'a') + shift_amount + 26) % 26);

		message[i] = letter;
		i++;
		letter = message[i];
	}
}

