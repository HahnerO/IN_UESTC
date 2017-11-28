#include <stdio.h>

float power(float x,int n);

int main()
{
	float x,y;
	int n;
	
	printf("Enter x and n (x n): ");
	scanf("%f %d",&x,&n);
	
	y = power(x,n);
	
	printf("x^n = %f\n",y);
	return 0;
}

float power(float x,int n)
{
	if (n == 0)
	    return 1;
    else if (n%2 == 0)
        return power(x,n/2)*power(x,n/2);
    else if (n%2 == 1)
        return x*power(x,n-1);
}
