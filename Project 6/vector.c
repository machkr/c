// Programmer: Matthew Kramer
//
// Program: Project 6 - vector.c
//
// Description: Provides two functions for user-input vectors
//
// Course: Program Design - COP 3514, Section 003

#include <stdio.h>													//Initialization of standard input/output method

void multi_vec (int *v1, int *v2, int *v3, int n);					//Declaration of 'multi_vec' function
int comp_vec(int *v1, int *v2, int n);								//Declaration of 'comp_vec' function

int main(void)														//'main' function
{

	int n;															//Declaration of integer 'n' for use as length of vectors
	int i;															//Declaration of integer 'i' for use in 'for' loops

	printf("\nPlease enter the length of the two vectors: ");		//Asks for and reads in the length of the two vectors, stores it in 'n'
	scanf("%d", &n);

	int v1[n];														//Declaration of three arrays - one for each vector
	int v2[n];
	int v3[n];

	printf("Please enter the first vector's components: ");			//Asks for and reads in the first vector's components
	for(i = 0; i < n; i++)
	{
		scanf("%d", v1 + i);
	}

	printf("Please enter the second vector's components: ");		//Asks for and reads in teh second vector's components
	for(i = 0; i < n; i++)
	{
		scanf("%d", v2 + i);
	}

	multi_vec(v1, v2, v3, n);										//Calls function 'multi_vec'

	printf("\nThe product of the two vectors is [%d", *v3);			//Prints the results of the 'multi_vec' function, vector 3
	for(i = 1; i < n; i++)
	{
		printf(", %d", *(v3 + i));
	}
	printf("].\n");

	if(comp_vec(v1, v2, n) == 1)									//If the result of 'comp_vec' is 1 (vectors were equivalent)
	{
		printf("The vectors are equivalent.\n\n");					//Print that fact
	}
	else															//Otherwise...
	{
		printf("The vectors are not equivalent.\n\n");				//Print that they weren't equivalent
	}

	return 0;														//End of 'main' function
	
}

void multi_vec (int *v1, int *v2, int *v3, int n)					//'multi_vec' multiplies the corresponding components of the two vectors
{
	int i;															//Declaration of integer 'i' for use in 'for' loop

	for(i = 0; i < n; i++)											//'For' loop that runs through the vectors, element by element, until the end is reached
	{
		*(v3 + i) = (*(v1 + i)) * (*(v2 + i));						//The component 'i' in vector 3 is equal to component 'i' of vector 1 multiplied by component 'i' of vector 2

	}
}

int comp_vec(int *v1, int *v2, int n)								//'comp_vec' compares the corresponding components of the two vectors
{
	
	int result;														//Declaration of integer 'result'
	int i;															//Declrration of integer 'i' for use in 'for' loop

	for(i = 0; i < n; i++)											//'For' loop that runs through the vectors, element by element, until the end is reached
	{
		if(*(v1 + i) == *(v2 + i))									//If component 'i' of vector 1 is equivalent to component 'i' of vector 2...
		{
			result = 1;												//'Result' = 1 (True)
		}
		else														//Else...
		{
			result = 0;												//'Result' = 0 (False)
			break;													//Break the 'for' loop
		}
	}

	return result;													//Return result, either 1 or 0

}