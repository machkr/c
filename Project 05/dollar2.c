// Programmer: Matthew Kramer
//
// Program: Project 5 - dollar2.c
//
// Description: Calculates and makes change for a 
//				user-input amount of money, using pointers.
//
// Course: Program Design - COP 3514, Section 003

//Initializes standard input/output method
#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)					//'pay_amount' function calculates smallest number of each bill needed using pointers as arguments
{
	*twenties = (dollars / 20);
	dollars = (dollars % 20);

	*tens = (dollars / 10);
	dollars = (dollars % 10);

	*fives = (dollars / 5);
	dollars = (dollars % 5);

	*ones = dollars;
}


int main(void)
{
	int dollars;																				//Declarations of integer variables used in program
	int twenties;
	int tens;
	int fives;
	int ones;

	printf("Please enter the amount of U.S. Dollars to be processed: ");						//Asks for, and scans in, the number of dollars to be processed by the program
	scanf("%d", &dollars);

	if(0 > dollars || dollars > 1000000000)														//Simple if-check for negative/zero/excessively large dollar amounts
	{
		printf("You have entered the invalid amount of %d dollars. \n", dollars);
		printf("Please enter a number between zero and one billion, inclusive. \n");
		return 0;
	}

	pay_amount(dollars, &twenties, &tens, &fives, &ones);										//Call for the 'pay_amount' function, using the address of the bills as arguments

	printf("The simplest way to make change for $%d is: \n", dollars);							//Prints results using (largely unnecessary) if-checks for proper grammar

	if(twenties == 1)
	{
		printf("%d Twenty Dollar Bill \n", twenties);
	}
		else
		{
			printf("%d Twenty Dollar Bills \n", twenties);
		}

	if(tens == 1)
	{
		printf("%d Ten Dollar Bill \n", tens);
	}
		else
		{
			printf("%d Ten Dollar Bills \n", tens);
		}

	if(fives == 1)
	{
		printf("%d Five Dollar Bill \n", fives);
	}
		else
		{
			printf("%d Five Dollar Bills \n", fives);
		}

	if(ones == 1)
	{
		printf("%d One Dollar Bill \n", ones);
	}
		else
	 	{
			printf("%d One Dollar Bills \n", ones);
		}

	return 0;																					//Ends program
}