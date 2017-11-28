/*Frame the statistics inputed by users*/

#include <stdio.h>

int main(void)
{
	int d,a,b,c;
	float f;
	
	printf("Enter item number: ");
	scanf("%d",&d);
	printf("Enter unit price: ");
	scanf("%f",&f);
	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%d/%d/%d",&a,&b,&c);
	
	printf("Item\t Unit\t\t Purchase\n\t Price\t\t Date\n%d\t $ %.2f\t %d/%d/%d",d,f,a,b,c);
}
