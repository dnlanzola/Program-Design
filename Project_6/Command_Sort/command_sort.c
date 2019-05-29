/*     Project 6 - command_sort.c    */
/* Name: Daniel Anzola Delgado */

/* This program sorts the elements of
   an array in ascending or descending order. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

void selection_sort(int *a, int n);
int *find_largest(int *a, int n);
void swap(int *p, int *q);
void selection_sort_d(int *a, int n);
int *find_smallest(int *a, int n);

int main(int argc, char *argv[])
{
	int values[SIZE];
	int i;
	int error = 0;

	// GETS VALUES FROM COMMAND
	for(i = 0; i < SIZE; i++)
		values[i] = atoi(argv[2 + i]);
	
	// ASCENDING ORDER
	if (strcmp(argv[1], "-a") == 0)
		selection_sort(values, SIZE);
	// DESCENDING ORDER
	else if (strcmp(argv[1], "-d") == 0)	
		selection_sort_d(values, SIZE);
	else
	{
		printf("Invalid option\n");
		error = 1;
	}
	
	// PRINTS OUTPUT
	if (error == 0)
	{
		printf("\n Output: ");
		for (i = 0; i < SIZE; i++)
			printf("%d ", values[i]);
	}

	
	return 0;
}

/* Function: selection_sort.
   Description: sorts elements of an array (a) in ascending order using the functions
   find_largest and swap.
   Parameters:
   		- *a (int): pointer.
   		- n (int): represents the length of vectors.
*/ 
void selection_sort(int *a, int n)
{
    int *p = a;
    int i;
    int j;

    if (n == 1)
		return;

    i = *(p + n - 1);
    j = *find_largest(a, n);
	swap(p + n - 1, find_largest(a, n));

	selection_sort(a, n - 1);
 }
 
 /* Function: selection_sort_d.
   Description: sorts elements of an array (a) in descending order using the functions
   find_largest and swap.
   Parameters:
   		- *a (int): pointer.
   		- n (int): represents the length of vectors.
*/ 
 
void selection_sort_d(int *a, int n)
{
    int *p = a;
    int i;
    int j;

    if (n == 1)
		return;

    i = *(p + n - 1);
    j = *find_smallest(a, n);
	swap(p + n - 1, find_smallest(a, n));

	selection_sort_d(a, n - 1);
 }

/* Function: find_largest.
   Description: the function will return a pointer to the array’s largest element. 
   Parameters:
   		- *a (int): pointer.
   		- n (int): represents the length of vectors.
*/ 
int *find_largest(int *a, int n)
{
    int *p = a;
	int *largest = p;

	for(p = a ; p < a + n - 1; p++) 
	{
		if ( *(p + 1) > *largest)
			largest = (p + 1);
	}
	
	return largest;
 }

/* Function: find_smallest.
   Description: the function will return a pointer to the array’s smallest element. 
   Parameters:
   		- *a (int): pointer.
   		- n (int): represents the length of vectors.
*/ 

int *find_smallest(int *a, int n)
{
    int *p = a;
	int *smallest = p;

	for(p = a ; p < a + n - 1; p++) 
	{
		if ( *(p + 1) < *smallest)
			smallest = (p + 1);
	}
	
	return smallest;
 }
/* Function: swap.
   Description: the function should exchange the values of the variables.
   Parameters:
   		- *p (int): pointer.
   		- *q (int): pointer.
*/ 
void swap(int *p, int *q) 
{
	int i = *p;
    *p = *q;
    *q = i;  
}
