/* Reverse the words the sentence */

#include <stdio.h>

#define WORD_NUM 30
#define MAX_LEN 20

int main()
{
    char word[WORD_NUM][MAX_LEN+1];
    int num_word, len_letter;
    int max;
    char ch;
    
    printf("Enter a sentence: ");
    
    for (num_word = 0, len_letter	 = 0; (ch = getchar()) != '.' && ch != '?' && ch != '!'; ){
        if (ch != ' '){
            word[num_word][len_letter] = ch;
            len_letter++;
        }
        
        if (ch == ' ' && len_letter	 != 0){
            word[num_word][len_letter] = '\0';
            num_word++;
            len_letter = 0;
        }
    }
    
    word[num_word][len_letter] = '\0';
    max = num_word;
    
    printf("Reverse of sentence: ");
    
    for (; num_word >= 0; num_word--){
        printf("%s", word[num_word]);
        if (num_word != 0)
            printf(" ");
        else
            printf("%c\n", ch);
    }
    
    return 0;
}


