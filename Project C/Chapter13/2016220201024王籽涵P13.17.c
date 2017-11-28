#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool is_palindrome(char *message);
void read_line(char *message);

int main()
{
	char message[255];
	printf("Enter a message: ");
	read_line(message);
	if (is_palindrome(message))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
    return 0;
}

bool is_palindrome(char *message)
{
	char *q, *p;
	
	q = message;
	
	for (; *message != '\0'; message++)
	;
	p = --message;
	
	for (; q < p; q++, p--)
		if (*q != *p)
			break;
	
	if (q < p)
		return false;
	else
		return true;
}

void read_line(char *message)
{
	char ch;
	for (; (ch = getchar()) != '\n';)
		if (isalpha(ch))
			*message++ = tolower(ch);
	*message = '\0';
}
