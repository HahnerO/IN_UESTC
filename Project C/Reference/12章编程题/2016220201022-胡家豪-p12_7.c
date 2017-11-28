#include<stdio.h>

#define N 10

void max_min(int a[],int n,int *max,int *min);

int main(void)
{
	int a[N],*p,big,small;
	
	printf("Enter %d numbers: ",N);
	for(p=a;p<a+N;p++)
		scanf("%d",p);
	
	max_min(a,N,&big,&small);
	
	printf("Largest: %d\n",big);
	printf("Smallest: %d\n",small);
	
	return 0;
}

void max_min(int a[],int n,int *max,int *min)
{
	int *p;
	*max=*min=a[0];
	for(p=a+1;p<a+n;p++){
		*max = *p>*max ? *p:*max;
	 	*min = *p<*min ? *p:*min;
	}
}
