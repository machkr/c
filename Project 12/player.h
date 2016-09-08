#ifndef PLAYER_H
#define PLAYER_H

#define NAME_LEN 30                                                                     //Macro definition of the length of player's first or last name

struct player                                                                           //Global definition of 'player' struct
{
    int number;                                                                         //Integer 'number' for the player number
	char first_name[NAME_LEN+1];                                                        //String 'first_name' for first name                                                             
	char last_name[NAME_LEN+1];                                                         //String 'last_name' for last name
	struct player *next;                                                                //Link to the next node
};

struct player *append_to_list(struct player *roster);                                   //Prototype of 'append_to_list' function
struct player *delete_from_list(struct player *roster);									//Prototype of 'delete_from_list' function
void find_player(struct player *roster);                                                //Prototype of 'find_player' function
void printList(struct player *roster);                                                  //Prototype of 'printList' function
void clearList(struct player *roster);                                                  //Prototype of 'clearList' function
int read_line(char str[], int n);                                                       //Prototype of 'read_line' function

#endif