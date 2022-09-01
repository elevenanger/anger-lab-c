/*
 * @author Anger
 * @date 2022/9/1
 * @brief 输入当月的天数和第一天是星期几
 * 展示当月的日历
 */
#include <stdio.h>

int main(void) {

    int days, start_day_of_week;

    printf("Enter number of days in month : ");
    scanf("%d", &days);

    printf("\n Enter starting day of the week : ");
    scanf("%d", &start_day_of_week);

    for (int i = 1; i < days + start_day_of_week; ++i) {
        if (i < start_day_of_week) {
            printf("   ") ;
            continue;
        }

        printf("%3d", i - start_day_of_week + 1);
        if (i % 7 == 0)
            printf("\n");
    }

    return 0;
}