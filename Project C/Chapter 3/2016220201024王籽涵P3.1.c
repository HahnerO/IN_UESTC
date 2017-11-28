/*Change date from mm/dd/yy to yyyymmdd*/

#include <stdio.h>

int main(void)
{
	int a,b,c;
	
	printf("Enter a date (mm/dd/yyyy):  ");
	scanf("%d/%d/%d",&b,&c,&a);
	
	printf("You entered the date %d%02d%02d\n",a,b,c);
}
