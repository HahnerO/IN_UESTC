//
//  main.c
//  Painter
//
//  Created by 王籽涵 on 2016/12/03.
//  Copyright © 2016年 Hahn. All rights reserved.

/* Find out the closest flight(pointer version) */

#include <stdio.h>

void find_closest_flight (int desired_time, int *departure_time, int *arrival_time);

int main(void)
{

    
    int depart, arrive, min, hour, total_min;
    int *departure_time = &depart, *arrival_time = &arrive;
    
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);
    total_min = 60 * hour + min;
   
    find_closest_flight(total_min, departure_time, arrival_time);
    
    printf("Closesst departure time is %2d:%.2d a.m., ", depart / 60, depart % 60);
    printf("arriving at %2d:%.2d a.m.\n", arrive / 60, arrive % 60);

    return 0;
} 


void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    if (desired_time <= 531){
        *departure_time = 480;
        *arrival_time = 616;
    }
    
    else if (desired_time <= 631){
        *departure_time = 583;
        *arrival_time = 712;
    }
    
    else if (desired_time <= 723){
        *departure_time = 679;
        *arrival_time = 811;
    }
    
    else if (desired_time <= 803){
        *departure_time = 734;
        *arrival_time = 900;
    }
    
    else if (desired_time <= 892){
        *departure_time = 840;
        *arrival_time = 968;
    }
    
    else if (desired_time <= 1042){
        *departure_time = 945;
        *arrival_time = 1075;
    }
    
    else if (desired_time <= 1222){
        *departure_time = 1140;
        *arrival_time = 1280;
    }
    
    else {
        *departure_time = 1305;
        *arrival_time = 1438;
    }
}
