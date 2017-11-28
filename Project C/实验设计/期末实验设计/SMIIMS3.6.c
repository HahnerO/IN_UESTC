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
#define STRUCT_LEN sizeof(struct info_items)

#define TRUE 1
#define FALSE 0

#define F_PATH "/Users/hahn/Desktop/Item_Information.txt"


void main_menu (void);
void edit (void);
void delete (void);
void insert (void);
void sort (void);
void print (void);
void format (void);
void search (void);

struct info_items* read_line (FILE* fp);



struct info_items{         //Use struct to define the items
    int item_id;
    char item_name[NAME_LEN + 1];
    float item_price;
    int item_stock;
} ;

struct info_items *items[MAX_ITEMS];

int num_items = 0;





int main (void)        //The main body of the system
{
    system("color F2");
    
    char operation,confirm,start_code, safe_code;
    
S:  printf("System will be started based on  file Items_Information.txt \n\n");
    printf("START or QUIT?<S/Q>: ");
    start_code = getchar();
    safe_code = getchar();
    
    for ( ; safe_code != '\n'; ){
        while ((safe_code = getchar()) != 'n');
        printf("Illeagle instruction, please input again: ");
        start_code = getchar();
        safe_code = getchar();
    }
    
    if (start_code == 's' || start_code == 'S'){
        printf("Start successfully!!!\n\nPress any key to coutinue.");
        getchar();
    }
    else if (start_code == 'q' || start_code == 'Q'){
        printf("Confirm to QUIT<Y/N>: ");
        if ((confirm = getchar()) == 'y' || confirm == 'Y' ){
            printf("\nYou quited the system successfully!~\n");
            return 0;
        }
        else if (confirm == 'n' || confirm == 'N'){
            getchar();
            goto S;
        }
    }
    
    
    
    
 M: for ( ; ; ){
        main_menu();
    
        printf("Enter operation code: ");
        operation = getchar();
        while (getchar() != '\n')
            ;
        switch (operation){
            case '1':   search();
                break;
            case '2':   edit();
                break;
            case '3':   delete();
                break;
            case '4':   insert();
                break;
            case '5':   sort();
                break;
            case '6':   format();
                break;
            case '7':   print();
                break;
            case '9':
                printf("Confirm to QUIT<Y/N>: ");
                if ((confirm = getchar()) == 'y' || confirm == 'Y' ){
                    printf("\nYou quited the system successfully!~\n");
                    return 0;
                }
                else if (confirm == 'n' || confirm == 'N'){
                    getchar();
                    break;
                }
            case '0':
                goto M;
            default:
                printf("Wrong operation code!!!");
                break;
        }
        printf("\nPress any key to contimue.\n");
        getchar();
        system ("cls");
    }
    return 0;
}


//Below are the speciffic steps of functions


void main_menu (void)
{
    printf("Welcome to the supermarket commodity information management system\n\n");
    printf("******************************************************\n");
    printf("*                                                    *\n");
    printf("*              1 - Search the item                   *\n");
    printf("*                                                    *\n");
    printf("*              2 - Edit the item                     *\n");
    printf("*                                                    *\n");
    printf("*              3 - Delete the item                   *\n");
    printf("*                                                    *\n");
    printf("*              4 - Insert the item                   *\n");
    printf("*                                                    *\n");
    printf("*              5 - Sort the items                    *\n");
    printf("*                                                    *\n");
    printf("*              6 - Format the items                  *\n");
    printf("*                                                    *\n");
    printf("*              7 - Print the items' table            *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*              0 - BACK                              *\n");
    printf("*              9 - QUIT                              *\n");
    printf("*                                                    *\n");
    printf("******************************************************\n\n");
}





void edit_menu (void)
{
    printf("Welcome to the supermarket commodity information management system\n\n");
    printf("******************************************************\n");
    printf("*                                                    *\n");
    printf("*              1 - Edit the ID                       *\n");
    printf("*                                                    *\n");
    printf("*              2 - Edit the name                     *\n");
    printf("*                                                    *\n");
    printf("*              3 - Edit the price                    *\n");
    printf("*                                                    *\n");
    printf("*              4 - Edit the stock                    *\n");
    printf("*                                                    *\n");
    printf("*              5 - Edit all the features             *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*              0 - BACK                              *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("******************************************************\n\n");}





void print (void)
{
    int  i,j = 0;
    FILE *fp = NULL;
    if ((fp = fopen(F_PATH,"r")) == NULL){
        fprintf(stderr,"Can't open it, please check it carefully!!!");
        return;
    }
    while(!feof(fp)){
        items[j] = read_line(fp);
        j++;
        num_items++;
    }
    if (j == 0){
        printf("Nothing in the file!");
        return;
    }

    fclose(fp);
    printf("ID\t\t\t\t\tNAME\t\t\t\t\tPRICE\t\t\t\t\tSTOCK\n");
    for (i = 0; i < j; i++){
        printf("%-10d\t\t\t",items[i]->item_id);
        printf("%-20s\t",items[i]->item_name);
        printf("%-10.2f\t\t\t",items[i]->item_price);
        printf("%-10d\n",items[i]->item_stock);
    }

    return;
}









void sort (void)
{
    int i,j = 0;
    int sort_way;
    int m,n;
    struct info_items trans_item;
    
    for (i = 0; i < MAX_ITEMS; i++){
        items[i] = (struct info_items*)malloc(STRUCT_LEN);
    }
    
    FILE *fp = NULL;
    if ((fp = fopen(F_PATH,"r")) == NULL){
        fprintf(stderr,"Can't open it, please check it carefully!!!");
        return;
    }
    while(!feof(fp)){
        items[j] = read_line(fp);
        j++;
    }
    if (j == 0){
        printf("Nothing in the file!");
        return;
    }
    fclose(fp);
    
SORT:printf("Use ID/NAME/PRICE/STOCK to sort <I/N/P/S>: ");
    sort_way = getchar();
    switch (sort_way) {
        case 'i':
        case 'I':
            for (n = j; n > 0; n--){
                for (m = 0; m < n; m++){
                    if (items[m]->item_id > items[m + 1]->item_id){
                        trans_item = *items[m];
                        *items[m] = *items[m+1];
                        *items[m + 1] = trans_item;
                    }
                }
            }
            break;
        case 'n':
        case 'N':
            for (n = j; n > 0; n--){
                for (m = 0; m < n; m++){
                    if (strcmp(items[m]->item_name, items[m + 1]->item_name) > 0){
                        trans_item = *items[m];
                        *items[m] = *items[m+1];
                        *items[m + 1] = trans_item;
                    }
                }
            }
            break;
        case 'p':
        case 'P':
            for (m = 0; m < j - 1; m++){
                for (n = m + 1; n < j; n++){
                    if (items[m]->item_price > items[n]->item_price){
                        trans_item.item_id = items[m]->item_id;
                        strcpy(trans_item.item_name, items[m]->item_name);
                        trans_item.item_price = items[m]->item_price;
                        trans_item.item_stock = items[m]->item_stock;
                        *items[m] = *items[n];
                        *items[n] = trans_item;
                    }
                }
            }
            break;
        case 's':
        case 'S':
            for (n = j; n > 0; n--){
                for (m = 0; m < n; m++){
                    if (items[m]->item_stock > items[m + 1]->item_stock){
                        trans_item = *items[m];
                        *items[m] = *items[m+1];
                        *items[m + 1] = trans_item;
                    }
                }
            }
            break;
        default:
            printf("\nIlleagle instruction code!\nPlease check carefully!!\n");
            getchar();
            goto SORT;
    }
    
    fp = fopen(F_PATH, "w");
    for (i = 0; i < j - 1; i++){
        fprintf(fp, "%10d\t\t%20s\t\t%20.2f\t\t\t%10d\n", items[i]->item_id, items[i]->item_name, items[i]->item_price, items[i]->item_stock);
    }
    
    fclose(fp);
    printf("Sort successfully!~");

    return;
}






void search (void)
{
    int i,j = 0;
    int id;
    char name[NAME_LEN + 1];
    char search_way;
    
    for (i = 0; i < MAX_ITEMS; i++){
        items[i] = (struct info_items*)malloc(STRUCT_LEN);
    }
    
    FILE *fp;
    if ((fp = fopen(F_PATH,"r")) == NULL){
        fprintf(stderr,"Can't open it, please check it carefully!!!");
        return;
    }
    while(!feof(fp)){
        items[j] = read_line(fp);
        j++;
    }
    if (j == 0){
        printf("Nothing in the file!");
        return;
    }
    fclose (fp);
        
  SERCH:printf("Use ID/NAME to search the item <I/N>: ");
        search_way = getchar();
        switch (search_way) {
            case 'i':
            case 'I':
                printf("\nPlease enter the ID of item: ");
                scanf("%d", &id);
                for(i = 0; i < j; i++){
                    if (items[i]->item_id == id){
                        printf("\nID\t\tNAME\t\tPRICE\t\tSTOCK\n");
                        printf("%d\t\t%s\t\t%.2f\t\t%d\n", items[j]->item_id, items[j]->item_name, items[j]->item_price, items[j]->item_stock);
                        break;
                    }
                }
                if (i == j){
                    printf("Didn't find the item, please check the ID!");
                }
                break;
            case 'n':
            case 'N':
                getchar();
                printf("\nPlease enter the NAME of item: ");
                scanf("%s",name);
                for(i = 0; i < j; i++){
                    if (strcmp(items[i]->item_name, name) == 0){
                        printf("\nID\t\tNAME\t\tPRICE\t\tSTOCK\n");
                        printf("%d\t\t%s\t\t%.2f\t\t%d\n", items[j]->item_id, items[j]->item_name, items[j]->item_price, items[j]->item_stock);
                        break;
                    }
                }
                if (i ==j){
                    printf("Didn't find the item, please check the ID!");
                }
            default:
                printf("\nIlleagle instruction code!\nPlease check carefully!!\n");
                getchar();
                goto SERCH;
        }

        for (i = 0; i < MAX_ITEMS; i++){
            free(items[i]);
        }
        return;
    }








void edit (void)
{
    int i,j = 0;
    char name[NAME_LEN + 1];
    for (i = 0; i < MAX_ITEMS; i++){
        items[i] = (struct info_items*)malloc(STRUCT_LEN);
    }
    
    FILE *fp;
    
    fp = fopen(F_PATH, "r+");
    if (fp == NULL){
        printf("Open failed , please check carefully.\n");
        return;
    }
    else{
        while(!feof(fp)){
            if((fread(items[j], STRUCT_LEN, 1, fp)) == 1){
                j++;
            }
        }
        printf("Plsase enter the name of good: ");
        scanf("%s", name);
        for (i = 0; i <= j+1; i++){
            if (strcmp(name, items[i]->item_name) == 0){
                system("cls");
                edit_menu();                            // _edit_menu()
                
            }
        }
    }
    if (i == j + 1){
        printf("Didn't find the item!!!\n");
        return;
    }
    
    printf("Edit successfully!!!");
    
    rewind (fp);
    for (i = 0; i < j; i++){
        fwrite(items[i], STRUCT_LEN, 1, fp);
    }
    fclose(fp);
    for (i = 0; i < 100; i++){
        free(items[i]);
    }
    
    printf("\nPress any key to contimue.\n");
    getchar();
    system ("cls");
    
    return;
}








void format (void)
{
    int i, j = 0;
    FILE *fp;
    if ((fp = fopen(F_PATH,"r")) == NULL){
        fprintf(stderr,"Can't open it, please check it carefully!!!");
        return;
    }
    else {
        while (!feof(fp)){
            if (fread(items[j], STRUCT_LEN, 1, fp) == 1){
                j++;
            }
            if (j ==0){
                printf("\nTXT has already been formatted!\n");
                return;
            }
            else{
                for(i = 0; i < MAX_ITEMS; i++){
                    free(items[i]);
                }
                
                printf("\nFormatted successfully!!!");
                
                fclose(fp);
                
                return;
            }
        }
    }
}


    
    
    
    
    
    
    
void delete (void)
{
    int i, j = 0;
    char name[NAME_LEN];
    for (i = 0; i < MAX_ITEMS; i++){
        items[i] = (struct info_items*)malloc(NAME_LEN);
    }
    
    FILE *fp;

    if ((fp = fopen(F_PATH,"r")) == NULL){
        fprintf(stderr,"Can't open it, please check it carefully!!!");
        return;
    }
    else {
        while (!feof(fp)){
            if (fread(items[j], NAME_LEN, 1, fp) == 1){
                j++;
            }
        }
        printf("Plsase enter the name of good: ");
        scanf("%s", name);
        for (i = 0; i <= j+1; i++){
            if (strcmp(name, items[i]->item_name) == 0){
                printf("");                            // _delete_menu
                
                
                
                
                
                
            }
        }
    }
    if (i == j + 1){
        printf("Didn't find the item!!!\n");
        return;
    }
    
    printf("Delete successfully!!!\n");
    
    rewind (fp);
    for (i = 0; i < j; i++){
        fwrite(items[i], STRUCT_LEN, 1, fp);
    }
    
    fclose(fp);
    
    for (i = 0; i < 100; i++){
        free(items[i]);
    }
    
    printf("\nPress any key to contimue.\n");
    getchar();
    system ("cls");
    
    return;
}







void insert (void)
{
    int i, j = 0;
    for (i = 0; i < MAX_ITEMS; i++){
        items[i] = (struct info_items*)malloc(NAME_LEN);
    }
    struct info_items *new_item;
    new_item = (struct info_items*)malloc(NAME_LEN);
    
    FILE *fp;
    
    if ((fp = fopen(F_PATH,"r+")) == NULL){
        fprintf(stderr,"Can't open it, please check it carefully!!!");
        return;
    }
    else {
        while (!feof(fp)){
            if (j >= MAX_ITEMS){
                printf("The number of items is maxium, can't add more!!!");
                fclose (fp);
                return;
            }
            if(fread(items[j], STRUCT_LEN, 1, fp) == 1){
                j++;
            }
            else if (fread(items[j], STRUCT_LEN, 1, fp) != 1){
                break;
            }
        }
        printf("Please enter the following features: \n");
        
    ID: printf("\nItem's ID: ");
        scanf("%d", &items[j]->item_id);
        for (i = 0; i < j; i++){
            if (items[i]->item_id == items[j]->item_id){
                printf("\nThis ID has already exists!\n");
                goto ID;
            }
        }
        
    NA: printf("\nItem's name: ");
        scanf("%s", items[j]->item_name);
        for (i = 0; i < j; i++){
            if (strcmp(items[i]->item_name, items[j]->item_name) == 0){
                printf("This name has already exists!\n");
                goto NA;
            }
        }
        
        printf("\nItem's price: ");
        scanf("%f", &items[j]->item_price);
        printf("\nItem's stock: ");
        scanf("%d", &items[j]->item_stock);
    }
    
    printf("\nYou've inserted the item successfully\n");
    printf("ID\tNAME\t\tPRICE\tSTOCK\n");
    printf("%d\t%s\t\t%.2f\t%d\t", items[j]->item_id, items[j]->item_name, items[j]->item_price, items[i]->item_stock);
    
    rewind(fp);
    
    free(new_item);
    for(i = 0; i <= j; i++){
    fwrite(items[i], STRUCT_LEN, 1, fp);
    }
    
    fclose(fp);
    for (i = 0; i < 100; i++){
        free(items[i]);
    }
    
    printf("\nPress any key to contimue.\n");
    getchar();
    system ("cls");
    
    return;
}


void open_file (void)
{
    int  j = 0;
    FILE *fp;
    if ((fp = fopen(F_PATH,"r")) == NULL){
        fprintf(stderr,"Can't open it, please check it carefully!!!");
        return;
    }
    while(!feof(fp)){
        items[j] = read_line(fp);
        j++;
        num_items++;
    }
    if (j == 0){
        printf("Nothing in the file!");
        return;
    }
    return;
}



struct info_items* read_line (FILE* fp)
{
    struct info_items* items = malloc(STRUCT_LEN);
    fscanf(fp, "%d", &items->item_id);
    fscanf(fp, "%s", items->item_name);
    fscanf(fp, "%f", &items->item_price);
    fscanf(fp, "%d", &items->item_stock);
    return items;
}
