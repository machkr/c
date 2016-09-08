#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "player.h"

struct player *append_to_list(struct player *roster)                                               //'append_to_list' function appends a user input function to the roster
{
    struct player *previous;
    struct player *current;                                                                        //Declaration of player node 'current' for use as a marker
    struct player *new;                                                                            //Declaration of player node 'new' for use as a temp node for the new player

    new = malloc(sizeof(struct player));                                                           //Allocates memory to new based on size of the player node
    
    if(new == NULL)                                                                                //If the 'new' node is null (memory not allocated)
    {
        printf("\nMemory was unable to be allocated for the new player.\n");                       //Then print a message stating that fact
        
        return roster;                                                                             //And return 'roster', instead of continuing in the function                                                  
    }

    printf("\nPlease enter the player's number: ");                                                //Asks for and scans in the player's number
    scanf("%d", &new->number);

    for(current = roster; current != NULL; current = current->next)                                //For loop to find if this player's number already exists in the linked list
    {
        if(new->number == current->number)                                                         //If the new node's number value matches the current's
        {
            printf("\nA player with this number already exists in the roster.");                   //Print a message saying so
            
            free(new);                                                                             //Free up the memory allocated to the new node
            
            return roster;                                                                         //And return 'roster'
        }
    }

    printf("\nPlease enter the player's last name: ");                                             //Asks for and reads in the player's last name
    scanf("%s", new->last_name);

    printf("\nPlease enter the player's first name: ");                                            //Asks for and reads in the player's first name
    scanf("%s", new->first_name);

    new->next = NULL;                                                                              //Makes the node after 'new' NULL, forming the end of the linked list

    current = roster;                                                                              //Set 'current' -- iterating node -- to 'roster'
    previous = NULL;                                                                               //Set 'previous' -- temporary node -- to NULL

    while(current != NULL && strcmp(current->last_name, new->last_name) <= 0)                      //Until the end of the roster, or while the roster has elements, AND the current name is less than the new one
    {
        if(strcmp(current->last_name, new->last_name) == 0)                                        //If the current last name is the same as the last name of the player to be entered
        {
            if(strcmp(current->first_name, new->first_name) <= 0)                                  //Then, if the current first name comes before the new first name
            {
                previous = current;                                                                //Set 'previous' node to the 'current' node
                current = current->next;                                                           //Set the 'current' node to the next node in the roster
                continue;                                                                          //And return to the loop to continue
            }
            else                                                                                   //Otherwise...
            {
                continue;                                                                          //Continue
            }
        }
        previous = current;                                                                        //If the condition above isn't met, set 'previous' node to 'current'
        current = current->next;                                                                   //And 'current' node to the next node in the roster
    }

    new->next = current;                                                                           //Once the position of insertion has been found by the above loop, link the end of the list to the new node
    
    if(previous == NULL)                                                                           //If, after processing, 'previous' is NULL (empty roster)
    {
        roster = new;                                                                              //Set 'roster' equal to the new node
    }
    else                                                                                           //Otherwise...
    {
        previous->next = new;                                                                      //Link the beginning of the list to the node
    }

    return roster;                                                                                 //And return the roster
}

struct player* delete_from_list(struct player *roster)                                             //'delete_from_list' function deletes a player from the roster by their number
{
    struct player *current;                                                                        //Declaration of player node 'current' for use as a marker
    struct player *previous;                                                                       //Declaration of player node 'previous' for use as a holder for the node before current
    int num = 0;                                                                                   //Temporary 'integer' num

    printf("\nPlease enter the number of the player you would like to delete: ");                  //Asks for and reads in the player's number to be deleted
    scanf("%d", &num);

    previous = NULL;                                                                               //Set 'previous' to NULL, initially

    for(current = roster; current != NULL; previous = current, current = current->next)            //'for' loop to process the linked list, element by element
    {
        if(current->number == num)                                                                 //If the player currently being visited matches the number to be deleted
        {
            if(previous == NULL)                                                                   //If 'previous' is NULL (player to be deleted at beginning of list)
            {
                roster = current->next;                                                            //Set 'roster' to the linked list after the 'current' node
            }
            else
            {
                previous->next = current->next;                                                    //Otherwise, delete the element as normal
            }

            printf("\nPlayer number %d, %s %s, has successfully been deleted from the roster.",    //Print a message stating the function's successful completion
                num, current->first_name, current->last_name);

            free(current);                                                                         //Free the memory allocated to the current element to be deleted

            return roster;                                                                         //And return roster (player deleted)
        }
        else
        {
            continue;                                                                              //If the numbers don't match, try again with the next node
        }
    }

    printf("\nPlayer number %d could not be found.", num);                                         //If the loop is escaped (no matching player), print a message stating that

    return roster;                                                                                 //And return the roster
}

void find_player(struct player *roster)                                                            //'find_player' function searches for a user input player, by number
{
    struct player *x;                                                                              //Declaration of temporary player 'x'
    int num;                                                                                       //Declaration of integer 'number'

    printf("\nPlease enter the number of the player you would like to find: ");                    //Asks for and reads in the player's number to be found
    scanf("%d", &num);

    for(x = roster; x != NULL && num != x->number; x = x->next)                                    //'for' loops to search the roster for a matching number
        ;

    if(x != NULL && num == x->number)                                                              //If x, after the loop runs, isn't NULL (is a match)
    {
        printf("\nPlayer number %d is %s %s.", num, x->first_name, x->last_name);                  //Print a message stating so
    }
    else                                                                                           //Otherwise,...
    {
        printf("\nPlayer number %d could not be found.", num);                                     //Print a message stating that the player could not be found
    }
}

void printList(struct player *roster)                                                              //'printList' function displays the contents of a linked list
{
    struct player *x;                                                                              //Declaration of temporary player 'x'

    printf("\n--------------------------------------------------------");

    printf("\n\nNumber\t\tFirst Name\t\tLast Name\n\n");                                           //Prints the column headers

    for(x = roster; x != NULL; x = x->next)                                                        //'for' loop that processes the linked list, node by node
    {
        printf("%d\t\t%s\t\t\t%s\n\n", x->number, x->first_name, x->last_name);                    //Prints the current node's data
    }

    printf("--------------------------------------------------------");
}

void clearList(struct player *roster)                                                              //'clearList' clears the contents of a linked list
{
    struct player *x;                                                                              //Declaration of temporary player 'x'

    while(roster != NULL)                                                                          //While the roster is not empty
    {
        x = roster;                                                                                //Set the temporary node 'x' to the beginning
        roster = roster->next;                                                                     //And move roster to the next node

        if(x != NULL)                                                                              //If the temporary node 'x' isn't NULL
        {
            free(x);                                                                               //Make it so (free the allocated memory)
        }
    }
}