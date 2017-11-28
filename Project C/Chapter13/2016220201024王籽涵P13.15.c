#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;
char expression[255];
int i;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);
int read_num(int now_num);
int num(char ch);
void calculate(void); 
int evaluate_RPN_expression(const char *expression);

int main()
{
	printf("Any time you can put in 'n' to exit\n");
	for (;;){
		int end;
		make_empty();
		printf("Enter an RPN expression: ");
		gets(expression);
		end = evaluate_RPN_expression(expression);
		printf("Value of expression: %d\n", end);
	}
} 

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(int i)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = i;
}

int pop(void)
{
	if (is_empty())
		stack_underflow();
	else
		return contents[--top];
}

void stack_overflow()
{
	printf("Expression is too complex\n");
	exit(EXIT_SUCCESS);
}

void stack_underflow()
{
	printf("Not enough operands in espression\n");
	exit(EXIT_SUCCESS);
}

int read_num(int now_num)
{
	now_num = now_num*10 + num(expression[i]);
	i++;
	if (expression[i] >= 48 && expression[i] <= 57)
		return read_num(now_num);
	else
		return now_num;
}

int num(char ch)
{
	return ch - 48;
}

void calculate()
{
	int num1, num2;
	num2 = pop();
	num1 = pop();
	
	if (expression[i] == '+')
		push(num1+num2);
	else if (expression[i] == '-')
		push(num1-num2);
	else if (expression[i] == '*')
		push(num1*num2);
	else if (expression[i] == '/')
		push(num1/num2);
}

int evaluate_RPN_expression(const char *expression)
{
	for (i = 0;; i++){
		char ch;
		ch = expression[i];
		if (expression[i] >= 48 && expression[i] <= 57)
			push(read_num(0));
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
			calculate();
		if (expression[i] == '=')
			return pop();
		if (expression[i] == 'n' || expression[i] == 'N')
			exit(EXIT_SUCCESS);
	}
}
