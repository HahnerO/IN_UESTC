/*Computes the bit of a number*/

#include <stdio.h>

int main(void)
{
	int a,b;
	
	printf("Enter a 24-hour time: ");
	scanf("%d:%d",&a,&b);
	
	if (a<0||a>24||b<0||b>=60){
		printf("Wrong!!!");
	}
    else if (a<=12){
	  printf("Equivalent 12-hour time: %d:%d AM",a,b);
	  }
	else if(a<=24){
	  printf("Equivalent 12-hour time: %d:%d PM",a-12,b);
	  } 
    
    return 0;
} 
