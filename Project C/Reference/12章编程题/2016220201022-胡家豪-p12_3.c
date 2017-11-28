#include<stdio.h>

#define N 100

int main(void)
{
	char a[N],*p;
	
	printf("Enter a messsage: ");
	for(p=a;;p++){
		*p=getchar();
		if(*p=='\n')
			break;	
	}
	
	printf("Reversal is: ");
	for(p=p-1;p>=a;p--){
		putchar(*p);
	}
	putchar('\n');
	
	return 0;
}
