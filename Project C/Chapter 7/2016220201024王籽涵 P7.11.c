/*Show the name*/

#include <stdio.h>

int main(void)
{
	char ch_1,ch_2;
	
	printf("Enter a first and last name: ");
	ch_1=getchar();
	
	while((ch_2=getchar())!=' ');
	
	while((ch_2=getchar())!='\n'){
		putchar(ch_2);
	};
	
	printf(", %c",ch_1);
	
	return 0;
} 
