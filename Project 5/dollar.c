/*dollar.c for project 5
  Program Design
 */

#include <stdio.h>

int main()
{
	//initialize variables and read input
	int dollar = 0, twenty = 0, ten = 0, five = 0, one =0;
        printf("Enter a dollar amount:\n");
	scanf("%d", &dollar);

	//check the range of the input amount
	if(dollar < 0 || dollar > 1000000000)
	   printf("Invalid amount %d,\nAmount must be between 0 and 1000000000, inclusive\n", dollar);
        else {
		twenty = dollar/20;
		ten = (dollar - (twenty * 20))/10;
		five = (dollar - (twenty * 20) - (ten * 10))/5;
		one = dollar - (twenty * 20) - (ten * 10) - (five * 5);

		printf("$20 bills: %d\n", twenty);
	        printf("$10 bills: %d\n", ten);
        	printf("$5 bills: %d\n", five);
	        printf("$1 bills: %d\n", one);
	}
	return 0;
}

	
