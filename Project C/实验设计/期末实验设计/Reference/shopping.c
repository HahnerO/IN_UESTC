#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


#define NAME_LEN 30
#define UNIT_LEN 10

struct shopping
{
	char name[NAME_LEN + 2];
	double price;
	long int on_hand;
	char unit[UNIT_LEN + 2];
	struct shopping *next;
};							/*������ʵ����Ʒ��Ϣ����*/ 

struct shopping *commidity = NULL;

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
	int i; 					/*����*/ 
	char name_tem[NAME_LEN + 2];			/*�ݴ���Ʒ����*/
	char unit_tem[UNIT_LEN + 2];				/*�ݴ������λ����*/
	struct shopping *com_init = commidity;   /*��ס����ͷ*/
	
	if (commidity == NULL)
	{
		printf("��Ǹ����Ʒ����������Ʒ��Ϣ��\n\n");
		return;
	}
	
	printf("��Ʒ����            �۸�        �����      ������λ\n");
	for(; commidity != NULL; commidity = commidity->next)
	{
		
		for(i = 0; (commidity->name)[i] != '\n'; i++)
			;
		strcpy(name_tem, commidity->name);
		name_tem[i] = '\0';
		for(i = 0; (commidity->unit)[i] != '\n'; i++)
			;
		strcpy(unit_tem, commidity->unit);
		unit_tem[i] = '\0';
		printf("%-20s%-13.2lf%-11ld%s\n", name_tem, commidity->price, commidity->on_hand, unit_tem);
	}
	printf("\n\n\n");
	commidity = com_init;
}

void info_search()
{
	char name_tem[NAME_LEN + 2];
	char num;
	struct shopping *tem;
	int i;			/*����*/
	
	printf("������������ҵ���Ʒ������: ");
	fgets(name_tem, NAME_LEN + 1, stdin);
	if(strlen(name_tem) == NAME_LEN)
		if(name_tem[NAME_LEN - 1] != '\n') 
			while(getchar() != '\n')
				;						 /*��������ʱ����Ķ�����ַ�*/ 
	for(i = 0; i < strlen(name_tem); i++)
		;
	name_tem[i - 1] = '\0';
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
	struct shopping *com_now = commidity;   /*��ס����������õ���λ��*/
	char num;
	double change1 = 0;
	long change2 = 0;
 	int i; 					/*����*/
	
	m: printf("�����������޸ĵ���Ʒ������: ");
	fgets(name_tem, NAME_LEN + 1, stdin);
	if(strlen(name_tem) == NAME_LEN)
		if(name_tem[NAME_LEN - 1] != '\n') 
			while(getchar() != '\n')
				;						 /*��������ʱ����Ķ�����ַ�*/ 
	for(i = 0; i < strlen(name_tem); i++)
		;
	name_tem[i - 1] = '\0';
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
			if((i = strlen(unit_tem)) == (UNIT_LEN + 1))
			{
		
				if(unit_tem[UNIT_LEN] != '\n') 
					while(getchar() != '\n')
						;							/*��������ʱ����Ķ�����ַ�*/ 
				printf("������λ���������������룡\n");
				goto t;						 
			}
			unit_tem[i - 1] = '\n';
			unit_tem[i] = '\0';
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
	int i; 					/*����*/
	int count = 0; 				/*����*/
	struct shopping *com_init = commidity;   /*��ס����ͷ*/
	struct shopping *com_now = commidity;   /*��ס����������õ���λ��*/
	char name_tem[NAME_LEN + 1];
	
	for(; commidity != NULL; commidity = commidity->next)
	{
		for(i = 0; name_input[i] != '\0'; i++)
		{
			if((commidity->name)[i] == name_input[i])
				;
			else
				break;
		}
		if(name_input[i] == '\0')
		{
			printf("%s\n", commidity->name);
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
		commidity = com_init;
		for(; commidity != NULL; commidity = commidity->next)
		{
			for(i = 0; (commidity->name)[i] != '\n'; i++)
			{
				if((commidity->name)[i] == name_tem[i])
					;
				else
					break;
			}
			if((commidity->name)[i] == '\n' && name_tem[i] == '\0')
			{
				com_now = commidity;
				commidity = com_init;
				return com_now;
			}
		
		
		}
		printf("���������Ʒ��Ϣ�������������룡��");
		goto g;
	}
	
	
}

void info_output(struct shopping *com_now)
{
	struct shopping *com_init = commidity;   /*��ס����ͷ*/
	
	printf("��Ʒ���ҳɹ�����������Ʒ��Ϣ��\n\n");
	printf("�۸�        �����      ������λ\n");
	printf("%-13.2lf%-11ld%s\n", com_now->price, com_now->on_hand, com_now->unit);
	commidity = com_init;
	return;
}

void info_dele()
{
	char name_tem[NAME_LEN + 2];
	struct shopping *tem;
	struct shopping *cur, *prev;
	int i; 							/*����*/
	char num;
	
	m: printf("����������ɾ������Ʒ������: ");
	fgets(name_tem, NAME_LEN + 1, stdin);
	if(strlen(name_tem) == NAME_LEN)
		if(name_tem[NAME_LEN - 1] != '\n') 
			while(getchar() != '\n')
				;						 /*��������ʱ����Ķ�����ַ�*/ 
	for(i = 0; i < strlen(name_tem); i++)
		;
	name_tem[i - 1] = '\0';
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
		for (cur = commidity, prev = NULL; cur != NULL; prev = cur, cur = cur->next)
	{
		if (cur == tem)
		{
			if (prev == NULL)
			{
				commidity = commidity->next;
				free(cur);
				printf("��Ʒɾ���ɹ���\n\n");
				info_flush();
				return;
			}
			else
			{
				
				prev->next = cur->next;
				free(cur);
				info_flush();
				printf("��Ʒɾ���ɹ���\n\n");
				return;
			}
				
		}
			
	}
	}
} 

void info_insert()
{
	struct shopping *new_commidity;
	char name_tem[NAME_LEN + 2];
	char unit_tem[UNIT_LEN + 2];
	char price_tem[1000];
	char on_hand_tem[1000];
	int i;							/*��¼��������*/ 
	
	new_commidity = malloc(sizeof(struct shopping));
	if (new_commidity == NULL)
	{
		fprintf(stderr,"����ʧ�ܣ������ǵ����ڴ���������رպ���й���Ա��\n");
		return;
	}
	
	l : printf("����������������Ʒ������󲻳���%d����ĸ/����/�ַ�����", NAME_LEN);
	fgets(name_tem, NAME_LEN + 2, stdin);
	if((i = strlen(name_tem)) == (NAME_LEN + 1))
	{
		
		if(name_tem[NAME_LEN] != '\n') 
			while(getchar() != '\n')
				;							/*��������ʱ����Ķ�����ַ�*/ 
		printf("���ֹ��������������룡\n");
		goto l;						 
	}
	name_tem[i - 1] = '\n';
	name_tem[i] = '\0';
	strcpy(new_commidity->name, name_tem);
	z : printf("����������������Ʒ������λ������󲻳���%d����ĸ/����/�ַ�����", UNIT_LEN);
	fgets(unit_tem, UNIT_LEN + 2, stdin);
	if((i = strlen(unit_tem)) == (UNIT_LEN + 1))
	{
		
		if(unit_tem[UNIT_LEN] != '\n') 
			while(getchar() != '\n')
				;							/*��������ʱ����Ķ�����ַ�*/ 
		printf("���ֹ��������������룡\n");
		goto z;						 
	}
	unit_tem[i - 1] = '\n';
	unit_tem[i] = '\0';
	strcpy(new_commidity->unit, unit_tem);
	printf("****************************************************************************\n");
	printf("*                                                                          *\n");
	printf("*          ��ע�⣬����Ƿ��ַ�ʱ����ĸ����ţ��۸�Ϳ�潫Ϊ��!!!         *\n");
	printf("*                                                                          *\n");
	printf("****************************************************************************\n");
	printf("���������������Ʒ�ļ۸�: ");
	scanf("%lf", &(new_commidity->price));
	while(getchar() != '\n')
				;
	if(new_commidity->price == 0)
		printf("��ע�⣬��Ʒ�۸�Ϊ�㣡\n\n");
	printf("���������������Ʒ�Ŀ��: ");
	scanf("%ld", &(new_commidity->on_hand));
	while(getchar() != '\n')
				;
	if(new_commidity->on_hand == 0)
		printf("��ע�⣬��Ʒ���Ϊ�㣡\n\n");
	printf("��Ʒ����ɹ���\n\n");
	new_commidity->next = commidity;
	commidity = new_commidity;
	info_flush();
}

void info_init()
{
	FILE *fp;
	struct shopping *new_node;
	int tem;
	int i;
	char name_tem[NAME_LEN + 1]; 
	
	if ((fp = fopen("commodity.txt", "r")) == NULL)
	{
		fprintf(stderr,"��Ʒ��Ϣ��ʧ�ܣ���رպ���й���Ա��\n");
		exit(EXIT_FAILURE); 
	}
	
	for(;;)
	{
		new_node = malloc(sizeof(struct shopping));
		if (new_node == NULL)
		{
			fprintf(stderr,"�����ڴ���������Ʒ��Ŀ���࣬��رպ���й���Ա��\n");
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		if(fgets(new_node->name, NAME_LEN + 1, fp) == NULL)
		{
			free(new_node);
			fclose(fp);
			break;
		}
		if((fscanf(fp, "%lf", &(new_node->price))) == EOF)
		{
			for(i = 0; (new_node->name)[i] != '\n'; i++)
				;
			strcpy(name_tem, new_node->name);
			name_tem[i] = '\0';
			fprintf(stderr,"%s�ļ۸����ݶ���ʧ�ܣ���رճ������ϵ����Ա.\n", name_tem);
			free(new_node);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		if((fscanf(fp, "%ld", &(new_node->on_hand))) == EOF)
		{
			for(i = 0; (new_node->name)[i] != '\n'; i++)
				;
			strcpy(name_tem, new_node->name);
			name_tem[i] = '\0';
			fprintf(stderr,"%s�Ŀ�����ݶ���ʧ�ܣ���رճ������ϵ����Ա.\n", name_tem);
			free(new_node);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		fscanf(fp, "%d", &tem);			/*ȥ��on_hand��Ļ��з�*/ 

		if(fgets(new_node->unit, UNIT_LEN + 1, fp) == NULL)
		{
			for(i = 0; (new_node->name)[i] != '\n'; i++)
				;
			strcpy(name_tem, new_node->name);
			name_tem[i] = '\0';
			fprintf(stderr,"%s�ļ�����λ���ݶ���ʧ�ܣ���رճ������ϵ����Ա.\n", name_tem);
			free(new_node);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		
		new_node->next = commidity;
		commidity = new_node;
		fscanf(fp, "%d", &tem);
		if (tem == '/n') 		/*ȥ��ÿ�������Ļ��з�*/ 
			;
		else if(tem == EOF)
			break;
		
	}
	
	printf("��Ʒ��Ϣ��ʼ���ɹ���\n");
	printf("��������Ӧ��...\n\n"); 
	fclose(fp);
} 

void info_flush()
{
	FILE *fp;
	struct shopping *com_init = commidity;   /*��ס����ͷ*/

	
	if ((fp = fopen("commodity.txt", "w")) == NULL)
	{
		fprintf(stderr,"��Ʒ��Ϣ��ʧ�ܣ���رպ���й���Ա��\n");
		exit(EXIT_FAILURE); 
	}
	
	if(commidity == NULL)
	{
		fprintf(fp, "");
		return;
	} 
	else
	{
		fputs(commidity->name, fp);
		fprintf(fp, "%lf\n", commidity->price);
		fprintf(fp, "%ld\n", commidity->on_hand);
		fputs(commidity->unit, fp);
	}
	
	fclose(fp);
	
	if ((fp = fopen("commodity.txt", "a")) == NULL)
	{
		fprintf(stderr,"��Ʒ��Ϣ��ʧ�ܣ���رպ���й���Ա��\n");
		exit(EXIT_FAILURE); 
	}
	
	
	for(commidity = commidity->next; commidity != NULL; commidity = commidity->next)
	{
		fputs(commidity->name, fp);
		fprintf(fp, "%lf\n", commidity->price);
		fprintf(fp, "%ld\n", commidity->on_hand);
		fputs(commidity->unit, fp);
	}
	
	fclose(fp);
	commidity = com_init; 
} 