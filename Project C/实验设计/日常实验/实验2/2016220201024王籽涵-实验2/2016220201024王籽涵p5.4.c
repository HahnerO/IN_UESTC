#include <stdio.h>
int main(){
 	int i;
 	printf("Please input the wind speed:");
 	scanf("%d",&i);
 	if(i<1){
	 	printf("Calm");
	 }
    else if(i<3){
    	printf("Light air"); 
    }
    else if(i<27){
    	printf("Breeze");
    }
    else if(i<47){
    	printf("Gale");
   	
    }
    else if(i<63){
    	printf("Storm");
    }
    else {
    	printf("Hurrican");
    }
    return 0; 
}

 