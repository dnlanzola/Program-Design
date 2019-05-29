/*     Project 5 - vector.c    */
/* Name: Daniel Anzola Delgado */

/* This program multiplies two vectors
   of given size "length". It also compares                
   if the vectors are equal.              */

#include <stdio.h>

void multi_vec(int *v1, int *v2, int *v3, int n);
int comp_vec(int *v1, int *v2, int n);

int main()
{
	int length,i;
	int *v1, *v2, *v3;
	int equal_vectors;
	
	printf("Enter length of vectors: ");
	scanf("%d", &length);

	int a[length], b[length], c[length];
	
	v1 = a;
	v2 = b;
	v3 = c;
	
	//ASK USER TO INPUT FIRST VECTOR
	printf("Enter first vector: ");
	//SCAN VECTOR
	for (i = 0; i < length; i++)
    	scanf("%d", &v1[i]);
    	
	//ASK USER TO INPUT SECOND VECTOR
	printf("Enter second vector: ");
	//SCAN VECTOR
	for (i = 0; i < length; i++)
    	scanf("%d", &v2[i]);
    
    //CALL multi_vec FUNCTION	
    multi_vec(v1, v2, v3, length);
    
    //PRINTS THE MULTIPLICATION OF VECTORS
    printf("The multiplication of vectors is: ");
    for (i = 0; i < length; i++)
    	printf(" %d", c[i]);
  	printf("\n");
    
    //CALL equal_vectors FUNCTION
    equal_vectors = comp_vec(v1, v2, length);
    
    //DEPENDING ON WHAT equal_vectors FUNCTION RETURNED
    //IT WILL PRINT IF THE VECTORS ARE EQUAL OR NOT.
    if (equal_vectors == 1)
    	printf("Vectors v1 and v2 are equal\n");
    else
    	printf("Vectors v1 and v2 are not equal\n");
    
    
	return 0;    	
}


/* Function: multi_vec.
   Description: The multi_vec function multiplies vectors v1 and v2 and stores the 
   result in v3. n is the length of the vectors. 
   Parameters:
   		- *v1 (int): points to vector a.
   		- *v2 (int): points to vector b.
   		- *v3 (int): points to vector c.
   		- n (int): represents the length of vectors.
*/ 
void multi_vec(int *v1, int *v2, int *v3, int n)
{
	int i;

	for(i = 0; i < n; i++)
		v3[i] = v1[i] * v2[i];
}

/* Function: comp_vec.
   Description: The comp_vec function compares v1 and v2, return 1 if vectors v1
   and v2 are equal (their corresponding components are equal), and 0 otherwise.
   Parameters:
   		- *v1 (int): points to vector a.
   		- *v2 (int): points to vector b.
   		- n (int): represents the length of vectors.
*/ 
int comp_vec(int *v1, int *v2, int n)
{
	int equal = 0;
	int i;
	
	for (i = 0; i < n; i++)
	{
		if (v1[i] == v2[i])
			equal = 1;
	}
	
	return equal;
}
