#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>							// C99

#define N 100

bool is_palindrome(char a[],int n);

int main(void)
{
	char ch,a[N],*p;
	
	printf("Enter a message: ");
	for(p=a;;){
		ch=getchar();
		if(ch=='\n')
			break;
		if(isalpha(ch)){
			*p=tolower(ch);
			p++;
		}
	}
	if(is_palindrome(a,p-a)==true)					// p-a为读入字母字符的个数 
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");
	
	return 0;
}

bool is_palindrome(char a[],int n)
{
	char *p1=a, *p2=a+n-1;
	for(; p1<a+n; p1++,p2--){
		if(*p1!=*p2)
			return false;
	}
	return true;
}
