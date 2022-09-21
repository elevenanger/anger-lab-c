/*
 * @author Anger
 * @date 2022/9/19
 * @brief 输入 mm/dd/yyyy
 * 输出 月（英文全名） 日 年
 */
#include <stdio.h>

int main(void) {

    char year[5], month[3], day[3];

    printf("Enter a date (mm/dd/yyyy) : ");
    scanf("%2s/%2s/%4s/", month, day, year);

    printf("You Entered date => %s %s,%s\n", month, day, year);

    return 0;
}