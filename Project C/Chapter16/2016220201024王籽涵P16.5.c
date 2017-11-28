#include <stdio.h>
#include <stdlib.h>

#define N sizeof(flights)/sizeof(flights[0])

struct time {
	int depart_time;
	int arrive_time;
};

int main()
{
	int h, m, z, i, min, min_num;
	struct time times[MAX] = 
    {{8*60, 10*60+16}, {9*60+43, 11*60+52},
        {11*60+19, 13*60+31}, {12*60+47, 15*60},
        {14*60, 16*60+8}, {15*60+45, 17*60+55},
        {19*60, 21*60+20}, {21*60+45, 23*60+58}};
    
	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &h, &m);
	z = 60*h + m;
	
	min = 1305;
	
	for (i = 0; i < MAX; i++)
		if (abs(z - times[i].put_time) < min){
			min = abs(z - times[i].put_time);
			min_num = i;
		}
	
	printf("Closesst departure time is  %2d:%.2d,arriving at  %2d:%.2d\n", times[min_num].put_time/60, times[min_num].put_time%60, times[min_num].arrive_time/60, times[min_num].arrive_time%60);
    
	return 0;
}
