/*
 * @author Anger
 * @date 2022/9/1
 * @brief 输入两个数字
 * 计算它们的最大公约数
 */
#include <stdio.h>
#include "greatest_divisor.h"

int largest_divisor(int m, int n) {
    int d;

    if (m == 0 || n ==0) return 1;

    if (m == n) goto output;

    /*
     * 确保 m 总是较大的数字
     */
    if (m < n) {
        d = m;
        m = n;
        n = d;
    }

    /*
     * m 与 n 取余数
     * 将余数的值付给 n
     * 将 n 的值付给 m
     * 直到 n = 0
     */
    while (n != 0) {
        d = n;
        n = m % n;
        m = d;
    }

    output:
    printf("Greatest common divisor : %d\n", m);

    return m;
}

int i_main() {
    int m, n;

    printf("Enter two number : ");
    scanf("%d%d", &m, &n);
    largest_divisor(m, n);
    return 0;
}