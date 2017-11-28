#include<stdio.h>
#include<ctype.h>
int main(void)
{
	int A[26]={0},i;
	char ch;
	printf("Enter first word: ");
	for(;;){
		ch=getchar();
		if(ch=='\n')
			break;
		ch=tolower(ch);
		if(isalpha(ch)==0)
			continue;
		A[ch-'a']++;
	}
	printf("Enter second word: ");
	for(;;){
		ch=getchar();
		if(ch=='\n')
			break;
		ch=tolower(ch);
		if(isalpha(ch)==0)
			continue;
		A[ch-'a']--;
	}
	for(i=0;i<26;i++){
		if(A[i])
			break;		
	}
	if(i==26)
		printf("The words are anagrams.\n");
	else
		printf("The words are not anagrams.\n");
	return 0;
}