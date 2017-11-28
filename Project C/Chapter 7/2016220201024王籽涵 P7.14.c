/*Computes the square boot in Newton's way*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	double x,y=1;
	
	printf("Enter a positive number: ");
	scanf("%lf",&x);
	 
	while(fabs((1.0/2.0)*(x/y+y)-y)>=0.00001){/***I know how to do it,but I can't understand it......as for now...***/ 
		y=(1.0/2.0)*(y+x/y);
	}
	
	printf("square root: %lf",y);
	
	return 0;
}
