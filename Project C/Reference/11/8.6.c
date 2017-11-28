#include <stdio.h>
#include<ctype.h>
int main(){
	char a[10000],ch;
	int i=0,j;
	printf("Enter massage:");
	while((ch=getchar())!='\n'){
	  if('a'<ch&&ch<'z')
	  a[i]=toupper(ch);
	  else
	  a[i]=ch;
	  if(a[i]=='A')
	    a[i]='4';
      if(a[i]=='B')
        a[i]='8';
      if(a[i]=='E')
        a[i]='3';
      if(a[i]=='I')
        a[i]='1';
      if(a[i]=='O')
        a[i]='0';
      if(a[i]=='S')
        a[i]='5';
      i=i+1;
	}
	printf("In B1FF-speak:");
	for(j=0;j<=i;j++)
	  printf("%c",a[j]);
    
	printf("!!!!!!!!");
    
	return 0;  
	  
	  
	
}