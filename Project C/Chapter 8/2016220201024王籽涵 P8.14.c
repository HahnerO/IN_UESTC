/*Inverse the order of the words in a sentence*/

#include<stdio.h>

int main(void)
{
	int i,f,l;
	char ch[99],punc;

	printf("Enter a sentence: ");
	
	ch[0]=' ';

	for(i=1;;i++){
		ch[i]=getchar();
		if(ch[i]=='?'||ch[i]=='!'||ch[i]=='.')
		break;
	}
	
	punc=ch[i];

	printf("Reversal of sentence:");

	for(i-=1;i>0;i--){
        for(l=i;ch[i]!=' ';i--);
        f=i;
        for(;f<=l;f++){
        	printf("%c",ch[f]);
        }
	}

	printf("%c\n",punc);

	return 0;
} 
