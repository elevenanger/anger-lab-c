/**
* 输入 24 小时制时间
* 显示 12 小时制时间
*/
#include <stdio.h>

int main(void) {
    int hour, minute;

    puts("Enter 24-hour-time : ");
    scanf("%2d:%2d", &hour, &minute);

    if (hour < 0 || hour > 23 ||
            minute < 0 || minute > 60)
        return 1;

    printf("Equivalent 12-hour time : ");

    if (hour == 12)
        printf("%d:%d PM", hour, minute);
    else if (hour > 12)
        printf("%d:%d PM", hour - 12, minute);
    else
        printf("%d:%d AM", hour, minute);

    return 0;
}