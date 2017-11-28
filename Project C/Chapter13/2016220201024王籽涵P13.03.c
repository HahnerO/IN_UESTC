/* Show the full cards in hand */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define BOOL int
#define TRUE 1
#define FALSE 0

int main()
{
    int i, j;
    BOOL in_hand[NUM_SUITS][NUM_RANKS];
    int num_cards, rank, suit;
    const char *rank_code[] = {"Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
    const char *suit_code[] = {"clubs","siamods","hearts","spades"};
    for (i = 0; i < NUM_SUITS; i++){
        for (j = 0; j < NUM_RANKS; j++){
            in_hand[i][j] = FALSE;
        }
    }
    
    srand((unsigned) time(NULL));
    
    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);
    
    printf("Your hand:\n");
    
    while (num_cards > 0){
        suit = rand() % NUM_SUITS;
        rank = rand() % NUM_RANKS;
        
        if (!in_hand[suit][rank]){
            in_hand[suit][rank] = TRUE;
            num_cards--;
            printf("%s of %s\n", rank_code[rank], suit_code[suit]);
        }
    }
    
    printf("\n");
    
    return 0;
}

