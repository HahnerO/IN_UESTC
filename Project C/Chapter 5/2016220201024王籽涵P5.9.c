/*Compete the earlier date*/

#include <stdio.h>

int main(void)
{
	int d1,m1,y1,d2,m2,y2;
	
	printf("Enter a date (mm/dd/yy): ");
	scanf("%d/%d/%d",&m1,&d1,&y1);
	
	while(m2!=0||d2!=0||y2!=0)
	{
       printf("Enter a date (mm/dd/yy): ");
       scanf("%d/%d/%d",&m2,&d2,&y2);
	   
	   if(m2==0&d2==0&y2==0)
	      break;	
	   else if (y1<y2){
	      m1=m1,d1=d1,y1=y1;} 
       else if (y1>y2){
	      m1=m2,d1=d2,y1=y2;}
       else
          if (m1<m2){
             m1=m1,d1=d1,y1=y1;}
          else if (m1>m2){
             m1=m2,d1=d2,y1=y2;}
          else
            if(d1<d2){
      	       m1=m1,d1=d1,y1=y1;}
   	        else if(d1>=d2){
   	           m1=m2,d1=d2,y1=y2;}
	};
	
	printf("%d/%d/%02d is the earliest date",m1,d1,y1);
	
    return 0;
} 
