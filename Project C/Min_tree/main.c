#include <stdio.h>
#include <stdlib.h>

#define MAXV 100
#define F_path "/Users/hahn/Desktop/data.txt"      //更加方便的修改文件路径

typedef struct{
    char u;      //起始点
    char v;      //终止点
    int w;      //权制
}Edge;


int m, n;
char Name[MAXV];
Edge E[MAXV];



void read_file(){
    int i, j = 0;
    char sp;
    FILE *fp;
    fp = fopen(F_path, "r");
    if (!fp){
        printf("Can't open it, please check it carefully.");
        return;
    }
    fscanf(fp, "%d %d\n", &m, &n);          //读入节点名称
    for(i = 0; i < m; i++){
        fscanf(fp, "%c ", &Name[i]);
    }
    while(j < n){                         //读入每条边
        fscanf(fp, "\n%c %c %d", &E[j].u, &E[j].v, &E[j].w);
        j++;
    }
    return;
}


void Edge_sort(){              //对面条辨进行相应的排序
    int i=1, j=1;
    char mid1, mid2;
    int mid3, mid = 0;

    for(;i<=n;i++){
        mid1 = E[i].u;
        mid2 = E[i].v;
        mid3 = E[i].w;

        for(j = i+1; j <= n; j++ ){
            if(mid3 >= E[j].w){
                mid = j;
                mid3 = E[j].w;
            }
        }
        if(mid1 == E[i].u && mid2 == E[i].v && mid3 == E[i].w)
            continue;

        mid1 = E[mid].u;
        mid2 = E[mid].v;
        mid3 = E[mid].w;

        E[mid].u = E[i].u;
        E[mid].v = E[i].v;
        E[mid].w = E[i].w;

        E[i].u = mid1;
        E[i].v = mid2;
        E[i].w = mid3;
    }
    return ;
};



void MiniSpanTree_Kruskal(Edge E[], int n){
    int i, j, k;
    int vest[MAXV];
    int cost = 0;      //代价
    for (i = 1; i <n; i++){
        vest[i] = i;               //初始化vest数组
    }
    k = 1; j = 2;
    while(k < n){
        if (vest[E[i].u]!= vest[E[j].v]){            //若一条的头等于下一条的尾则进行输出下一条变，并使代价自加
            printf("(%c, %c): %d\n", E[j].u, E[j].v, E[j].w);    //由于已经排过序，所以只需要依次向后操作即可
            cost += E[j].w;
            k++;
            for(i = 0; i < n; i++){
                if (vest[i] == vest[E[j].v]){
                    vest[j] = vest[E[j].u];
                }
            }
        }
        j++;
    }
    printf("The COST is %d", cost);
    return;
}


int main(void){               //执行主函数
    read_file();
    Edge_sort();
    MiniSpanTree_Kruskal(E, m);
}
