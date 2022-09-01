/*
 * @author Anger
 * @date 2022/9/1
 * @brief 输入一个数字
 * 输出数字的逆序
 */
#include <stdio.h>

int reverse_number(int n) {
    int r = 0;
    if (n < 10) return n;

    do {
        r *= 10;
        r += (n % 10);
    } while ((n /= 10) > 0);

    return r;
}

int main(void) {

    int n;

    printf("Enter a number : ");

    scanf("%d", &n);

    printf("reversal number : %d\n", reverse_number(n));

    return 0;
}