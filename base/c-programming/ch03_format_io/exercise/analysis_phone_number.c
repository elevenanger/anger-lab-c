/*
 * @author 刘昂林 
 * @date 2022/8/30
 * @brief 解析电话号码
 */
#include <stdio.h>

int main() {
    int country_code, state_code, number;

    puts("Enter phone number [(xxx) xxx-xxxx] : ");

    scanf("(%d) %d-%d", &country_code, &state_code, &number);

    printf("You entered : %d.%d.%d\n", country_code, state_code, number);

    return 0;
}