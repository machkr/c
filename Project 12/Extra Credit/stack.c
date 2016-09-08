#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node* push(struct node* top, int i)                                              //'push' function adds an element to the top of a stack
{
    struct node *new_node;                                                              //Temporary node for the element to be added to the stack

    new_node = malloc(sizeof(struct node));                                             //Allocate memory for this new node based on the size of the struct

    if(new_node == NULL)                                                                //If 'new_node' is still NULL
    {
        printf("Warning: memory was unable to be allocated for the new node.\n");       //Print a message stating that memory couldn't be allocated
        
        return top;                                                                     //And return the stack, unchanged
    }
   
    new_node->value = i;                                                                //Otherwise, assign the value to the new node
    new_node->next = top;                                                               //And link the rest of the stack to the new node

    return new_node;                                                                    //Finish by returning 'new_node' - now with the stack linked to it
}

struct node *make_empty(struct node *top)                                               //'make_empty' function empties a stack
{
    struct node *x;                                                                     //Temporary iterating node 'x' for the stack

    if(top == NULL)                                                                     //If the stack is empty
    {
        printf("The stack you have tried to empty is, well, already empty.\n");         //Print a message stating that it's empty
        
        return top;                                                                     //And return the stack, unchanged
    }

    while(top != NULL)                                                                  //Until the stack is empty
    {
        x = top;                                                                        //Set the iterating node to the top of the stack
        top = top->next;                                                                //Advance the top node to the next element of the stack
        free(x);                                                                        //And free the memory allocated to 'x'
    }

    printf("The stack is now empty.\n");                                                //Print a message stating the function's successful completion

    return top;                                                                         //And return the stack, now emptied
}

struct node *pop(struct node *top, int *i)                                              //'pop' function removes the top element of a stack and saves the value that it held to a pointer
{
    struct node *x;                                                                     //Temporary node 'x' for the top element of the stack

    if(top == NULL)                                                                     //If the stack is empty
    {
        printf("The stack you have tried to pop is empty.\n");                          //Print a message stating that the stack is empty

        return top;                                                                     //And return the empty stack
    }

    *i = top->value;                                                                    //Otherwise, set the value of the node to be popped to the pointer

    x = top;                                                                            //Set 'x' to the top node
    top = top->next;                                                                    //Set the next node in the stack to top
    free(x);                                                                            //And free the memory allocated to 'x'

    return top;                                                                         //Finish by returning the stack, now popped
}

struct node *roll(struct node *top)                                                     //'roll' function shifts the top three elements of a stack
{
    int x;                                                                              //Three integer variables to hold the stack values temporarily
    int y;
    int z;

    x = top->value;                                                                     //Set 'x' equal to the top stack element value
    y = top->next->value;                                                               //Set 'y' equal to the second element in the stack
    z = top->next->next->value;                                                         //Set 'z' equal to the third element in the stack

    top->next->next->value = y;                                                         //Set the third element in the stack to 'y'
    top->next->value = x;                                                               //Set the second element in the stack to 'x'
    top->value = z;                                                                     //Set the top element in the stack to 'z'

    return top;                                                                         //Return the newly rolled stack
}

void print_stack(struct node *top)                                                      //'print_stack' function prints the elements located in a stack
{
    struct node *x;                                                                     //Temporary iterating node 'x'

    if(top != NULL)                                                                     //If the stack is not empty
    {
        for(x = top; x != NULL; x = x->next)                                            //'for' loop to process the elements of the stack, top to bottom
        {
            printf("%d\n", x->value);                                                   //Process the current element of stack, pointed to by the temp node 'x'  
        }

        printf("\n");                                                                   //Formatting business
    }
    else
    {
        printf("The stack you have tried to print is empty.\n\n");                      //Otherwise, print a message stating the stack is empty
    }
}
