#include <stdio.h>
int main(){
	int i,n;
	printf("This program prints a table of squares.\n"); 
	printf("Enter number of entries in table:\n");
	scanf("%d",&n);/*��һ�β�������2147483647������������������2147483648������ʾ�հס�
	�ڶ��β��Խ�����n����Ϊshort�ͺ�ʹ�����������е����n=181
	�����β��Խ�����n����Ϊlong int�ͺ�ʹ�����������е����n=2147483648*/ 
	
	for(i=1;i<=n;i++)
	  printf("%10d%10d\n",i,i*i);
    
    return 0;
	
	
}