#include<stdio.h>
#include<ctype.h>
int main(void)
{
	int A[26]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
	int m,sum=0;
	char ch;
	printf("Enter a word: ");
	for(; ;){
		ch=getchar();
		if(ch=='\n')
		break;
		ch=toupper(ch);
		sum+=A[ch-'A'];
	}
	printf("Scrabble value: %d\n",sum);
	return 0;
}