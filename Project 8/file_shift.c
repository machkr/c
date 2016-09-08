// Programmer: Matthew Kramer
//
// Program: Project 8 - file_shift.c
//
// Description: Takes a *.txt file and shifts each letter
//              a user input number of times, writing the
//              newly processed text to a new file. 
//
// Course: Program Design - COP 3514, Section 003

#include <stdio.h>                                                          //Initialization of standard input/output library
#include <string.h>                                                         //Initialization of string library
#include <stdlib.h>                                                         //Initialization of standard C library
//#include <ctype.h>                                                          //Initialization of C type library

#define MAX_SIZE 100                                                        //Macro definition of 'Max_Size' - the length of the filenames

void shift(char *message, int shift_amount);                                //Declaration of shift function
char input[MAX_SIZE + 1];                                                   //Declaration of string for input file name
char output[MAX_SIZE + 1];                                                  //Declaration of string for output file name

int main(void)
{
    int ch;                                                                 //Declaration of integer ch
    int i;                                                                  //Declaration of integer i
    int shift_amount;                                                       //Declaration of integer shift_amount
    char message[1000];                                                     //Declaration of character array (string) message
    FILE *instream;                                                         //Declaration of file pointer instream for input file
    FILE *outstream;                                                        //Declaration of file pointer 'outstream' for output file

    printf("\nPlease enter the name of the file to be processed: ");        //Asks for the name of the input file

    for(i = 0; i < MAX_SIZE && (ch = getchar()) != '\n'; i++)               //'for' loop that retrieves a string character-by-character
    {
        *(input + i) = ch;                                                  //Adding it to the input filename string
        *(output + i) = ch;                                                 //As well as the output filename string
    }

    if((instream = fopen(input, "r")) == '\0')                              //Opens the input file, while doing some error-checking as well
    {
        printf("\nThere was an error when opening the file. Please "        //If there is an error when opening the file, print a message
            "make sure you have entered the filename correctly.\n\n");
        return 1;                                                           //And return 1
    }

    strcat(input, "\0");                                                    //Appends the null character to the input filename
    strcat(output, ".sft\0");                                               //Appends the '.sft' and null character to the output filename

    printf("\nPlease enter the amount of shift (1-25): ");                  //Asks for and reads in the amount of shift
    scanf("%d", &shift_amount);

    while(shift_amount < 1 || shift_amount > 25)                            //Checks for invalid shift amount
    {
        printf("\nYou have entered an invalid shift amount. Please "        //Prints a message if it encounters an invalid shift amount
            "try again.\n");
        printf("\nPlease enter the amount of shift (1-25): ");              //Asks for and reads in the amount of shift
        scanf("%d", &shift_amount);
    }

    printf("\nThe processed file will be named '%s'.\n", output);           //Prints the newly formatted output filename

    for(i = 0; (ch = fgetc(instream)) != EOF; i++)                          //'for' loop that reads the input file into a string, while
    {                                                                       //doing some error-checking as well
        if(ferror(instream))
        {
            printf("There was an error when reading the file. Please "      //If there is an error when reading the file, print a message
                "make sure the file is not corrupted.\n\n");
            return 1;                                                       //And return 1
        }

        *(message + i) = ch;
    }

    *(message + i) = '\0';                                                  //Adds null character to the 'message' string
    
    fclose(instream);                                                       //Closes the input stream

    shift(message, shift_amount);                                           //Calls 'shift' function using newly created string

    printf("\n'%s' was shifted successfully.\n", input);                    //Informs the user of the program's accomplishment

    if((outstream = fopen(output, "w")) == '\0')                            //Opens the output file, while doing some error-checking as well
    {
        printf("\nThere was an error opening the new file.\n\n");           //If there is an error when opening the file, print a message
        return 1;                                                           //And return 1
    }

    for(i = 0; *(message + i) != '\0'; i++)                                 //Processes the 'message' string, character-by-character
    {
        if(fputc(*(message + i), outstream) == EOF)                         //Puts the current character if the message in the output file,
        {                                                                   //while doing some error-checking as well
            printf("\nThere was an error when writing the new file.\n\n");  //If there is an error when writing the file, print a message
            return 1;                                                       //And return 1
        }
    }

    printf("\n'%s' was saved successfully.\n\n", output);                   //Informs the user of the program's accomplishment

    fclose(outstream);                                                      //Closes output file

    return 0;                                                               //Return 0
}

void shift(char *message, int shift_amount)                                 //'shift' function implements the character shift of a string
{
    int ch;                                                                 //Declaration of integer 'ch'   
    int i;                                                                  //Declaration of integer 'i'

    for(i = 0; *(message + i) != '\0'; i++)                                 //'for' loop to process the message character by character,
    {                                                                       //until the null character is reached
        ch = *(message + i);

        if(ch >= 'a' && ch <= 'z')                                          //If the character is lowercase
            ch = ((ch - 'a') + shift_amount) % 26 + 'a';                    //Perform shifting operation, implementing wrap around

        if(ch >= 'A' && ch <= 'Z')                                          //If the character is uppercase
            ch = ((ch - 'A') + shift_amount) % 26 + 'A';                    //Perform shifting operation, implementing wrap around

        *(message + i) = ch;                                                //Setting the current value of message to the shifted character
    }
}