/*Encrypt the sentence in Caesar's law*/

#include <stdio.h>

int main (void)
{
	char ch[80];
	int i,n,m;
	
	printf("Enter message to be encrypted: ");
	
	for(i=0;(ch[i]=getchar()) != '\n';i++);
	
	m=i;
	
	printf("Enter shift amount (1-25): ");
	scanf("%d",&n);
	
	for(i=0;i<=m;i++){
		if('A'<=ch[i]&&ch[i]<='Z')
			ch[i]=((ch[i]-'A')+n)%26+'A';
		if('a'<=ch[i]&&ch[i]<='z')
			ch[i]=((ch[i]-'a')+n)%26+'a';
	}
	
	printf("Encrypted message: ");
	
	for (i=0;i<=m;i++){
		printf("%c",ch[i]);
	}
	
	return 0;
}
