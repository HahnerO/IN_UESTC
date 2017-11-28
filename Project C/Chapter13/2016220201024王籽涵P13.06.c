/* Compare the instruction code with a speciffic program */


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

void str_tolower(char *P);

int main(int argc, char *argv[])
{
    char *planets[] = {"mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune", "pluto"};
    int i, j;
    char *ins;
    
    for (i = 1; i < argc; i++){
        ins = argv[i];
        str_tolower(ins);
        
        for (j = 0; j < NUM_PLANETS; j++)
            if (strcmp(ins, planets[j]) == 0){
                printf("%s is planet %d\n", argv[i], j+1);
                break;
            }
        
        if (j == NUM_PLANETS){
            printf("%s is not a planet\n", argv[i]);
        }
    }
    
    return 0;
}


void str_tolower(char *p)
{
    for (; *p != '\0'; p++)
        *p = tolower(*p);
} 
