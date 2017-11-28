/* Print the name with a speciffic structure */

#include <stdio.h>
#include <string.h>

void reverse_name(char *name);

int main(void)
{
    char name[25];
    
    printf("Enter a first and last name: ");
    gets(name);
    
    reverse_name(name);
    
    printf("%s\n", name);
    
    return 0;
}

void reverse_name(char *name)
{
    int n, i = 0;
    char first[4] = ", ";
    
    for (; name[i] == ' '; i++)
        ;
    first[2] = name[i];
    
    first[3] = '\0';
    
    for (; name[i] != ' '; i++)
        ;
    
    for (; name[i] == ' '; i++)
        ;
    
    n = i;
    
    for (; name[i] != ' '; i++){
        name[i-n] = name[i];
    }
    
    name[i-n] = '\0';
    
    strcat(name, first);
    
}
