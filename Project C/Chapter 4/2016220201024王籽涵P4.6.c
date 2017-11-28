/*Computes a Universal Product Code check digit*/

#include <stdio.h>

int main(void)
{
	int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,sum1,sum2,c;
	
	printf("Enter the first 12 digits of a EAN: ");
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&i1,&i2,&i3,&i4,&i5,&i6,&i7,&i8,&i9,&i10,&i11,&i12);
	
	sum1=i2+i4+i6+i8+i10+i12;
	sum2=i1+i3+i5+i7+i9+i11;
	c=9-(((3*sum1+sum2)-1)%10);
	
	printf("Check digit:%d\n",c);
	
	return 0;
} 
