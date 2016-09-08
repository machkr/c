#ifndef BOOLEAN_H
#define BOOLEAN_H

#define TRUE 1
#define FALSE 0
typedef int Bool;

//function prototypes
Bool logical_and(Bool a, Bool b);
Bool logical_or(Bool a, Bool b);
Bool logical_not(Bool a);
void print_bool(Bool b); 

#endif