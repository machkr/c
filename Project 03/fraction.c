// Programmer: Matthew Kramer
//
// Program: Project 3 - Fraction.c
//
// Description: Takes two user-inputted fractions and an
//              operation and calculates the result.
//
// Course: Program Design - COP 3514, Section 003

//Initializes standard input/output method
#include <stdio.h>

int main(void)
{
	//Declares necessary variables; integers for the numerators and denominators of the fractions,
	//and a character variable for the operator.
        int num1;
        int num2;
	int num3;
        int den1;
        int den2;
	int den3;
        char oprtr;

	//Asks for and reads in the two fractions and operation to be used in the calculation
        printf("Please input two fractions separated by the arithmetic operation to be completed: ");
	scanf("%d/%d %c %d/%d", &num1, &den1, &oprtr, &num2, &den2);

	//Switch statement to carry out the given process for the input operation; the process
	//being calculating the numerator and denominator of the result, then printing it. If the
	//operator doesn't match one of the required arithmetic operations, it prints an error
	//message and ends the program.
	switch (oprtr)
	{
	        case '+':
			num3 = (num1 * den2) + (num2 * den1);
			den3 = (den1 * den2);
			printf("The sum of %d/%d and %d/%d is %d/%d.\n", num1, den1, num2, den2, num3, den3);
			break;

		case '-':
			num3 = (num1 * den2) - (num2 * den1);
			den3 = (den1 * den2);
			printf("The difference of %d/%d and %d/%d is %d/%d.\n", num1,den1, num2, den2, num3, den3);
			break;

		case '*':
			num3 = (num1 * num2);
			den3 = (den1 * den2);
                        printf("The product of %d/%d and %d/%d is %d/%d.\n", num1, den1, num2, den2, num3, den3);
			break;

		case '/':
			num3 = (num1 * den2);
			den3 = (num2 * den1);
                        printf("The quotient of %d/%d and %d/%d is %d/%d.\n", num1, den1, num2, den2, num3, den3);
			break;

		default:
			printf("Error: you have entered an invalid operation.\n");
	}

	return 0;

}
