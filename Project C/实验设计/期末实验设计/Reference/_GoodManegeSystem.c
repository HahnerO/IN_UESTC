#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define NAME_LENGTH 20
#define TITLE_LENGTH 20
#define AUTHOR_LENGTH 20
#define COLOR_LENGTH 20
#define LEN sizeof(struct part)

struct part{
	char name[NAME_LENGTH+1];
	double price;
	int in_hand;
	int id;
	
};
struct part *goods[100]={NULL};

void OutputAll();
void info_output(int i);
void info_change();
void info_dele();
void info_search();
void info_insert();
void main_menu();
void info_empty();

int main(){
	char code,ch;
	
	while(1){
		main_menu(); 
		printf("Please enter a code:");
		scanf("%c",&code);
		switch(code){
			case'i':
				info_insert();
				break;
			case'c':
				info_change();
				break;
			case's':
				info_search();
				break;
			case'd':
				info_dele();
				break;
			case'p':
				OutputAll();
				break;
			case'e':
				info_empty();
				break;
			case'q':
				getchar();
				printf("Quit?(y/n)");
				scanf("%c",&ch); 
				if(ch=='Y'||ch=='y'){
				    return 0;
					}
				else if(ch=='N'||ch=='n'){
				
					break;
				}
			default:printf("you entered a wrong code,please try it again.\n"); 
		}
		getchar();
		printf("please get any key to continue.");
		getchar(); 
		system("cls");  
	}
}

void OutputAll(){
	int i,m=0;
	FILE *fp;
 for(i=0;i<100;i++){
   	goods[i]=(struct part*)malloc(LEN);
   } 
	if((fp=fopen("C:/Users/Administrator/Desktop/file2.txt","r"))==NULL){
		printf("can not open!\n");
		return;
	}else{
	while(!feof(fp)){
		if(fread(goods[m]->name,sizeof(struct part),1,fp)==1){
			m++;
		}
	}
	fclose(fp);
	printf("id\tname\tprice\tqunatity\n");
	for(i=0;i<m;i++){
		printf("%d\t",goods[i]->id);
	    printf("%s\t",goods[i]->name);
	    printf("%.2lf\t",goods[i]->price);
		printf("%d\n",goods[i]->in_hand); 
	    }
	}
	for(i=0;i<100;i++){
		free(goods[i]);
	}
    return;
}

void info_change(){
    char ch[NAME_LENGTH+1];
    int i,m=0;
	FILE *fp;
	for(i=0;i<100;i++){
   	goods[i]=(struct part*)malloc(LEN);
   } 
	if((fp=fopen("C:/Users/Administrator/Desktop/file2.txt","r+"))==NULL){
	    printf("can not open!\n");
		return;
	}else{
		while(!feof(fp)){
			if((fread(goods[m],sizeof(struct part),1,fp))==1){
				m++;
			}
		}
	    printf("please enter the name of the good:");
	    scanf("%s",ch);
		for(i=0;i<=m+1;i++){
			if(strcmp(ch,goods[i]->name)==0){
				printf("please enter the new id:");
				scanf("%d",&goods[i]->id);
				printf("please enter the new price:");
				scanf("%lf",&goods[i]->price);
				printf("please enter the new quantity:");
				scanf("%d",&goods[i]->in_hand);
				break;
			}
			
			}
		}
		if(i==m+1){
				printf("Not find!\n");
				return;
				}
    rewind(fp); 
	for(i=0;i<m;i++){
		fwrite(goods[i],LEN,1,fp);
		
	}
	fclose(fp);
	for(i=0;i<100;i++){
		free(goods[i]);
	}
	return;
}

void info_empty(){
	FILE *fp;
	int i,m=0;
	for(i=0;i<100;i++){
   	goods[i]=(struct part*)malloc(LEN);
   } 
	if((fp=fopen("C:/Users/Administrator/Desktop/file2.txt","r"))==NULL){
	    printf("can not open!\n");
		return;
	}else{
		while(!feof(fp)){
			if((fread(goods[m],LEN,1,fp))==1){
				m++;
			}
		if(m==0){
			printf("No good in it!\n");
			return; 
		}
		m=0;
		if((fp=fopen("C:/Users/Administrator/Desktop/file2.txt","w"))==NULL){
	        printf("can not open!\n");
		    return;
			}else{
				printf("Empty successfully!\n");
		for(i=0;i<100;i++){
		    free(goods[i]);
	    }
				return;
			} 
        }
        
	}
} 
void info_dele(){
	int i,m=0;
	char ch[NAME_LENGTH+1];
	FILE *fp;
	for(i=0;i<100;i++){
   	   goods[i]=(struct part*)malloc(LEN);
   } 
	if((fp=fopen("C:/Users/Administrator/Desktop/file2.txt","r"))==NULL){
	    printf("can not open!\n");
		return;
	}else{
		while(!feof(fp)){
			if((fread(goods[m],LEN,1,fp))==1){
				m++;
			}
		}
		
		if(m==0){
			printf("No good in it!\n");
			return; 
		}
		fclose(fp);
		
		printf("please choose a good:");
		scanf("%s",ch);
		
		for(i=0;i<=m;i++){
			if(strcmp(ch,goods[i]->name)==0){
				for(;i<m-1;i++){
			        *goods[i]=*goods[i+1];
		        }
				break;
			}
		}
		
		if(i==m){
			printf("Not find!\n");
			return;
		}
		m--;
	if((fp=fopen("C:/Users/Administrator/Desktop/file2.txt","w"))==NULL){
	    printf("can not open!\n");
		return;
	}else{
		
		for(i=0;i<m;i++){
			fwrite(goods[i],LEN,1,fp);
		}
		
		fclose(fp);
	    }
	}
	
	for(i=0;i<100;i++){
		free(goods[i]);
	}
	return;
}
void info_search(){
	char ch[NAME_LENGTH+1];
	int i,m=0;
	for(i=0;i<100;i++){
   	goods[i]=(struct part*)malloc(LEN);
   } 
	FILE *fp;
	if((fp=fopen("C:/Users/Administrator/Desktop/file2.txt","r"))==NULL){
	    printf("can not open!\n");
		return;
	}else{
		while(!feof(fp)){
			if((fread(goods[m],LEN,1,fp))==1){
				m++;
			}
		}
		if(m==0){
			printf("No good in it!\n");
			return; 
		}
		printf("--%d--\n",m); 
		printf("please enter the name of the good:");
		scanf("%s",ch);
		for(i=0;i<m;i++){
			if(strcmp(ch,goods[i]->name)==0){
				printf("the id of the good is:%d\n",goods[i]->id);
				printf("the price is : %.2lf\n",goods[i]->price);
				printf("the quantity is %d\n",goods[i]->in_hand);
				break;
			}
			}
		if(i==m){
			printf("Not find!\n");
		} 
		
	} 
	fclose(fp);
	for(i=0;i<100;i++){
		free(goods[i]);
	}
	return;

} 
void info_insert(){
   int i,m=0,n,j;
   for(i=0;i<100;i++){
   	goods[i]=(struct part*)malloc(LEN);
   } 
   struct part *temp_good;
   temp_good=(struct part*)malloc(LEN);
   FILE *fp;
    if((fp=fopen("C:/Users/Administrator/Desktop/file2.txt","r+"))==NULL){
	    printf("can not open!\n");
		return;
	}else{  
		while(!feof(fp)){
			if(m>=100){
	    		printf("Is full!");
	    		fclose(fp);
	    		return;
			}
			if(fread(goods[m],sizeof(struct part),1,fp)==1){
					m++;
			}else if(fread(goods[m],sizeof(struct part),1,fp)!=1){
				break;
			}
		}
		printf("--%d--\n",m);
		printf("please enter the id of the new good:");
		scanf("%d",&goods[m]->id);
		printf("please enter the name of the new good:");
		scanf("%s",goods[m]->name);
		
		for(i=0;i<m;i++){
			if(goods[i]==NULL){
				printf("the space is not exiting!\n");
			}
			if(strcmp(goods[i]->name,goods[m]->name)==0){
				printf("the good is exiting!\n");
				return;
			}
		}
		printf("please enter the price of the new good:");
		scanf("%lf",&goods[m]->price);
		printf("please enter the quantity of the new good:");
		scanf("%d",&goods[m]->in_hand);
	}
	
	for(j=m;j>=0;j--){
			for(n=0;n<j;n++){
				if(strcmp(goods[n]->name,goods[n+1]->name)>0){
					*temp_good=*goods[n];
					*goods[n]=*goods[n+1];
					*goods[n+1]=*temp_good;
				}
			}
		} 
    rewind(fp);
    
    free(temp_good);
	for(i=0;i<=m;i++){ 
	fwrite(goods[i],sizeof(struct part),1,fp);
	}
	fclose(fp); 
	for(i=0;i<100;i++){
		free(goods[i]);
	}
	
    return;
}

void main_menu(){
	printf("*************************\n");
	printf("*i:insert\t\t*\n*s:search information\t*\n");
	printf("*c:change information\t*\n");
	printf("*p:print all\tq:quit\t*\n");
	printf("*e:empty\t\t*\n"); 
	printf("*************************\n"); 
}
