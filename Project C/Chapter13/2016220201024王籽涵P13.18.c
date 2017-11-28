#include <stdio.h>
#include <string.h>

int main()
{
	int month, day, year;
	char *months[] = {"January", "February", "March", "Apirl", "May", "June", "July", 
					  "August", "September", "October", "November", "December"};
 	
 	printf("Enter a date (mm/dd/yyyy): ");
 	scanf("%d/%d/%d", &month, &day, &year);
 	printf("You entered the date %s %2d, %4d\n", months[month-1], day, year);
 	
 	return 0;
}
