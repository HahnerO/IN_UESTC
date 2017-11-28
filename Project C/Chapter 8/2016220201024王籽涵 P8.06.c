/*Program a B1FF filter machine*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char B1FF[100]={0};
	int i,j;
	
	printf("Enter message:");
	
	for(i=0;(B1FF[i]=getchar())!='\n';i++);
	
	for(j=0;j<=i-1;j++){
		switch(B1FF[j]){
			case 'a':
			case 'A':
			    putchar('4');
			    break;
            case 'b':
            case 'B':
                putchar('8');
                break;
            case 'e':
            case 'E':
                putchar('3');
                break;
            case 'i':
            case 'I':
                putchar('1');
                break;
            case 'o':
            case 'O':
                putchar('0');
                break;
            case 's':
            case 'S':
                putchar('5');
                break;
            default:
                B1FF[j]=toupper(B1FF[j]);
                putchar(B1FF[j]);
                break;
		}
	}
	
	printf("!!!!!!!!!!\n");
	
	return 0;
} 
