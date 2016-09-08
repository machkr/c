#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "player.h"
#include "readline.h"

int main(void)
{
    char code;                                                                          //Character 'code' for operation code 

    struct player *team_roster = NULL;                                                  //Creation of 'team_roster' linked list

    printf("\nOperation Codes:\n\n\t'A' - Append\n\t'F' - Find"                         //Prints operation codes
        "\n\t'P' - Print\n\t'Q' - Quit\n\n");
    
    for(;;)                                                                             //'for' loop to process operation codes
    {
        printf("Please enter an operation code: ");                                     //Asks for and reads in operation code
        scanf(" %c", &code);

        while (getchar() != '\n')                                                       //Skips to end of line
            ;

        switch(code)                                                                    //Switch statement to process operation code, upper or lowercase
        {
            case 'a':                                                                   //Uppercase/lowercase 'a'
            case 'A': team_roster = append_to_list(team_roster);                        //Call 'append_to_list' function
                    break;

            case 'f':                                                                   //Uppercase/lowercase 'f'
            case 'F': find_player(team_roster);                                         //Call 'find_player' function
                    break;

            case 'p':                                                                   //Uppercase/lowercase 'p'
            case 'P': printList(team_roster);                                           //Call 'printList' function
                    break;

            case 'q':                                                                   //Uppercase/lowercase 'q'
            case 'Q': clearList(team_roster);                                           //Call 'clearList' function
                    return 0;

            default:  printf("\nYou have entered an invalid code.\n");                  //Contingency for invalid operation code
        }
        printf("\n");
    }
}