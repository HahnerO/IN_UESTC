//
//  main.c
//  Painter
//
//  Created by 王籽涵 on 2016/12/03.
//  Copyright © 2016年 Hahn. All rights reserved.

/* Turn fractions into lowest one(pointer version) */

#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void)
{
    int numer, denom, *re_numer, *re_denom, reduced_numerator, reduced_denominator;
    re_numer = &reduced_numerator, re_denom = &reduced_denominator;
    
    printf("Enter a fraction:");
    scanf("%d/%d", &numer, &denom);
    
    reduce(numer, denom, re_numer, re_denom);
    
    printf("In lowest terms: %d/%d", *re_numer, *re_denom);
    
    return 0;
}


void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int small, middle, big;
    
    big = (numerator > denominator ? numerator : denominator);
    small = (denominator > numerator ? numerator : denominator);
    
    for(;small;)
    {
        middle = big % small;
        big = small;
        small = middle;
    }
    
    *reduced_numerator = numerator / big;
    *reduced_denominator = denominator / big;
}
