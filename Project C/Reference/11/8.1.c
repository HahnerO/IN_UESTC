#include <stdio.h>
int main(){
	int a[10]={0},ok=1;
	long n; 
	
	int digit;
	
	
	printf("Enter a number:");
	scanf("%ld",&n);	  
	
	while(n>0){
		digit=n%10;
		a[digit]++;
		if(a[digit]>=2)
		  printf("Repeated number :%d\n",digit);
		n/=10; 
	}
	for(digit=0;digit<=9;digit++){
		
		if(a[digit]>=2)
		  ok=0;
    
      
	}if(ok)
      printf("No repeated number");
	
	return 0;
	
} 
