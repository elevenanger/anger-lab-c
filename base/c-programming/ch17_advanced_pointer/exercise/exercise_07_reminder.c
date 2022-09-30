/*
 * @author Anger
 * @date 2022/9/30
 * @brief 优化 reminder 程序，使得数组中的每个元素指向 vstring 结构指针
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

struct v_string {
    int len;
    char str[];
};

int read_line(char str[], int n);

int main(void) {
    struct v_string *reminders[MAX_REMIND];
    char day_str[3], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left -- ");
            break;
        }

        printf("Enter day and reminder : ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);

        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]->str) < 0)
                break;

        for (j = num_remind; j > i; j--) {
            strcpy(reminders[j]->str, reminders[j - 1]->str);
            reminders[j]->len = reminders[j - 1]->len;
        }

        reminders[i] = malloc(2 + strlen(msg_str) + 1);
        if (reminders[i] == NULL) {
            printf("-- No space left --\n");
            break;
        }

        strcpy(reminders[i]->str, day_str);
        strcat(reminders[i]->str, msg_str);
        reminders[i]->len = strlen(day_str) + strlen(msg_str);

        num_remind++;
    }

    printf("\nDay reminder\n");
    for (i = 0; i < num_remind; ++i)
        printf(" %s\n", reminders[i]->str);

    return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = (char) ch;
    str[i] = '\n';
    return i;
}
