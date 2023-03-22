/*
 * @author Anger
 * @date 2023/3/21
 * @brief 演示数值溢出
 */
#include <stdio.h>

int int_overflow();

int main() {
    printf("%d\n", int_overflow());
    printf("%d\n", (500 * 400) * 300 * 200);
    printf("%d\n", (500 * 400 * 300) * 200);
    printf("%d\n", (500 * 200) * 300 * 400);

    printf("%f\n", 3.14 + 1e20 - 1e20);
    printf("%f\n", 3.14 + (1e20 - 1e20));

    return 0;
}

int int_overflow() {
    int i = 200 * 300 * 400 * 500;
    return i;
}