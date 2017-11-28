/*Culculates a series of brokers' commission*/

#include <stdio.h>

int main(void)
{
	float com,val;
    
    do{
	printf("Enter value of trade: ");
    scanf("%f",&val);
    
    if (val==0)
      return 0;
    else if (val<2500.00f)
      com=30.00f+.017f*val;
    else if (val<6250.00f)
      com=56.00f+.0066f*val;
    else if (val<20000.00f)
      com=76.00f+.0034f*val;
    else if (val<50000.00f)
      com=100.00f+.0022f*val;
    else if (val<500000.00)
      com=155.00f+.0011f*val;
    else
      com=255.00f+.0009f*val;
      
    if (com<39.00f)
      com=39.00f;
      
    printf("Commission: $%.f\n",com);}while(val!=0);
    
    return 0;
}
