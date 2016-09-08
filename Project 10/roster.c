// Programmer: Matthew Kramer
//
// Program: Project 10 - roster.c
//
// Description: Maintains a roster for a sports team.
//
// Course: Program Design - COP 3514, Section 003

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_LEN 30                                                                     //Macro definition of the length of player's first or last name

struct player                                                                           //Global definition of 'player' struct
{
    int number;                                                                         //Integer 'number' for the player number
	char first_name[NAME_LEN+1];                                                        //String 'first_name' for first name                                                             
	char last_name[NAME_LEN+1];                                                         //String 'last_name' for last name
	struct player *next;                                                                //Link to the next node
};

struct player *append_to_list(struct player *roster);                                   //Prototype of 'append_to_list' function
void find_player(struct player *roster);                                                //Prototype of 'find_player' function
void printList(struct player *roster);                                                  //Prototype of 'printList' function
void clearList(struct player *roster);                                                  //Prototype of 'clearList' function
int read_line(char str[], int n);                                                       //Prototype of 'read_line' function

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

struct player *append_to_list(struct player *roster)                                    //'append_to_list' function appends a user input function to the roster
{
    struct player *current;                                                             //Declaration of player node 'current' for use as a marker
    struct player *new;                                                                 //Declaration of player node 'new' for use as a temp node for the new player

    new = malloc(sizeof(struct player));                                                //Allocates memory to new based on size of the player node
    
    if(new == NULL)                                                                     //If the 'new' node is null (memory not allocated)
    {
        printf("\nMemory was unable to be allocated for the new player.\n");            //Then print a message stating that fact
        
        return roster;                                                                  //And return 'roster', instead of continuing in the function
                                                        
    }

    printf("\nPlease enter the player's number: ");                                     //Asks for and scans in the player's number
    scanf("%d", &new->number);

    for(current = roster; current != NULL; current = current->next)                     //For loop to find if this player's number already exists in the linked list
    {
        if(new->number == current->number)                                              //If the new node's number value matches the current's
        {
            printf("\nA player with this number already exists in the roster.\n");      //Print a message saying so
            
            free(new);                                                                  //Free up the memory allocated to the new node
            
            return roster;                                                              //And return 'roster'
        }
    }

    printf("\nPlease enter the player's last name: ");                                  //Asks for and reads in the player's last name
    scanf("%s", new->last_name);

    printf("\nPlease enter the player's first name: ");                                 //Asks for and reads in the player's first name
    scanf("%s", new->first_name);

    new->next = NULL;                                                                   //Makes the node after 'new' NULL, forming the end of the linked list

    printf("\n%s %s (#%d) was added successfully.\n", new->first_name, new->last_name,  //Print a message stating that the player was added successfully 
        new->number);

    current = roster;                                                                   //Reset current to roster

    if(current == NULL)                                                                 //If roster is empty (first time)
    {
        current = new;                                                                  //Set first element to new node
        
        return current;                                                                 //And return this node
    }

    for(current = roster; current != NULL; current = current->next)                     //'for' loop to process the roster, node by node
    {
        if(current->next == NULL)                                                       //If the next element is NULL
        {
            current->next = new;                                                        //Make this element the new player
            
            current = roster;                                                           //And the elements before it the rest of the roster
            
            return current;                                                             //Returning current to finish
        }
    }

    return roster;                                                                      //Fallback case, return roster
}

void find_player(struct player *roster)                                                 //'find_player' function searches for a user input player, by number
{
    struct player *x;                                                                   //Declaration of temporary player 'x'
    int number;                                                                         //Declaration of integer 'number'

    printf("\nPlease enter the number of the player you would like to find: ");         //Asks for and reads in the player's number to be found
    scanf("%d", &number);

    for(x = roster; x != NULL && number != x->number; x = x->next)                      //'for' loops to search the roster for a matching number
        ;

    if(x != NULL && number == x->number)                                                //If x, after the loop runs, isn't NULL (is a match)
    {
        printf("\nPlayer number %d is %s %s.\n", number, x->first_name, x->last_name);  //Print a message stating so
    }
    else                                                                                //Otherwise,...
    {
        printf("\nThe player number you have entered could not be found.\n");           //Print a message stating that the player could not be found
    }
}

void printList(struct player *roster)                                                   //'printList' function displays the contents of a linked list
{
    struct player *x;                                                                   //Declaration of temporary player 'x'

    printf("\n\nNumber\t\tFirst Name\t\tLast Name\n\n");                                //Prints the column headers

    for(x = roster; x != NULL; x = x->next)                                             //'for' loop that processes the linked list, node by node
    {
        printf("%d\t\t%s\t\t\t%s\n\n", x->number, x->first_name, x->last_name);         //Prints the current node's data
    }
}

void clearList(struct player *roster)                                                   //'clearList' clears the contents of a linked list
{
    struct player *x;                                                                   //Declaration of temporary player 'x'

    while(roster != NULL)                                                               //While the roster is not empty
    {
        x = roster;                                                                     //Set the temporary node 'x' to the beginning
        roster = roster->next;                                                          //And move roster to the next node

        if(x != NULL)                                                                   //If the temporary node 'x' isn't NULL
        {
            free(x);                                                                    //Make it so (free the allocated memory)
        }
    }

}

int read_line(char str[], int n)
{
    int ch;
    int i = 0;

    while(isspace(ch = getchar()))
    ;
    
    str[i++] = ch;

    while((ch = getchar()) != '\n')
    {
        if(i < n)
        {
            str[i++] = ch;
        }
    }

    str[i] = '\0';

    return i;
 }
