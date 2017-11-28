#include <stdio.h>
#include <stdbool.h>
int main(){
	bool digit_seen[10]={false};
	int digit;
	long n;
	
	printf("Enter a number:");
	scanf("%ld",&n);
	
	while(n>0){
	
	while(n>0){
		digit=n%10;
		if(digit_seen[digit])
		  goto L;
        digit_seen[digit]=true;
        n/=10;}
    n=1;
    printf("Enter a number:");
	scanf("%ld",&n);
	}
	L:
	if(n>0)
	  printf("Repeated digit\n");
    else
      printf("No repeated digit\n");
      return 0;
	
	 
}