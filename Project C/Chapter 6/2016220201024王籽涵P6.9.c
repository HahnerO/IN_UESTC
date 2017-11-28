/*culculate the least bills of the money we need */

#include <stdio.h>

int main(void)
{
  float loan,rate,payment;
  int num,i;
  
  printf("please enter loan:");
  scanf("%f",&loan);
  printf("please enter rate:");
  scanf("%f",&rate);
  printf("please enter payment:");
  scanf("%f",&payment);
  printf("please enter the pay times:");
  scanf("%d",&num);
   
  for(i=1;i<=num;i++)
  {
    loan=loan*(1+rate/100/12)-payment;
    printf("after %d month,loan is %8.2f\n",i,loan);
  }	
	
	return 0;
} 
