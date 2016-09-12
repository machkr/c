// Programmer: Matthew Kramer
//
// Program: Project 6 - merge.c
//
// Description: Merges two user-input strings, character by character
//
// Course: Program Design - COP 3514, Section 003

#include <stdio.h>                                              //Initialization of standard input/output library
#define LENGTH 1000												//Macro definition of length as 1000

int read_line(char *str, int n);								//Declaration of 'read_line' function
void merge(char *s3, const char *s1, const char *s2);			//Declaration of 'merge' function

int main(void)
{
	char s1[LENGTH + 1];										//Declaration of string/character array 's1' with length 'LENGTH + 1' to account for null
	char s2[LENGTH + 1];										//Declaration of string/character array 's2 with length 'LENGTH + 1' to account for null
	char s3[(2 * LENGTH) + 1];									//Declaration of string/character array 's3' with length '(2 * LENGTH) + 1' to account for input strings and null

	printf("Please enter the first set of characters: ");		//Asks for the input of the first string
	read_line(s1, LENGTH + 1);									//Calls the 'read_line' function which will input 'LENGTH + 1' characters into the string 's1'

	printf("Please enter the second set of characters: ");		//Asks for the input of the second string
	read_line(s2, LENGTH + 1);									//Calls the 'read_line' function which will input 'LENGTH + 1' characters into the string 's2'

	merge(s3, s1, s2);											//Calls the 'merge' function which returns a string 's3', the interlaced merging of strings 's1' and 's2'

	printf("Here is the merged set of characters: %s\n", s3);	//Prints the result of the 'merge' function, string 's3'

	return 0;
}

int read_line(char *str, int n)									//'read_line' function performs the 'scanf' function with capabiility to skip i
{
	int ch;														//Declaration of temporary character variable 'ch' for use in reading in line of text
	int i = 0;													//Declaration of integer 'i' for use as index in the function

	while ((ch = getchar()) != '\n')							//While the current retrieved character is not the return character
	{
		if (i < n)												//If the current index is less than the length of the line to be read in						
		{
			*str++ = ch;										//Add it to the output string
			i++;												//And increment the index variable
		}
	}

	*str = '\0';												//Adds a null character to the end of the output string

	return i;
}

void merge(char *s3, const char *s1, const char *s2)
{
	while(*s1 != '\0' && *s2 != '\0')							//While the current character of both 's1' and 's2' are not null [Strings of same length]
    {

    	*s3++ = *s1++;											//The current character of 's3' is set to the current character of 's1' and these pointers are incremented: 
    															//'s3' so that the 's2' character can be the next in the string, and 's1' for the next time the loop runs.
    	*s3++ = *s2++;											//The current character of 's3' is set to the current character of 's2' and these pointers are incremented:
																//'s3' so that the 's1' character can be the next in the string, and 's2' for the next time the loop runs.
    }

    while(*s1 != '\0')											//While the current character of the string 's1' is not null [String 's1' longer than 's2']
    {
        *s3++ = *s1++;											//The current character of 's3' is set to the current character of 's1' and these pointers are incremented
        														//to append the remaining characters of 's1' to 's3'
    }

    while(*s2 != '\0')											//While the current character of the string 's2' is not null [String 's2' longer than 's1']
    {

        *s3++ = *s2++;											//The current character of 's3' is set to the current character of 's2' and these pointers are incremented
        														//to append the remaining characters of 's2' to 's3'
    }

    *s3 = '\0';													//Adds null character to end of result string 's3'

}