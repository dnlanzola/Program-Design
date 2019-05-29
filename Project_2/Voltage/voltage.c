/*     Project 2 - voltage.c    */
/* Name: Daniel Anzola Delgado */

/* This program calculates the voltage across the
   capacitor at time t.                           */

#include <stdio.h>
#include <math.h>

/* CONSTANTS */

#define V 10
#define R 3000
#define C 50*pow(10,-6)
#define T 0.15
#define INCREMENT 0.06666666666667

int main()
{
	/* VARIABLES */
	float t, result;
	
	// PRINT HEADER
	printf("Time (sec)      Voltage\n");
	
	// LOOP - FROM 0 TO 1 WITH INCREMENTS OF 1/15
	for (t = 0; t <= 1; t = t + INCREMENT)
	{	
		// FORMULA TO CALCULATE THE VOLTAGE ACROSS THE CAPACITOR
		// AT TIME "t"
		result = V * (1 - exp(-t/T));
		
		// PRINTS TIME AND RESULT 
		printf("   %.2f          %.2f\n",t,result);	
	}
		
	return 0;
}
