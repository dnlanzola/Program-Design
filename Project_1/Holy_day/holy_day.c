/*   Project 1 - Holy_Day.c    */
/* Name: Daniel Anzola Delgado */

/* This program calculates the due date for assignments
   it will take into consideration the holy days and
   will print a corrected due date if necessary.        */

#include <stdio.h>

int main(void)
{
	/* VARIABLES */
	int today, dueDays, option;
	int error = 0;
	
	// ASKS USER TO ENTER DAY OF THE WEEK
	printf("Enter today's day of the week\n");
	printf("0 - Sunday\n1 - Monday\n2 - Tuesday\n3 - Wednesday\n4 - Thursday\n5 - Friday\n6 - Saturday\n");
	printf("\nSelected day: ");
	// SCAN DAY OF THE WEEK
	scanf("%d",&today);

	// CHECK IF THE DAY ENTERED BY USER IS IN THE RANGE BETWEEN 0 AND 6
	if(today < 0 || today > 6)
		error = 1;

	// IF THE DAY ENTERED BY USER IS VALID IT WILL PROCEED WITH THE PROGRAM
	if (error == 0)
	{
		//ASK USER FOR DAYS FOR DUE DATE OF ASSIGNMENT
		printf("\nEnter number of days for due date of assignment: ");
		// SCAN DAYS FOR DUE DATE
		scanf("%d",&dueDays);

		// THIS CALCULATION WILL GIVE THE DAY OF DUE DATE
		option = (today + dueDays)%7;

		switch(option)
		{
			// SUNDAY - IT WILL ADD AN EXTRA DAY
			case 0:
				printf("\nThe work is due Monday. Number of days needed for assignment: %d\n",(dueDays+1));
				break;
		
			// MONDAY
			case 1:
				printf("\nThe work is due Monday. Number of days needed for assignment: %d\n",dueDays);
                                break;
		
			// TUESDAY
			case 2:
                               	printf("\nThe work is due Tuesday. Number of days needed for assignment: %d\n",dueDays);
                                break;

			// WEDNESDAY
			case 3:
                               	printf("\nThe work is due Wednesday. Number of days needed for assignment: %d\n",dueDays);
                                break;

			// THURSDAY
			case 4:
                               	printf("\nThe work is due Thursday. Number of days needed for assignment: %d\n",dueDays);
                                break;

			// FRIDAY - IT WILL ADD 3 EXTRA DAYS
			case 5:
				printf("\nThe work is due Monday. Number of days needed for assignment: %d\n",(dueDays+3));
				break;

			// SATURDAY - IT WILL ADD 2 EXTRA DATS
			case 6:
				printf("\nThe work is due Monday. Number of days needed for assignment: %d\n",(dueDays+2));
				break;

		}
	}
	// IF THE DAY ENTERED BY USER IS NOT VALID IT WILL PRINT ERROR
	else
		printf("\nError\n");

	return 0;
}
