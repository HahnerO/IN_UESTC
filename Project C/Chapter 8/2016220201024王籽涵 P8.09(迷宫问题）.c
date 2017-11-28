/*Describe the trade of a 10*10 array*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define M 10
#define N 10

int main(void)
{
	char trade[M][N],str;
	int x,y,z,f,n;
	
	for (x=0;x<M;x++){
		for (y=0;y<N;y++){
			trade[M][N]='.';
		}
	}
	
	for (x=0;x<M;x++){
		printf("\n");
		for (y=0;y<N;y++){
			printf("%c",trade[M][N]);
		}
	}
	
	printf("\n");
	
	srand((unsigned)time(NULL));
	
} 