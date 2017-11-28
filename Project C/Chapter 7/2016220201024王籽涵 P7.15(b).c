/*Culculate the factorial of a positive integer*/

#include <stdio.h>

int main(void)
{
	int n,m,sum=1;
	
	printf("Enter a positive integer: ");
	scanf("%d",&n);
	
	m=n;
	
	for(;n!=1;n--){
		sum*=n;
	}
	
	printf("Factorial of %d: %d",m,sum);
	
	return 0;
} 
