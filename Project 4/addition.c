// Programmer: Matthew Kramer
//
// Program: Project 4 - addition.c
//
// Description: Finds the sum of two user-input
//				integers through the use of recursion
//
// Course: Program Design - COP 3514, Section 003

//Note: comments are located to the right of the program

#include <stdio.h>														//Initializes standard input/output method

int add(int x, int y, int z);											//Declaration of the 'add' function

int main()																//'main' function that will carry out the top layer of the program
{
	int x = 0;															//Declaration of the necessary variables, x and y for the addends, z for the sum
	int y = 0;
	int z = 0;

	printf("\nPlease enter any two integers, separated by a space: ");	//Asks for and reads in the user-input integers used within the add function
	scanf("%d %d", &x, &y);

	printf("The sum of %d and %d is %d.\n\n", x, y, add(x, y, z));		//Prints the results of the program, calling the add function for the sum

	return 0;															//'return 0', as this is the main function
}

int add(int x, int y, int z)											//'add' function that will carry out the calculation behind the main function, recursively
{

	if(y > 0)															//If the second addend is greater than zero (a positive integer)
	{
		while(y != 0)													//Then, until it equals zero as a result of the following decrement,
		{
			z = add(++x, --y, z);										//The result is equal to the add function called recursively with the parameter x incremented and y decremented
		}																			
		return z;														//Returns the result, integer 'z'
	}

	else if(y < 0)														//Else if the second addend is less than zero (a negative integer)
	{
		while(y != 0)													//Then, until it equals zero as result of the following increment,
		{
			z = add(--x, ++y, z);										//The result is equal to the add function called recursively with the parameter x decremented and y incremented
		}
		return z;														//Returns the result, integer 'z'
	}

	else if(y == 0)														//Else if the second addend is zero
	{
		z = x;															//Then the result is equal to whatever the first addend is

		return z;														//Returns the result, integer 'z'
	}

	return 0;															//Fallback, 'return 0'
}