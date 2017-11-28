/* Comeputes the numbers of vowel */

#include <stdio.h>

int compute_vowel_count(const char *sentence);

int main()
{
    char sentence[255];
    int number;
    
    printf("Enter a sentence: ");
    
    gets(sentence);
    
    number = compute_vowel_count(sentence);
    printf("Your sentence contains %d vowels.\n", number);
    
    return 0;
}

int compute_vowel_count(const char *sentence)
{
    int i = 0;
    
    for (; *sentence != '\0'; sentence++){
        if (*sentence == 'a' || *sentence == 'A' || *sentence == 'e' || *sentence == 'E' || *sentence == 'i' || *sentence == 'I' || *sentence == 'o' || *sentence == 'O' || *sentence == 'u' || *sentence == 'U')
            i++;
    }
    
    return i;
}
