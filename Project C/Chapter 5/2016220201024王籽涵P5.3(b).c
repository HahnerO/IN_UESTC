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
	  printf("Clam（无风）");
	else if (v<=3)
	  printf("Light air（轻风）");
	else if (v<=27)
	  printf("Breeze（微风）");
	else if (v<=47)
	  printf("Gale（大风）");
	else if (v<=63)
	  printf("Storm（暴风）");
    else
      printf("Hurricane（飓风）");

    return 0;
} 
