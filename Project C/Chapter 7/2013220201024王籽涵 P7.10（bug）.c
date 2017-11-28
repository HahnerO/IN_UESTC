/*Computes the times that vowels was mentioned*/

#include <stdio.h>

int main(void)
{
	int times_a=0,times_e=0,times_i=0,times_o=0,times_u=0,i=0;
	char ch;
	
	printf("Enter a sentence: ");
	
	for(;(ch=getchar())!='\n';){
		switch(ch){
			case 'A':
			case 'a':
			times_a++;
			break;
			case 'E':
			case 'e':
			times_e++;
			break;
			case 'I':
			case 'i':
			times_i++;
			break;
			case 'O':
			case 'o':
			times_o++;
			break;
			case 'U':
			case 'u':
			times_u++;
			break;
		}
	}

	i=times_a+times_e+times_i+times_o+times_u;
	printf("Your sentence contains %d vowels.\n",i);
	
	return 0;
} 
