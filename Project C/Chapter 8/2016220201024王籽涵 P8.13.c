/*Show the name*/

#include <stdio.h>

int main(void)
{
	char first,last[20];
	int i,j;
	
	printf("Enter a first and last name: ");
	first=getchar();
	
	for (i=0;(last[i]=getchar())!=' ';i++);
	
	for (i=0;(last[i]=getchar())!='\n';i++);
		
	printf("You entered the name: ");
	for (j=0;j<=i-1;j++){
		putchar(last[j]);
	}
	
	printf(", %c",first);
	
	return 0;
} 
