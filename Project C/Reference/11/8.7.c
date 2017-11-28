#include <stdio.h>
int main(){
	int a[5][5],row,column,row_1,row_2,row_3,row_4,row_5,column_1,column_2,column_3,column_4,column_5;
	
	for(row=0;row<5;row++){
		printf("Enter row %d:",row+1);
		for(column=0;column<5;column++)
		  scanf("%d",&a[row][column]);
	}
	row_1=a[0][0]+a[0][1]+a[0][2]+a[0][3]+a[0][4];
	row_2=a[1][0]+a[1][1]+a[1][2]+a[1][3]+a[1][4];
	row_3=a[2][0]+a[2][1]+a[2][2]+a[2][3]+a[2][4];
	row_4=a[3][0]+a[3][1]+a[3][2]+a[3][3]+a[3][4];
	row_5=a[4][0]+a[4][1]+a[4][2]+a[4][3]+a[4][5];
	column_1=a[0][0]+a[1][0]+a[2][0]+a[3][0]+a[4][0];
	column_2=a[0][1]+a[1][1]+a[2][1]+a[3][1]+a[4][1];
	column_3=a[0][2]+a[1][2]+a[2][2]+a[3][2]+a[4][2];
	column_4=a[0][3]+a[1][3]+a[2][3]+a[3][3]+a[4][3];
	column_5=a[0][4]+a[1][4]+a[2][4]+a[3][4]+a[4][4];
	
	printf("Row totals:   %3d\t%3d\t%3d\t%3d\t%3d\t\n",row_1,row_2,row_3,row_4,row_5);
	printf("Column totals:%3d\t%3d\t%3d\t%3d\t%3d\t",column_1,column_2,column_3,column_4,column_5);
	
	return 0;


} 
