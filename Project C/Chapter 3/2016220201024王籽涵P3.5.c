/*Culculate a 4x4 matrix by specific ways given by users*/

#include <stdio.h>

int main(void)
{
	int num1,num2,num3,num4,num5,num6,num7,num8,num9,num10,num11,num12,num13,num14,num15,num16,row1,row2,row3,row4,column1,column2,column3,column4,diagonal1,diagonal2;
	
	printf("Enter the numbers from 1 to 16 in any order: \n");
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&num1,&num2,&num3,&num4,&num5,&num6,&num7,&num8,&num9,&num10,&num11,&num12,&num13,&num14,&num15,&num16);
	
	row1=num1+num2+num3+num4;
	row2=num5+num6+num7+num8;
	row3=num9+num10+num11+num12;
	row4=num13+num14+num15+num16;
	column1=num1+num5+num9+num13;
	column2=num2+num6+num10+num14;
	column3=num3+num7+num11+num15;
	column4=num4+num8+num12+num16;
	diagonal1=num1+num6+num11+num16;
	diagonal2=num4+num7+num10+num13;
	
	printf("%d\t%d\t%d\t%d\n",num1,num2,num3,num4);
	printf("%d\t%d\t%d\t%d\n",num5,num6,num7,num8);
	printf("%d\t%d\t%d\t%d\n",num9,num10,num11,num12);
	printf("%d\t%d\t%d\t%d\n\n",num13,num14,num15,num16);
	
	printf("Row sums: %d\t%d\t%d\t%d\n",row1,row2,row3,row4);
	printf("Column sums: %d\t%d\t%d\t%d\n",column1,column2,column3,column4);
	printf("Diagonal sums: %d\t%d\n",diagonal1,diagonal2);
	
	return 0;
} 
