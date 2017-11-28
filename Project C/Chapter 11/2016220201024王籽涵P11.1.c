/*culculate the least bills of the money we need */

#include <stdio.h>

void pay_amount(int dollars,int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
	int x,a,b,c,d;
	int *twenties = &a, *tens = &b, *fives = &c, *ones = &d;
	
	printf("Enter a dollar amount:  ");
	scanf("%d",&x);
	
	pay_amount(x,twenties,tens,fives,ones);
	
	printf("$20 bills: %d\n", a);
	printf("$10 bills: %d\n", b);
	printf(" $5 bills: %d\n", c);
	printf(" $1 bills: %d\n", d);
	
	return 0;
} 

void pay_amount(int dollars,int *twenties, int *tens, int *fives, int *ones)
{
	*twenties = dollars/20;
	*tens = (dollars - *twenties * 20) / 10;
	*fives = (dollars - *twenties * 20 - *tens * 10) / 5;
	*ones = (dollars - *twenties * 20 - *tens * 10 - *fives * 5) / 1;
}
