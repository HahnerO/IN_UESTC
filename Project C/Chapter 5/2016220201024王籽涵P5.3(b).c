/*Computes the level of the wind*/

#include <stdio.h>

int main(void)
{
	float v;
	
	printf("Enter the velocity of the wind: ");
	scanf("%f",&v);
	
	if (v<0)
	  printf("Illegal velocity\n");
	else if (v<=1)
	  printf("Clam���޷磩");
	else if (v<=3)
	  printf("Light air����磩");
	else if (v<=27)
	  printf("Breeze��΢�磩");
	else if (v<=47)
	  printf("Gale����磩");
	else if (v<=63)
	  printf("Storm�����磩");
    else
      printf("Hurricane��쫷磩");

    return 0;
} 
