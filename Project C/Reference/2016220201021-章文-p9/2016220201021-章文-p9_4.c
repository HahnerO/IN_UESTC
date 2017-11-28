#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define N 26
#define M 255

void read_word(int counts[N]);
bool equal_array(int counts1[N],int counts2[N]);

int num,num1,num2;

int main()
{
	int counts1[N] = {0},counts2[N] = {0};
	
	printf("Enter first word: ");
	read_word(counts1);
	num1 = num;
	
	printf("Enter second word: ");
	read_word(counts2);
	num2 = num;
	
	if (equal_array(counts1,counts2))
	    printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");
}

void read_word(int counts[N])
{
	int i;
	char ch;
	
	for (i = 0; (ch = getchar()) != '\n'; i++)
	{
		if (isalpha(ch))
		    ch = tolower(ch);
		
		switch (ch)
		{
			case 'a': counts[0]++; break;
			case 'b': counts[1]++; break;
			case 'c': counts[2]++; break;
			case 'd': counts[3]++; break;
			case 'e': counts[4]++; break;
			case 'f': counts[5]++; break;
			case 'g': counts[6]++; break;
			case 'h': counts[7]++; break;
			case 'i': counts[8]++; break;
			case 'j': counts[9]++; break;
			case 'k': counts[10]++; break;
			case 'l': counts[11]++; break;
			case 'm': counts[12]++; break;
			case 'n': counts[13]++; break;
			case 'o': counts[14]++; break;
			case 'p': counts[15]++; break;
			case 'q': counts[16]++; break;
			case 'r': counts[17]++; break;
			case 's': counts[18]++; break;
			case 't': counts[19]++; break;
			case 'u': counts[20]++; break;
			case 'v': counts[21]++; break;
			case 'w': counts[22]++; break;
			case 'x': counts[23]++; break;
			case 'y': counts[24]++; break;
			case 'z': counts[25]++; break;
		}
	}
	num = i;
}

bool equal_array(int counts1[N],int counts2[N])
{
	int i;
	
	if (num1 != num2)
	    return false;
    else
    {
    	for (i = 0; i < N; i++)
    	{
	    	if (counts1[i] != counts2[i])
	    	    return false;
	    }
	    return true;
    }
}
