#include <stdio.h>
#include <string.h>

#define STR_LEN 1000

void merge(char *s3, char *s1, char *s2);
int read_line(char *str, int n);

int main()
{
	char s1[STR_LEN], s2[STR_LEN], s3[STR_LEN];
	int s1_len, s2_len;
	
	// READS FIRST SET OF CHARACTERS
	printf("Enter the first set of characters: ");	
	s1_len = read_line(s1, STR_LEN);
	
	// READS SECOND SET OF CHARACTERS
	printf("Enter the second set of characters: ");
	s2_len = read_line(s2, STR_LEN);

	// CALLS MERGE FUNCTION
	merge(s3,s1,s2);

	// PRINTS OUTPUT
	printf("\nOutput: %s \n", s3);

	return 0;
}

int read_line(char *str, int n) 
{           
	int ch; 
	int i = 0;
          
    while ((ch = getchar()) != '\n')           
    {  
    	if (i < n)              
    		{ 
    			*str++= ch;
      			i++;              
      		}   
    }           
    
    *str = '\0';   /* terminates string */           
    
    return i;        /* number of characters stored */ 
}

/* Function: merge.
   Description: the function will merge the two set of characters. 
   Parameters:
   		- *s1 (char): pointer.
   		- *s2 (char): pointer.
   		- *s3 (char): pointer.
*/ 
void merge(char *s3, char *s1, char *s2) 
{
	int i = 0;
	int j = 0;
    
	for (i = 0; i < STR_LEN; i++) 
	{
		// IF LAST ELEMENT OF S1 IS NULL, FILLS THE REST OF S3 WITH S2
		if (*s1 == '\0') 
		{
			for (j = i; j < STR_LEN; j++) 
			{
				*(s3 + j) = *s2;
				s2++;
			}
			break;
		}
      
		// IF LAST ELEMENT OF S2 IS NULL, FILLS THE REST OF S3 WITH S1
		if (*s2 == '\0') 
		{
			for (j = i; j < STR_LEN; j++) 
			{
				*(s3 + j) = *s1;
				s1++;
			}
			break;
		}
      
		// IF POSITION IS EVEN S1 GOES INTO S3
		if (i % 2 == 0) 
		{
			*(s3 + i) = *s1;
			s1++;
		}
		// IF POSITION IS ODD S2 GOES INTO S3
		else 
		{
			*(s3 + i) = *s2;
			s2++;
		}
	}
}
