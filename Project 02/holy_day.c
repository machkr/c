// Programmer: Matthew Kramer
//
// Program: Project 2 - Holy_Day.c
//
// Description: Calculates the best day for homework due date,
//		taking into consideration the holy days of
//		different religions.
//
// Course: Program Design - COP 3514, Section 003

//Initializes standard input/output method
#include <stdio.h>

int main(void)
{
	//Initialization of variables used in various stages of the program
	int today;
	int D;
	int dueDay;
	int totalRemainder;
	int weekRemainder;

	//Asks for and scans in the integer reference to the day of the week
	printf("Please enter the day of the week as an integer from 0 (Sunday) to 6 (Saturday): ");
	scanf("%d", &today);
	printf("\n");

	//Simple 'if' check for invalid values of above input, aborts the program if so
	if(today >= 7 || today < 0)
	{
	  printf("You have entered an invalid value.\n");
	  printf("ABORT! ABORT! ABORT! ABORT! ABORT!\n");
          printf("\n");
	  return 0;
	}

	//Asks for and scans in the number of days for the students to complete assignment
	printf("Please enter the number of days until the homework is due: ");
	scanf("%d", &D);
        printf("\n");

	//Calculates the number of days between today's day of the week and the day of the week
	//that the due date falls on, currently
	totalRemainder = (D % 7);

	//Switch statement that calculates the due date if the above number of days causes the
	//week to "roll" - or continue into the next week. If it does not, it sets the due date
	//to today's day of the week incremented by the number of days (totalRemainder) calculated
	switch(today)
	{
		case 0: if(totalRemainder > 6)
			{
			  weekRemainder = ((totalRemainder + today) % 7);
			  dueDay = weekRemainder;
			}
			else
			{
			  dueDay = (today + totalRemainder);
			}
			break;

		case 1: if(totalRemainder > 5)
			{
                          weekRemainder = ((totalRemainder + today) % 7);
                          dueDay = weekRemainder;
                        }
                        else
                        {
                          dueDay = (today + totalRemainder);
                        }
			break;

		case 2: if(totalRemainder > 4)
			{
                          weekRemainder = ((totalRemainder + today) % 7);
                          dueDay = weekRemainder;
                        }
                        else
                        {
                          dueDay = (today + totalRemainder);
                        }
			break;

		case 3: if(totalRemainder > 3)
			{
                          weekRemainder = ((totalRemainder + today) % 7);
                          dueDay = weekRemainder;
                        }
                        else
                        {
                          dueDay = (today + totalRemainder);
                        }
			break;

		case 4:	if(totalRemainder > 2)
			{
                          weekRemainder = ((totalRemainder + today) % 7);
                          dueDay = weekRemainder;
                        }
                        else
                        {
                          dueDay = (today + totalRemainder);
                        }
			break;

		case 5: if(totalRemainder > 1)
			{
                          weekRemainder = ((totalRemainder + today) % 7);
                          dueDay = weekRemainder;
                        }
                        else
                        {
                          dueDay = (today + totalRemainder);
                        }
			break;

		case 6: if(totalRemainder > 0)
			{
                          weekRemainder = ((totalRemainder + today) % 7);
                          dueDay =  weekRemainder;
                        }
                        else
                        {
                          dueDay = (today + totalRemainder);
                        }
			break;
	}

	//Switch statement that prints the results of the above calculations. If the due date
	//falls on a holy day, it makes sure to increment the number of days until it no longer
	//falls on a holy day.
	switch(dueDay)
	{
		case 0: D += 1;
         		dueDay = 1;
         		printf("The due date fell on a Sunday. Since Sunday "
			"is a holy day in Christianity, the homework will "
			"instead be due on Monday and your students will have "
			"%d days to complete it.\n", D);
		        printf("\n");
			break;

		case 1: printf("The homework will be due on Monday, %d days from today.\n", D);
		        printf("\n");
			break;

		case 2: printf("The homework will be due on Tuesday, %d days from today.\n", D);
       			printf("\n");
                        break;

		case 3: printf("The homework will be due on Wednesday, %d days from today.\n", D);
                        printf("\n");
			break;

		case 4: printf("The homework will be due on Thursday, %d days from today.\n", D);
                        printf("\n");
			break;

		case 5: D += 3;
                        dueDay = 1;
                        printf("The due date fell on a Friday. Since Friday "
                        "is a holy day in Islam, the homework will instead "
			"be due on Monday and your students will have %d days "
			"to complete it.\n", D);
       			printf("\n");
			break;

		case 6: D += 2;
                        dueDay = 1;
                        printf("The due date fell on a Saturday. Since Saturday "
                        "is a holy day in Judaism, the homework will instead be "
			"due on Monday and your students will have %d days to "
			"complete it.\n", D);
                        printf("\n");
			break;

	}

	return 0;

}
