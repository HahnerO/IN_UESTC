/*Transform 12-hour time into 24-hour time*/

#include <stdio.h>

int main(void)
{
	int hour,min;
	char ch;
	
	printf("Enter a 12-hour time: ");
	scanf("%d:%d %c",&hour,&min,&ch);
	if(ch=='P'){
		hour+=12;
	}
	
	printf("Equivalent 24-hour time: %d:%d",hour,min);
	
	return 0;
} 
