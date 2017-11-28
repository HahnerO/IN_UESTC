/* Computes the length of the sentence */

#include <stdio.h>

double compute_average_word_length(const char *sentence);

int main()
{
    double average;
    char sentence[100];

    printf("Enter a sentense: ");
    gets(sentence);
    
    average = compute_average_word_length(sentence);
    
    printf("Average word lengh: %.1lf\n", average);
    
    return 0;
}

double compute_average_word_length(const char *sentence)
{
    int word = 0;
    int letter = 0;
    
    for (;;)
    {
        for (; *sentence == ' ' && *sentence != '\0'; sentence++)
            ;
        
        if (*sentence == '\0')
            break;
        
        for (; *sentence != ' ' && *sentence != '\0'; sentence++){
            letter++;
        }
        
        word++;
        
        if (*sentence == '\0')
            break;
    }
    
    return (double) letter / word;
}

