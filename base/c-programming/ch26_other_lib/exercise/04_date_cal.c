/*
 * @author Anger
 * @date 2022/10/27
 * @brief 输入一个日期和整数 n ，显示 n 天之后的日期
 */
#include <stdio.h>
#include <time.h>

int main(void) {
    struct tm t;
    int n;

    t.tm_sec = 0;
    t.tm_min = 0;
    t.tm_hour = 0;
    t.tm_isdst = -1;

    printf("输入月份(1 - 12):");
    scanf("%d", &t.tm_mon);
    printf("输入日期：");
    scanf("%d", &t.tm_mday);
    printf("输入年份：");
    scanf("%d", &t.tm_year);
    t.tm_year -= 1900;

    printf("输入未来的天数：");
    scanf("%d", &n);

    t.tm_mday += n;
    mktime(&t);

    printf("\n未来的日期：%.2d/%.2d/%d\n",
           t.tm_mon + 1, t.tm_mday, t.tm_year + 1900);

    return 0;
}