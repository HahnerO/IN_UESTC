#include <stdio.h>

float calculate(float x);
float power(float x,int n);

int main()
{
	float x,y;
	
	printf("Enter x: ");
	scanf("%f",&x);
	
	y = calculate(x);
	printf("3x^5+2x^4-5x^3-x^2+7x-6 = %f\n",y);
	
	return 0;
}

float calculate(float x)
{
	float y;
	
	y = 3*power(x,5) + 2*power(x,4) - 5*power(x,3) - power(x,2) + 7*x - 6;
	
	return y;
}

float power(float x,int n)
{
	if (n == 1)
	    return x;
    else
        return x*power(x,n-1);
}
