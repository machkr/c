// Programmer: Matthew Kramer
//
// Program: Project 1 - Dollar.c
//
// Description: Calculates and makes change for a user-input amount of money
//
// Course: Program Design - COP 3514, Section 003

//Initializes standard input/output method
#include <stdio.h>

int main(void)
{
	//Defines integer variables for program
	int dollars;
	int remainingDollars;
	int twenties;
	int tens;
	int fives;
	int ones;

	//Asks for, and scans in, the number of dollars
	printf("Please enter the amount of U.S. Dollars to be processed: ");
	scanf("%d", &dollars);

	//Simple if-check for negative/zero/large dollar amounts
	if(0 > dollars || dollars > 1000000000)
	{
	  printf("You have entered the invalid amount of %d dollars. \n", dollars);
	  printf("Please enter a number between zero and one billion, inclusive. \n");
	  return 0;
	}

	//Calculates smallest number of each bill needed, keeps track of remaining dollars
	twenties = (dollars / 20);
	remainingDollars = (dollars % 20);
	tens = (remainingDollars / 10);
	remainingDollars = (remainingDollars % 10);
	fives = (remainingDollars / 5);
	remainingDollars = (remainingDollars % 5);
	ones = remainingDollars;

	//Prints results using (unnecessary) if checks for proper grammar
	printf("The simplest way to make change for $%d is: \n", dollars);

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

	//Ends program
	return 0;
}
