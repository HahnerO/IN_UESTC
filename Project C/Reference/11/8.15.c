#include<stdio.h>
int main(void)
{
	int n,i,r;
	char ch[80];
	printf("Enter a message to be encrypted: ");
	for(i=0;;i++){
		ch[i]=getchar();
		if (ch[i]=='\n')
		break;
	}
	r=i;
	printf("Enter shift amount (1-25): ");
	scanf("%d",&n);
	for(i=0;i<=r;i++){
		if('A'<=ch[i]&&ch[i]<='Z')
			ch[i]=((ch[i]-'A')+n)%26+'A';
		if('a'<=ch[i]&&ch[i]<='z')
			ch[i]=((ch[i]-'a')+n)%26+'a';
	}
	printf("Encrypted message: ");
	for(i=0;i<=r;i++)
		printf("%c",ch[i]);
	return 0;
} 