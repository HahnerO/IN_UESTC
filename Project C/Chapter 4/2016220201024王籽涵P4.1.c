/*Print the reversal*/

#include <stdio.h> 

int main(void)
{
	int num;
	
	printf("Enter a number: ");
	scanf("%d",&num);
	
	printf("The reversal is: ");
	for(;num!=0;num/=10)
	  printf("%d",num%10);
	  
    return 0;
	 
}
