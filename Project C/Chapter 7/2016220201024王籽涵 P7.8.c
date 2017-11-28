/*Find out the closest flight*/

#include <stdio.h>

int main(void)
{
	int i1,i2,i3,i4,i5,i6,i7,i8,j1,j2,j3,j4,n1,n2,t,a,b,c;
	char ch;
	
	printf("Enter a 12-hour time: ");
	scanf("%d:%d",&a,&b);
	do{
		ch=getchar() ;
	} while(ch==' ');
	
	if(ch=='p'){
		c=60*(a+12)+b;
	}
	if(ch=='P'){
		c=60*(a+12)+b;
	}
	if(ch=='a'){
		c=60*a+b;
	}
	if(ch=='A'){
		c=60*a+b;
	};
	
	if(480>c)
	  i1=480-c;
    else
      i1=c-480;
      
   	if(583>c)
	  i2=583-c;
    else
      i2=c-583;
      
	if(679>c)
	  i3=679-c;
    else
      i3=c-679;
      
	if(767>c)
	  i4=767-c;
    else
      i4=c-767;
      
	if(840>c)
	  i5=840-c;
    else
      i5=c-840;
      
	if(945>c)
	  i6=945-c;
    else
      i6=c-945;
      
	if(1140>c)
	  i7=1140-c;
    else
      i7=c-1140;
      
	if(1305>c)
	  i8=1305-c;
    else
      i8=c-1305;
      
    if(i1<i2)
      j1=i1;
    else
      j1=i2;
      
    if(i3<i4)
      j2=i3;
    else
      j2=i4;
      
    if(i5<i6)
      j3=i5;
    else
      j3=i6;
      
    if(i7<i8)
      j4=i7;
    else
      j4=i8;
      
    if(j1<j2)
      n1=j1;
    else
      n1=j2;
      
    if(j3<j4)
      n2=j3;
    else
      n2=j4;
    
	if(n1<n2)
	  t=n1;
	else
	  t=n2;
	  
	if(t==i1)
	  printf("Closest departure time is 8:00a.m.,arriving at 10:16a.m.");
	else if(t==i2)
	  printf("Closest departure time is 9:43a.m.,arriving at 11:52a.m.");
	else if(t==i3)
	  printf("Closest departure time is 11:19a.m.,arriving at 1:31p.m.");
	else if(t==i4)
	  printf("Closest departure time is 12:47p.m.,arriving at 3:00p.m.");
	else if(t==i5)
	  printf("Closest departure time is 2:00p.m.,arriving at 4:08p.m.");
	else if(t==i6)
	  printf("Closest departure time is 3:45p.m.,arriving at 5:55p.m.");
	else if(t==i7)
	  printf("Closest departure time is 7:00p.m.,arriving at 9:20p.m.");
	else if(t==i8)
	  printf("Closest departure time is 9:45p.m.,arriving at 11:58p.m.");
	  
    return 0;
} 
