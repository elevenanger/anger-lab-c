/*
 * @author 刘昂林 
 * @date 2022/8/30
 * @brief 以 mm/dd/yyyy 接收用户输入的数据，格式化为 yyyymmdd 格式
 */
#include <stdio.h>

int main(void) {
    int year, month, day;

    puts("Enter date (mm/dd/yyyy)");

    scanf("%d/%d/%d", &month, &day, &year);

    puts("You entered the date : ");

    printf("%4d/%2d/%2d", year, month, day);

    return 0;
}