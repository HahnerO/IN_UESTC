#include <stdio.h>

void pay_amout(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main()
{
	int dollar, twenty, ten, five, one;
	
	printf("Enter a dollar amount:");
	scanf("%d",&dollar);
	
	pay_amout(dollar, &twenty, &ten, &five, &one);
	
	printf("$20 bills:%d\n",twenty);
	printf("$10 bills:%d\n",ten);
	printf("$5 bills:%d\n",five);
	printf("$1 bills:%d\n",one);
	
	return 0;
}

void pay_amout(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
	*twenties = dollars / 20;
	
	dollars = dollars - 20*(*twenties);
	*tens = dollars / 10;
	
	dollars = dollars - 10*(*tens);
	*fives = dollars / 5;
	
	dollars = dollars - 5*(*fives);
	*ones = dollars;
}

