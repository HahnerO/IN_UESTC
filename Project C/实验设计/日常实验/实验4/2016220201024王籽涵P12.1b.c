#include <stdio.h>
#define LEN 30
int i;
char *t;
void read_line(char *s);

int main(void)
{
    char ch[LEN];
    printf("Enter a message:");
    read_line(ch);
    printf("Reversal is:");
    for (i-=1;i>=0;i--) {
        printf("%c",*(t+i));
    }
    printf("\n");
    return 0;
}

void read_line(char *s)
{
    char ch;
    t=&s[0];
    for (i=0;i<LEN;i++) {
        if ((ch=getchar())=='\n') return;
        *(t+i)=ch;
    }
    return;
}
