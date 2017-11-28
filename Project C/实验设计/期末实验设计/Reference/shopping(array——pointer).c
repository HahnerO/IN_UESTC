#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


#define NAME_LEN 30
#define UNIT_LEN 10
#define MAX_ITEM 999

struct shopping
{
	char name[NAME_LEN + 2];
	double price;
	long int on_hand;
	char unit[UNIT_LEN + 2];
};							/*�ýṹ����ʵ����Ʒ��Ϣ����*/ 

struct shopping *commidity[MAX_ITEM];

/*��һ��txt�ļ��ڶ�ȡ��Ʒ��Ϣ�Գ�ʼ������*/	
void info_init();					

/*�����������иĶ�������Ʒ��Ϣ���浽ԭ�ļ���*/
void info_flush();

/*����Ʒ�б���������Ʒ��ÿ����Ϣ��ӡ����Ļ��*/
void OutputAll();					

/*��ʽ�����ĳһ����Ʒ��Ϣ��nameΪ����Ʒ������*/
void info_output(struct shopping *com_now);		

/********************************************************************* 
 *�����Ʒ��Ϣ���޸Ĺ��ܣ�����Ҫ���û�������Ҫ�޸ĵ�ĳ����Ʒ�����ƣ� * 
 *Ȼ������ƽ��в��ң��ҵ�������������Ʒ�ĸ�����Ϣ������ʾ�޸ĳɹ� * 
 *���û���ҵ�����ʾ��Ӧ��Ʒδ�ҵ�������ѡ��󶼷��ص���ʼ��ѡ��˵� * 
 *********************************************************************/ 
void info_change();	

/********************************************************************* 
 *���ɾ��ĳ����Ʒ������Ϣ�Ĺ��ܣ�                                   *
 *ͨ�������ĳ����Ʒ������ɾ����Ӧ����Ϣ���������Ʒ�����ҵ���Ӧ	 *
 *����Ʒ��ɾ������Ʒ��Ϣ�����ͷ�ָ����ָ����ڴ棬���Ѹ�ָ�븳ֵ	 *
 *Ϊ NULL��������ʾɾ���ɹ������û���ҵ�����ƷҪ��ʾû���ҵ�����	 *
 *Ʒ��Ϣ��������ѡ���¶��ص���һ��ѡ�����                           * 
 *********************************************************************/				

void info_dele();

/************************************************************************* 
 *�����Ʒ��Ϣ�Ĳ��ҹ��ܣ�Ȼ��ͨ������ĳ����Ʒ��Ϣ��������������Ʒ��Ϣ��,*
 *���ҵ�����ʾ����Ʒ����ϸ��Ϣ��û�в��ҵ�����ʾû�и���Ʒ 				 *					 
 *************************************************************************/ 
void info_search();

/************************************************************************** 
 *�����Ʒ��Ϣ�Ĳ��룬�ڲ���֮ǰ��̬�ķ����ڴ������洢�������Ʒ��Ϣ��	  *
 *Ȼ���ָ����ڴ��ָ����뵽��һ������Ľṹ��ָ�������еĵ�һ����Ԫ����*
 *���ڲ���֮ǰ���뿼��������Ϣ����޶������������������Ҫ���û�����ʾ	  *			 					 
 **************************************************************************/
void info_insert();

/************************************************************************* 
 *������Ʒ���ƣ����ҵ�����Ʒ�򷵻���Ʒ��Ϣ��ָ�룬�Ҳ����򷵻ؿ�ָ��	 *					 
 *************************************************************************/ 
struct shopping *info_return(char name_input[NAME_LEN + 2]);

int main(void)
{
	char num;
	
	system("color 0A");  
	info_init();		 /*���ļ��ж�ȡ��Ϣ����ʼ������*/
	
	printf("****************************************************************************\n");
	printf("*                                                                          *\n");
	printf("*                    ---��ӭ����xx������Ʒ����ϵͳ---                      *\n");
	printf("*                                                                          *\n");
	printf("****************************************************************************\n");
	printf("\n\n");
	printf("        ע����ϵͳ����Ʒ���в�������Ϣ���Զ����棬������Ϊģ��������\n\n\n");
	
	while(1)
	{
		printf("                       *****************************\n");
		printf("                       *                           *\n"); 
		printf("                       * 1.����i¼����Ʒ��Ϣ��     *\n");
		printf("                       *                           *\n");
		printf("                       * 2.����c�޸���Ʒ��Ϣ��     *\n");
		printf("                       *                           *\n");
		printf("                       * 3.����dɾ����Ʒ��Ϣ��     *\n");
		printf("                       *                           *\n");
		printf("                       * 4.����s������Ʒ��Ϣ��     *\n");
		printf("                       *                           *\n");
		printf("                       * 5.����o��ӡ������Ʒ��Ϣ�� *\n");
		printf("                       *                           *\n");
		printf("                       * 6.����q�˳�ϵͳ��         *\n");
		printf("                       *                           *\n");
		printf("                       *****************************\n\n\n");
		printf("����������еĲ���: ");
		
		k : scanf(" %c", &num); 	/*��������ʱ������ַ�ǰ��Ŀո�*/ 
		if(getchar() != '\n')
		{
			printf("������Ĳ����������������룺 ");
			while(getchar() != '\n')
				;						 /*��������ʱ����Ķ�����ַ�*/ 
			goto k; 
		}						/*����û��Ƿ������˶���ַ�*/
		switch(tolower(num))
		{
			case 'i': info_insert();
			break;
			case 'c': info_change();
			break;
			case 'd': info_dele();
			break;
			case 's': info_search();
			break;
			case 'o': OutputAll();
			break;
			case 'q': info_flush();
			printf("�˳��ɹ���\n"); 
			return 0;
			default :
			printf("�����������������롣\n");
			break;
		}
	}
	
	return 0; 
}



void OutputAll()
{
	int i, y; 					/*����*/ 
	char name_tem[NAME_LEN + 2];			/*�ݴ���Ʒ����*/
	char unit_tem[UNIT_LEN + 2];				/*�ݴ������λ����*/
	
	if (!strcmp("", commidity[0]->name))
	{
		printf("��Ǹ����Ʒ����������Ʒ��Ϣ��\n\n");
		return;
	}
	
	printf("��Ʒ����            �۸�        �����      ������λ\n");
	for(i = 0; strcmp("", commidity[i]->name) != 0; i++)
	{
		for(y = 0; (commidity[i]->name)[y] != '\n'; y++)
			;
		strcpy(name_tem, commidity[i]->name);
		name_tem[y] = '\0';
		for(y = 0; (commidity[i]->unit)[y] != '\n'; y++)
			;
		strcpy(unit_tem, commidity[i]->unit);
		unit_tem[y] = '\0';
		printf("%-20s%-13.2lf%-11ld%s\n", name_tem, commidity[i]->price, commidity[i]->on_hand, unit_tem);
	}
	printf("\n\n\n");
}

void info_search()
{
	char name_tem[NAME_LEN + 2];
	char num;
	struct shopping *tem;
	int i, y;			/*����*/
	
	printf("������������ҵ���Ʒ������: ");
	fgets(name_tem, NAME_LEN + 1, stdin);
	if(strlen(name_tem) == NAME_LEN)
		if(name_tem[NAME_LEN - 1] != '\n') 
			while(getchar() != '\n')
				;						 /*��������ʱ����Ķ�����ַ�*/ 
	for(y = 0; y < strlen(name_tem); y++)
		;
	name_tem[y - 1] = '\0';
	if((tem = info_return(name_tem)) != NULL)
		info_output(tem);
	else
	{
		printf("���������Ʒ��Ϣ�������Ʒ�����ڣ���ѡ������������s�����������Ʒ��Ϣ��i�����߷��������棨b��: ");
		l: scanf(" %c", &num); 	/*��������ʱ������ַ�ǰ��Ŀո�*/ 
		if(getchar() != '\n')
		{
			printf("������Ĳ����������������룺 ");
			while(getchar() != '\n')
				;						 /*��������ʱ����Ķ�����ַ�*/ 
			goto l; 
		}						/*����û��Ƿ������˶���ַ�*/
		switch(tolower(num))
		{
			case 's': info_search();
			break;
			case 'i': info_insert();
			break;
			case 'b': return;
			default:
			printf("������������󣬿�ѡ������������s�����������Ʒ��Ϣ��i�����߷��������棨b��: ");
			goto l;			/*���²���*/ 
		}
		
	}
		
}

void info_change()
{
	char name_tem[NAME_LEN + 2];		/*�ݴ���Ʒ����*/
	char unit_tem[UNIT_LEN + 2];		/*�ݴ������λ����*/
	struct shopping *com_now;
	char num;
	double change1 = 0;
	long change2 = 0;
 	int i, y; 					/*����*/
	
	m: printf("�����������޸ĵ���Ʒ������: ");
	fgets(name_tem, NAME_LEN + 1, stdin);
	if(strlen(name_tem) == NAME_LEN)
		if(name_tem[NAME_LEN - 1] != '\n') 
			while(getchar() != '\n')
				;						 /*��������ʱ����Ķ�����ַ�*/ 
	for(y = 0; y < strlen(name_tem); y++)
		;
	name_tem[y - 1] = '\0';
	printf("\n\n");
	if((com_now = info_return(name_tem)) == NULL )
	{
		printf("���������Ʒ��Ϣ�������Ʒ�����ڣ���ѡ���������루s�����������Ʒ��Ϣ��i�����߷��������棨b��: ");
		q: scanf(" %c", &num); 	/*��������ʱ������ַ�ǰ��Ŀո�*/ 
		if(getchar() != '\n')
		{
			printf("������Ĳ����������������룺 ");
			while(getchar() != '\n')
				;						 /*��������ʱ����Ķ�����ַ�*/ 
			goto q; 
		}						/*����û��Ƿ������˶���ַ�*/
		switch(tolower(num))
		{
			case 's': goto m; 
			case 'i': info_insert();
			break;
			case 'b': return;
			default:
			printf("������������󣬿�ѡ������������s�����������Ʒ��Ϣ��i�����߷��������棨b��: ");
			goto q;			/*���²���*/ 
		}
		 
	}
	else
	{
		printf("****************************************************************************\n");
		printf("*                                                                          *\n");
		printf("*        ��ע�⣬����Ƿ��ַ�ʱ����ĸ����ţ��۸�Ϳ������Ϊ��!!!       *\n");
		printf("*                                                                          *\n");
		printf("****************************************************************************\n");
		printf("�����������޸ĵ���Ʒ����Ϣ: �۸�p����������λ��u�����߿�棨o��,�򷵻������棨b��: ");
		
		l: scanf(" %c", &num); 	/*��������ʱ������ַ�ǰ��Ŀո�*/ 
		if(getchar() != '\n')
		{
			printf("������Ĳ����������������룺 ");
			while(getchar() != '\n')
				;						 /*��������ʱ����Ķ�����ַ�*/ 
			goto l; 
		}						/*����û��Ƿ������˶���ַ�*/
		switch(tolower(num))
		{
			case 'u':
			t: printf("�����������λ: ����󲻳���%d����ĸ/����/�ַ�����", UNIT_LEN);
			fgets(unit_tem, UNIT_LEN + 2, stdin);
			if((y = strlen(unit_tem)) == (UNIT_LEN + 1))
			{
		
				if(unit_tem[UNIT_LEN] != '\n') 
					while(getchar() != '\n')
						;							/*��������ʱ����Ķ�����ַ�*/ 
				printf("������λ���������������룡\n");
				goto t;						 
			}
			unit_tem[y - 1] = '\n';
			unit_tem[y] = '\0';
			strcpy(com_now->unit, unit_tem);
			printf("��Ʒ������λ�޸ĳɹ�����������������...\n\n");
			info_flush();
			return;
			case 'p':
			printf("�����������޸ĵ������-1Ϊ����һԪ��2Ϊ������Ԫ����������ʱ�������+���ţ��ᱻ��Ϊ�Ƿ��ַ���: ");
			scanf("%lf", &change1);
			while(getchar() != '\n')
				;
			if(change1 == 0)
			{
				printf("��ע�⣬��δ����Ʒ���������\n\n");
				break; 
			}
			com_now->price += change1;
			printf("��Ʒ�۸��޸ĳɹ�����������������...\n\n");
			info_flush();
			return;
			case 'o': 
			printf("�����������޸ĵ������-1Ϊ����һ����棬2Ϊ����������棬��������ʱ�������+���ţ��ᱻ��Ϊ�Ƿ��ַ���: ");
			scanf("%ld", &change2);
			while(getchar() != '\n')
				;
			if(change2 == 0)
			{
				printf("��ע�⣬��δ����Ʒ���������\n\n");
				break; 
			}
			com_now->on_hand += change2;
			printf("��Ʒ����޸ĳɹ�����������������...\n\n");
			info_flush();
			return;
			case 'b': 
			return;
			default:
			printf("������������󣬿�ѡ���޸ļ۸�p������棨o�����߷��������棨b��: ");
			goto l;			/*���²���*/ 
		}
	}
		
	
	
}

struct shopping *info_return(char name_input[NAME_LEN + 2])
{
	int i, y; 					/*����*/
	int count = 0; 				/*����*/
	struct shopping *com_now = commidity;   /*��ס����������õ���λ��*/
	char name_tem[NAME_LEN + 1];
	
	for(i = 0; strcmp(commidity[i]->name, ""); i++)
	{
		for(y = 0; name_input[y] != '\0'; y++)
		{
			if(commidity[i]->name[y] == name_input[y])
				;
			else
				break;
		}
		if(name_input[y] == '\0')
		{
			printf("%s\n", commidity[i]->name);
			count++;
		}
		
		
	}
	if(count == 0)
		return NULL;
	else
	{
		printf("\n�����ǿ��ܵĽ�������������������Ʒ�����ǣ���");
		g: fgets(name_tem, NAME_LEN + 1, stdin);
		if(strlen(name_tem) == NAME_LEN)
			if(name_tem[NAME_LEN - 1] != '\n') 
				while(getchar() != '\n')
					;						 /*��������ʱ����Ķ�����ַ�*/ 
		for(i = 0; i < strlen(name_tem); i++)
			;
		name_tem[i - 1] = '\0';
		for(i = 0; strcmp(commidity[i]->name, ""); i++)
		{
			for(y = 0; (commidity[i]->name)[y] != '\n'; y++)
			{
				if((commidity[i]->name)[y] == name_tem[y])
					;
				else
					break;
			}
			if((commidity[i]->name)[y] == '\n' && name_tem[y] == '\0')
			{
				com_now = commidity[i];
				return com_now;
			}
		
		
		}
		printf("���������Ʒ��Ϣ�������������룡��");
		goto g;
	}
	
	
}

void info_output(struct shopping *com_now)
{
	
	printf("��Ʒ���ҳɹ�����������Ʒ��Ϣ��\n\n");
	printf("�۸�        �����      ������λ\n");
	printf("%-13.2lf%-11ld%s\n", com_now->price, com_now->on_hand, com_now->unit);
	return;
}

void info_dele()
{
	char name_tem[NAME_LEN + 2];
	struct shopping *tem;
	struct shopping cur, prev;
	int i, y; 							/*����*/
	char num;
	
	m: printf("����������ɾ������Ʒ������: ");
	fgets(name_tem, NAME_LEN + 1, stdin);
	if(strlen(name_tem) == NAME_LEN)
		if(name_tem[NAME_LEN - 1] != '\n') 
			while(getchar() != '\n')
				;						 /*��������ʱ����Ķ�����ַ�*/ 
	for(y = 0; y < strlen(name_tem); y++)
		;
	name_tem[y - 1] = '\0';
	tem = info_return(name_tem);
	if(tem == NULL)
	{
		printf("\n���������Ʒ��Ϣ�������Ʒ�����ڣ���ѡ���������루s�����߷��������棨b��: ");
		l: scanf(" %c", &num); 	/*��������ʱ������ַ�ǰ��Ŀո�*/ 
		if(getchar() != '\n')
		{
			printf("������Ĳ����������������룺 ");
			while(getchar() != '\n')
				;						 /*��������ʱ����Ķ�����ַ�*/ 
			goto l; 
		}						/*����û��Ƿ������˶���ַ�*/
		switch(tolower(num))
		{
			case 's': goto m; 
			case 'b': return;
			default:
			printf("������������󣬿�ѡ������������s�����߷��������棨b��: ");
			goto l;			/*���²���*/ 
		}
	}
	else
	{
		for (i = 0; strcmp(commidity[i]->name, ""); i++)
	{
		if (commidity[i] == tem)
		{
				
			for(; strcmp(commidity[i + 1]->name, ""); i++)
				commidity[i] = commidity[i + 1];
			strcpy(commidity[i]->name, "");
			info_flush();
			printf("��Ʒɾ���ɹ���\n\n");
			return;
		}
				
		
			
	}
	}
} 

void info_insert()
{
	char name_tem[NAME_LEN + 2];
	char unit_tem[UNIT_LEN + 2];
	char price_tem[1000];
	char on_hand_tem[1000];
	int i, y;							/*����*/ 
	
	for(i = 0; strcmp(commidity[i]->name, ""); i++)
	{
		if (i == MAX_ITEM - 1)
	{
		fprintf(stderr,"����ʧ�ܣ���Ʒ�����ﵽ������ޣ���رպ���й���Ա��\n");
		return;
	}
	}
	
	
	l : printf("����������������Ʒ������󲻳���%d����ĸ/����/�ַ�����", NAME_LEN);
	fgets(name_tem, NAME_LEN + 2, stdin);
	if((y = strlen(name_tem)) == (NAME_LEN + 1))
	{
		
		if(name_tem[NAME_LEN] != '\n') 
			while(getchar() != '\n')
				;							/*��������ʱ����Ķ�����ַ�*/ 
		printf("���ֹ��������������룡\n");
		goto l;						 
	}
	name_tem[y - 1] = '\n';
	name_tem[y] = '\0';
	strcpy(commidity[i]->name, name_tem);
	z : printf("����������������Ʒ������λ������󲻳���%d����ĸ/����/�ַ�����", UNIT_LEN);
	fgets(unit_tem, UNIT_LEN + 2, stdin);
	if((y = strlen(unit_tem)) == (UNIT_LEN + 1))
	{
		
		if(unit_tem[UNIT_LEN] != '\n') 
			while(getchar() != '\n')
				;							/*��������ʱ����Ķ�����ַ�*/ 
		printf("���ֹ��������������룡\n");
		goto z;						 
	}
	unit_tem[y - 1] = '\n';
	unit_tem[y] = '\0';
	strcpy(commidity[i]->unit, unit_tem);
	printf("****************************************************************************\n");
	printf("*                                                                          *\n");
	printf("*          ��ע�⣬����Ƿ��ַ�ʱ����ĸ����ţ��۸�Ϳ�潫Ϊ��!!!         *\n");
	printf("*                                                                          *\n");
	printf("****************************************************************************\n");
	printf("���������������Ʒ�ļ۸�: ");
	scanf("%lf", &(commidity[i]->price));
	while(getchar() != '\n')
				;
	if(commidity[i]->price == 0)
		printf("��ע�⣬��Ʒ�۸�Ϊ�㣡\n\n");
	printf("���������������Ʒ�Ŀ��: ");
	scanf("%ld", &(commidity[i]->on_hand));
	while(getchar() != '\n')
				;
	if(commidity[i]->on_hand == 0)
		printf("��ע�⣬��Ʒ���Ϊ�㣡\n\n");
	printf("��Ʒ����ɹ���\n\n");
	commidity[i + 1] = malloc(sizeof(struct shopping));
	strcpy(commidity[i + 1]->name, "");
	info_flush();
}

void info_init()
{
	FILE *fp;
	int tem;
	int i, y;							/*����*/
	char name_tem[NAME_LEN + 1]; 
	
	if ((fp = fopen("commodity.txt", "r")) == NULL)
	{
		fprintf(stderr,"��Ʒ��Ϣ��ʧ�ܣ���رպ���й���Ա��\n");
		exit(EXIT_FAILURE); 
	}
	
	for(i = 0; i < MAX_ITEM; i++)
	{
		
		commidity[i] = malloc(sizeof(struct shopping)); 
		if(fgets(commidity[i]->name, NAME_LEN + 1, fp) == NULL)
		{
			free(commidity[i]);
			fclose(fp);
			break;
		}
		if((fscanf(fp, "%lf", &(commidity[i]->price))) == EOF)
		{
			for(y = 0; (commidity[i]->name)[y] != '\n'; y++)
				;
			strcpy(name_tem, commidity[i]->name);
			name_tem[y] = '\0';
			fprintf(stderr,"%s�ļ۸����ݶ���ʧ�ܣ���رճ������ϵ����Ա.\n", name_tem);
			free(commidity[i]);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		if((fscanf(fp, "%ld", &(commidity[i]->on_hand))) == EOF)
		{
			for(y = 0; (commidity[i]->name)[y] != '\n'; y++)
				;
			strcpy(name_tem, commidity[i]->name);
			name_tem[y] = '\0';
			fprintf(stderr,"%s�Ŀ�����ݶ���ʧ�ܣ���رճ������ϵ����Ա.\n", name_tem);
			free(commidity[i]);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		fscanf(fp, "%d", &tem);			/*ȥ��on_hand��Ļ��з�*/ 

		if(fgets(commidity[i]->unit, UNIT_LEN + 1, fp) == NULL)
		{
			for(y = 0; (commidity[i]->name)[y] != '\n'; y++)
				;
			strcpy(name_tem, commidity[i]->name);
			name_tem[y] = '\0';
			fprintf(stderr,"%s�ļ�����λ���ݶ���ʧ�ܣ���رճ������ϵ����Ա.\n", name_tem);
			free(commidity[i]);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		fscanf(fp, "%d", &tem);
		if (tem == '/n') 		/*ȥ��ÿ�������Ļ��з�*/ 
			;
		else if(tem == EOF)
			break;
		
	}
	commidity[i] = malloc(sizeof(struct shopping));
	strcpy(commidity[i]->name, "");
	printf("��Ʒ��Ϣ��ʼ���ɹ���\n");
	printf("��������Ӧ��...\n\n"); 
	fclose(fp);
} 

void info_flush()
{
	FILE *fp;
	int i;							/*����*/
	
	if ((fp = fopen("commodity.txt", "w")) == NULL)
	{
		fprintf(stderr,"��Ʒ��Ϣ��ʧ�ܣ���رպ���й���Ա��\n");
		exit(EXIT_FAILURE); 
	}
	for(i = 0; strcmp(commidity[i]->name, ""); i++)
		; 
	if(i == 0)
	{
		fprintf(fp, "");
		return;
	} 
	else
	{
		fputs(commidity[0]->name, fp);
		fprintf(fp, "%lf\n", commidity[0]->price);
		fprintf(fp, "%ld\n", commidity[0]->on_hand);
		fputs(commidity[0]->unit, fp);
	}
	
	fclose(fp);
	
	if ((fp = fopen("commodity.txt", "a")) == NULL)
	{
		fprintf(stderr,"��Ʒ��Ϣ��ʧ�ܣ���رպ���й���Ա��\n");
		exit(EXIT_FAILURE); 
	}
	
	
	for(i = 1; strcmp(commidity[i]->name, ""); i++)
	{
		fputs(commidity[i]->name, fp);
		fprintf(fp, "%lf\n", commidity[i]->price);
		fprintf(fp, "%ld\n", commidity[i]->on_hand);
		fputs(commidity[i]->unit, fp);
	}
	
	fclose(fp);
} 