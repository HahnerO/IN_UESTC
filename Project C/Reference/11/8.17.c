#include<stdio.h>
int main(void)
{
	int r,m,i=1,n,A[99][99]={0};
	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square£º ");
	scanf("%d",&n);
	r=0;
	m=(n-1)/2;
	A[r][m]=i;
	for(i++;i<=n*n;A[r][m]=i,i++){
		if(r-1!=-1&&m+1!=n&&A[r-1][m+1]!=0){
			r++;
			continue;
		}
		if(r-1==-1&&m+1!=n&&A[n-1][m+1]!=0){
			r++;
			continue;
		}
		if(r-1!=-1&&m+1==n&&A[r-1][0]!=0){
			r++;
			continue;
		}
		if(r-1==-1&&m+1==n&&A[n-1][0]!=0){
			r++;
			continue;
		}
		if(r-1!=-1&&m+1!=n&&A[r-1][m+1]==0){
			r--;
			m++;
			continue; 
		}
		if(r-1==-1&&m+1==n&&A[n-1][0]==0){
			r=n-1;
			m=0;
			continue;	
		}
		if(r-1==-1&&m+1!=n&&A[n-1][m+1]==0){
			r=n-1;
			m++;
			continue;
		}
		if(r-1!=-1&&m+1==n&&A[r-1][0]==0){
			r--;
			m=0;
			continue;
		}
	}
	for(r=0;r<n;r++){
		for(m=0;m<n;m++)
			printf("%5d",A[r][m]);
		printf("\n");
	}	
	return 0; 
	
} 