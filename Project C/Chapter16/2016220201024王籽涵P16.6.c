#include <stdio.h>

struct date {
	int day;
    int month;
	int year;
}time1, time2, earlier, later;

int compare_dates(struct date time1, struct date time2);

int main()
{
	printf("Enter first date (mm/dd/yy):");
	scanf("%d/%d/%d", &time1.month, &time1.day, &time1.year);
	printf("Enter second date (mm/dd/yy):");
	scanf("%d/%d/%d", &time2.month, &time2.day, &time2.year);
	
	if (compare_dates(time1, time2) > 0)
		printf("%d/%d/%2d is earlier than %d/%d/%2d\n", time1.month, time2.day, time2.year, time1.month, time1.day, time1.year);
	else if (compare_dates(time1, time2) < 0)
		printf("%d/%d/%2d is earlier than %d/%d/%2d\n", time2.month, time1.day, time1.year, time2.month, time2.day, time2.year);
	else
		printf("%d/%d/%2d is the same as %d/%d/%2d\n", time1.month, time1.day, time1.year, time2.month, time2.day, time2.year);
}

int compare_dates(struct date time1, struct date time2)
{
	if (time1.year > time2.year)
		return 1;
	else if (time1.year < time2.year)
		return -1;
	else{
		if (time1.month > time2.month)
			return 1;
		else if (time1.month < time2.month)
			return -1;
		else{
			if (time1.day > time2.day)
				return 1;
			else if (time1.day < time2.day)
				return -1;
			else
				return 0;
		}
	}
}
