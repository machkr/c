#include <stdio.h>
#include "boolean.h"
	
Bool logical_and(Bool a, Bool b)
{
		return (a&&b);
}
Bool logical_or(Bool a, Bool b)
{
		return (a||b);
}
Bool logical_not(Bool a)
{
		return (!a);
}

void print_bool(Bool b)
{
		printf("%s\n", (b ? "TRUE" : "FALSE"));
}