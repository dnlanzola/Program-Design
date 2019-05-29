/*     Project 8 - sort_boxes.c    */
/* Name: Daniel Anzola Delgado */

/* This program reads the file boxes.txt and sort the boxes by volume. 
   It saves the sorted boxes, including volumes, in a text file called
   sorted_boxes.txt. */

#include <stdio.h>
#include <stdlib.h>

//CONSTANT FOR THE VECTOR
#define LIMIT 100

struct box
{
	double length;
	double width;
	double height;
	double weight;
};

void selection_sort(struct box myBoxes[], int n);
double computeVolume(struct box a);

int main()
{
	/* VARIABLES */
	double len = 0;
	double wid = 0;
	double hei = 0;
	double wei = 0;
	
	int i = 0;
	int j = 0;
	
	struct box boxes[LIMIT];

	FILE *inputFile = fopen("boxes.txt", "r");
	FILE *outputFile = fopen("sorted_boxes.txt", "w");
	
	//SCANS DATA FROM TEXT FILE AND STORES IT IN A VECTOR
	if (inputFile != NULL)
	{
		while (!feof(inputFile))
		{
			fscanf(inputFile, "%lf, %lf, %lf, %lf\n", &len, &wid, &hei, &wei);
			boxes[j].length = len;
			boxes[j].width = wid;
			boxes[j].height = hei;
			boxes[j].weight = wei;
			
			j++;
		}
	}
	
	//PRINTS DATA BEFORE SORTING
   	printf("Before sorting:\n#\t  Length \t  Width \t  Height \t  Volume \t  Weight\n");
   	for(i = 0; i < j; ++i)
		printf("%d \t %.6f \t %.6f \t %.6f \t %.6f \t %.6f \n", i, boxes[i].length, boxes[i].width, boxes[i].height, computeVolume(boxes[i]), boxes[i].weight);
	
	//CALLS FUNCTION selection_sort TO SORT DATA
	selection_sort(boxes, j);
	
	//PRINTS DATA AFTER SORTING
	printf("\nAfter sorting:\n#\t  Length \t  Width \t  Height \t  Volume \t  Weight\n");
	for(i = 0; i < j; ++i)
		printf("%d \t %.6f \t %.6f \t %.6f \t %.6f \t %.6f \n", i, boxes[i].length, boxes[i].width, boxes[i].height, computeVolume(boxes[i]), boxes[i].weight);

	//SAVES SORTED DATA IN TEXT FILE
	fprintf(outputFile,"#\t  Length \t  Width \t  Height \t  Volume \t  Weight\n");
	for(i = 0; i < j; i++)
		fprintf(outputFile,"%d \t %.6f \t %.6f \t %.6f \t %.6f \t %.6f \n", i, boxes[i].length, boxes[i].width, boxes[i].height, computeVolume(boxes[i]), boxes[i].weight);
	
	//CLOSES FILES
	fclose(inputFile);
	fclose(outputFile);
	
	return 0;
}

/* Function: selection_sort.
   Description: The function sorts a vector with boxes.
   Parameters:
   		- myBoxes (struct box): vector that contain structures type box.
   		- n (int): represents the amount of boxes 
*/ 
void selection_sort(struct box myBoxes[], int n)
{
	int i = 0;
	int j = 0;
	int min = 0;
	
	struct box saveSwap;
	
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (computeVolume(myBoxes[j]) < computeVolume(myBoxes[min]))
				min = j;
		}
		
		//SWAPS BOX IN POSITION i WITH BOX IN POSITION min
		saveSwap = myBoxes[i];
		myBoxes[i] = myBoxes[min];
		myBoxes[min] = saveSwap;
	}
}

/* Function: computeVolume.
   Description: computes the volume of a box.
   Parameter:
   		- a (struct box): structure type box.
*/ 
double computeVolume(struct box a)
{
	double vol;
	
	vol = a.length * a.width * a.height;
	
	return vol;
}