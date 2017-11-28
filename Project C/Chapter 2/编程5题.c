/*culculate a specific polynomial:((((3*x+2)*x-5)*x-1)*x+7)*x-6 */

#include <stdio.h>

int main(void)
{
	float x,result;
	
	printf("Enter x:  ");
	scanf("%f",&x);
	result = ((((3*x+2)*x-5)*x-1)*x+7)*x-6;
	
	printf("The result is: %.2f\n",result);
	
	return 0;
} 
