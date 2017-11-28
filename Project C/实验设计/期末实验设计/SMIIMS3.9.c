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
    char item_name[NAME_LEN];
    char item_cate[NAME_LEN];
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
        while ((safe_code = getchar()) != '\n');
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
    
    
    
    
    for ( ; ; ){
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
            default:
                printf("Wrong operation code!!!");
                break;
        }
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
    printf("*                                                    *\n");
    printf("*              9 - QUIT                              *\n");
    printf("*                                                    *\n");
    printf("******************************************************\n\n");
}





int edit_menu_and_function (int i)
{
    int j;;
    
    char operation;
    int id;
    char name[NAME_LEN];
    char category[NAME_LEN];
    float price;
    int stock;
    
    printf("Welcome to the supermarket commodity information management system\n\n");
    printf("******************************************************\n");
    printf("*                                                    *\n");
    printf("*              1 - Edit the ID                       *\n");
    printf("*                                                    *\n");
    printf("*              2 - Edit the name                     *\n");
    printf("*                                                    *\n");
    printf("*              3 - Edit the category                 *\n");
    printf("*                                                    *\n");
    printf("*              4 - Edit the price                    *\n");
    printf("*                                                    *\n");
    printf("*              5 - Edit the stock                    *\n");
    printf("*                                                    *\n");
    printf("*              6 - Edit all the features             *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("*              0 - BACK                              *\n");
    printf("*                                                    *\n");
    printf("*                                                    *\n");
    printf("******************************************************\n\n");

    printf("Enter the operation code to edit: ");
    
O:  getchar();
    operation = getchar();
    switch (operation) {
        case '1':
            printf("Enter the ID you want to change: ");
        ID: scanf("%d", &id);
            for (j = 0; j < num_items; j++){
                if (items[j]->item_id == id){
                    printf ("\nThis ID has already been existed!!!, please chang another one: ");
                    goto ID;
                }
            }
            items[i]->item_id = id;
            break;
        case '2':
            printf("Enter the NAME you want to change: ");
      NAME: scanf("%s", name);
            for (j = 0; j < num_items; j++){
                if (strcmp(items[j]->item_name, name) == 0){
                    printf ("\nThis NAME has already been existed!!!, please chang another one: ");
                    goto NAME;
                }
            }
            strcpy(items[i]->item_name, name);
            break;
        case '3':
            printf("Enter the CATEGORY you want to change: ");
            scanf("%d", &id);
            
            
                                                                       // NEED EDIT
            
            
            items[i]->item_id = id;
            break;
        case '4':
            printf("Enter the PRICE you want to change: ");
            scanf("%f", &price);
            items[i]->item_price = price;
            break;
        case '5':
            printf("Enter the STOCK you want to change: ");
            scanf("%d", &stock);
            items[i]->item_stock = stock;
            break;
        case '6':
            printf("Enter the ID you want to change: ");
      ID_A: scanf("%d", &id);
            for (j = 0; j < num_items; j++){
                if (items[j]->item_id == id){
                    printf ("This ID has already been existed!!!, please chang another one: ");
                    goto ID_A;
                }
            }
            items[i]->item_id = id;
            
            printf("Enter the NAME you want to change: ");
    NAME_A: scanf("%s", name);
            for (j = 0; j < num_items; j++){
                if (strcmp(items[j]->item_name, name) == 0){
                    printf ("\nThis NAME has already been existed!!!, please chang another one: ");
                    goto NAME_A;
                }
            }
            strcpy(items[i]->item_name, name);
            
                                                  //NEED ADD
            
            printf("Enter the PRICE you want to change: ");
            scanf("%f", &price);
            items[i]->item_price = price;
            
            printf("Enter the STOCK you want to change: ");
            scanf("%d", &stock);
            items[i]->item_stock = stock;
            break;
        case '0':
            system("clr");
            main_menu();
            return 0;
        default:
            printf("Wrong operation code, please enter agian: ");
            goto O;
    }
    return 1;
}





void print (void)
{
    int  i,j = 0;
    
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

    num_items = j;
    
    if (j == 0){
        printf("Nothing in the file!");
        return;
    }

    fclose(fp);
    printf("\nID\t\t\t\t\tNAME\t\t\t\t\tCATEGORY\t\t\t\tPRICE\t\t\t\t\tSTOCK\n");
    for (i = 0; i < j; i++){
        printf("%-10d\t\t\t",items[i]->item_id);
        printf("%-20s\t",items[i]->item_name);
        printf("%-20s\t",items[i]->item_cate);
        printf("%-10.2f\t\t\t\t",items[i]->item_price);
        printf("%-10d\n",items[i]->item_stock);
    }

    printf("\nPress any key to contimue.\n");
    getchar();
    system ("cls");
    
    for (i = 0; i < MAX_ITEMS; i++){
        free(items[i]);
    }
    
    return;
}









void sort (void)
{
    int i,j = 0;
    char sort_way;
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
    
    num_items = j;
    
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
            for (m = 0; m < j - 1; m++){
                for (n = 0; n < j - m - 1; n++){
                    if (items[n]->item_id > items[n + 1]->item_id){
                        trans_item.item_id = items[n]->item_id;
                        strcpy(trans_item.item_name, items[n]->item_name);
                        strcpy(trans_item.item_cate, items[n]->item_cate);
                        trans_item.item_price = items[n]->item_price;
                        trans_item.item_stock = items[n]->item_stock;
                        *items[n] = *items[n + 1];
                        *items[n + 1] = trans_item;
                    }
                }
            }
            break;
        case 'n':
        case 'N':
            for (m = 0; m < j - 1; m++){
                for (n = 0; n < j - m - 1; n++){
                    if (strcmp(items[n]->item_name, items[n + 1]->item_name)){
                        trans_item.item_id = items[n]->item_id;
                        strcpy(trans_item.item_name, items[n]->item_name);
                        strcpy(trans_item.item_cate, items[n]->item_cate);
                        trans_item.item_price = items[n]->item_price;
                        trans_item.item_stock = items[n]->item_stock;
                        *items[n] = *items[n + 1];
                        *items[n + 1] = trans_item;
                    }
                }
            }
            break;
        case 'p':
        case 'P':
            for (m = 0; m < j - 1; m++){
                for (n = 0; n < j - m - 1; n++){
                    if (items[n]->item_price > items[n + 1]->item_price){
                        trans_item.item_id = items[n]->item_id;
                        strcpy(trans_item.item_name, items[n]->item_name);
                        strcpy(trans_item.item_cate, items[n]->item_cate);
                        trans_item.item_price = items[n]->item_price;
                        trans_item.item_stock = items[n]->item_stock;
                        *items[n] = *items[n + 1];
                        *items[n + 1] = trans_item;
                    }
                }
            }
            break;
        case 's':
        case 'S':
            for (m = 0; m < j - 1; m++){
                for (n = 0; n < j - m - 1; n++){
                    if (items[n]->item_stock > items[n + 1]->item_stock){
                        trans_item.item_id = items[n]->item_id;
                        strcpy(trans_item.item_name, items[n]->item_name);
                        strcpy(trans_item.item_cate, items[n]->item_cate);
                        trans_item.item_price = items[n]->item_price;
                        trans_item.item_stock = items[n]->item_stock;
                        *items[n] = *items[n + 1];
                        *items[n + 1] = trans_item;
                    }
                }
            }
            break;
        default:
            printf("\nIlleagle instruction code!\nPlease check carefully!!\n");
            goto SORT;
    }
    
    fp = fopen(F_PATH, "w");
    for (i = 0; i < num_items; i++){
        fprintf(fp, "%-10d", items[i]->item_id);
        fprintf(fp, "%-15s", items[i]->item_name);
        fprintf(fp, "%-15s", items[i]->item_cate);
        fprintf(fp, "%-20.2f", items[i]->item_price);
        fprintf(fp, "%-10d\n", items[i]->item_stock);
    }
    
    fclose(fp);
    
    for (i = 0; i < MAX_ITEMS; i++){
        free(items[i]);
    }
    
    while (getchar() != '\n');
    
    printf("Sort successfully!~");
    printf("\nPress any key to contimue.\n");
    getchar();
    system ("cls");

    return;
}






void search (void)
{
    int id;
    char name[NAME_LEN];
    char search_way;
    int i,j = 0;
    
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
                    printf("ID\t\t\t\t\tNAME\t\t\t\t\tCATEGORY\t\t\t\tPRICE\t\t\t\t\tSTOCK\n");
                    printf("%-10d\t\t\t",items[i]->item_id);
                    printf("%-20s\t",items[i]->item_name);
                    printf("%-20s\t",items[i]->item_cate);
                    printf("%-10.2f\t\t\t\t",items[i]->item_price);
                    printf("%-10d\n",items[i]->item_stock);
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
                    printf("ID\t\t\t\t\tNAME\t\t\t\t\tCATEGORY\t\t\t\tPRICE\t\t\t\t\tSTOCK\n");
                    printf("%-10d\t\t\t",items[i]->item_id);
                    printf("%-20s\t",items[i]->item_name);
                    printf("%-20s\t",items[i]->item_cate);
                    printf("%-10.2f\t\t\t",items[i]->item_price);
                    printf("%-10d\n",items[i]->item_stock);
                    break;
                }
            }
            if (i ==j){
                printf("Didn't find the item, please check the ID!");
            }
            break;
        default:
            printf("\nIlleagle instruction code!\nPlease check carefully!!\n");
            getchar();
            goto SERCH;
    }
    
    for (i = 0; i < MAX_ITEMS; i++){
        free(items[i]);
    }
    
    getchar();
    
    printf("\nPress any key to contimue.\n");
    getchar();
    system ("cls");
    
    return;
}








void edit (void)
{
    int i,j = 0;
    char search_way;
    int id;
    char name[NAME_LEN];
    
    for (i = 0; i < MAX_ITEMS; i++){
        items[i] = (struct info_items*)malloc(STRUCT_LEN);
    }
    
    FILE *fp = NULL;
    
    fp = fopen(F_PATH, "r");
    if (fp == NULL){
        printf("Open failed , please check carefully.\n");
        return;
    }

    while(!feof(fp)){
        items[j] = read_line(fp);
        j++;
    }
    
    fclose(fp);
    
    if (j == 0){
        printf("Nothing in the file!");
        return;
    }

EDIT:printf("Use ID/NAME to search the item <I/N>: ");
    search_way = getchar();
    switch (search_way){
        case 'i' :
        case 'I' :
            printf("Please enter the ID of item : ");
            scanf("%d", &id);
            for (i = 0; i < j; i++){
                if (items[i]->item_id == id){
                    if (edit_menu_and_function(i)){
                        printf("Edit the item successfully!~\n");
                        printf("Now the information of item you changed is shown below\n");
                        printf("ID\t\t\t\t\tNAME\t\t\t\t\tCATEGORY\t\t\t\tPRICE\t\t\t\t\tSTOCK\n");
                        printf("%-10d\t\t\t",items[i]->item_id);
                        printf("%-20s\t",items[i]->item_name);
                        printf("%-20s\t",items[i]->item_cate);
                        printf("%-10.2f\t\t\t",items[i]->item_price);
                        printf("%-10d\n",items[i]->item_stock);
                        break;
                    }
                    else{
                        goto EDIT;
                    }
                }
            }
            if (i == j){
                printf("Didn't find the item!!!\n");
                getchar();
                printf("\nPress any key to contimue.\n");
                getchar();
                system ("cls");
                return;
            }
            break;
        case 'n' :
        case 'N' :
            printf("Please enter the NAME of item : ");
            scanf("%s", name);
            for (i = 0; i < j; i++){
                if (strcmp(name, items[i]->item_name) == 0){
                    if (edit_menu_and_function(i)){
                        printf("Edit the item successfully!~\n");
                        printf("Now the information of item you changed is shown below\n");
                        printf("ID\t\t\t\t\tNAME\t\t\t\t\tCATEGORY\t\t\t\tPRICE\t\t\t\t\tSTOCK\n");
                        printf("%-10d\t\t\t",items[i]->item_id);
                        printf("%-20s\t",items[i]->item_name);
                        printf("%-20s\t",items[i]->item_cate);
                        printf("%-10.2f\t\t\t",items[i]->item_price);
                        printf("%-10d\n",items[i]->item_stock);
                        break;
                    }
                    else{
                        goto EDIT;
                    }
                }
            }
            if (i == j){
                printf("Didn't find the item!!!\n");
                getchar();
                printf("\nPress any key to contimue.\n");
                getchar();
                system ("cls");
                return;
            }
            break;
        default:
            printf("\nIlleagle instruction code!\nPlease check carefully!!\n");
            getchar();
            goto EDIT;
    }

    

    fp = fopen(F_PATH, "w");
    for (i = 0; i < j; i++){
        fprintf(fp, "%-10d", items[i]->item_id);
        fprintf(fp, "%-15s", items[i]->item_name);
        fprintf(fp, "%-15s", items[i]->item_cate);
        fprintf(fp, "%-20.2f", items[i]->item_price);
        fprintf(fp, "%-10d\n", items[i]->item_stock);
        
    }
    
    fclose(fp);

    for (i = 0; i < MAX_ITEMS; i++){
        free(items[i]);
    }
    
    getchar();
    
    printf("\nPress any key to contimue.\n");
    getchar();
    system ("cls");
    
    return;
}








void format (void)
{
    int i,j = 0;
    
    for (i = 0; i < MAX_ITEMS; i++){
        items[i] = (struct info_items*)malloc(STRUCT_LEN);
    }
    
    FILE *fp = NULL;
    
    fp = fopen(F_PATH, "r");
    if (fp == NULL){
        printf("Open failed , please check carefully.\n");
        return;
    }
    
    while(!feof(fp)){
        items[j] = read_line(fp);
        j++;
    }
    
    fclose(fp);
    
    if (j == 0){
        printf("The file has already been formated!!!");
        return;
    }
    
    char confirm;
    
    printf("\nConfirm to format the file <Y/N>: ");
    
CON:
    
    if ((confirm = getchar()) == 'y' || confirm == 'Y' ){
        fp = fopen(F_PATH, "w");
        fclose(fp);
        printf("\nFormated successfully!~\nNow nothing in the file\n");
    }
    else if (confirm == 'n' || confirm == 'N'){
        while (getchar() != '\n');
        return;
    }
    else{
        while (getchar() != '\n');
        printf("\nWrong instruction code, now back to the menu.\n");
    }
    
    for (i = 0; i < MAX_ITEMS; i++){
        free(items[i]);
    }
    
    
    printf("\nPress any key to contimue.\n");
    getchar();
    system ("cls");
    
    return;
    
}


    
    
    
    
    
    
    
void delete (void)
{
    int i,j = 0;
    char name[NAME_LEN];
    char search_way;
    int id;
    
    for (i = 0; i < MAX_ITEMS; i++){
        items[i] = (struct info_items*)malloc(STRUCT_LEN);
    }
    
    FILE *fp = NULL;
    
    fp = fopen(F_PATH, "r");
    if (fp == NULL){
        printf("Open failed , please check carefully.\n");
        return;
    }
    
    while(!feof(fp)){
        items[j] = read_line(fp);
        j++;
    }
    
    fclose(fp);
    
    if (j == 0){
        printf("The file has already been formated!!!");
        return;
    }
    
DELETE:printf("Use ID/NAME to search the item <I/N>: ");
    search_way = getchar();
    switch (search_way){
        case 'i' :
        case 'I' :
            printf("Please enter the ID of item : ");
            scanf("%d", &id);
            for (i = 0; i < j; i++){
                if (items[i]->item_id == id){
                    for (; i <= j; i++){
                        *items[i] = *items[i + 1];
                    }
                    break;
                }
            }
            if (i == j){
                printf("Didn't find the item!!!\n");
                getchar();
                printf("\nPress any key to contimue.\n");
                getchar();
                system ("cls");
                return;
            }
            break;
        case 'n' :
        case 'N' :
            printf("Please enter the NAME of item : ");
            scanf("%s", name);
            for (i = 0; i < j; i++){
                if (strcmp(name, items[i]->item_name) == 0){
                    for (; i <= j; i++){
                        *items[i] = *items[i + 1];
                    }
                    break;
                }
            }
            if (i == j){
                printf("Didn't find the item!!!\n");
                getchar();
                printf("\nPress any key to contimue.\n");
                getchar();
                system ("cls");
                return;
            }
            break;
        default:
            printf("\nIlleagle instruction code!\nPlease check carefully!!\n");
            getchar();
            goto DELETE;
    }

    j--;
    
    fp = fopen(F_PATH, "w");
    for (i = 0; i < j; i++){
        fprintf(fp, "%-10d", items[i]->item_id);
        fprintf(fp, "%-15s", items[i]->item_name);
        fprintf(fp, "%-15s", items[i]->item_cate);
        fprintf(fp, "%-20.2f", items[i]->item_price);
        fprintf(fp, "%-10d\n", items[i]->item_stock);
        
    }
    
    fclose(fp);
    
    printf("\nDelete successfully!~\n");
    
    for (i = 0; i < MAX_ITEMS; i++){
        free(items[i]);
    }
    
    
    getchar();
    printf("\nPress any key to contimue.\n");
    getchar();
    system ("cls");
    
    return;
}







void insert (void)
{
    int i,j = 0;
    
    for (i = 0; i < MAX_ITEMS; i++){
        items[i] = (struct info_items*)malloc(STRUCT_LEN);
    }
    
    FILE *fp = NULL;
    
    fp = fopen(F_PATH, "r");
    if (fp == NULL){
        printf("Open failed , please check carefully.\n");
        return;
    }
    
    while(!feof(fp)){
        items[j] = read_line(fp);
        j++;
    }
    
    fclose(fp);
    
    if (j == 0){
        printf("The file has already been formated!!!");
        return;
    }
    
    printf("Please enter the ID of the new item: ");
    scanf("%d", &items[j]->item_id);
    for(i=0;i<j;i++){
        if(items[i]==NULL){
            printf("The space dosen't exists!\n");
        }
        if(items[i]->item_id == items[i]->item_id){
            printf("The item has already existed!!\n");
            return;
        }
    }
    printf("Please enter the NAME of the new item: ");
    scanf("%s", items[j]->item_name);
    for(i=0;i<j;i++){
        if(items[i]==NULL){
            printf("The space dosen't exists!\n");
        }
        if(strcmp(items[i]->item_name,items[i]->item_name)==0){
            printf("The item has already existed!!\n");
            return;
        }
    }
    printf("Please enter the CATEGORY of the new item: ");
    scanf("%s", items[j]->item_cate);
    printf("Please enter the PRICE of the new item: ");
    scanf("%f", &items[j]->item_price);
    printf("Please enter the STOCK of the new item: ");
    scanf("%d", &items[j]->item_stock);
    
    
    
    printf("\nInsert the new item successfully!~\n\n");
    printf("Now the information of item you changed is shown below\n");
    printf("ID\t\t\t\t\tNAME\t\t\t\t\tCATEGORY\t\t\t\tPRICE\t\t\t\t\tSTOCK\n");
    printf("%-10d\t\t\t",items[j]->item_id);
    printf("%-20s\t",items[j]->item_name);
    printf("%-20s\t",items[j]->item_cate);
    printf("%-10.2f\t\t\t",items[j]->item_price);
    printf("%-10d\n",items[j]->item_stock);
    
    
    
    fp = fopen(F_PATH, "w");
    for (i = 0; i <= j; i++){
        fprintf(fp, "%-10d", items[i]->item_id);
        fprintf(fp, "%-15s", items[i]->item_name);
        fprintf(fp, "%-15s", items[i]->item_cate);
        fprintf(fp, "%-20.2f", items[i]->item_price);
        fprintf(fp, "%-10d\n", items[i]->item_stock);
        
    }
    
    fclose(fp);
    
    for (i = 0; i < MAX_ITEMS; i++){
        free(items[i]);
    }
    
    while(getchar() != '\n');
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
    fscanf(fp, "%s", items->item_cate);
    fscanf(fp, "%f", &items->item_price);
    fscanf(fp, "%d\n", &items->item_stock);
    return items;
}
