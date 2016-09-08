// Programmer: Matthew Kramer
//
// Program: Project 2 - Voltage.c
//
// Description: Calculates the voltage across a capacitor
//		within a circuit, as time progresses.
//
// Course: Program Design - COP 3514, Section 003

//Initializes math library
#include <math.h>
#include <stdio.h>

int main(void)
{
	//Declares the variables (some unnecessary for this program):
	//constants using macro definition, decimals to be rounded as floats
	#define VOLTAGE 10
	#define TAU 0.15
	#define RESISTANCE 3000
	#define CAPACITANCE (50 * pow(10,-6))
	float capVoltage = 0.00;
	float time = 0.00;

	//Prints table header, moves cursor to next line
        printf("\nTime (seconds)     Voltage (volts)\n");

	//For loop that runs from time = 0 to time = 1, incrementing
	//by 1/15 each time. Each time the loop runs, it calculates
	//the voltage across the capactor at that time value, then
	//prints the current time value and voltage value, rounded
	//to two decimal places.
	for(;time <= 1.00; time += 0.0666)
	{
	   capVoltage = VOLTAGE * (1 - (exp(-(time/TAU))));
	   printf("     %.2f		%.2f\n", time, capVoltage);
	}

	printf("\n");

	return 0;
}
