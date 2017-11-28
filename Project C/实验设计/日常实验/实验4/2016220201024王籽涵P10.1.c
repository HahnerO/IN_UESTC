#include<stdio.h>
#include<stdbool.h>
#define STACK_SIZE 100
int contents[STACK_SIZE];
int top=0;


bool is_full(void);
bool is_empty(void);
void push(int i);
int pop(void);


int main(){
    char a,b;
    printf("Enter parenteses and/or breces:");
    for(;;)
    {
        scanf("%c",&a);
        if(a != '}' && a != ')' && a != '\n')
            push(a);
        else if(a != '\n')
        {
            b=pop();
            if((a == '}' && b == '{') || (a == ')' && b == '('))
                continue;
            else{
                printf("Parenteses/braces are not nested properly\n");
                break;
            }
        }
        else if(a == '\n'){
            if(is_empty()){
                printf("Parenteses/braces are  nested properly\n");
                break;
            }
            else{
                printf("Parenteses/braces are not nested properly\n");
                break;
                
            }
        }
    }
    return 0;
}

bool is_empty(void){
    return top==0;
}

bool is_full(void){
    return top==STACK_SIZE;
}

void push(int i){
    contents[top++]=i;
}

int pop(void){
    return contents[--top];
}

