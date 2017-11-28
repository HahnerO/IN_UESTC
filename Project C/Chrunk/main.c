#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

struct Node{
    ElemType data;
    struct node *next;
};

typedef struct Node LNode;
typedef struct Node *LinkedList;

void find_first_different_char (LinkedList X, LinkedList Y)
{
    LinkedList cpr;            //create compare pointer
    cpr->next = NULL;
    LNode* p;
    LNode* tem;
    LNode* q;

    p = Y->next;
    cpr->next = tem;
    tem->data = p->data;
    p = p->next;

    for(; p != NULL; p = p->next){          //insert the different date into cpr pointer
        for(; tem != NULL; tem = tem->next){
            if (tem == p) {
                break;
            }
        }
        if (tem == NULL){
            tem = p;
        }
    }

    tem = cpr->next;
    q = X->next;
    for (; q != NULL; q = q->next){
        for(; tem != NULL; tem = tem->next){
            if (tem != q || tem != NULL){
                printf("The first different character is %c", &q->data);
                return;
            }
        }
    }
    printf("No any different charater");
    return;
}
