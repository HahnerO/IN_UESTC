#include<stdio.h>

#define N 100

int main(void)
{
	char a[N];
	int i;
	
	printf("Enter a messsage: ");
	for(i=0;;i++){
		a[i]=getchar();
		if(a[i]=='\n')
			break;	
	}
	
	printf("Reversal is: ");
	for(i=i-1;i>=0;i--){
		putchar(a[i]);
	}
	putchar('\n');
	
	return 0;
}
