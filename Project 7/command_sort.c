// Programmer: Matthew Kramer
//
// Program: Project 6 - command_sort.c
//
// Description: Sorts command-line arguments
//
// Course: Program Design - COP 3514, Section 003

#include <stdio.h>                                                      //Initialization of standard input/output library
#include <string.h>                                                     //Initialization of string library
#include <stdlib.h>                                                     //Initialization of standard library
#define N 10                                                            //Macro definition of N as 10

void sort_asc(int *a, int n);                                           //Declaration of 'sort_asc' function
void sort_des(int *a, int n);                                           //Declaration of 'sort_des' function
int *find_largest(int *a, int n);                                       //Declaration of 'find_largest' function
int *find_smallest(int *a, int n);                                      //Declaration of 'find_smallest' function
void swap(int *p, int *q);                                              //Declaration of 'swap' function

int main(int argc, char *argv[])
{
	int i;                                                              //Declaration of integer i for use in for loops         
	int a[N + 1];                                                       //Declaration of array 'a' of length 'N + 1' (to account for null character) for use in place of argv[]

	for(i = 0; i < N; i++)                                              //For loop to enter the elements of argv[] into a[]
	{
		*(a + i) = atoi(argv[i + 2]);
	}

	if(strcmp(argv[1], "-a") == 0)                                      //If the command line argument is '-a'
	{
		sort_asc(a, N);                                                 //Call the 'sort_asc' function
		printf("Here is the set of integers, in ascending order: ");    //And print the results
		for(i = 0; i < N; i++)
    	{
        	printf("%d ", *(a + i));
    	}
    	printf("\n");
	}
	else if(strcmp(argv[1], "-d") == 0)                                 //If the command line argument is '-d'
	{
		sort_des(a, N);                                                 //Call the 'sort_des' function
		printf("Here is the set of integers, in descending order: ");   //And print the results
		for(i = 0; i < N; i++)
    	{
        	printf("%d ", *(a + i));
    	}
    	printf("\n");
	}
	else                                                                //Otherwise, if neither '-a' or '-d' is found
	{
		printf("You have entered an invalid argument.\n");              //Print a statement saying so
	}

	return 0;
}


void sort_asc(int *a, int n)                              		        //'sort_asc' provides the sorting functionality, calling the other two functions in the process
{

    int *largest = find_largest(a, n);                                  //Declaration and assignment of pointer integer 'largest' as the result of the 'find_largest' function

    if(n == 1)                                                          //Condition to break the recursive calling of the function
    {
        return;
    }

    if(largest < a + (n - 1))                                           //If the address of the largest element in the array isn't at the end
    {
        swap(a + (n - 1), largest);                                     //Make it so it is
    }

    sort_asc(a, n - 1);                                   		        //Call the function recursively, reducing the bounds (n) by one
}


void sort_des(int *a, int n)                              		        //'sort_des' provides the sorting functionality, calling the other two functions in the process
{

    int *smallest = find_smallest(a, n);                                //Declaration and assignment of pointer integer 'smallest' as the result of the 'find_largest' function

    if(n == 1)                                                          //Condition to break the recursive calling of the function
    {
        return;
    }

    if(smallest < a + (n - 1))                                          //If the address of the smallest element in the array isn't at the end
    {
        swap(a + (n - 1), smallest);                                    //Make it so it is
    }

    sort_des(a, n - 1);                                   		        //Call the function recursively, reducing the bounds (n) by one
}


int *find_largest(int *a, int n)                                        //'find_largest' returns the largest value of a set of elements
{

    int *max = a;                                                       //Declaration and assignment of pointer integer 'max' to the first element of the set
    int *p;                                                             //Declaration of pointer integer 'p' for use in the 'for' loop

    for(p = a; p < (a + n); p++)                                        //'For' loop that processes the elements in the set one by one
    {
        if(*p > *max)                                                   //If the current element's value is greater than the current max element's value
        {
            max = p;                                                    //Make the address of the max value the address of the current element
        }
    }

    return max;                                                         //Return 'max'

}


int *find_smallest(int *a, int n)                                       //'find_smallest' returns the smallest value of a set of elements
{

    int *min = a;                                                       //Declaration and assignment of pointer integer 'max' to the first element of the set
    int *p;                                                             //Declaration of pointer integer 'p' for use in the 'for' loop

    for(p = a; p < (a + n); p ++)                                       //'For' loop that processes the elements in the set one by one             
    {
        if(*p < *min)                                                   //If the current element's value is less than the current min element's value
        {
            min = p;                                                    //Make the address of the min value the address of the current element
        }
    }

    return min;                                                         //Return 'max'
}


void swap(int *p, int *q)                                               //'swap' function swaps two pointers
{

    int temp = *p;                                                      //Declaration and assignment of integer 'temp' to hold first swapped value
    *p = *q;                                                            //First swapped pointer is assigned the value of the second swapped pointer
    *q = temp;                                                          //Second swapped pointer is assigned the value of 'temp'

}