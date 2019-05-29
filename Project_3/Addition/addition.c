/*     Project 3 - addition.c    */
/* Name: Daniel Anzola Delgado */

/* This program  takes two numbers as input and display the addition of them
   using only recursion.  */

#include <stdio.h>

int add(int m, int n);

int main() 
{
	/* VARIALES */
	int n1, n2;

	// ASKS USER THE TWO NUMBERS
	printf("Enter the two numbers: \n");
	// SCANS THE TWO NUMBERS
	scanf("%d%d", &n1, &n2);

	// PRINTS RESULT
	printf("Result = %d\n", add(n1, n2));

	return 0;
}


int add(int n, int m) 
{
	// IF M IS A NEGATIVE NUMBER
	if (m < 0)
		return add(--n, ++m);

	// IF M IS EQUAL TO 0 - THIS CASE IS WHEN M IS A POSITIVE NUMBER
	if (m == 0)
		return n;
	else
		return add(++n, --m);
}