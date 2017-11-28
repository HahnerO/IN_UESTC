#include<stdio.h>
int main(void)
{
	int m,i,r;
	char ch[99],n;
	printf("Enter a sentence: ");
	ch[0]=' ';
	for(i=1;;i++){
		ch[i]=getchar();
		if(ch[i]=='?'||ch[i]=='!'||ch[i]=='.')
		break;
	}
	n=ch[i];
	printf("Reversal of sentence:");
	for(--i;i>0;i=m-1){
		for(m=i;;m--){
			if(ch[m]==' ')
				for(r=m;r<=i;r++)
					printf("%c",ch[r]);

		}
	}
	printf("%c\n",n);
	return 0;
} 