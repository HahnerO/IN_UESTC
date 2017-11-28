#include <stdio.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main()
{
	int hour, minute, sum_minute, departure, arrival, departure_hour, departure_minute, arrival_hour, arrival_minute;
	
	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &minute);
	sum_minute = 60*hour + minute;
	
	find_closest_flight(sum_minute, &departure, &arrival);
	
	departure_hour = departure / 60;
	departure_minute = departure % 60;
	arrival_hour = arrival / 60;
	arrival_minute = arrival % 60;
	
	printf("Closesst departure time is %2d:%.2d a.m., arriving at %2d:%.2d a.m.\n", departure_hour, departure_minute, arrival_hour, arrival_minute);
	return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
	if (desired_time <= 531)
	{
		*departure_time = 480;
		*arrival_time = 616;
	}
    else if (desired_time <= 631)
    {
		*departure_time = 583;
		*arrival_time = 712;
	}
    else if (desired_time <= 723)
    {
		*departure_time = 679;
		*arrival_time = 811;
	}
    else if (desired_time <= 803)
    {
		*departure_time = 734;
		*arrival_time = 900;
	}
    else if (desired_time <= 892)
    {
		*departure_time = 840;
		*arrival_time = 968;
	}
    else if (desired_time <= 1042)
    {
		*departure_time = 945;
		*arrival_time = 1075;
	}
    else if (desired_time <= 1222)
    {
		*departure_time = 1140;
		*arrival_time = 1280;
	}
    else
    {
		*departure_time = 1305;
		*arrival_time = 1438;
	}
}
