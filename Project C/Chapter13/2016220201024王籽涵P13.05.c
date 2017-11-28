/* Sum the instruction codes */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num[argc-1];
    int i = 1, sum = 0;
    
    for (; i < argc;)
    {
        num[i] = atoi(argv[i]);
        sum += num[i++];
    }
    
    printf("Total: %d\n", sum);
    
    return 0;
}
