/*culculate the least bills of the money we need */

#include <stdio.h>

int main(void)
{
	float a,b,c,d,e,f;
	
	printf("Enter amount of loan:  ");
	scanf("%f",&a);
	printf("Enter interest rate:  ");
	scanf("%f",&b);
	printf("Enter monthly payment:  ");
	scanf("%f",&c);
	
	d= a*b/100.0f/12 +a-c;
	e=d*b/100.0f/12 +d-c;
	f=e*b/100.0f/12 +e-c;
	
	printf("Balance remaining after first payment: %.2f\n",d);
	printf("Balance remaining after second payment: %.2f\n",e);
	printf("Balance remaining after third payment: %.2f\n",f);
	
	
	return 0;
} 
