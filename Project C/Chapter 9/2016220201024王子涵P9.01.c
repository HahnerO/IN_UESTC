/*Computes a series of integers*/

#include <stdio.h>


void selection_sort (int a[],int n);

int main(void)
{
    int i,n;
    

    printf("Enter the number of the number string: ");
    scanf("%d",&n);
    
    int a[n];
    
    printf("Enter the number string: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    selection_sort(a,n);
    
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
    
    return 0;
}

void selection_sort (int a[],int n)
{
    int i,j=0,max=a[0],pos;
    
    for (i=1;i<n;i++){
        if(a[i]>max){
             j=i;
            max=a[i];
        }
    }
    
    pos=a[n-1];
    a[n-1]=a[j];
    a[j]=pos;
    
    n--;
    
    if(n>2)
        selection_sort(a, n);
    else
        return;
}
