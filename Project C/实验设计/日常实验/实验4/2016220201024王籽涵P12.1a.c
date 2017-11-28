#include <stdio.h>
#define LEN 500

int main(){
    char ch,a[LEN];
    int i;
    printf("Enter a maessage(The length should not be more than %d): ",LEN);
    
    for(i=0;(ch=getchar())!='\n' && i<LEN;i++){
        a[i]=ch;
    }
    
    printf("The reversal is:");
    
    for(;i>=0;i--)
        printf("%c",a[i]);
    
    printf("\n");
    
    return 0;
}
