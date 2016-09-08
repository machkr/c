#include <stdio.h>
#define N 10

void selection_sort(int *a, int n);
int *find_largest(int *a, int n);
void swap(int *p, int *q);

int main(void)
{
	int i;
	int a[N];

	printf("Please enter %d numbers to be sorted:\n", N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", a + i);
    }

    selection_sort(a, N);

    printf("Here is the sorted set:\n");
    for(i = 0; i < N; i++)
    {
        printf(" %d", *(a + i));
        printf("\n");
    }
}

void selection_sort(int *a, int n)
{
	int *largest = find_largest(a, n);


}

int *find_largest(int *a, int n)
{
	int *p;
	int *max;
	max = a;

	for(p = a + 1; p < a + (n - 1); p++)
	{
		if(*p > *max)
		{
			max = p;
		}
	}

	return *max;
}

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}