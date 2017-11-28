#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define Fpath "/Users/hahn/Desktop/numbers.txt"

void QuickSort (int *data, int left, int right);
int find(int *data, int n, int target);

int main(void)
{
    int i = 0, n = 0;
    int data[MAX];
    int target, res;

    FILE* fp = fopen(Fpath, "r");
    if(!fp){
        printf("Can't open it,please check it carefully!");
        return 1;
    }
    printf("Input data succeed!");

    printf("\n----split----\n");

    printf("Datas below:\n");
    while((fscanf(fp, "%d", &data[n])) != EOF){
        printf("%d\t", data[n]);
        n++;
    }

    n--;//上个while循环中结尾处n额外加了一次

    QuickSort(data, 0, n);

    printf("\n----split----\n");

    printf("After Qsort:\n");
    for(i = 0; i<=n; i++){
        printf("%d\t", data[i]);
    }

    printf("\n----split----\n");

    printf("Input the numbre U want to find:");
    scanf("%d", &target);

    res = find(data, n, target);
    if(res == 0){
        printf("Faild to find target");
    }
    else{
        printf("Find success! Total %d target(s).", res);
    }
    return 1;
}

void QuickSort (int *data, int left, int right){
    int i = 0, j = 0;
    int middle = data[left];
    int tem;

    if(left < right){
        i = left;
        j = right;

        while( i < j) {
            for (; i < j && data[j] > middle; j--);
            if (i < j) {
                tem = data[i];
                data[i] = data[j];
                data[j] = tem;
                i++;
            }

            for (; i < j && data[i] < middle; i++);
            if (i < j) {
                tem = data[j];
                data[j] = data[i];
                data[i] = tem;
                j--;
            }
        }
        QuickSort(data, left, i - 1);
        QuickSort(data, i + 1, right);
    }
    return;
}

int find(int *data, int n, int target){
    int i = 0, middle = 0;
    int left = 0, right = n;
    int same_count = 0;

    while (left < right){
        middle = (left + right)/2;
        if (data[middle] == target){
            for(; middle >= left; middle-- ){
                if (data[middle] == target) same_count++;
                else break;
            }
            for(; middle <= right; middle++){
                if (data[middle] == target) same_count++;
                else break;
            }
            return same_count;
        }
        if (data[middle] > target){
            right = middle - 1;
        }
        if (data[middle] < target){
            left = middle + 1;
        }
    }

    return 0;
}
