/*computes the length of sentence*/

#include <stdio.h>

int main(void)
{
	float i,j;
	char ch;
	
	printf("Enter a sentence: ");
	
	for(i=0,j=1;(ch=getchar())!='\n';){
		if(ch==' '){
			j++;
		}
		else{
			i++;
		};
	}
	
	printf("Average word length: %.1f",i/j);
	
	return 0;
}
