// Programmer: Matthew Kramer
//
// Program: Project 12 - sort_commands.c
//
// Description: Sorts command-line arguments alphabetically
//
// Course: Program Design - COP 3514, Section 003

#include <stdio.h>                                              //Initialization of standard input/output library
#include <string.h>                                             //Initialization of string library
#include <stdlib.h>                                             //Initialization of standard library
#define MAX 100                                                 //Macro definition of maximum number of words

int compare(const void *a, const void *b);                      //Prototype of 'compare' function

int main(int argc, char *argv[])                                //Main function, for processing command line arguments
{
	char *words[MAX + 1];                                       //Declaration of array to store words
    int count = 0;                                              //Declaration of integer to track number of words
    int i;                                                      //Declaration of integer for loop-processing

    for(i = 1; i < argc; i++, count++)                          //Processes each command line argument, one at a time
    {
        words[count] = malloc(strlen(argv[i]) + 1);             //Allocate memory for the word to be entered
        strcpy(words[i - 1], argv[i]);                          //Copy word into the array
    }

    qsort(words, count, sizeof(char *), compare);               //Call the 'qsort' function to do the sorting

    printf("\n");

    for(i = 0; i < count; i++)                                  //Print the array of words, one at a time
    {
        printf("%s ", words[i]);                                //Print the current word, with a space
        free(words[i]);                                         //And free that word's memory in the array
    }

    printf("\n\n");                                             //Unnecessary formatting things

    return 0;                                                   //Return 0
}

int compare(const void *a, const void *b)                       //'compare' function for two strings, used for 'qsort'
{
    return strcmp(*(char **)a, *(char **)b);                    //Return 'strcmp' value of these strings
}