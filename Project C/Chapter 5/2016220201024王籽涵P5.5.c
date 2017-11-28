/*Computes the text of salary*/

#include <stdio.h>

int main(void)
{
	float sala,tax;
	
	printf("Enter the salary: ");
	scanf("%f",&sala);
	
	if (sala<0)
	  printf("Illegal salary");
	else if (sala<=750)
	  tax=.01f*sala;
	else if (sala<=2250)
	  tax=7.50+.02f*(sala-750);
	else if (sala<=3750)
	  tax=37.50+.03f*(sala-2250);
	else if (sala<=5250)
	  tax=82.50+.04f*(sala-3750);
	else if (sala<=7000)
	  tax=142.50+.05f*(sala-5250);
    else
      tax=230.00+.06f*(sala-7000);
      
    printf("The tax is: %.2f\n",tax);
      
    return 0;
} 
