#include<stdio.h>
int main(void)
{
	 char ch=' ',i;
	 printf("Enter a first and last name: ");
	 for( ;ch==' '; )
	 ch=getchar();
	 i=ch;
	 for(ch=' ';ch>='Z'||ch<='A'; )
	 ch=getchar();
	 printf("You enered the name: %c",ch);
	 for( ; ; ){
 		ch=getchar();
 		if(ch=='\n')
 		break;
 		if(ch==' ')
 		continue;
 		printf("%c",ch);	
 	}
 	printf(", %c.\n",i);
 	return 0;
}