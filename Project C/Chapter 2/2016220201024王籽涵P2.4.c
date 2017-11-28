/*Culculate the amount with tex*/

#include <stdio.h>

int main(void)
{
    float amount,tax;
    
    printf("Enter an amoumt:");
    scanf("%f",&amount );
    
    tax=amount*1.05f;
    
    printf("With tax added:%.2f",tax);
    
    return 0;
}
