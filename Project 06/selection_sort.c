// Programmer: Matthew Kramer
//
// Program: Project 6 - selection_sort.c
//
// Description: Sorts user-input array
//
// Course: Program Design - COP 3514, Section 003

//Initializes standard input/output method
#include <stdio.h>                                              //Initialization of standard input/output method
#define N 10                                                    //Macro definition of N as 10

void selection_sort(int *a, int n);                             //Declaration of 'selection_sort' function
int *find_largest(int *a, int n);                               //Declaration of 'find_largest' function
void swap(int *p, int *q);                                      //Declaration of 'swap' function

int main(void)                                                  //'main' function
{

    int i;                                                      //Declaraton of integer 'i' for use in 'for' loops
    int a[N];                                                   //Declaration of array 'a' with length 'N'

    printf("Please enter %d numbers to be sorted:\n", N);       //Asks for and reads in the elements to be sorted
    for(i = 0; i < N; i++)
    {
        scanf("%d", a + i);
    }

    selection_sort(a, N);                                       //Calls the 'selection_sort' function

    printf("Here is the sorted set: ");                         //Prints the results of the 'selection_sort' function
    for(i = 0; i < N; i++)
    {
        printf("%d ", *(a + i));
    }
    printf("\n");

    return 0;                                                   //End of 'main' function

}

void selection_sort(int *a, int n)                              //'selection_sort' provides the sorting functionality, calling the other two functions in the process
{

    int *largest = find_largest(a, n);                          //Declaration and assignment of pointer integer 'largest' as the result of the 'find_largest' function

    if(n == 1)                                                  //Condition to break the recursive calling of the function
    {
        return;
    }

    if(largest < a + (n - 1))                                   //If the address of the largest element in the array isn't at the end
    {
        swap(a + (n - 1), largest);                             //Make it so it is
    }

    selection_sort(a, n - 1);                                   //Call the function recursively, reducing the bounds (n) by one

}


int *find_largest(int *a, int n)                                //'find_largest' returns the largest value of a set of elements
{

    int *max = a;                                               //Declaration and assignment of pointer integer 'max' to the first element of the set
    int *p;                                                     //Declaration of pointer integer 'p' for use in the 'for' loop

    for(p = a; p < (a + n); p++)                                //'For' loop that processes the elements in the set one by one
    {
        if(*p > *max)                                           //If the current element's value is greater than the current max element's value
        {
            max = p;                                            //Make the address of the max value the address of the current element
        }
    }

    return max;                                                 //Return 'max'

}


void swap(int *p, int *q)                                       //'swap' function swaps two pointers
{

    int temp = *p;                                              //Declaration and assignment of integer 'temp' to hold first swapped value
    *p = *q;                                                    //First swapped pointer is assigned the value of the second swapped pointer
    *q = temp;                                                  //Second swapped pointer is assigned the value of 'temp'

}