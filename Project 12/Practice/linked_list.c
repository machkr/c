#include <stdio.h>
#include <stdlib.h>

struct node *add_to_list(struct node *list, int n);
struct node *search_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);
void clearList(struct node *list);
void printList(struct node *list);

struct node {
	int value;          /* data stored in the node  */
	struct node *next;  /* pointer to the next node */
};

int main()
{

 	struct node *first = NULL;

	/* inserting nodes */
	first = add_to_list(first, 83);
	first = add_to_list(first, 64);
	first = add_to_list(first, 98);
	first = add_to_list(first, 31);
        first = add_to_list(first, 64);
	first = add_to_list(first, 3);
	first = add_to_list(first, 136);

        printList(first);	
	clearList(first);
	return 0;

}

struct node *add_to_list(struct node *list, int n)
{
	  struct node *new_node;
	
	  new_node = malloc(sizeof(struct node));
	  if (new_node == NULL) {
	    printf("Error: malloc failed in add_to_list\n");
	    return list;
	  }
	  new_node->value = n;
	  new_node->next = list;
	  return new_node;
}

struct node *search_list(struct node *list, int n)
{
	  struct node *p;
	
	  for (p = list; p != NULL; p = p->next)
	    if (p->value == n)
	      return p;
	  return NULL;
}

struct node *delete_from_list(struct node *list, int n)
{
  struct node *cur, *prev;
	  
  for (cur = list, prev = NULL;
       cur != NULL && cur->value != n;
       prev = cur, cur = cur->next)
    ;
  if (cur == NULL) 
    return list;             /* n was not found */
  if (prev == NULL)
    list = list->next;       /* n is in the first node */
  else
    prev->next = cur->next;  /* n is in some other node */
  free(cur);
  return list;
}

void clearList(struct node *list)
{
  struct node *p;
  while(list != NULL)
  {
	p = list;
        list = list->next;
        if( p!= NULL)
           free(p);
  }
}

void printList(struct node *list)
{
   struct node *p;
   for(p = list; p!= NULL; p = p->next)
	printf("%d\n", p->value);
}
