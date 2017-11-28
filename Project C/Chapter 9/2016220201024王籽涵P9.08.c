//
//  main.c
//  Painter
//
//  Created by 王籽涵 on 2016/11/24.
//  Copyright © 2016年 Hahn. All rights reserved.


/*Do a random game*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

int roll_dice(void)
{
    int i,j;
    i=rand()%6+1;
    j=rand()%6+1;
    
    return i+j;
}


BOOL play_game(void)
{
    srand((unsigned) time(NULL));
    
    int i,j;
    i=roll_dice();
    printf("You rolled: %d\n",i);
    
    if(i==7||i==11)
        return TRUE;
    else if(i==2||i==3||i==12)
        return FALSE;
    else{
        for(j=0;j!=i;){
            j=roll_dice();
            printf("You rolled: %d\n",j);
            if(j==7)
                return FALSE;
        }
    }
    
    return TRUE;
}

int main(void)
{
    int i,n,w=0,l=0;
    char ch='y',ent;
    
    for(n=0;ch=='y'||ch=='Y';n++){
        i=play_game();
        if(i==TRUE){
            printf("You win!!!\n\n");
            w++;
        }
        else if(i==FALSE){
            printf("You lose!!!\n\n");
            l++;
        }
        
        printf("Play again? ");
        ch=getchar();
        ent=getchar();
        printf("\n\n");
    }
    
        printf("\nYou totally played %d times\nWins:%d     Loses:%d",n,w,l);
    
    return 0;
    
}
