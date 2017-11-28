#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

struct Node{
    ElemType data;
    struct node *next;
};

typedef struct Node LNode;
typedef struct Node *LinkedList;

void LinkedListInit1(LinkedList L){
    L = NULL;
}

void LinkedListInit2(LinkedList L){            //with head
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL){
        printf("Apply space faild");
        exit(0);
    };
    L->next = NULL;
}

int LinkedListLength(LinkedList L){
    LNode *p;                              //p is the type of Node
    p = L->next;
    int j = 0;
    while(p != NULL){
        j++;
        p = p->next;                       // move p into the next node
    }
    return j;
}

LinkedList  LinkedListGet(LinkedList L, int i){    //with head
    LNode *p;
    p = L->next;
    int j =1;
    while ((p != NULL) && (j < i)){
        p = p->next;
    }
    return p;
}

LNode LinkedListLocate(LinkedList L, ElemType e){     //with head
    LNode *p;
    p = L->next;
    while((p != NULL) && (p->data != e)){
        p = p->next;
    };
    return p;
}

void LinkedListInsert(LinkedList L, LinkedList p, ElemType e){     //with NO head
    LNode *q, *pre;
    q = (LNode *)malloc(sizeof(LNode));
    if (q = NULL){
        printf("Apply space faild");
        exit(0)
    }
    q->data = e;

    if (p == L){
        q->next = L;
        L = q;
        exit(0);
    }

    //insert in the middle of the linked list
    pre = L;
    while ((pre != NULL) && (pre->next != p)){        //get the pre of the p
        pre = pre->next;
    };
    q->next = pre->next;
    pre->next = q;
}

void LinkedListInsert2(LinkedList L, LinkedList p, ElemType e) {                  //with head
    LNode *q, *pre;
    q = (LNode *) malloc(sizeof(LNode));
    if (q == NULL) {
        printf("Aplly space faild");
        exit(0);
    }

    q->data = e;

    //insert a new node
    pre = L;
    while ((pre != NULL) && (pre->next != p)){
        pre = pre->next;
    };                                               //find the pre of the p
    q->next = pre->next;
    pre->next = q;
}

void LinkedListDel(LinkedList L, ElemType e, LinkedList p){      //with no head
    LNode *pre;
    pre = L;
    while((pre != NULL) && (pre->next->data != e)){     // find the pre of e
        pre = pre->next;
    }

    if (p != NULL){                           //find the node needed to delete
        if (p == L){                          //delete the first node
            L = p->next;
        }
        else {
            pre->next = p->next;              //or delete the other node
        }
        free(p);
    }
}

void LinkedListDel2(LinkedList L, ElemType e, LinkedList p){          //with head
    LNode *pre;
    pre = L;
    while ((pre->next != NULL) && (pre->next->data != e)){           // find the pre of e
        pre = pre->next;
        p = pre->next;
    }

    if (p !== NULL){                                      //find the node needed to delete
        pre->next = p->next;
        free(p);
    }
}

int n;              //the number of a[ ]

void LinkedListCreate1(LinkedList L, ElemType a[n]){       //create the linked list with head insert
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL){
        printf("Aplly space faild");
        exit(0);
    }
    L->next = NULL;

    LNode *p;

    for(int i = 0, i < n; i++){
        p = (LNode *)malloc(sizeof(LNode));
        if (p == NULL){
            printf("Aplly space faild");
            exit(0);
        }

        p->data = a[i];
        p->next = L->next;
        L->next = p;
    }
}

void LinkedlistCreate2(LinkedList L, ElemType a[n]){     //create the linked list with tail insert
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL){
        printf("Aplly space faild");
        exit(0);
    }
    L->next = NULL;
    LNode *tail;
    tail = L;                                 //make a tail_pointer

    LNode *p;

    for(int i = 0; i < n; i++){
        p = (LNode *)malloc(sizeof(LNode));
        if (p == NULL){
            printf("Allpy space faild");
            exit(0);
        }

        p->data = a[i];
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
}

void LinkedListMerge(LinkedList La, LinkedList Lb, LinkedList Lc){
    LNode *pa, *pb, *pc;
    pa = La->next;
    pb = Lb->next;
    Lc = La;
    pc = Lc;

    while ((pa != NULL) && (pb != NULL)){
        if (pa->data <= pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    if (pa != NULL){
        pc = pa->next;
    }
    else{
        pc = pb->next;
    }

    free(pb);
}

























int main(void)
{

}