/*
 * @author Anger
 * @date 2022/9/16
 * @brief 提醒列表
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
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

void remind(void) {
    char msgs[REMIND_NUM][MSG_LEN + 3];
    char day_str[3], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind >= REMIND_NUM) {
            printf("-- MSG FULL --");
            break;
        }
        printf("Enter day and msg : ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind ;i++)
            if (strcmp(day_str, msgs[i]) < 0)
                break;

        for (j = num_remind; j > i; j--)
            strcpy(msgs[j], msgs[j - 1]);

        strcpy(msgs[i], day_str);
        strcat(msgs[i], msg_str);

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf("%s\n",msgs[i]);
}
