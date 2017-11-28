#include <stdio.h>
#define N 1000

int main(){
    
    char ch,a[N],*p;
    p=a;
    printf("Enter a maessage(The length should not be more than 1000): ");
    
    for(;(ch=getchar())!='\n';p++)
        *p=ch;
    printf("The reversal is:");
    
    for(;p>=a;p--)
        printf("%c",*p);
    
    printf("\n");
    
    return 0;
    
}
