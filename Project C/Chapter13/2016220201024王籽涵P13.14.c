#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define N 30
#define MAX 100

bool are_anagrams(const char *word1, const char *word2);

int main()
{
	char word1[MAX], word2[MAX];
	int check[N] = {0};
	
	printf("Enter first word: ");
	gets(word1);
	printf("Enter second word: ");
	gets(word2);
	
	if (are_anagrams(word1, word2))
	    printf("The words are anagrams.\n");
 	else
 		printf("The words are not anagrams.\n");
}

bool are_anagrams(const char *word1, const char *word2)
{
	int check[N] = {0};
	
	for (; *word1 != '\0'; word1++){
		switch (*word1){
			case 'a': check[0]++; break;
			case 'b': check[1]++; break;
			case 'c': check[2]++; break;
			case 'd': check[3]++; break;
			case 'e': check[4]++; break;
			case 'f': check[5]++; break;
			case 'g': check[6]++; break;
			case 'h': check[7]++; break;
			case 'i': check[8]++; break;
			case 'j': check[9]++; break;
			case 'k': check[10]++; break;
			case 'l': check[11]++; break;
			case 'm': check[12]++; break;
			case 'n': check[13]++; break;
			case 'o': check[14]++; break;
			case 'p': check[15]++; break;
			case 'q': check[16]++; break;
			case 'r': check[17]++; break;
			case 's': check[18]++; break;
			case 't': check[19]++; break;
			case 'u': check[20]++; break;
			case 'v': check[21]++; break;
			case 'w': check[22]++; break;
			case 'x': check[23]++; break;
			case 'y': check[24]++; break;
			case 'z': check[25]++; break;
		}
	}
	for (; *word2 != '\0'; word2++){
		switch (*word2){
			case 'a': check[0]--; break;
			case 'b': check[1]--; break;
			case 'c': check[2]--; break;
			case 'd': check[3]--; break;
			case 'e': check[4]--; break;
			case 'f': check[5]--; break;
			case 'g': check[6]--; break;
			case 'h': check[7]--; break;
			case 'i': check[8]--; break;
			case 'j': check[9]--; break;
			case 'k': check[10]--; break;
			case 'l': check[11]--; break;
			case 'm': check[12]--; break;
			case 'n': check[13]--; break;
			case 'o': check[14]--; break;
			case 'p': check[15]--; break;
			case 'q': check[16]--; break;
			case 'r': check[17]--; break;
			case 's': check[18]--; break;
			case 't': check[19]--; break;
			case 'u': check[20]--; break;
			case 'v': check[21]--; break;
			case 'w': check[22]--; break;
			case 'x': check[23]--; break;
			case 'y': check[24]--; break;
			case 'z': check[25]--; break;
		}
	}
	
	int i = 0;
	for (; i < N; i++)
		if (check[i] != 0)
			break;
	if (i < N)
		return false;
	else
		return true;
}
