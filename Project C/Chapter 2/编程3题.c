/*culculate the price with tax */

#include <stdio.h>

int main(void)
{
	float amount,result;
	
	printf("Enter an amount:  ");
	scanf("%f",&amount);
	result = 1.05f*amount;
	
	printf("With tax added:$ %.2f\n",result);
	
	return 0;
} 
