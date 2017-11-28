/*Computes the repeted numbers and their mentioned times*/

#include <stdio.h> 

int main(void)
{
	int digit_seen[10]={0}; 
	int digit;
	long n,i;
	
	printf("Enter a number: ");
	
	for (;n!=0;){
	   scanf("%ld",&n);
	   i=n;
	   for (;i>0;i/=10){
	      digit = i%10;
	      digit_seen[digit]++; 
	   }
	}
	
	digit_seen[0]++;
	
	printf("Digit:      ");
	
	for(digit=0;digit<=9;digit++){
		printf("%3d",digit);
	}
	
	printf("\nOccurrences:");
	
	for(digit=0;digit<=9;digit++){
		printf("%3d",digit_seen[digit]);
	}
     
	return 0;
}
