#include <stdio.h>

int main(void)
{
	char ch,a[15];
	int i,j;
	
	printf("Enter phone number: ");
	
	
	for(i=0;ch!='\n';i++){
		ch=getchar();
			
				
		switch(ch){
			case 'A':
			case 'B':
			case 'C':
			a[i]='2';
			break;
			case 'D':
			case 'E':
			case 'F':
			a[i]='3';
			break;
			case 'G':
			case 'H':
			case 'I':
			a[i]='4';
			break;
			case 'J':
			case 'K':
			case 'L':
			a[i]='5';
			break;
			case 'M':
			case 'N':
			case 'O':
			a[i]='6';
			break;
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			a[i]='7';
			break;
			case 'T':
			case 'U':
			case 'V':
			a[i]='8';
			break;
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			a[i]='9';
			break;
			default:
			a[i]=ch;
			
				}
           
		
	}
	 printf("In numeric form:");
            for(j=0;j<=i;j++)
              printf("%c",a[j]);
	
	return 0;
} 
