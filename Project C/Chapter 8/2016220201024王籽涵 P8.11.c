/*Transform the phone number from character into number*/

#include <stdio.h>

int main(void)
{
	char ch[100]={0};
	int i,j;
	
	printf("Enter phone number: ");
	
	for (i=0;(ch[i]=getchar())!='\n';i++);
	
	printf("In numeric form: ");
	
	for (j=0;j<=i-1;j++){
		switch(ch[j]){
			case 'A':
			case 'B':
			case 'C':
			printf("2");
			break;
			case 'D':
			case 'E':
			case 'F':
			printf("3");
			break;
			case 'G':
			case 'H':
			case 'I':
			printf("4");
			break;
			case 'J':
			case 'K':
			case 'L':
			printf("5");
			break;
			case 'M':
			case 'N':
			case 'O':
			printf("6");
			break;
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			printf("7");
			break;
			case 'T':
			case 'U':
			case 'V':
			printf("8");
			break;
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			printf("9");
			break;
			default:
			printf("%c",ch[j]);
			break;
		}
    }
	return 0;
} 
