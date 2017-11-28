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
};							/*用结构数组实现商品信息储存*/ 

struct shopping *commidity[MAX_ITEM];

/*从一个txt文件内读取商品信息以初始化链表*/	
void info_init();					

/*将程序运行中改动过的商品信息储存到原文件中*/
void info_flush();

/*将商品列表中所有商品的每项信息打印到屏幕上*/
void OutputAll();					

/*格式化输出某一项商品信息，name为该商品的名称*/
void info_output(struct shopping *com_now);		

/********************************************************************* 
 *完成商品信息的修改功能，其中要求用户输入需要修改的某项商品的名称， * 
 *然后对名称进行查找，找到则继续输入该商品的各项信息，并提示修改成功 * 
 *如果没有找到则提示对应商品未找到在两种选择后都返回到初始的选择菜单 * 
 *********************************************************************/ 
void info_change();	

/********************************************************************* 
 *完成删除某条商品库中信息的功能，                                   *
 *通过输入的某项商品的名称删除对应的信息，如果在商品库中找到对应	 *
 *的商品便删除该商品信息（即释放指针所指向的内存，并把该指针赋值	 *
 *为 NULL），并提示删除成功；如果没有找到该商品要提示没有找到该商	 *
 *品信息，在两种选择下都回到上一步选择界面                           * 
 *********************************************************************/				

void info_dele();

/************************************************************************* 
 *完成商品信息的查找功能，然后通过输入某种商品信息的名称来检索商品信息库,*
 *查找到则显示该商品的详细信息，没有查找到则提示没有该商品 				 *					 
 *************************************************************************/ 
void info_search();

/************************************************************************** 
 *完成商品信息的插入，在插入之前动态的分配内存用来存储插入的商品信息，	  *
 *然后把指向该内存的指针加入到第一步定义的结构体指针数组中的第一个空元素中*
 *；在插入之前必须考虑整个信息库的限定容量，如果超过上限要给用户以提示	  *			 					 
 **************************************************************************/
void info_insert();

/************************************************************************* 
 *传入商品名称，若找到该商品则返回商品信息的指针，找不到则返回空指针	 *					 
 *************************************************************************/ 
struct shopping *info_return(char name_input[NAME_LEN + 2]);

int main(void)
{
	char num;
	
	system("color 0A");  
	info_init();		 /*从文件中读取信息并初始化链表*/
	
	printf("****************************************************************************\n");
	printf("*                                                                          *\n");
	printf("*                    ---欢迎进入xx超市商品管理系统---                      *\n");
	printf("*                                                                          *\n");
	printf("****************************************************************************\n");
	printf("\n\n");
	printf("        注：本系统对商品进行操作后信息会自动保存，搜索均为模糊搜索。\n\n\n");
	
	while(1)
	{
		printf("                       *****************************\n");
		printf("                       *                           *\n"); 
		printf("                       * 1.输入i录入商品信息。     *\n");
		printf("                       *                           *\n");
		printf("                       * 2.输入c修改商品信息。     *\n");
		printf("                       *                           *\n");
		printf("                       * 3.输入d删除商品信息。     *\n");
		printf("                       *                           *\n");
		printf("                       * 4.输入s查找商品信息。     *\n");
		printf("                       *                           *\n");
		printf("                       * 5.输入o打印所有商品信息。 *\n");
		printf("                       *                           *\n");
		printf("                       * 6.输入q退出系统。         *\n");
		printf("                       *                           *\n");
		printf("                       *****************************\n\n\n");
		printf("输入您想进行的操作: ");
		
		k : scanf(" %c", &num); 	/*跳过输入时输入的字符前面的空格*/ 
		if(getchar() != '\n')
		{
			printf("您输入的操作有误，请重新输入： ");
			while(getchar() != '\n')
				;						 /*跳过输入时输入的多余的字符*/ 
			goto k; 
		}						/*检查用户是否输入了多个字符*/
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
			printf("退出成功！\n"); 
			return 0;
			default :
			printf("输入有误，请重新输入。\n");
			break;
		}
	}
	
	return 0; 
}



void OutputAll()
{
	int i, y; 					/*计数*/ 
	char name_tem[NAME_LEN + 2];			/*暂存商品名称*/
	char unit_tem[UNIT_LEN + 2];				/*暂存计量单位名称*/
	
	if (!strcmp("", commidity[0]->name))
	{
		printf("抱歉，商品库中暂无商品信息！\n\n");
		return;
	}
	
	printf("商品名称            价格        库存量      计量单位\n");
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
	int i, y;			/*计数*/
	
	printf("请输入您想查找的商品的名称: ");
	fgets(name_tem, NAME_LEN + 1, stdin);
	if(strlen(name_tem) == NAME_LEN)
		if(name_tem[NAME_LEN - 1] != '\n') 
			while(getchar() != '\n')
				;						 /*跳过输入时输入的多余的字符*/ 
	for(y = 0; y < strlen(name_tem); y++)
		;
	name_tem[y - 1] = '\0';
	if((tem = info_return(name_tem)) != NULL)
		info_output(tem);
	else
	{
		printf("您输入的商品信息有误或商品不存在，可选择重新搜索（s）、插入该商品信息（i）或者返回主界面（b）: ");
		l: scanf(" %c", &num); 	/*跳过输入时输入的字符前面的空格*/ 
		if(getchar() != '\n')
		{
			printf("您输入的操作有误，请重新输入： ");
			while(getchar() != '\n')
				;						 /*跳过输入时输入的多余的字符*/ 
			goto l; 
		}						/*检查用户是否输入了多个字符*/
		switch(tolower(num))
		{
			case 's': info_search();
			break;
			case 'i': info_insert();
			break;
			case 'b': return;
			default:
			printf("您输入操作有误，可选择重新搜索（s）、插入该商品信息（i）或者返回主界面（b）: ");
			goto l;			/*重新操作*/ 
		}
		
	}
		
}

void info_change()
{
	char name_tem[NAME_LEN + 2];		/*暂存商品名称*/
	char unit_tem[UNIT_LEN + 2];		/*暂存计量单位名称*/
	struct shopping *com_now;
	char num;
	double change1 = 0;
	long change2 = 0;
 	int i, y; 					/*计数*/
	
	m: printf("请输入您想修改的商品的名称: ");
	fgets(name_tem, NAME_LEN + 1, stdin);
	if(strlen(name_tem) == NAME_LEN)
		if(name_tem[NAME_LEN - 1] != '\n') 
			while(getchar() != '\n')
				;						 /*跳过输入时输入的多余的字符*/ 
	for(y = 0; y < strlen(name_tem); y++)
		;
	name_tem[y - 1] = '\0';
	printf("\n\n");
	if((com_now = info_return(name_tem)) == NULL )
	{
		printf("您输入的商品信息有误或商品不存在，可选择重新输入（s）、插入该商品信息（i）或者返回主界面（b）: ");
		q: scanf(" %c", &num); 	/*跳过输入时输入的字符前面的空格*/ 
		if(getchar() != '\n')
		{
			printf("您输入的操作有误，请重新输入： ");
			while(getchar() != '\n')
				;						 /*跳过输入时输入的多余的字符*/ 
			goto q; 
		}						/*检查用户是否输入了多个字符*/
		switch(tolower(num))
		{
			case 's': goto m; 
			case 'i': info_insert();
			break;
			case 'b': return;
			default:
			printf("您输入操作有误，可选择重新搜索（s）、插入该商品信息（i）或者返回主界面（b）: ");
			goto q;			/*重新操作*/ 
		}
		 
	}
	else
	{
		printf("****************************************************************************\n");
		printf("*                                                                          *\n");
		printf("*        请注意，输入非法字符时（字母或符号）价格和库存变更将为零!!!       *\n");
		printf("*                                                                          *\n");
		printf("****************************************************************************\n");
		printf("请输入您想修改的商品的信息: 价格（p）、计量单位（u）或者库存（o）,或返回主界面（b）: ");
		
		l: scanf(" %c", &num); 	/*跳过输入时输入的字符前面的空格*/ 
		if(getchar() != '\n')
		{
			printf("您输入的操作有误，请重新输入： ");
			while(getchar() != '\n')
				;						 /*跳过输入时输入的多余的字符*/ 
			goto l; 
		}						/*检查用户是否输入了多个字符*/
		switch(tolower(num))
		{
			case 'u':
			t: printf("请输入计量单位: （最大不超过%d个字母/数字/字符）：", UNIT_LEN);
			fgets(unit_tem, UNIT_LEN + 2, stdin);
			if((y = strlen(unit_tem)) == (UNIT_LEN + 1))
			{
		
				if(unit_tem[UNIT_LEN] != '\n') 
					while(getchar() != '\n')
						;							/*跳过输入时输入的多余的字符*/ 
				printf("计量单位过长！请重新输入！\n");
				goto t;						 
			}
			unit_tem[y - 1] = '\n';
			unit_tem[y] = '\0';
			strcpy(com_now->unit, unit_tem);
			printf("商品计量单位修改成功！即将返回主界面...\n\n");
			info_flush();
			return;
			case 'p':
			printf("请输入您想修改的数额（如-1为减少一元，2为增加两元，并且增加时请勿添加+符号，会被视为非法字符）: ");
			scanf("%lf", &change1);
			while(getchar() != '\n')
				;
			if(change1 == 0)
			{
				printf("请注意，您未对商品做出变更！\n\n");
				break; 
			}
			com_now->price += change1;
			printf("商品价格修改成功！即将返回主界面...\n\n");
			info_flush();
			return;
			case 'o': 
			printf("请输入您想修改的数额（如-1为减少一个库存，2为增加两个库存，并且增加时请勿添加+符号，会被视为非法字符）: ");
			scanf("%ld", &change2);
			while(getchar() != '\n')
				;
			if(change2 == 0)
			{
				printf("请注意，您未对商品做出变更！\n\n");
				break; 
			}
			com_now->on_hand += change2;
			printf("商品库存修改成功！即将返回主界面...\n\n");
			info_flush();
			return;
			case 'b': 
			return;
			default:
			printf("您输入操作有误，可选择修改价格（p）、库存（o）或者返回主界面（b）: ");
			goto l;			/*重新操作*/ 
		}
	}
		
	
	
}

struct shopping *info_return(char name_input[NAME_LEN + 2])
{
	int i, y; 					/*计数*/
	int count = 0; 				/*计数*/
	struct shopping *com_now = commidity;   /*记住链表搜索后得到的位置*/
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
		printf("\n以上是可能的结果，请问您想操作的商品名称是？：");
		g: fgets(name_tem, NAME_LEN + 1, stdin);
		if(strlen(name_tem) == NAME_LEN)
			if(name_tem[NAME_LEN - 1] != '\n') 
				while(getchar() != '\n')
					;						 /*跳过输入时输入的多余的字符*/ 
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
		printf("您输入的商品信息有误，请重新输入！：");
		goto g;
	}
	
	
}

void info_output(struct shopping *com_now)
{
	
	printf("商品查找成功！以下是商品信息：\n\n");
	printf("价格        库存量      计量单位\n");
	printf("%-13.2lf%-11ld%s\n", com_now->price, com_now->on_hand, com_now->unit);
	return;
}

void info_dele()
{
	char name_tem[NAME_LEN + 2];
	struct shopping *tem;
	struct shopping cur, prev;
	int i, y; 							/*计数*/
	char num;
	
	m: printf("请输入您想删除的商品的名称: ");
	fgets(name_tem, NAME_LEN + 1, stdin);
	if(strlen(name_tem) == NAME_LEN)
		if(name_tem[NAME_LEN - 1] != '\n') 
			while(getchar() != '\n')
				;						 /*跳过输入时输入的多余的字符*/ 
	for(y = 0; y < strlen(name_tem); y++)
		;
	name_tem[y - 1] = '\0';
	tem = info_return(name_tem);
	if(tem == NULL)
	{
		printf("\n您输入的商品信息有误或商品不存在，可选择重新输入（s）或者返回主界面（b）: ");
		l: scanf(" %c", &num); 	/*跳过输入时输入的字符前面的空格*/ 
		if(getchar() != '\n')
		{
			printf("您输入的操作有误，请重新输入： ");
			while(getchar() != '\n')
				;						 /*跳过输入时输入的多余的字符*/ 
			goto l; 
		}						/*检查用户是否输入了多个字符*/
		switch(tolower(num))
		{
			case 's': goto m; 
			case 'b': return;
			default:
			printf("您输入操作有误，可选择重新搜索（s）或者返回主界面（b）: ");
			goto l;			/*重新操作*/ 
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
			printf("商品删除成功！\n\n");
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
	int i, y;							/*记数*/ 
	
	for(i = 0; strcmp(commidity[i]->name, ""); i++)
	{
		if (i == MAX_ITEM - 1)
	{
		fprintf(stderr,"操作失败！商品数量达到最大上限，请关闭后呼叫管理员。\n");
		return;
	}
	}
	
	
	l : printf("请输入您想加入的商品名（最大不超过%d个字母/数字/字符）：", NAME_LEN);
	fgets(name_tem, NAME_LEN + 2, stdin);
	if((y = strlen(name_tem)) == (NAME_LEN + 1))
	{
		
		if(name_tem[NAME_LEN] != '\n') 
			while(getchar() != '\n')
				;							/*跳过输入时输入的多余的字符*/ 
		printf("名字过长！请重新输入！\n");
		goto l;						 
	}
	name_tem[y - 1] = '\n';
	name_tem[y] = '\0';
	strcpy(commidity[i]->name, name_tem);
	z : printf("请输入您想加入的商品计量单位名（最大不超过%d个字母/数字/字符）：", UNIT_LEN);
	fgets(unit_tem, UNIT_LEN + 2, stdin);
	if((y = strlen(unit_tem)) == (UNIT_LEN + 1))
	{
		
		if(unit_tem[UNIT_LEN] != '\n') 
			while(getchar() != '\n')
				;							/*跳过输入时输入的多余的字符*/ 
		printf("名字过长！请重新输入！\n");
		goto z;						 
	}
	unit_tem[y - 1] = '\n';
	unit_tem[y] = '\0';
	strcpy(commidity[i]->unit, unit_tem);
	printf("****************************************************************************\n");
	printf("*                                                                          *\n");
	printf("*          请注意，输入非法字符时（字母或符号）价格和库存将为零!!!         *\n");
	printf("*                                                                          *\n");
	printf("****************************************************************************\n");
	printf("请输入您加入的商品的价格: ");
	scanf("%lf", &(commidity[i]->price));
	while(getchar() != '\n')
				;
	if(commidity[i]->price == 0)
		printf("请注意，商品价格为零！\n\n");
	printf("请输入您加入的商品的库存: ");
	scanf("%ld", &(commidity[i]->on_hand));
	while(getchar() != '\n')
				;
	if(commidity[i]->on_hand == 0)
		printf("请注意，商品库存为零！\n\n");
	printf("商品加入成功！\n\n");
	commidity[i + 1] = malloc(sizeof(struct shopping));
	strcpy(commidity[i + 1]->name, "");
	info_flush();
}

void info_init()
{
	FILE *fp;
	int tem;
	int i, y;							/*记数*/
	char name_tem[NAME_LEN + 1]; 
	
	if ((fp = fopen("commodity.txt", "r")) == NULL)
	{
		fprintf(stderr,"商品信息打开失败，请关闭后呼叫管理员。\n");
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
			fprintf(stderr,"%s的价格数据读入失败，请关闭程序后联系管理员.\n", name_tem);
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
			fprintf(stderr,"%s的库存数据读入失败，请关闭程序后联系管理员.\n", name_tem);
			free(commidity[i]);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		fscanf(fp, "%d", &tem);			/*去除on_hand后的换行符*/ 

		if(fgets(commidity[i]->unit, UNIT_LEN + 1, fp) == NULL)
		{
			for(y = 0; (commidity[i]->name)[y] != '\n'; y++)
				;
			strcpy(name_tem, commidity[i]->name);
			name_tem[y] = '\0';
			fprintf(stderr,"%s的计量单位数据读入失败，请关闭程序后联系管理员.\n", name_tem);
			free(commidity[i]);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		fscanf(fp, "%d", &tem);
		if (tem == '/n') 		/*去除每三行最后的换行符*/ 
			;
		else if(tem == EOF)
			break;
		
	}
	commidity[i] = malloc(sizeof(struct shopping));
	strcpy(commidity[i]->name, "");
	printf("商品信息初始化成功！\n");
	printf("正在启动应用...\n\n"); 
	fclose(fp);
} 

void info_flush()
{
	FILE *fp;
	int i;							/*记数*/
	
	if ((fp = fopen("commodity.txt", "w")) == NULL)
	{
		fprintf(stderr,"商品信息打开失败，请关闭后呼叫管理员。\n");
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
		fprintf(stderr,"商品信息打开失败，请关闭后呼叫管理员。\n");
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