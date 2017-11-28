#include<stdio.h>
#include<string.h>
#define WORD_LENTH 50

int main()
{
    char smallest_word[WORD_LENTH], largest_word[WORD_LENTH], new_word[WORD_LENTH];
    
    printf("Enter word: ");
    scanf("%s", new_word);
    strcpy(smallest_word, new_word);
    strcpy(largest_word, new_word);
    
    for(;;)
    {
        printf("Enter word: ");
        scanf("%s", new_word);
        if(strcmp(smallest_word, new_word)>0){
            strcpy(smallest_word, new_word);
        }
        if(strcmp(largest_word, new_word)<0){
            strcpy(largest_word, new_word);
        }
        if(strlen(new_word)==4)
            break;
    }
    
    printf("\nSmallest word: %s\n",smallest_word);
    printf("Largest word: %s\n",largest_word);
    
    return 0;
}
