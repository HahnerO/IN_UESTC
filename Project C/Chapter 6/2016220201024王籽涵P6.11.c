/*Compete e*/

#include <stdio.h>

int main(void)
{
	float e=1,m,ebsial;
	int i,n;
	
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("Enter ebsial: ");
	scanf("%f",&ebsial);
	
	for(i=1,m=1;i<=n;i++,m++){
		m*=m;
		if (ebsial<=m)
		  e+=1/m;
		else 
          break;
		
	};
	
	printf("e=1+1/1!+1/2!+1/3!+...+1/n!=%f",e);
	
    return 0;
} 
