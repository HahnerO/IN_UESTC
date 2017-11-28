/* Sums a series of numbers 
  ********************************************************    
	  实验结果：
	  直接回车后，程序不会继续执行，等待用户输入内容
	  输入数组 不含0，程序仍然不会继续执行，直至用户输入0
  *******************************************************/

#include <stdio.h>

int main(void)
{
	int n,sum = 0;
	
	printf("This program sums a series of integers.\n");
	printf("Enter integers (0 to terminate): ");
	
	scanf("%d",&n);
	while (n!=0){
		sum+=n;
		scanf("%d",&n);
	}
	printf("The sum is: %d\n",sum);
	
	return 0;
}
