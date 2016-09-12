// Programmer: Matthew Kramer
//
// Program: Project 9 - sort_boxes.c
//
// Description: Sorts a database of boxes input by
//				a text file of dimensions.
//
// Course: Program Design - COP 3514, Section 003

#include <stdio.h>                                                                                  //Initialization of standard input/output library
#include <string.h>                                                                                 //Initialization of string library
#include <stdlib.h>                                                                                 //Initialization of standard C library

#define MAX 100                                                                                     //Macro definition of MAX, the maximum number of boxes as well as characters in the 'contents' string

struct box                                                                                          //Definition of 'box' structure
{
    double length;
    double width;
    double height;
    double volume;
    double weight;
};

struct box myBoxes[MAX];                                                                            //Declaration of an array of 'box' structures, 'myBoxes'

void selection_sort(struct box myBoxes[], int n);                                                   //Declaration of prototype 'selection_sort' function

int main(void)
{
	int i;                                                                                          //Declaration of integer 'i' for use in for loops
    int count;                                                                                      //Declaration of integer 'count' for keeping track of the number of boxes

	FILE *instream;                                                                                 //Declaration of file pointer instream for input file
    FILE *outstream;                                                                                //Declaration of file pointer 'outstream' for output file

    if((instream = fopen("boxes.txt", "r")) == '\0')                                                //Opens the input file, while doing some error-checking
    {
        printf("\nThere was an error when opening the file. Please "                                //If there is an error when opening the file, print a message
            "make sure you have entered the filename correctly.\n\n");

        return 1;                                                                                   //And return 1
    }

    for(i = 0; fscanf(instream, "%lf, %lf, %lf, %lf", &myBoxes[i].length,                           //'for' loop to process the input file, scanning in the data to a structure in the array
        &myBoxes[i].width, &myBoxes[i].height, &myBoxes[i].weight) != EOF; i++)
    {
        if(ferror(instream))
        {
            printf("There was an error when reading the file. Please "                              //If there is an error when reading the file, print a message
                "make sure the file is not corrupted.\n\n");
            
            return 1;                                                                               //And return 1
        }

    	myBoxes[i].volume = (myBoxes[i].length * myBoxes[i].width * myBoxes[i].height);             //Calculates and inserts the volume of the box

        count++;                                                                                    //Increments count, for every box inputted
    }

    fclose(instream);                                                                               //Closes input stream

    selection_sort(myBoxes, count);                                                                 //Calls 'selection_sort' function, with arguments for our structure array and number of boxes

    if((outstream = fopen("sorted_boxes.txt", "w")) == '\0')                                        //Opens the output file, while doing some error-checking
    {
        printf("\nThere was an error opening the new file.\n\n");                                   //If there is an error when opening the file, print a message

        return 1;                                                                                   //And return 1
    }

    fputs("#\tLength\t\tWidth\t\tHeight\t\tVolume\t\tWeight\n\n", outstream);                       //Places the column headers in the newly created file

    for(i = 0; i < count; i++)                                                                      //'for' loop to print the data from each structure in the array
    {
        if(fprintf(outstream, "%d\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n\n", i, myBoxes[i].length, 
            myBoxes[i].width, myBoxes[i].height, myBoxes[i].volume, myBoxes[i].weight) == EOF)
        {
            printf("\nThere was an error when writing the new file.\n\n");                          //If there is an error when writing the file, print a message

            return 1;                                                                               //And return 1
        }
    }

    printf("\n'sorted_boxes.txt' was saved successfully.\n\n");                                     //Informs the user of the program's accomplishment

    fclose(outstream);                                                                              //Closes the output stream

    return 0;                                                                                       //Return 0
}

void selection_sort(struct box myBoxes[], int n)                                                    //'selection_sort' function sorts an array of box structures by volume
{
    int i;                                                                                          //Declaration of integer 'i' for use in 'for' loops
    int largest = 0;                                                                                //Declaration of integer 'largest' for index of largest value
    struct box temp;                                                                                //Declaration of temporary box structure 'temp'

    if(n == 1)                                                                                      //Stopping case
        return;

    for(i = 1; i < n; i++)                                                                          //'for' loop to find index of largest volume in the array
    {
        if(myBoxes[i].volume > myBoxes[largest].volume)
        {
            largest = i;        
        }
    }

    if(largest < n - 1)                                                                             //Swap the largest volume box with the last box
    {
        temp = myBoxes[n - 1];
        myBoxes[n - 1] = myBoxes[largest];
        myBoxes[largest] = temp;
    }

    selection_sort(myBoxes, n - 1);                                                                 //Calls 'selection_sort' recursively
}