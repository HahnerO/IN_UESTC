#include <stdio.h> 
int main(void) {    
int digit_count[10] = {0};   

int digit;   

long n;     
printf("Enter a number: ");   
scanf("%ld", &n); 

while (n > 0) {     
digit = n % 10;      
digit_count[digit]++;     
n /= 10;   }    


printf ("Digit:      ");   

for (digit = 0; digit <= 9; digit++)     
printf("%3d", digit);   

printf("\nOccurrences:");    

for (digit = 0; digit <= 9; digit++)     
printf("%3d", digit_count[digit]);   

printf("\n");     
return 0;}