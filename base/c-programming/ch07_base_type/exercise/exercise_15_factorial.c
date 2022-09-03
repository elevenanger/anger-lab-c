/*
 * @author Anger
 * @date 2022/9/3
 * @brief 使用各个基础数值类型存储阶乘的值
 * 计算各种数值类型可以存储的最大的阶乘的数是多少
 */
#include <stdio.h>

unsigned long factorial(unsigned long n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

int main(void) {

    unsigned long l = 1;

    while ((short) factorial(l++));
    printf("Max factorial short : %d\n", (short) l);

    l = 1;
    while ((long) factorial(l++));
    printf("Max factorial long : %ld\n", (long) l);

    l = 1;
    while ((float) factorial(l++));
    printf("Max factorial float : %f\n", (float) l);


    l = 1;
    while ((double) factorial(l++));
    printf("Max factorial double: %f\n", (double) l);

    l = 1;
    while ((long double) factorial(l++));
    printf("Max factorial long double : %Lf\n", (long double) l);

    return 0;
}