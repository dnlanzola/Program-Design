/*     Project 5 - Dollar.c    */
/* Name: Daniel Anzola Delgado */

/* This program calculates how many bills of $20, $10, $5
   and $1 bills will the user need to pay.                
   This is a modified version of Project 1              */


#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main()
{
	/* VARIABLES */
	int dollar = 0, twenty = 0, ten = 0, five = 0, one =0;
	
	// ASK  USER TO ENTER AMOUNT
    printf("Enter a dollar amount:\n");
    // SCAN AMOUNT
	scanf("%d", &dollar);

	//CHECK THE RANGE OF THE INPUT AMOUNT
	if(dollar < 0 || dollar > 1000000000)
	    printf("Invalid amount %d,\nAmount must be between 0 and 1000000000, inclusive\n", dollar);
	    
	// IF THE AMOUNT ENTERED BY USER IS ACCEPTABLE IT WILL
	// PROCEED WITH CALCULATIONS
    else 
    {
    	// CALLS FUNCTION pay_amount
		pay_amount(dollar, &twenty, &ten, &five, &one);

		// PRINTS RESULT
		printf("$20 bills: %d\n", twenty);
	    printf("$10 bills: %d\n", ten);
     	printf("$5 bills: %d\n", five);
	    printf("$1 bills: %d\n", one);
	}
	
	return 0;
}

/* Function: pay_amount.
   Description: The function determines the smallest number of $20, $10, $5, and $1 
   bills necessary to pay the amount.
   Parameters:
   		- dollars (int): represents the total amount.
   		- twenties (*int): points to twenty.
   		- tens (*int): points to ten.
   		- fives (*int): points to five.
   		- ones (*int): points to one.
*/   		
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
		*twenties = dollars/20;
		*tens = (dollars - (*twenties * 20))/10;
		*fives = (dollars - (*twenties * 20) - (*tens * 10))/5;
		*ones = dollars - (*twenties * 20) - (*tens * 10) - (*fives * 5);
}





