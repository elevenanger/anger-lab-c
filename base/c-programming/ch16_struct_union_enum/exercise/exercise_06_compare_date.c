/*
 * @author Anger
 * @date 2022/9/26
 * @brief  
 */
#include <stdio.h>
#include <stdbool.h>

struct date {
    int year;
    int month;
    int day;
};

int validation_date(const struct date date) {
    if (date.day <= 0 || date.day > 31 ||
        date.month <= 0 || date.month > 12 ||
        date.year <= 0 ) {
        return 0;
    }
    return 1;
}

int main(void) {
    struct date date_1, date_2;
    bool flag = 0;

    puts("Enter first date : (mm/dd/yy)");
    scanf("%2d%2d%2d", &date_1.month, &date_1.day, &date_1.year);
    if (!validation_date(date_1))
        return 1;

    puts("Enter second date : (mm/dd/yy)");
    scanf("%2d%2d%2d", &date_2.month, &date_2.day, &date_2.year);
    if (!validation_date(date_2))
        return 1;

    if (date_1.year < date_2.year||
        (date_1.year == date_2.year && date_1.month < date_2.month) ||
        (date_1.year == date_2.year && date_1.month == date_2.month &&
        date_1.day < date_2.day))
        flag = 1;

    printf("Early date is : ");

    if (!flag)
        printf("%d/%d/%d", date_2.month, date_2.day, date_2.year);
    else
        printf("%d/%d/%d", date_1.month, date_1.day, date_1.year);

    return 0;
}
