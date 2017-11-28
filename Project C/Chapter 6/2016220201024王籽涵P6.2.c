/* Find the largest number inputed by user*/

#include <stdio.h>

int main(void)
{
    int m,n,a,i,j;
	
	printf("Enter a fraction: ");
	scanf("%d/%d",&m,&n);
	
	i=m;
	j=n;
	
	while(n!=0){
		a=m%n;
		m=n;
		n=a;
	} 
	
	i=i/m;
	j=j/m;
	
	printf("In lowest terms:%d/%d",i,j);
	
	return 0;
}
