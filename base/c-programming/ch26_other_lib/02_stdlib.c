/*
 * @author Anger
 * @date 2022/10/27
 * @brief 通用实用工具
 */
#include <stdio.h>
#include <stdlib.h>

/* 数值转换函数 */
void numeric_transfer_functions(const char *number_str);

int main(void) {

    numeric_transfer_functions("100.2");

    return 0;
}

void numeric_transfer_functions(const char *number_str) {
    printf("atof 转换成 double 类型数值 => %g\n", atof(number_str));
    printf("atoi 转换成 int 类型数值 => %d\n", atoi(number_str));
    printf("atol 转换成 long int 类型数值 => %ld\n", atol(number_str));
    printf("atoll 转换成 long long int 类型数值 => %lld\n", atoll(number_str));

    char *end;
    printf("strtod 转换成 double 类型数值 => %g\n", strtod(number_str, &end));
    printf("strtol 转换成 long int 类型数值 => %ld\n", strtol(number_str, &end, 10));
}
