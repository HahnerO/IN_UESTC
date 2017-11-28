#include <stdio.h>

#define N 255

void reverse(char *message);

int main()
{
	char message[255];
	printf("Enter a message: ");
	gets(message);
	reverse(message);
	printf("Reversal is: %s\n", message);
	return 0;
}

void reverse(char *message)
{
	char *p, *q, ch;
	
	p = message;
	
	for (; *message != '\0'; message++)
	;
	q = --message;
	
	for (; p < q; p++, q--){
		ch = *p;
		*p = *q;
		*q = ch;
	}
}
