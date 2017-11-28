/*Adds two fractions*/

#include <stdio.h>

int main(void)
{
	int num1,denom1,num2,denom2,resn,resd;
	
	printf("Enter two fractions separated by a plus sign: ");
	scanf("%d/%d+%d/%d",&num1,&denom1,&num2,&denom2);
	
	resn=num1*denom2+num2*denom1;
	resd=denom1*denom2;
	
	printf("The sum is %d/%d\n",resn,resd);
	
	return 0;
} 
