#include <stdio.h>
int main(){
	int i,n;
	printf("This program prints a table of squares.\n"); 
	printf("Enter number of entries in table:\n");
	scanf("%d",&n);/*第一次测试输入2147483647程序运行正常，输入2147483648程序显示空白。
	第二次测试将变量n定义为short型后，使程序正常运行的最大n=181
	第三次测试将变量n定义为long int型后使程序正常运行的最大n=2147483648*/ 
	
	for(i=1;i<=n;i++)
	  printf("%10d%10d\n",i,i*i);
    
    return 0;
	
	
}