/*Transform the grade into level
  我实在不知道拆分成两个数字该怎么做
  因为如果是100就是三个数字了
  .........                 sorry*/

#include <stdio.h>

int main(void)
{
	int a,b;
	
	printf("Enter numerical grade: ");
	scanf("%d",&a);
	b=a/10;
	
	switch(b){
	  case 10:
	  case 9 :   printf("A");
                 break;
      case 8 :   printf("B");
                 break;
      case 7 :   printf("C");
                 break;
      case 6 :   printf("D");
                 break;
      case 5 :
      case 4 :
      case 3 :
      case 2 :
      case 1 :
      case 0 :   printf("F");
                 break;
      }
      
      return 0;
}
