/*Conputes the volume of a sphere from input provided by user */

#include <stdio.h>

int main(void)
{
	int radius,volume;
	
	printf("inter radius of sphere:  ");
	scanf("%d",&radius);
	volume = 4.0f/3.0f*3.14*radius*radius*radius;
	
	printf("volume: %d\n",volume);
	
	return 0;
} 
