/* Sums the number of character */

#include <stdio.h>

int compute_scrable_value(const char *word);

int main()
{
    char *word;
    int value;
    
    printf("Enter a word: ");
    scanf("%s", word);
    
    value = compute_scrable_value(word);
    
    printf("Scrabble value: %d\n", value);
    
    return 0;
}

int compute_scrable_value(const char *word)
{
    int value = 0;
    
    for (; *word != '\0'; word++)
    {
        if (*word == 'a' || *word == 'e' || *word == 'i' || *word == 'l' || *word == 'n' || *word == 'o' || *word == 'r' || *word == 's' || *word == 't' || *word == 'u'){
            value += 1;
        }
        else if (*word == 'd' || *word == 'g'){
            value += 2;
        }
        else if (*word == 'b' || *word == 'c' || *word == 'm' || *word == 'p'){
            value += 3;
        }
        else if (*word == 'f' || *word == 'h' || *word == 'v' || *word == 'w' || *word == 'y'){
            value += 4;
        }
        else if (*word == 'k'){
            value += 5;
        }
        else if (*word == 'j' || *word == 'x'){
            value += 8;
        }
        else if (*word == 'q' || *word == 'z'){
            value += 10;
        }
    }
    
    return value;
}
