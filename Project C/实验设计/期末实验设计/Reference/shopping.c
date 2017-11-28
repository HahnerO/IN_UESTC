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
};							/*用链表实现商品信息储存*/ 

struct shopping *commidity = NULL;

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
	int i; 					/*计数*/ 
	char name_tem[NAME_LEN + 2];			/*暂存商品名称*/
	char unit_tem[UNIT_LEN + 2];				/*暂存计量单位名称*/
	struct shopping *com_init = commidity;   /*记住链表头*/
	
	if (commidity == NULL)
	{
		printf("抱歉，商品库中暂无商品信息！\n\n");
		return;
	}
	
	printf("商品名称            价格        库存量      计量单位\n");
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
	int i;			/*计数*/
	
	printf("请输入您想查找的商品的名称: ");
	fgets(name_tem, NAME_LEN + 1, stdin);
	if(strlen(name_tem) == NAME_LEN)
		if(name_tem[NAME_LEN - 1] != '\n') 
			while(getchar() != '\n')
				;						 /*跳过输入时输入的多余的字符*/ 
	for(i = 0; i < strlen(name_tem); i++)
		;
	name_tem[i - 1] = '\0';
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
	struct shopping *com_now = commidity;   /*记住链表搜索后得到的位置*/
	char num;
	double change1 = 0;
	long change2 = 0;
 	int i; 					/*计数*/
	
	m: printf("请输入您想修改的商品的名称: ");
	fgets(name_tem, NAME_LEN + 1, stdin);
	if(strlen(name_tem) == NAME_LEN)
		if(name_tem[NAME_LEN - 1] != '\n') 
			while(getchar() != '\n')
				;						 /*跳过输入时输入的多余的字符*/ 
	for(i = 0; i < strlen(name_tem); i++)
		;
	name_tem[i - 1] = '\0';
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
			if((i = strlen(unit_tem)) == (UNIT_LEN + 1))
			{
		
				if(unit_tem[UNIT_LEN] != '\n') 
					while(getchar() != '\n')
						;							/*跳过输入时输入的多余的字符*/ 
				printf("计量单位过长！请重新输入！\n");
				goto t;						 
			}
			unit_tem[i - 1] = '\n';
			unit_tem[i] = '\0';
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
	int i; 					/*计数*/
	int count = 0; 				/*计数*/
	struct shopping *com_init = commidity;   /*记住链表头*/
	struct shopping *com_now = commidity;   /*记住链表搜索后得到的位置*/
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
		printf("\n以上是可能的结果，请问您想操作的商品名称是？：");
		g: fgets(name_tem, NAME_LEN + 1, stdin);
		if(strlen(name_tem) == NAME_LEN)
			if(name_tem[NAME_LEN - 1] != '\n') 
				while(getchar() != '\n')
					;						 /*跳过输入时输入的多余的字符*/ 
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
		printf("您输入的商品信息有误，请重新输入！：");
		goto g;
	}
	
	
}

void info_output(struct shopping *com_now)
{
	struct shopping *com_init = commidity;   /*记住链表头*/
	
	printf("商品查找成功！以下是商品信息：\n\n");
	printf("价格        库存量      计量单位\n");
	printf("%-13.2lf%-11ld%s\n", com_now->price, com_now->on_hand, com_now->unit);
	commidity = com_init;
	return;
}

void info_dele()
{
	char name_tem[NAME_LEN + 2];
	struct shopping *tem;
	struct shopping *cur, *prev;
	int i; 							/*计数*/
	char num;
	
	m: printf("请输入您想删除的商品的名称: ");
	fgets(name_tem, NAME_LEN + 1, stdin);
	if(strlen(name_tem) == NAME_LEN)
		if(name_tem[NAME_LEN - 1] != '\n') 
			while(getchar() != '\n')
				;						 /*跳过输入时输入的多余的字符*/ 
	for(i = 0; i < strlen(name_tem); i++)
		;
	name_tem[i - 1] = '\0';
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
		for (cur = commidity, prev = NULL; cur != NULL; prev = cur, cur = cur->next)
	{
		if (cur == tem)
		{
			if (prev == NULL)
			{
				commidity = commidity->next;
				free(cur);
				printf("商品删除成功！\n\n");
				info_flush();
				return;
			}
			else
			{
				
				prev->next = cur->next;
				free(cur);
				info_flush();
				printf("商品删除成功！\n\n");
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
	int i;							/*记录名称字数*/ 
	
	new_commidity = malloc(sizeof(struct shopping));
	if (new_commidity == NULL)
	{
		fprintf(stderr,"操作失败！可能是电脑内存已满，请关闭后呼叫管理员。\n");
		return;
	}
	
	l : printf("请输入您想加入的商品名（最大不超过%d个字母/数字/字符）：", NAME_LEN);
	fgets(name_tem, NAME_LEN + 2, stdin);
	if((i = strlen(name_tem)) == (NAME_LEN + 1))
	{
		
		if(name_tem[NAME_LEN] != '\n') 
			while(getchar() != '\n')
				;							/*跳过输入时输入的多余的字符*/ 
		printf("名字过长！请重新输入！\n");
		goto l;						 
	}
	name_tem[i - 1] = '\n';
	name_tem[i] = '\0';
	strcpy(new_commidity->name, name_tem);
	z : printf("请输入您想加入的商品计量单位名（最大不超过%d个字母/数字/字符）：", UNIT_LEN);
	fgets(unit_tem, UNIT_LEN + 2, stdin);
	if((i = strlen(unit_tem)) == (UNIT_LEN + 1))
	{
		
		if(unit_tem[UNIT_LEN] != '\n') 
			while(getchar() != '\n')
				;							/*跳过输入时输入的多余的字符*/ 
		printf("名字过长！请重新输入！\n");
		goto z;						 
	}
	unit_tem[i - 1] = '\n';
	unit_tem[i] = '\0';
	strcpy(new_commidity->unit, unit_tem);
	printf("****************************************************************************\n");
	printf("*                                                                          *\n");
	printf("*          请注意，输入非法字符时（字母或符号）价格和库存将为零!!!         *\n");
	printf("*                                                                          *\n");
	printf("****************************************************************************\n");
	printf("请输入您加入的商品的价格: ");
	scanf("%lf", &(new_commidity->price));
	while(getchar() != '\n')
				;
	if(new_commidity->price == 0)
		printf("请注意，商品价格为零！\n\n");
	printf("请输入您加入的商品的库存: ");
	scanf("%ld", &(new_commidity->on_hand));
	while(getchar() != '\n')
				;
	if(new_commidity->on_hand == 0)
		printf("请注意，商品库存为零！\n\n");
	printf("商品加入成功！\n\n");
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
		fprintf(stderr,"商品信息打开失败，请关闭后呼叫管理员。\n");
		exit(EXIT_FAILURE); 
	}
	
	for(;;)
	{
		new_node = malloc(sizeof(struct shopping));
		if (new_node == NULL)
		{
			fprintf(stderr,"电脑内存已满或商品数目过多，请关闭后呼叫管理员。\n");
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
			fprintf(stderr,"%s的价格数据读入失败，请关闭程序后联系管理员.\n", name_tem);
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
			fprintf(stderr,"%s的库存数据读入失败，请关闭程序后联系管理员.\n", name_tem);
			free(new_node);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		fscanf(fp, "%d", &tem);			/*去除on_hand后的换行符*/ 

		if(fgets(new_node->unit, UNIT_LEN + 1, fp) == NULL)
		{
			for(i = 0; (new_node->name)[i] != '\n'; i++)
				;
			strcpy(name_tem, new_node->name);
			name_tem[i] = '\0';
			fprintf(stderr,"%s的计量单位数据读入失败，请关闭程序后联系管理员.\n", name_tem);
			free(new_node);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		
		new_node->next = commidity;
		commidity = new_node;
		fscanf(fp, "%d", &tem);
		if (tem == '/n') 		/*去除每三行最后的换行符*/ 
			;
		else if(tem == EOF)
			break;
		
	}
	
	printf("商品信息初始化成功！\n");
	printf("正在启动应用...\n\n"); 
	fclose(fp);
} 

void info_flush()
{
	FILE *fp;
	struct shopping *com_init = commidity;   /*记住链表头*/

	
	if ((fp = fopen("commodity.txt", "w")) == NULL)
	{
		fprintf(stderr,"商品信息打开失败，请关闭后呼叫管理员。\n");
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
		fprintf(stderr,"商品信息打开失败，请关闭后呼叫管理员。\n");
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