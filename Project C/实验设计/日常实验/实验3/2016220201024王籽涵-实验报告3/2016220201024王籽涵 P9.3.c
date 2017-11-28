#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void generate_random_walk(char A[10][10])；
void print_array(char A[10][10])；


int main(void)
{
	char ch='A',A[10][10];
	generate_random_walk(A); 
 	print_array(A);
 	
	return 0;	    
}

void generate_random_walk(char A[10][10]){
    int r,m,n;
    char ch='A';
    for(m=0;m<10;m++)
        for(n=0;n<10;n++)
            A[m][n]='.';
    srand((unsigned)time(NULL));
    m=rand()%9;
    n=rand()%9;
    for(A[m][n]=ch;ch<'Z';){
        r=rand()%4;
        if((m==0&&n==0&&A[1][0]!='.'&&A[0][1]!='.')||
           (m==0&&n==9&&A[0][8]!='.'&&A[1][9]!='.')||
           (m==9&&n==0&&A[8][0]!='.'&&A[9][1]!='.')||
           (m==9&&n==9&&A[8][9]!='.'&&A[9][8]!='.'))
            break;
        if((m==0&&A[1][n]!='.'&&A[0][n-1]!='.'&&A[0][n+1]!='.')||
           (m==9&&A[8][n]!='.'&&A[9][n-1]!='.'&&A[9][n+1]!='.')||
           (n==0&&A[m][1]!='.'&&A[m-1][0]!='.'&&A[m+1][0]!='.')||
           (n==9&&A[m][8]!='.'&&A[m-1][9]!='.'&&A[m+1][9]!='.'))
            break;
        if(A[m+1][n]!='.'&&A[m-1][n]!='.'&&A[m][n+1]!='.'&&A[m][n-1]!='.')
            break;
        if((r==0&&(m==0||A[m-1][n]!='.'))||
           (r==1&&(m==9||A[m+1][n]!='.'))||
           (r==2&&(n==0||A[m][n-1]!='.'))||
           (r==3&&(n==9||A[m][n+1]!='.')))
            continue;
        if(r==0){
            m--;
            A[m][n]=++ch;
        }
        if(r==1){
            m++;
            A[m][n]=++ch;
        }
        if(r==2){
            n--;
            A[m][n]=++ch;
        }
        if(r==3){
            n++;
            A[m][n]=++ch;	
        }
    }
} 
void print_array(char A[10][10]){
    int m,n;
    for(m=0;m<10;m++){
        for(n=0;n<10;n++)
            printf("%c ",A[m][n]);
        printf("\n");
    }
}
