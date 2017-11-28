/*culculate the least bills of the money we need */

#include <stdio.h>

int main(void)
{
	int x,a,b,c,d;
	
	printf("Enter a dollar amount:  ");
	scanf("%d",&x);
	
	a=x/20;
	b=(x-a*20)/10;
	c=(x-a*20-b*10)/5;
	d=(x-a*20-b*10-c*5)/1;
	
	printf("$20 bills: %d\n",a);
	printf("$10 bills: %d\n",b);
	printf(" $5 bills: %d\n",c);
	printf(" $1 bills: %d\n",d);
	
	return 0;
} 
