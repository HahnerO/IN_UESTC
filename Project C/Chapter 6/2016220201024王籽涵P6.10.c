/*Compete e*/

#include <stdio.h>

int main(void)
{
	float e=1,m;
	int i,n;
	
	printf("Enter a number: ");
	scanf("%d",&n);
	
	for(i=1,m=1;i<=n;i++,m++){
		m*=m;
		e+=1/m;
	};
	
	printf("e=1+1/1!+1/2!+1/3!+...+1/n!=%f",e);
	
    return 0;
} 
