/*Culculate the price of a word*/

#include <stdio.h>

int main(void)
{
	int i,j,sum;
	char ch[100];
	
	printf("Enter a word: ");
	
	for(i=0;(ch[i]=getchar())!='\n';i++);

    for(j=0;j<=i-1;j++){
		switch(ch[j]){
			case 'a':
			case 'e':
			case 'i':
			case 'l':
			case 'n':
			case 'o':
			case 'r':
			case 's':
			case 't':
			case 'u':
			sum+=1;
			break;
			case 'd':
			case 'g':
			sum+=2;
			break;
			case 'b':
			case 'c':
			case 'm':
			case 'p':
			sum+=3;
			break;
			case 'f':
			case 'h':
			case 'v':
			case 'w':
			case 'y':
			sum+=4;
			break;
			case 'k':
			sum+=5;
			break;
			case 'j':
			case 'x':
			sum+=8;
			break;
			case 'q':
			case 'z':
			sum+=10;
			break;
		}
	}
	
	printf("Scrabble value: %d",sum);
	
	return 0;
}
