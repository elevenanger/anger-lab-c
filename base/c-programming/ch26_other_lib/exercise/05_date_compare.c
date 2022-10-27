/*
 * @author Anger
 * @date 2022/10/27
 * @brief 输入两个日期，显示差值
 */
#include <time.h>
#include <stdio.h>

int main(void) {

    struct tm t1, t2;

    t1.tm_sec = 0;
    t1.tm_min = 0;
    t1.tm_hour = 0;
    t1.tm_isdst = -1;
    t2 = t1;

    printf("Date 1: Enter month (1-12): ");
    scanf("%d", &t1.tm_mon);
    t1.tm_mon--;

    printf("Date 1: Enter day (1-31): ");
    scanf("%d", &t1.tm_mday);

    printf("Date 1: Enter year (1900+): ");
    scanf("%d", &t1.tm_year);
    t1.tm_year -= 1900;

    printf("Date 2: Enter month (1-12): ");
    scanf("%d", &t2.tm_mon);
    t2.tm_mon--;

    printf("Date 2: Enter day (1-31): ");
    scanf("%d", &t2.tm_mday);

    printf("Date 2: Enter year (1900+): ");
    scanf("%d", &t2.tm_year);
    t2.tm_year -= 1900;

    printf("Days between dates: %d\n",
           (int) (difftime(mktime(&t2), mktime(&t1)) / 60/60/24));

    return 0;
}