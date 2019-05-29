/*     Project 5 - selection_sort.c    */
/* Name: Daniel Anzola Delgado */

/* This program multiplies two vectors
   of given size "length". It also compares                
   if the vectors are equal.              */

#include <stdio.h>
#define N 10

void selection_sort(int *a, int n);
int *find_largest(int *a, int n);
void swap(int *p, int *q);

int main(void)
{
  int i;
  int a[N];

  printf("Enter %d numbers to be sorted: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  selection_sort(a, N);

  printf("In sorted order:");
  for (i = 0; i < N; i++)
    printf(" %d", a[i]);
  printf("\n");

  return 0;
}


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

void swap(int *p, int *q) 
{
	int i = *p;
    *p = *q;
    *q = i;  
}






