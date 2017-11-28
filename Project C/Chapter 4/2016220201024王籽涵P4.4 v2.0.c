/*Computes a Universal Product Code check digit*/

#include <stdio.h>
 
int main(void)  
{
	int d,i1,i2,i3,i4,i5,j1,j2,j3,j4,j5,sum1,sum2,t;
	
	printf("Enter the first 11 digits of a UPC: ");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&d,&i1,&i2,&i3,&i4,&i5,&j1,&j2,&j3,&j4,&j5);
	
	sum1=d+i2+i4+j1+j3+j5;
	sum2=i1+i3+i5+j2+j4;
	t=3*sum1+sum2;
	
	printf("Check digit:%d\n",9-((t-1)%10));
	
	return 0;
}
