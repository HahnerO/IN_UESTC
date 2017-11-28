/*Computes square in sppeciffic way*/

#include <stdio.h>

int main(void)
{
	int day,count,c,i;
	
	printf("Enter number of days in mouth: ");
	scanf("%d",&day);
	printf("Enter starting day of the week(1=Sun,7=Sat): ");
	scanf("%d",&count);
	
	c=day+count-1;
	
	for(i=1;i<=c;i++){
		if(i<count){
			printf("\t");
		}
		else if(i%7!=0){
			printf("%d\t",i-count+1);
		}
		else if(i%7==0){
			printf("%d\n",i-count+1);
		}
	}
	  
    return 0;
} 
