//
//  main.c
//  Painter
//
//  Created by 王籽涵 on 2016/12/03.
//  Copyright © 2016年 Hahn. All rights reserved.

/*********************************************************
 The fiveth(final) experiment production of this term
 Dosigned & Produced by Hahn
 In language C
 Working tool:
 Xcode
 Production name:
 The supermarket commodity information management system
 *********************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define MAX_ITEMS 200


void menu (void);
int find_items (void);
void edit (void);
void delete (void);
void insert (void);
void print (void);
void save (void);
void search_in_name (void);

int read_line (char str[], int n);



struct items{         //Use struct to define the items
    int item_id;
    char item_name[NAME_LEN + 1];
    float item_price;
    int item_stock;
} ;

struct items *Items[MAX_ITEMS];

int num_parts = 0;





int main (void)        //The main body of the system
{
    system("color F2");
    
    printf("Welcome to the supermarket commodity information management system");
    
    
    char operation,confirm;
    
    
    for ( ; ; ){
        menu();
        printf("Enter operation code: ");
        operation = getchar();
        while (getchar() != '\n')
            ;
        switch (operation){
            case 'e':   edit();
                break;
            case 'd':   delete();
                break;
            case 'i':   insert();
                break;
            case 'q':
                printf("Confirm to QUIT<Y/N>: ");
                if ((confirm = getchar()) == 'y' || confirm == 'Y' ){
                    printf("\nYou quited the system successfully!~\n");
                    return 0;
                }
                else if (confirm == 'n' || confirm == 'N'){
                    getchar();
                    break;
                }
            default:
                printf("Wrong operation code!!!");
                break;
        }
        printf("\n");
    }
    return 0;
}


//Below are the speciffic steps of functions


int find_items (void)
{
    return 1;
}


void edit (void)
{
    
}


void delete (void)
{
    
}


void insert (void)
{
    
}




