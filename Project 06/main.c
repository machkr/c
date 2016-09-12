#include <stdio.h>

int compare_array(int a[], int n, int value)
{
	int *p;
	int count = 0;

	for(p = &a[0]; p < &a[n]; p++)
	{
		if(*p > value) 
		{
			count ++; 
		}
	}
	return count; }

int* find_smallest(int a[], int n)
{
	int *p;
	int *p_min = &a[0];

	for(p = &a[1]; p < &a[n]; p++)
	{
		if(*p < *p_min)
		{
			p_min = p;
		}
	} 
	return p_min;
}

int main()
{  
	int count = 0;
	int a[7] = {3, 42, 52, 91, 2, 13, 49};
	int* min;

	min = find_smallest(a, 7);

	printf("the smallest value is: %d\n", *min);

	count = compare_array(a, 7, 25);

	printf("the number of elements greater than 25 is: %d\n", count);

	return 0;
}