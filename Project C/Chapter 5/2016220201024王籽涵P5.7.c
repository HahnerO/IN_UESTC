/*Find the largest and smallest number*/

#include <stdio.h>

int main(void)
{
	int a,b,c,d,l1,l2,s1,s2;
	
	printf("Enter four integers: ");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	if(a>=b)
	  l1=a,s1=b;
	  else 
	  l1=b,s1=a;
	if(c>=d)
	  l2=c,s2=d;
	  else
	  l2=d,s2=c;
	if(l1>=l2)
	  printf("Largest: %d",l1);
	  else 
	  printf("Largest: %d",l2);
    if(s1<=s2)
      printf("Smallest:%d\n",s1);
      else
      printf("Smallest:%d\n",s2);
      
    return 0;
}
