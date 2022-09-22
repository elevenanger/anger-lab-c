/*
 * @author Anger
 * @date 2022/9/22
 * @brief  
 */
#include <stdio.h>
#include <string.h>
#include "readline.h"

#define REMIND_NUM  50
#define MSG_LEN     32

int main(void) {
    char msgs[REMIND_NUM][MSG_LEN + 12];
    char time_str[12], month_str[3], day_str[3], hour_str[3], msg_str[MSG_LEN + 1];
    int month, day, hour, i, j, num_remind = 0;

    for (;;) {
        if (num_remind >= REMIND_NUM) {
            printf("-- MSG FULL --");
            break;
        }
        printf("Enter month day hour and msg : ");
        scanf("%2d %2d %2d", &month, &day, &hour);

        if (month <= 0 || month > 12) {
            printf("error month => %d\n", month);
            continue;
        }
        if (day < 0 || day > 31) {
            printf("error day => %d\n", day);
            continue;
        }
        if (hour < 0 || hour > 23) {
            printf("error hour => %d\n", hour);
            continue;
        }
        if (day == 0)
            break;

        sprintf(month_str, "%02d", month);
        sprintf(day_str, "%02d", day);
        sprintf(hour_str, "%02d", hour);
        strcpy(time_str, month_str);
        strcat(time_str, " ");
        strcat(time_str, day_str);
        strcat(time_str, " ");
        strcat(time_str, hour_str);
        strcat(time_str, " : ");

        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind ;i++)
            if (strcmp(month_str, msgs[i]) < 0)
                break;

        for (j = num_remind; j > i; j--)
            strcpy(msgs[j], msgs[j - 1]);

        strcpy(msgs[i], time_str);
        strcat(msgs[i], msg_str);

        num_remind++;
    }

    printf("\nReminder\n");
    for (i = 0; i < num_remind; i++)
        printf("%s\n",msgs[i]);
    return 0;
}