/*     Project 5 - fraction.c    */
/* Name: Daniel Anzola Delgado */

/* This program calculates the result of two fractions and
   an operator. The program is able to recognize the following
   operators: add (+), subtract (-), multiply (*), and divide (/).
   This program will automatically print the result in its reduced
   form.
   The format of the input should be: a/b operator c/d.            */
   
   
#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);
int find_gcd(int m, int n);

int main(void)
{
	/* VARIABLES */
	int num1, denom1, num2, denom2, result_num, result_denom;
	char operator;

	// ASKS USER FOR INPUT
	printf("Enter two fractions separated by a +, -, * or / sign: ");
	// SCANS INPUT
	scanf("%d/%d %c%d/%d", &num1, &denom1, &operator, &num2, &denom2);

	switch (operator) 
	{
		case '+':
			result_num = num1 * denom2 + num2 * denom1;
			result_denom = denom1 * denom2;     
      		// CALLS FUNCTION reduce
			reduce(result_num, result_denom, &result_num, &result_denom);
			printf("The sum is %d/%d\n", result_num, result_denom); 
                 
			break;
			
		case '-':
			result_num = num1 * denom2 - num2 * denom1;
			result_denom = denom1 * denom2;
      		// CALLS FUNCTION reduce
			reduce(result_num, result_denom, &result_num, &result_denom);
			printf("The difference is %d/%d\n", result_num, result_denom);
      
			break;
			
		case '*':
			result_num = num1 * num2;
			result_denom = denom1 * denom2;
      		// CALLS FUNCTION reduce
			reduce(result_num, result_denom, &result_num, &result_denom);      
			printf("The product is %d/%d\n", result_num, result_denom);
      
			break;
			
		case '/':
			result_num = num1 * denom2;
			result_denom = denom1 * num2;
      		// CALLS FUNCTION reduce
			reduce(result_num, result_denom, &result_num, &result_denom);
			printf("The quotient is %d/%d\n", result_num, result_denom);

			break;
			
		default:
			printf("Unrecognized operator: %c\n", operator);
	}

	return 0;
}


/* Function: find_gcd.
   Description: computes the GCD (greatest common divisor) of the numerator 
   and denominator.
   Parameters:
   		- m (int): represents the numerator.
   		- n (int): represents the denominator.
*/ 
int find_gcd(int m, int n)
{
	if(n == 0) return m;

	return find_gcd(n, m%n);
}

/* Function: reduce.
   Description: it reduces the fraction to lowest terms. 
   Parameters:
   		- numerator (int): represents the numerator of a fraction.
   		- denominator (int): represents the denominator of a fraction.
   		- reduced_numerator (*int): points to result_num.
   		- reduced_denominator (*int): points to result_denom.
*/ 
void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
	int greatest;
   
	greatest = find_gcd(numerator, denominator);
  
	*reduced_numerator = numerator/greatest;
	*reduced_denominator = denominator/greatest;  
}



