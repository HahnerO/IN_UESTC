#include<stdio.h>

#define N 10

int *split(int *p_start, int *p_end);
void quicksort(int *p_start, int *p_end);

int main(void)
{
  int a[N], i;
	
  printf("Enter %d numbers to be sorted: ",N);
  for(i=0; i<N; i++)
	scanf("%d",&a[i]);

  quicksort(a, a+N-1);
  
  printf("In sorted order: ");
  for(i=0; i<N; i++)
  	printf("%d ", a[i]);
  putchar('\n');
  
  return 0;
} 

void quicksort(int *p_start, int *p_end)
{
	if(p_start>=p_end)													// 不能用判等号！ 因为对 p_middle 有 +1/-1的操作 
		return;
  int *p_middle = split(p_start, p_end);
  quicksort(p_start, p_middle-1);							
  quicksort(p_middle+1, p_end);
}

int *split(int *p_start, int *p_end)
{
  int *low = p_start, *high = p_end, part_element= *p_start;
  for(;;){
  	for(; low<high&&*high>=part_element; high--)
 	 		;
  	if(low==high)
 			break;
  	*low++ = *high;
  	
	  for(; low<high&&*low<=part_element; low++)
		  ;
	  if(low==high)
 			break;
  	*high-- = *low; 
  }
  *low = part_element;
	return low; 
}
