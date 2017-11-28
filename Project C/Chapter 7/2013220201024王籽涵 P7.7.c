/*Computes two fractions in four different way*/

#include <stdio.h>

int main(void)
{
	int a,b,c,d,m,n;
	char ch;
	
	printf("Enter two fractions by culculation sign: ");
	scanf("%d/%d",&a,&b);
	ch=getchar();
	scanf("%d/%d",&c,&d);
	
	switch(ch){
		case '+':
		m=a*d+b*c;
		n=b*d;
		break;
		case '-':
		m=a*d-b*c;
		n=b*d;
		break;
		case '/':
		m=a*c+b*d;
		n=b*c;
		break;
		case '*':
		m=a*c;
		n=b*d;
		break;
	};
	
	if(m=0){
		printf("The result is 0");   /***result can give me ideal one***/
	}
	else {
	    printf("The result is %d/%d",m,n);
	};
	
	return 0;
} 
