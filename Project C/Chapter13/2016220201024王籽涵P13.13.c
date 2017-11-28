/* Reverse the words the sentence */

#include <stdio.h>

#define N 80
#define M 26

void encrypt(char *message, int shift);

int main()
{
    char message[N+1];
    int shift;
    
    printf("Enter message to be encrypted: ");
    gets(message);
    
    printf("Enter shift amout (1-25): ");
    scanf("%d", &shift);
    
    encrypt(message, shift);
    
    printf("Encrypted message: %s\n", message);
    
    return 0;
}

void encrypt(char *message, int shift)
{
    while (*message != '\0'){
        if (*message >= 'A' && *message <= 'Z'){
            if (*message+shift > 'Z')
                *message = *message+shift-M;
            else
                *message += shift;
        }
        
        if (*message >= 'a' && *message <= 'z'){
            if (*message+shift > 'z')
                *message = *message+shift-M;
            else
                *message += shift;
        }
        message++；
    }
}


