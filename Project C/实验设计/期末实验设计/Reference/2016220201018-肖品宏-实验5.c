#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM 100

typedef struct {          //����һ���ṹ�崢��һ����Ʒ��Ϣ 
	char	good_id[30];
	char	good_name[30];
	char	good_price[10];
	char	good_discount[10];
	int		good_amount;
	int		good_remain;
}GoodInfo;


GoodInfo* Goods[MAX_NUM];//�ṹָ�����飬����Ԫ��Ϊָ�� ����ĳһ��Ʒ�Ľṹ �ĵ�ַ 

int CurrentCnt = 0;//ȫ�ֱ������ڼ�¼�������м�¼������ 

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
	printf("������Ʒ����ϵͳ\n");
	printf("1.��Ʒ��Ϣ���޸�:\n");
	printf("2.ɾ��ĳ����Ʒ��Ϣ:\n");
	printf("3.������Ʒ��Ϣ:\n");
	printf("4.����ĳ����Ʒ��Ϣ:\n");
	printf("����.�˳�ϵͳ:\n");
	printf("********************************************\n");
	printf("��������ѡ��: ");
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
		printf("���Ѿ��˳�������Ʒ����ϵͳ!\n");
		freeGoodInfo();
		return 0;
	}
}
return 0;
}


void check_nullfile()//����ʼ���ļ��Ƿ���� 
{
	FILE *fp = fopen("D:\\goodinfo.txt","r");
	//��ʼ���ļ������� 
	if(!fp){
		printf("��Ʒ��Ϣ��ʼ���ļ�������!\n�����ŵ�D�̸�Ŀ¼����Ϊgoodinfo.txt��\n");
		exit(0);
	}
	
}


 
GoodInfo* read_line(FILE* fp)//���ļ���ʼ��һ��������Ʒ��Ϣ�Ľṹ 
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




void info_init()//ѭ��¼��ṹ�Ӷ���ȡ������Ϣ 
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



void write_one_GoodInfo(FILE* fp,GoodInfo* pGoodInfo)//���ı�����һ����Ʒ��Ϣ 
{
	fprintf(fp,"%s\t",pGoodInfo->good_id);
	fprintf(fp,"%s\t",pGoodInfo->good_name);
	fprintf(fp,"%s\t",pGoodInfo->good_price);
	fprintf(fp,"%s\t",pGoodInfo->good_discount);
	fprintf(fp,"%d\t",pGoodInfo->good_amount);
	fprintf(fp,"%d\n",pGoodInfo->good_remain);
}



void info_flush()//���Ķ���Ϣд���ļ� 
{
	FILE *fp = fopen("D:\\goodinfo.txt","w");
	int i=0;
	for(; i<MAX_NUM	; ++i){
		if(Goods[i])
			write_one_GoodInfo(fp,Goods[i]);
	}
	fclose(fp);
}


 
void info_output(int i)//�Ա�׼��ʽ��ӡ��Ʒ��Ϣ 
{
	printf("��Ʒ���: %s\n", Goods[i]->good_id);
	printf("��Ʒ����: %s\n", Goods[i]->good_name);
	printf("��Ʒ�۸�: %s\n", Goods[i]->good_price);
	printf("��Ʒ�ۿ�: %s\n", Goods[i]->good_discount);
	printf("��Ʒ��Ŀ: %d\n", Goods[i]->good_amount);
	printf("��Ʒ����: %d\n", Goods[i]->good_remain);
}



void info_change()//�޸���Ʒ��Ϣ 
{
	char name[30];
	int i;
	
	printf("������Ҫ�޸ĵ���Ʒ����: ");
	scanf(" %s", name);
	for(i = 0; i < CurrentCnt; i++){
		if(Goods[i] && (strcmp(Goods[i]->good_name, name) == 0)){
			printf("�����µ���Ʒ��Ϣ���Ի���������Ʒ��Ϣ��\n");
			printf("��Ʒ���: ");
			scanf(" %s", Goods[i]->good_id);
			printf("��Ʒ����: ");
			scanf(" %s", Goods[i]->good_name);
			printf("��Ʒ�۸�: ");
			scanf(" %s", Goods[i]->good_price);
			printf("��Ʒ�ۿ�: ");
			scanf(" %s", Goods[i]->good_discount);
			printf("��Ʒ����: ");
			scanf(" %d", &Goods[i]->good_amount);
			printf("��Ʒ����: ");
			scanf(" %d", &Goods[i]->good_remain);
			printf("�޸���Ʒ��Ϣ�ɹ���\n");
			return;
		}
	}
	printf("��Ҫ�޸ĵ���Ʒ�����ڣ�\n");
}





void info_dele()//ɾ����Ʒ��Ϣ 
{
	char name[30];
	int i;
	
	printf("������Ҫɾ������Ʒ����: ");
	scanf(" %s", name);
	for(i = 0; i < CurrentCnt; i++){
		if(Goods[i] && (strcmp(Goods[i]->good_name, name) == 0)){
			free(Goods[i]);
			Goods[i]=NULL; 
			CurrentCnt--;
			printf("ɾ����Ʒ��Ϣ�ɹ���\n");
			return;
		}
	}
	printf("��Ҫɾ������Ʒ�����ڣ�\n");
}




void info_search()//������Ʒ��Ϣ
{
	char name[30];
	int i;
	
	printf("������Ҫ��ѯ����Ʒ����: ");
	scanf(" %s", name);
	for(i = 0; i < CurrentCnt; i++){
		if(Goods[i] && (strcmp(Goods[i]->good_name, name) == 0)){
			info_output(i);
			return;
		}
	}
	printf("��Ҫ��ѯ����Ʒ�����ڣ�\n");
}





void info_insert()//������Ʒ��Ϣ 
{
	if(CurrentCnt>= MAX_NUM)
	{
		printf("��Ϣ��������Ҫ��������ɾ��һ����������!\n");
	}
	
	Goods[CurrentCnt] = (GoodInfo*)malloc(sizeof(GoodInfo));
	
	printf("������Ҫ�������Ʒ��Ϣ���Ի���������Ʒ��Ϣ��: \n");
	printf("��Ʒ���: ");
	scanf(" %s", Goods[CurrentCnt]->good_id);
	printf("��Ʒ����: ");
	scanf(" %s", Goods[CurrentCnt]->good_name);
	printf("��Ʒ�۸�: ");
	scanf(" %s", Goods[CurrentCnt]->good_price);
	printf("��Ʒ�ۿ�: ");
	scanf(" %s", Goods[CurrentCnt]->good_discount);
	printf("��Ʒ����: ");
	scanf(" %d", &Goods[CurrentCnt]->good_amount);
	printf("��Ʒ����: ");
	scanf(" %d", &Goods[CurrentCnt]->good_remain);
	CurrentCnt++;
	printf("��Ʒ��Ϣ����ɹ���\n");
}





void freeGoodInfo()//�ͷ��ڴ� 
{
	int i;
	for(i = 0; i < CurrentCnt; i++){
		free(Goods[i]);
		Goods[i]=NULL; 
	}
}
