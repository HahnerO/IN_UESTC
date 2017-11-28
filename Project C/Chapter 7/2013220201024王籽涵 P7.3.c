#include <stdio.h>
int main(){
	double n,sum=0;
	printf("This program sums seriesof intergers.\n");
	printf("Enter intergers(0 to terminate):");
	
	scanf("%lf",&n);
	while(n!=0){
		sum+=n;
		scanf("%lf",&n);
	}
	printf("The sum is: %lf\n",sum);
	return 0;
	
	 
} 