#include<stdio.h>

#define N 100

int main(void)
{
	char str[N],*p,ch,terminating_ch,*p_start,*p_end;
	
	printf("Enter a sentence: ");
	for(p=str;;p++){
		*p=getchar();
		if(*p=='.'||*p=='?'||*p=='!'){
			terminating_ch=*p;
			break;
		}
	}
	
	printf("Reversal of sentence: ");
	
	for(p_end=--p;;p--){
		if(p==str){
			for(p_start=p; p_start<=p_end; p_start++)
				putchar(*p_start);
			break;
		}
		if(*p==' '){
			for(p_start=p+1; p_start<=p_end; p_start++)
				putchar(*p_start);
			putchar(' ');
			p_end=p-1;
		}
	}
	putchar('\n');
	
	return 0;
} 
