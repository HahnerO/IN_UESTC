/* Find the largest or smallest word */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 20
#define STOP_LEN 4

int read_line(char str[]);

int main()
{
    int word_len;
    char word[MAX_LEN+1];
	char largest_word[MAX_LEN+1], smallest_word[MAX_LEN+1];

	
	printf("Enter word:  ");
	word_len = read_line(word);
	
	strcpy(largest_word, word);
	strcpy(smallest_word, word);
	
	for (;;)
	{
		if (word_len == STOP_LEN)
		    break;
        if (strcmp(largest_word, word) < 0)
		    strcpy(largest_word, word);
        if (strcmp(smallest_word, word) > 0)
            strcpy(smallest_word, word);
		

        
		printf("Enter word:  ");
		word_len = read_line(word);
	}
	
	printf("\nSmallest word: %s\n", smallest_word);
	printf("Largest word: %s\n", largest_word);
	
	return 0;
}

int read_line(char str[])
{
    int i = 0;
    for ( ;(str[i] = getchar()) != '\n' && i < MAX_LEN; i++);
    str[i] = '\0';
	
	return i;
}
