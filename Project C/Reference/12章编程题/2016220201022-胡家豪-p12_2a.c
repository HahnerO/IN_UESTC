#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>							// C99

#define N 100

bool is_palindrome(char a[],int n);

int main(void)
{
	char ch,a[N];
	int i;
	
	printf("Enter a message: ");
	for(i=0;;){
		ch=getchar();
		if(ch=='\n')
			break;
		if(isalpha(ch)){
			a[i]=tolower(ch);
			i++;
		}
	}
	if(is_palindrome(a,i)==true)					// iΪ������ĸ�ַ��ĸ��� 
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");
	
	return 0;
}

bool is_palindrome(char a[],int n)
{
	int i;
	for(i=0;i<n;i++){							// ������for����һ��д������Ϊʲô�� 
		if(a[i]!=a[n-1-i])
			return false;
	}
	return true;
}
