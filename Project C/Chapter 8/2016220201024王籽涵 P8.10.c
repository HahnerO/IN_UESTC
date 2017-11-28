/*Find out the closest flight*/

#include<stdio.h>

int main(void)
{
	int hour,minute,n,i,c;
	const int A[8]={8*60,9*60+43,11*60+19,12*60+47,14*60,15*60+45,19*60,21*60+45};
	const int B[8]={10*60+16,11*60+52,13*60+31,15*60,16*60+8,17*60+55,21*60+20,23*60+58};
	
	printf("Enter a 24-hour time: ");
 	scanf("%d:%d",&hour,&minute);
 	
    n=hour*60+minute;
 	
 	for(i=0,c=0;i<=7;i++){
		if(n-A[c]>0&&n-A[i]>0)
			if(n-A[c]<n-A[i])
				;
			else
				c=i;
		if(n-A[c]>0&&n-A[i]<0)
			if(n-A[c]<A[i]-n)
				;
			else 
				c=i;
		if(n-A[c]<0&&n-A[i]>0)
			if(A[c]-n<n-A[i])
				;
			else 
				c=i; 
		if(n-A[c]<0&&n-A[i]<0)
			if(A[c]-n<A[i]-n)
				;
			else 
				c=i; 
	 }

	if(A[c]<12*60) 
 	printf("Clostest departure time is %.2d:%.2d a.m.",A[c]/60,A[c]%60);
 	if(A[c]>=13*60)
 	printf("Clostest departure time is %.2d:%.2d p.m.",A[c]/60-12,A[c]%60);
 	else
 	printf("Clostest departure time is %.2d:%.2d p.m.",A[c]/60,A[c]%60);
	if(B[c]<12*60)
	printf(", arriving at %.2d:%.2d a.m.\n",B[c]/60,B[c]%60);
	if(B[c]>=13*60)
	printf(", arriving at %.2d:%.2d p.m.\n",B[c]/60-12,B[c]%60);
	else
 	printf(", arriving at %.2d:%.2d p.m.\n",B[c]/60,B[c]%60);
	return 0;
}
