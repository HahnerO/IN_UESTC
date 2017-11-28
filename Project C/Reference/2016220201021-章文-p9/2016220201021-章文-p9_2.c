#include <stdio.h>

float calculate(float x);

int main()
{
	float income,tax;
	
	printf("Enter the inclome: $");
	scanf("%f", &income);
	tax = calculate(income);
	
	printf("The tax is $%.2f\n\n",tax);
	return 0;
}

float calculate(float x)
{
	float y;
	if (x<=750) 
	    y=0.01f*x;
	else if (x<=2250) 
	    y=7.5f+0.02f*(x-750);
	else if (x<=3750) 
	    y=37.5f+0.03f*(x-2250);
	else if (x<=5250) 
	    y=82.5f+0.04f*(x-3750);
	else if (x<=7000) 
	    y=142.5f+0.05f*(x-5250);
	else 
	    y=230+0.06f*(x-7000);
	    
    return y;
}
