/*Computes the repeted numbers and their mentioned times*/

#include <stdio.h> 

int main(void)
{
	int digit_seen[10]={0}; 
	int digit;
	long n;
	
	printf("Enter a number: ");
	scanf("%ld",&n);
	
	for (;n>0;n/=10){
	   digit = n%10;
	   digit_seen[digit]++; 
	};
	
	printf("Digit:      ");
	
	for(digit=0;digit<=9;digit++){
		printf("%3d",digit);
	};
	
	printf("\nOccurrences:");
	
	for(digit=0;digit<=9;digit++){
		printf("%3d",digit_seen[digit]);
	};
     
	return 0;
}
