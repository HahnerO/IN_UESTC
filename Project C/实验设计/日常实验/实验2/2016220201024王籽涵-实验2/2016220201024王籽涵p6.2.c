#include <stdio.h>
int main(){
	int m,n,i;
	printf("Enter two intergers:");
	scanf("%d%d",&m,&n);
	while(n!=0){
		
		i=m%n;
		m=n;
		n=i;
	}
	if(n==0)
	  printf("Greatest common divisor:%d",m);
} 