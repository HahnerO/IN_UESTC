#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define TXT "d:\\haha.txt"
int count = 0;
struct GoodInfo{
	char id[30];
	char name[30];
	char price[10];
	char discount[10];
	int	amount;
	int remain;
}Goods[MAX];


void info_int()
{
	int i = 0;
	int j = 0;


	FILE *fp = fopen(TXT, "r");
	if (fp == NULL)
	{
		perror("xxx");
		exit(EXIT_FAILURE);
	}

	while (!feof(fp)){

		fscanf(fp, "%s", Goods[j].id);
		fscanf(fp, "\t%s", Goods[j].name);
		fscanf(fp, "\t%s", Goods[j].price);
		fscanf(fp, "\t%s", Goods[j].discount);
		fscanf(fp, "\t%d", &Goods[j].amount);
		fscanf(fp, "\t%d\n", &Goods[j].remain);
		j++;
		count++;
	}
	fclose(fp);
}
void info_flush()
{
	int i;
	FILE *fp = fopen(TXT, "w");
	for (i = 0; i<MAX; ++i){

		fprintf(fp, "%s\t", Goods[i].id);
		fprintf(fp, "%s\t", Goods[i].name);
		fprintf(fp, "%s\t", Goods[i].price);
		fprintf(fp, "%s\t", Goods[i].discount);
		fprintf(fp, "%d\t", Goods[i].amount);
		fprintf(fp, "%d\n", Goods[i].remain);
	}
	fclose(fp);
}
void search()
{
	int i;
	bool search = 0;
	char input[20];
	printf("输入你要查询的商品名称:");
	scanf("%s", input);
	for (i = 0; i<MAX; ++i){
		if (!strcmp(Goods[i].name, input)){


			printf("商品id:%s;商品名称:%s;商品价格:%s;商品折扣:%s;商品数目:%d;商品余数:%d\n",
				Goods[i].id, Goods[i].name, Goods[i].price, Goods[i].discount,
				Goods[i].amount, Goods[i].remain);
			search = 1;
			break;

		}
		if (search == 0){
			printf("您要查询的商品不存在!\n");
			break;
		}
	}
}
void info_change()
{
	struct Good{
		char	id[30];
		char	name[30];
		char	price[10];
		char	discount[10];
		int		amount;
		int		remain;
	}temp;
	int i = 0;
	bool change_result = 0;
	char input[20];

	printf("输入你要修改的商品名称:");
	scanf("%s", input);
	for (i = 0; i <= MAX; i++){
		if (!strcmp(Goods[i].name, input)){
			printf("输入新的商品信息（以换行区分信息条目）：\n");

			scanf("%s\n%s\n%s\n%s\n%d\n%d",
				&temp.id, &temp.name, &temp.price, &temp.discount, &temp.amount, &temp.remain);

			strcpy(Goods[i].id, temp.id);
			strcpy(Goods[i].name, temp.name);
			strcpy(Goods[i].price, temp.price);
			strcpy(Goods[i].discount, temp.discount);
			Goods[i].amount = temp.amount;
			Goods[i].remain = temp.remain;

			change_result = 1;
			printf("修改商品信息成功!\n");
			break;
		}
	}
	if (change_result == 0){
		printf("您要修改的商品不存在！\n");
	}
}
void info_dele()
{
	int i;
	bool dele_result = 0;
	char input[20];
	printf("输入你要删除的商品名称:");
	scanf("%s", input);
	for (int i = 0; i<MAX; ++i){
		if (!strcmp(Goods[i].name, input)){

			dele_result = 1;
			printf("删除商品信息成功!\n");

			count--;
			break;
		}
	}
	if (dele_result == 0){
		printf("您要删除的商品不存在!\n");
	}
}
void info_insert(void)
{
	int i = 0;
	struct Good{
		char	id[30];
		char	name[30];
		char	price[10];
		char	discount[10];
		int		amount;
		int		remain;
	}temp;
	if (count >= 100){
		printf("信息库已满，要插入请先删除一定量的数据!\n");
	}
	printf("输入你要插入的商品信息（以换行区分信息条目）：\n");

	scanf("%s\n%s\n%s\n%s\n%d\n%d",
		&temp.id, &temp.name, &temp.price, &temp.discount, &temp.amount, &temp.remain);
	for (i = 0; i<MAX; ++i){

		strcpy(Goods[count + 1].id, temp.id);
		strcpy(Goods[count + 1].name, temp.name);
		strcpy(Goods[count + 1].price, temp.price);
		strcpy(Goods[count + 1].discount, temp.discount);
		Goods[count + 1].amount = temp.amount;
		Goods[count + 1].remain = temp.remain;

		printf("商品信息插入完成!\n");
		count++;
		break;

	}
}

int main(void)
{
	int choice;
	info_int();
	while (1){
		printf("超市商品管理系统\n");
		printf("********************************************\n");
		printf("1.商品信息的修改:\n");
		printf("2.删除某个商品信息:\n");
		printf("3.查找商品信息:\n");
		printf("4.插入某个商品信息:\n");
		printf("其他.退出系统:\n");
		printf("********************************************\n");
		printf("输入您的选择: ");


		scanf("%d", &choice);
		switch (choice){
		case 1:
			info_change();
			break;
		case 2:
			info_dele();
			break;
		case 3:
			search();
			break;
		case 4:
			info_insert();
			break;
		default:
			info_flush();
			printf("您已经退出超市商品管理系统!\n");


			exit(0);
		}
	}

}
