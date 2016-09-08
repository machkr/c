#include <stdio.h>
#include "stack.h"

int main(void)
{
   int n;
   struct node *stack1 = NULL;
   struct node *stack2 = NULL;

   stack1 = push(stack1, 25);
   stack1 = push(stack1, 32);
   stack1 = push(stack1, 8);
   stack1 = push(stack1, 94);
   stack2 = push(stack2, 21);
	
   printf("\nThis is Stack 1:\n");
   print_stack(stack1);
   printf("This is Stack 2:\n");
   print_stack(stack2);   

   stack1 = roll(stack1);
   printf("They see me rollin'...\n");
   printf("\nStack 1 is now:\n");
   print_stack(stack1);

   stack1 = pop(stack1, &n);
   printf("*Pop!* -- Popped %d from Stack 1.\n", n);
   printf("\nStack 1 is now:\n");
   print_stack(stack1);
 
   stack2 = push(stack2, n);
   printf("Pushin' it real good...\n\n");
   printf("Stack 2 is now:\n");
   print_stack(stack2);
 
   stack1 = pop(stack1, &n);
   printf("*Pop!* -- Popped %d from Stack 1.\n", n);
   printf("\nStack 1 is now:\n");
   print_stack(stack1);
   
   stack1 = make_empty(stack1);
   printf("\nHere is Stack 1:\n");
   print_stack(stack1);

   stack2 = make_empty(stack2);
   printf("\nHere is Stack 2:\n");
   print_stack(stack2);

   return 0;
}
