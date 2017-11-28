#include <stdio.h>
#include <stdlib.h>


#define F_path "/Users/hahn/Desktop/ListExp.txt"                 //file path
#define MAX 10000                //max number of students to store


typedef struct stuInfo{
    int stuID;
    char stuName[10];
    int Age;
}Elemtype;
typedef struct node{
    Elemtype data;
    struct node *next;
} ListNode, *ListPtr;



ListPtr List_Init(ListPtr* L);
void List_Insert (Elemtype x, ListPtr *L);
void List_Destroy(ListPtr* L);
ListPtr List_Merge(ListPtr *La, ListPtr *Lb);
void OutPut(ListPtr L);
Elemtype read_line(FILE *fp);


int main(void)
{
    ListPtr L;
    L = List_Init(&L);
    OutPut(L);

    return 0;
}


ListPtr List_Init(ListPtr *L)
{
    int i, j;
    Elemtype stu[MAX];
    FILE *fp = NULL;
    fp = fopen(F_path, "r");
    if (fp == NULL){
        fprintf(stderr,"Can't open it, please check it carefully!!!");
        exit(0);
    }

    for(i = 0; !feof(fp); i++){                       //create a stu[] to store the data of file
        stu[i] = read_line(fp);
        if (i >= MAX){
            printf("No more space to store");
            break;
        }
    }

    if(i == 1){
        printf("Nothing in the file!");
        exit(0);
    }

    fclose(fp);

    j = i;

    ListNode *q, *q_pre, *tem, *p, *tail = *L;  //tail指向尾
    q = (*L)->next;
    q = (ListNode *)malloc(sizeof(ListNode));

    for (i = 0; i < j; i++){
        if(stu[i].stuID > tail->data.stuID){
            p = (ListNode *)malloc(sizeof(ListNode));
            p->data = stu[i];
            p->next = NULL;
            tail->next = p;       //p为此时的中转节点
            tail = p;
        }
        else{
            if (q->data.stuID >= stu[i].stuID){
                tem = (ListNode *)malloc(sizeof(ListNode));
                tem->data = stu[i];
                tem->next = q;
                (*L)->next = tem;
                q = tem;
            }
            while(q->data.stuID < stu[i].stuID){
                q_pre = q;          //q为ID刚好大于输入变量的那个
                q = q->next;
            }
            q = (*L);        //归位，方便下次查找

            tem = (ListNode *)malloc(sizeof(ListNode));
            q_pre = (ListNode *)malloc(sizeof(ListNode));
            tem->data = stu[i];
            tem->next = q_pre->next;     //tem为此时的中转节点
            q_pre->next = tem;
        }
    }

    return *L;
}


void List_Insert (Elemtype x, ListPtr *L)
{
    ListNode *p = (*L), *q,*s;
    q = p;
    while (1) {
        if (p->data.stuID < x.stuID) {
            q = p;
            p = p->next;
            if (p == NULL)
                break;
        }
        else
            break;
    }
    s = (ListNode *)malloc(sizeof(ListNode));
    s->data = x;
    s->next = q->next;
    q->next = s;

    return;
}


int Listlength(ListPtr L) {
    int j = 0;

    ListPtr p = L->next;

    while (p != NULL) {
        j++;

        p = p->next;
    }
    return j;
}


ListPtr List_Merge(ListPtr *La, ListPtr *Lb)
{
    ListPtr Lc;
    Lc = (ListPtr)malloc(sizeof(ListPtr));
    if (Lc == NULL) {
        printf("Ask space fault");
        exit(0);
    }
    Lc->next = NULL;
    ListPtr pa = (*La)->next;
    ListPtr pb = (*Lb)->next;

    int i = 0, j = 0;
    ListPtr p;
    p = (ListPtr)malloc(sizeof(ListPtr));
    while (i<Listlength(*La) && j<Listlength(*Lb)) {
        if ((pa->data.stuID) < (pb->data.stuID)) {
            p->data = pa->data;
            pa = pa->next;
            i++;
        }
        else {
            p->data = pb->data;
            pb = pb->next;
            j++;
        }
        p->next = Lc->next;
        Lc->next = p;
    }

    if (i<Listlength(*La)) {
        while (pa != NULL) {
            p->data = pb->data;
            p->next = Lc->next;
            pa = pa->next;
            Lc->next = p;
        }
    }
    if (j<Listlength(*Lb)) {
        while (pb != NULL) {
            p->data = pb->data;
            p->next = Lc->next;
            pb = pb->next;
            Lc->next = p;
        }
    }

    La = &Lc;
    return *La;

}

void OutPut(ListPtr L)
{
    ListNode *p;
    p = L->next;

    printf("ID\t\tName\t\tAge\t\t\n");
    for(; p!=NULL; p = p->next){
        printf("%d\t\t%s\t\t%d\n", p->data.stuID, p->data.stuName, p->data.Age);
    }

    free(p);

    return;
}


void List_Destroy(ListPtr *L)
{
    ListNode *p;

    for(; L != NULL;){
        p = *L;
        (*L) = (*L)->next;
        free(p);
    }

    return;
}


Elemtype read_line(FILE *fp)
{
    Elemtype stu;
    fscanf(fp, "%d", &stu.stuID);
    fscanf(fp, "%s", stu.stuName);
    fscanf(fp, "%d", &stu.Age);
    return stu;
}
