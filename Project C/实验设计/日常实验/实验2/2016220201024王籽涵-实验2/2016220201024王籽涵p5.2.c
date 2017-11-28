#include <stdio.h>
int main(){
	int i1,i2,j;
	printf("Enter a 24-hour time:");
	scanf("%d:%d",&i1,&j);
	if(i1<12)
	  printf("Equivalent 12-hour time:%d:%dAM\n",i1,j);
    else if(i1==12&&j==00)
	  printf("Equivalent 12-hour time:12:00"); 
	else if(i1>=12&&j!=00)
      i2=i1-12;
      printf("Equivalent 12-hour time:%d:%dPM",i2,j);
    return 0;
   
} 
