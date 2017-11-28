/*Computes the expression from left to right*/

#include <stdio.h>

int main(void)
{
	double a,b,c,mid,result;
	char sign_1,sign_2;
	
	printf("Enter an expression: ");
	scanf("%lf%c%lf%c%lf",&a,&sign_1,&b,&sign_2,&c);
	
	switch(sign_1){
		case '+':{
		    mid=a+b;
		}
		break;
		case '-':{
		    mid=a-b;
		}
		break;
		case '*':{
		    mid=a*b;
		}
		break;
		case '/':{
		if(b==0){
			printf("Illeagle expression!!!\n");
			return 0;
		}
		else{
			mid=a/b;
		};
		};
		break;
	}
	
	switch(sign_2){
		case '+':{
		    result=mid+c;
		}
		break;
		case '-':{
		result=mid-c;
	    }
		break;
		case '*':{ 
		result=mid*c;
	    }
		break;
		case '/':{
		if(c==0){
			printf("Illeagle expression!!!");
			return 0;
		}
		else{
			result=mid/c;
		};
	    };
		break;
	}
	
	printf("Value of expression: %lf",result);
	
	return 0;
} 
