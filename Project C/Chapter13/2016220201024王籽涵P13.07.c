/* Translate the number into English(Pointer version) */


#include <stdio.h>

#define N 10

int main()
{
    int ten_times,one_times;
    char *_teen[N] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *_ty[N] = {"\0", "\0", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *_num[N] = {"\0", "-one", "-two", "-three", "-four", "-five", "-six", "-seven", "-eight", "-nine"};
    
    printf("Enter a two-digit number:");
    scanf("%1d%1d",&ten_times,&one_times);
    
    printf("You entered the number ");
   
    if (ten_times == 1){
        printf("%s\n", _teen[one_times]);
    }
    else{
        printf("%s%s\n", _ty[ten_times], _num[one_times]);
    }
    
    return 0;
}
