/* A simple reminder system */


#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60
#define LEN 3

int read_line(char str[], int n);

int main()
{
    char reminders[MAX_REMIND][MSG_LEN+3];
    char mon_str[LEN], day_str[LEN], hour_str[LEN], min_str[LEN], time_str[12], msg_str[MSG_LEN];
    int month, day, hour, min;
    int num_reminder = 0;
    int i, j;
    
    
    printf("Please Enter time and reminder in the frame like month/date hour:minite(24hours)!~\n");
    
    for (;;)
    {
        if (num_reminder == MAX_REMIND){
            printf("\n-- No space left --\n");
            break;
        }
        
        printf("Enter and reminder: ");
        scanf("%d/%d %d:%d", &month, &day, &hour, &min);
        
        if (month > 12 || month < 0 || day > 31 || day < 0 || hour > 24 || hour < 0 || min > 60 || min < 0){
            printf("Default time.\n");
            continue;
        }
        if (month == 0)
            break;
        
        sprintf(mon_str, "%2d", month);
        strcpy(time_str, mon_str);
        strcat(time_str, "/");
        sprintf(day_str, "%2d", day);
        strcat(time_str, day_str);
        strcat(time_str, "\t");
        sprintf(hour_str, "%2d", hour);
        strcat(time_str, hour_str);
        strcat(time_str, ":");
        sprintf(min_str, "%2d", min);
        strcat(time_str, min_str);
        
        read_line(msg_str, MSG_LEN);
        
        for (i = 0; i < num_reminder; i++)
            if (strcmp(time_str, reminders[i]) < 0)
                break;
        for (j = num_reminder; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);
        
        strcpy(reminders[i], time_str);
        strcat(reminders[i], "\t");
        strcat(reminders[i], msg_str);
        num_reminder++;
    }
    
    printf("\nDay Reminder\n");
    for (i = 0; i < num_reminder; i++)
        printf(" %s\n", reminders[i]);
    
    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
