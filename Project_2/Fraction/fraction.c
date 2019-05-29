/*     Project 2 - fraction.c    */
/* Name: Daniel Anzola Delgado */

/* This program calculates the result of two fractions and
   an operator. The program is able to recognize the following
   operators: add (+), subtract (-), multiply (*), and divide (/).
   The format of the input should be: a/b operator c/d.            */

#include <stdio.h>

int main(void)
{
	/* VARIABLES */
	int a,b,c,d,denominator;
	char operator;

	// ASKS USER FOR INPUT
	printf("Enter two fractions separated by an operator (+, -, *, or /): ");
	
	// SCAN INPUT: VARIABLES a, b, c, d (integer) and operator (char)
	scanf("%d/%d %c %d/%d",&a,&b,&operator,&c,&d);
			
	switch(operator)
	{
		// CASE ADD
		case '+' :
		
			// CASE WHEN DENOMINATORS ARE EQUAL
			if(b == d)			
				printf("Result: %d/%d\n",(a+c),b);
			// CASE WHEN DENOMINATORS ARE NOT EQUAL
			else
			{
				denominator = b * d;
				printf("Result: %d/%d\n",( ( (denominator / b) * a) + ( (denominator / d) * c) ),denominator);
			}
			break;
	
		// CASE SUBTRACT
		case '-' :
			// CASE WHEN DENOMINATORS ARE EQUAL
			if(b == d)
				printf("Result: %d/%d\n",(a-c),b);
			// CASE WHEN DENOMINATORS ARE NOT EQUAL
			else
			{
				denominator = b * d;
				printf("Result: %d/%d\n",( ( (denominator / b) * a) - ( (denominator / d) * c) ),denominator);
			}
			break;

		// CASE MULTIPLY
		case '*' :
			printf("Result: %d/%d\n",(a*c),(b*d));
			break;

		// CASE DIVIDE
		case '/' :
			printf("Result: %d/%d\n",(a*d),(b*c));
			break;

		// CASE DEFAULT - PRINTS ERROR WHEN USER INPUTS AN INVALID OPERATOR
		default:
			printf("Error: Invalid operator\n");
			break;

	}
	
	return 0;
}
