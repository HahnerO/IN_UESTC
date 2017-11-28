#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>				//C99 only//

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
void push(char ch);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
  int ch;
  
  printf("Enter parenteses and/or braces: ");
 
  for(;;){
	char temp;
	ch = getchar();
	switch(ch){
	  case '(': case '{': push(ch); break;

      case ')': temp=pop();
  				if(temp!='('){
				  printf("Parenteses/braces are nested improperly.\n");
				  return 0;
				  }
				  break;
	  
      case '}':  temp=pop();
				 if(temp!='{'){
					printf("Parenteses/braces are nested improperly.\n");
					return 0;
				 }
				 break;
	  
      case '\n': if(top==0)
					printf("Parenteses/braces are nested properly.\n");
				 else
					printf("Parenteses/braces are nested improperly.\n");
				 return 0;
	  
      default:   printf("Illegal input.\n");
                 return 0;
	}
  }
}



void make_empty(void)
{
  top = 0;
}

void push(char ch)
{
  if(top==STACK_SIZE)
	stack_overflow();
  else
	contents[top++] = ch;
}

int pop(void)
{
  if(top==0)
	stack_underflow();
  else
	return contents[--top];
}

void stack_overflow(void)
{
  printf("Stack overflow.\n");
  exit(EXIT_SUCCESS);
} 

void stack_underflow(void)
{
  printf("Parenteses/braces are nested improperly.\n");
  exit(EXIT_SUCCESS);
} 
