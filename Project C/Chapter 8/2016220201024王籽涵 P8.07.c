/*Computes a 5*5 array's sums*/

#include <stdio.h>

int main (void)
{
	int num[5][5],i,j,row_1,row_2,row_3,row_4,row_5,column_1,column_2,column_3,column_4,column_5;
	
	for (i=0;i<5;i++){
		printf("Enter row %d: ",i+1);
		for (j=0;j<5;j++){
			scanf("%d",&num[i][j]);
		}
	}
	
	row_1=num[0][0]+num[0][1]+num[0][2]+num[0][3]+num[0][4];
	row_2=num[1][0]+num[1][1]+num[1][2]+num[1][3]+num[1][4];
	row_3=num[2][0]+num[2][1]+num[2][2]+num[2][3]+num[2][4];
	row_4=num[3][0]+num[3][1]+num[3][2]+num[3][3]+num[3][4];
	row_5=num[4][0]+num[4][1]+num[4][2]+num[4][3]+num[4][4];
	column_1=num[0][0]+num[1][0]+num[2][0]+num[3][0]+num[4][0];
	column_2=num[0][1]+num[1][1]+num[2][1]+num[3][1]+num[4][1];
	column_3=num[0][2]+num[1][2]+num[2][2]+num[3][2]+num[4][2];
	column_4=num[0][3]+num[1][3]+num[2][3]+num[3][3]+num[4][3];
	column_5=num[0][4]+num[1][4]+num[2][4]+num[3][4]+num[4][4];
	
	printf("Row totals:   %3d\t%3d\t%3d\t%3d\t%3d\t\n",row_1,row_2,row_3,row_4,row_5);
	printf("Column totals:%3d\t%3d\t%3d\t%3d\t%3d\t",column_1,column_2,column_3,column_4,column_5);
	
	return 0;
} 
