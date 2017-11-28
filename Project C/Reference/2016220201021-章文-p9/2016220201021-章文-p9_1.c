#include <stdio.h>

#define N 10

void selection_sort(int n, int a[]);

int main()
{
	int a[N],i;
	
	printf("Enter %d numbers: ",N);
	for (i = 0; i < N; i++)
	    scanf("%d", &a[i]);
    
    selection_sort(N, a);
    
    printf("In sorted order:");
    for (i = 0; i < N; i++)
        printf(" %d",a[i]);
    printf("\n");
    
    return 0;
}

void selection_sort(int n, int a[n])
{
	int max_number, i, max = 0;
	
	for (i = 0; i < n; i++)
	    if (a[i] >= max)
	    {
    		max = a[i];
    		max_number = i;
    	}
	a[max_number] = a[n-1];
	a[n-1] = max;
	
	if (n > 1)
	    selection_sort(n-1, a);
    else
        return;
}
