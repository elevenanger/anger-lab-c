/*
 * 输入两个日期
 * 展示更早的日期
 */
#include <stdio.h>
#include <stdbool.h>

int validation_date(int year, int month, int day) {
    if (day <= 0 || day > 31 ||
        month <= 0 || month > 12 ||
        year <= 0 ) {
        return 0;
    }
    return 1;
}

int main(void) {
    int year1, month1, day1,
        year2, month2, day2;
    bool flag = 0;

    puts("Enter first date : (mm/dd/yy)");
    scanf("%2d%2d%2d", &month1, &day1, &year1);
    if (!validation_date(year1, month1, day1))
        return 1;

    puts("Enter second date : (mm/dd/yy)");
    scanf("%2d%2d%2d", &month2, &day2, &year2);
    if (!validation_date(year2, month2, day2))
        return 1;

    if (year1 < year2 ||
            (year1 == year2 && month1 < month2) ||
            (year1 == year2 && month1 == month2 && day1 < day2))
        flag = 1;

    printf("Early date is : ");

    if (!flag)
        printf("%d/%d/%d", month2, day2, year2);
    else
        printf("%d/%d/%d", month1, day1, year1);

    return 0;
}