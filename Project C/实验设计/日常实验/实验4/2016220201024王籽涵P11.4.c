/*Clasifies a poker hand*/
#include <stdio.h>
#include <stdlib.h>
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
void read_cards(int r[],int s[]);
void analyze_hand(int *a,int *b,int *c,int *d,int *e,int r[],int s[]);
void print_result(int *a,int *b,int *c,int *d,int *e);
int main(void)
{
    int num_in_rank[NUM_RANKS];
    int num_in_suit[NUM_SUITS];
    int a,b,c,d,e;
    for (;;) {
        read_cards(num_in_rank,num_in_suit);
        analyze_hand(&a,&b,&c,&d,&e,num_in_rank,num_in_suit);
        print_result(&a,&b,&c,&d,&e);
    }
}
void read_cards(int r[],int s[])
{
    int card_exists[NUM_RANKS][NUM_SUITS];
    char ch,rank_ch,suit_ch;
    int rank,suit;
    int bad_card;
    int cards_read=0;
    for (rank=0;rank<NUM_RANKS;rank++) {
        r[rank]=0;
        for (suit=0;suit<NUM_SUITS;suit++)
            card_exists[rank][suit]=0;
    }
    for (suit=0;suit<NUM_SUITS;suit++)
        s[suit]=0;
    while (cards_read<NUM_CARDS) {
        bad_card=0;
        printf("Enter a card:");
        rank_ch=getchar();
        switch (rank_ch) {
            case '0':exit(EXIT_SUCCESS);
            case '2':rank=0;break;
            case '3':rank=1;break;
            case '4':rank=2;break;
            case '5':rank=3;break;
            case '6':rank=4;break;
            case '7':rank=5;break;
            case '8':rank=6;break;
            case '9':rank=7;break;
            case 't':case 'T':rank=8;break;
            case 'j':case 'J':rank=9;break;
            case 'q':case 'Q':rank=10;break;
            case 'k':case 'K':rank=11;break;
            case 'a':case 'A':rank=12;break;
            default:bad_card=1;
        }
        suit_ch=getchar();
        switch (suit_ch) {
            case 'c':case 'C':suit=0;break;
            case 'd':case 'D':suit=1;break;
            case 'h':case 'H':suit=2;break;
            case 's':case 'S':suit=3;break;
            default:bad_card=1;
        }
        while ((ch=getchar())!='\n')
            if (ch!=' ') bad_card=1;
        if (bad_card)
            printf("Bad card;ignored.\n");
        else if (card_exists[rank][suit])
            printf("Duplicate card;ignored.\n");
        else {
            r[rank]++;
            s[suit]++;
            card_exists[rank][suit]=1;
            cards_read++;
        }
    }
}
void analyze_hand(int *a,int *b,int *c,int *d,int *e,int r[],int s[])
{
    int num_consec=0;
    int rank,suit;
    *a=0;
    *b=0;
    *c=0;
    *d=0;
    *e=0;
    for (suit=0;suit<NUM_SUITS;suit++)
        if (s[suit]==NUM_CARDS)
            *b=1;
    rank=0;
    while (r[rank]==0) rank++;
    for (;rank<NUM_RANKS&&r[rank]>0;rank++)
        num_consec++;
    if (num_consec==NUM_CARDS) {
        *a=1;
        return;
    }
    for (rank=0;rank<NUM_RANKS;rank++) {
        if (r[rank]==4) *c=1;
        if (r[rank]==3) *d=1;
        if (r[rank]==2) (*e)++;
    }      
}
void print_result(int *a,int *b,int *c,int *d,int *e)
{
    if (*a&&*b) printf("Straight flush");
    else if (*c) printf("Four of a kind");
    else if (*d&&*e==1) printf("Full house");
    else if (*b) printf("Flush");
    else if (*a) printf("Straight");
    else if (*d) printf("Three of a kind");
    else if (*e==2) printf("Two pairs");
    else if (*e==1) printf("Pair");
    else printf("High card");
    printf("\n\n");
}
