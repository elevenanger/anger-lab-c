/*
 * @author Anger
 * @date 2022/9/17
 * @brief 对于提醒程序进行改造
 * 1、如果输入的日期为负数或者大于 31  程序显示错误信息，忽略错误提醒
 * 2、允许用户输入日期、24小时格式的时间和提醒。显示的提醒必须先按日期排序，再按照时间排序
 * 3、程序显示一年的提醒列表，要求按照 月/日 的格式输入信息
 */
#include <string.h>
#include <stdio.h>

#define MSG_LEN 50
#define REMIND_NUM 32

int read_line(char str[], int n);
void remind(void);

int main(void) {
    remind();
    return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

void remind(void) {
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
}
