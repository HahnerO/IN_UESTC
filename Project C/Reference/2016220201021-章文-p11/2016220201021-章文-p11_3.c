#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main()
{
	int numerator, denominator, reduced_n, reduced_d;
	
	printf("Enter a fraction:");
	scanf("%d/%d", &numerator, &denominator);
	
	reduce(numerator, denominator, &reduced_n, &reduced_d);
	
	printf("In lowest terms: %d/%d\n", reduced_n, reduced_d);
	return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
	int big, small, middle;
	
	big = numerator > denominator ? numerator : denominator;
	small = denominator > numerator ? numerator : denominator;
	
	while(small != 0)
	{
		middle = big % small;
		big = small;
		small = middle;
	}
	
	*reduced_numerator = numerator / big;
	*reduced_denominator = denominator / big;
}
