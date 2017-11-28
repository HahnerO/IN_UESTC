#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM 100

typedef struct {          //定义一个结构体储存一个商品信息 
	char	good_id[30];
	char	good_name[30];
	char	good_price[10];
	char	good_discount[10];
	int		good_amount;
	int		good_remain;
}GoodInfo;


GoodInfo* Goods[MAX_NUM];//结构指针数组，数组元素为指向 储存某一商品的结构 的地址 

int CurrentCnt = 0;//全局变量用于记录数组中有记录的数量 

void info_init();
void info_change(); 
void info_dele();
void info_search();
void info_insert();
void info_flush();
void freeGoodInfo();

int main()
{
	info_init();
	while(1){
		
	printf("********************************************\n");
	printf("超市商品管理系统\n");
	printf("1.商品信息的修改:\n");
	printf("2.删除某个商品信息:\n");
	printf("3.查找商品信息:\n");
	printf("4.插入某个商品信息:\n");
	printf("其他.退出系统:\n");
	printf("********************************************\n");
	printf("输入您的选择: ");
	int choice;
	scanf("%d",&choice);
	switch(choice){
	case 1:
		info_change();
		break;
	case 2:
		info_dele();
		break;
	case 3:
		info_search();
		break;
	case 4:
		info_insert();
		break;
	default:
		info_flush();
		printf("您已经退出超市商品管理系统!\n");
		freeGoodInfo();
		return 0;
	}
}
return 0;
}


void check_nullfile()//检查初始化文件是否存在 
{
	FILE *fp = fopen("D:\\goodinfo.txt","r");
	//初始化文件不存在 
	if(!fp){
		printf("商品信息初始化文件不存在!\n请您放到D盘根目录命名为goodinfo.txt！\n");
		exit(0);
	}
	
}


 
GoodInfo* read_line(FILE* fp)//从文件初始化一个储存商品信息的结构 
{
	GoodInfo* pGoodInfo = (GoodInfo*)malloc(sizeof(GoodInfo));
	fscanf(fp,"%s",&pGoodInfo->good_id);
	fscanf(fp,"%s",pGoodInfo->good_name);
	fscanf(fp,"%s",&pGoodInfo->good_price);
	fscanf(fp,"%s",&pGoodInfo->good_discount);
	fscanf(fp,"%d",&pGoodInfo->good_amount);
	fscanf(fp,"%d\n",&pGoodInfo->good_remain);
	return pGoodInfo;
}




void info_init()//循环录入结构从而读取所有信息 
{
	int i;
	for(i=0; i<MAX_NUM; ++i){
		Goods[i] = NULL;
	}
	check_nullfile(); 
	FILE *fp = fopen("D:\\goodinfo.txt","r");	
	int j = 0;
	while(!feof(fp) ){ 
		Goods[j] = read_line(fp);
		j++;
		CurrentCnt++; 
	}
	fclose(fp);
}



void write_one_GoodInfo(FILE* fp,GoodInfo* pGoodInfo)//从文本读入一个商品信息 
{
	fprintf(fp,"%s\t",pGoodInfo->good_id);
	fprintf(fp,"%s\t",pGoodInfo->good_name);
	fprintf(fp,"%s\t",pGoodInfo->good_price);
	fprintf(fp,"%s\t",pGoodInfo->good_discount);
	fprintf(fp,"%d\t",pGoodInfo->good_amount);
	fprintf(fp,"%d\n",pGoodInfo->good_remain);
}



void info_flush()//将改动信息写入文件 
{
	FILE *fp = fopen("D:\\goodinfo.txt","w");
	int i=0;
	for(; i<MAX_NUM	; ++i){
		if(Goods[i])
			write_one_GoodInfo(fp,Goods[i]);
	}
	fclose(fp);
}


 
void info_output(int i)//以标准格式打印商品信息 
{
	printf("商品编号: %s\n", Goods[i]->good_id);
	printf("商品名称: %s\n", Goods[i]->good_name);
	printf("商品价格: %s\n", Goods[i]->good_price);
	printf("商品折扣: %s\n", Goods[i]->good_discount);
	printf("商品数目: %d\n", Goods[i]->good_amount);
	printf("商品余量: %d\n", Goods[i]->good_remain);
}



void info_change()//修改商品信息 
{
	char name[30];
	int i;
	
	printf("输入你要修改的商品名称: ");
	scanf(" %s", name);
	for(i = 0; i < CurrentCnt; i++){
		if(Goods[i] && (strcmp(Goods[i]->good_name, name) == 0)){
			printf("输入新的商品信息（以换行区分商品信息）\n");
			printf("商品编号: ");
			scanf(" %s", Goods[i]->good_id);
			printf("商品名称: ");
			scanf(" %s", Goods[i]->good_name);
			printf("商品价格: ");
			scanf(" %s", Goods[i]->good_price);
			printf("商品折扣: ");
			scanf(" %s", Goods[i]->good_discount);
			printf("商品总数: ");
			scanf(" %d", &Goods[i]->good_amount);
			printf("商品余量: ");
			scanf(" %d", &Goods[i]->good_remain);
			printf("修改商品信息成功！\n");
			return;
		}
	}
	printf("您要修改的商品不存在！\n");
}





void info_dele()//删除商品信息 
{
	char name[30];
	int i;
	
	printf("输入你要删除的商品名称: ");
	scanf(" %s", name);
	for(i = 0; i < CurrentCnt; i++){
		if(Goods[i] && (strcmp(Goods[i]->good_name, name) == 0)){
			free(Goods[i]);
			Goods[i]=NULL; 
			CurrentCnt--;
			printf("删除商品信息成功！\n");
			return;
		}
	}
	printf("您要删除的商品不存在！\n");
}




void info_search()//查找商品信息
{
	char name[30];
	int i;
	
	printf("输入你要查询的商品名称: ");
	scanf(" %s", name);
	for(i = 0; i < CurrentCnt; i++){
		if(Goods[i] && (strcmp(Goods[i]->good_name, name) == 0)){
			info_output(i);
			return;
		}
	}
	printf("您要查询的商品不存在！\n");
}





void info_insert()//插入商品信息 
{
	if(CurrentCnt>= MAX_NUM)
	{
		printf("信息库已满，要插入请先删除一定量的数据!\n");
	}
	
	Goods[CurrentCnt] = (GoodInfo*)malloc(sizeof(GoodInfo));
	
	printf("输入你要插入的商品信息（以换行区分商品信息）: \n");
	printf("商品编号: ");
	scanf(" %s", Goods[CurrentCnt]->good_id);
	printf("商品名称: ");
	scanf(" %s", Goods[CurrentCnt]->good_name);
	printf("商品价格: ");
	scanf(" %s", Goods[CurrentCnt]->good_price);
	printf("商品折扣: ");
	scanf(" %s", Goods[CurrentCnt]->good_discount);
	printf("商品总数: ");
	scanf(" %d", &Goods[CurrentCnt]->good_amount);
	printf("商品余量: ");
	scanf(" %d", &Goods[CurrentCnt]->good_remain);
	CurrentCnt++;
	printf("商品信息插入成功！\n");
}





void freeGoodInfo()//释放内存 
{
	int i;
	for(i = 0; i < CurrentCnt; i++){
		free(Goods[i]);
		Goods[i]=NULL; 
	}
}
