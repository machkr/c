#ifndef STACK_H
#define STACK_H

struct node
{
	int value;
	struct node *next;
};

struct node *push(struct node *top, int i);
struct node *make_empty(struct node *top);
struct node *pop(struct node *top, int *i);
struct node *roll(struct node *top);
void print_stack(struct node *top);


#endif
