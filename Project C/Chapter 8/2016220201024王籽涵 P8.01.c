/*Show the repeted digits*/ 

#include <stdio.h>
#define BOOL int
#define TRUE 1
#define FALSE 0 

int main(void)
{
	int digit_seen[10]={FALSE}; 
	int digit;
	long n;
	
	printf("Enter a number: ");
	scanf("%ld",&n);
	
	printf("Repeated digit(s):");
	while(n>0){
	 digit = n%10;
	 if(digit_seen[digit]){
 		printf("%3d",digit);
 	}
 	else
     digit_seen[digit] = TRUE;
     n/=10;
	}
     
	return 0;
}
