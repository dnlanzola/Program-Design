/*     Project 1 - Dollar.c    */
/* Name: Daniel Anzola Delgado */

/* This program calculates how many bills of $20, $10, $5
   and $1 bills will the user need to pay.                */

#include <stdio.h>

int main(void)
{
	/* VARIABLES */
	int amount = 0;
	int bill20,bill10,bill5,bill1;
	int error = 0;

	// ASK  USER TO ENTER AMOUNT
	printf("Enter U.S. dollar amount: ");
	// SCAN AMOUNT
	scanf("%i", &amount);

	// CHECK IF AMOUNT IS LESS THAN 0 (NEGATIVE NUMBER)
	if (amount < 0)
		error = 1;

	// CHECK IF AMOUNT IS GREATER THAN 1 BILLION
	if (amount > 1000000000)
		error = 1;

	// IF THE AMOUNT ENTERED BY USER IS ACCEPTABLE IT WILL
	// PROCEED WITH CALCULATIONS
	if (error == 0)
	{
		/* CALCULATIONS */

		// $20 BILLS
		bill20 = amount / 20;
		// $10 BILLS
		bill10 = (amount % 20) / 10;
		// $5 BILLS
		bill5 = ((amount % 20) % 10) / 5;
		// $1 BILLS
		bill1 = (((amount % 20) % 10) % 5) / 1;
	
		// PRINT RESULTS
		printf("\n$20 = %i\n",bill20);
		printf("$10 = %i\n",bill10);
		printf("$5 = %i\n",bill5);
		printf("$1 = %i\n",bill1);
	}
	// IF THE AMOUNT ENTERED BY USER IS NOT ACCEPTABLE
	// IT WILL PRINT AN ERROR MESSAGE
	else
		printf("\nError\n");
	
	return 0;


}
