/*
 * @author Anger
 * @date 2022/9/5
 * @brief 修改 interest 程序
 * 使得修改后的程序可以每月整合一次利息
 * 而不是每年整合一起利息
 * 但是不要改变程序的输出格式
 * 还是按年输出余额
 */
#include <stdio.h>
#define SIZE(a) (int) (sizeof(a) / sizeof(a[0]))

int main(void) {

    int interest, year, initial_value = 100;
    double values[5];

    printf("Enter interest rate : ");
    scanf("%d", &interest);
    puts("");

    printf("Enter number of years : ");
    scanf("%d", &year);
    puts("");

    for (int i = 0; i < SIZE(values); ++i)
        values[i] = initial_value;

    printf("\nYears   ");
    for (int i = 0; i < SIZE(values); ++i)
        printf("%5d%%  ", interest + i);
    puts("");

    for (int i = 1; i <= year ; ++i) {
        printf("%3d     ", i);
        for (int j = 0; j < SIZE(values); ++j) {
            values[j] += (double)(interest + j) / 100 * values[j];
            printf("%7.2f ", values[j]);
        }
        puts("");
    }
    puts("");

    return 0;
}