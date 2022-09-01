/*
 * @author Anger
 * @date 2022/9/1
 * @brief 输入多个日期
 * 直到输入 0/0/0 则不在输入
 * 最终展示最早的日期
 */
#include <stdio.h>

int y = 99, m = 12, d = 31;

void earlier_date(int year, int month, int day) {
    if (year < y ||
        (year == y && month < m) ||
        (year == y && month == m && day < d)) {
        y = year;
        m = month;
        d = day;
    }
}

int main(void) {
    int year, month, day;

    while (1) {
        printf("Enter a date : (mm dd yy) ");
        scanf("%2d %2d %2d", &month, &day, &year);
        if (year + month + day == 0) break;
        earlier_date(year, month, day);
    }
    printf("%d/%d/%d is earliest date.", m, d, y);
}