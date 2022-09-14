/*
 * @author Anger
 * @date 2022/9/14
 * @brief 指针和变长数组
 * 指针在变长数组中的使用方式与在普通数组中的使用方式基本一致
 */
#include <stdio.h>

void f(int n);
void g(int m, int n);

int main(void) {
    f(10);
    g(3, 5);
    return 0;
}

void f(int n) {
    int a[n], *p, sum = 0;
    p = a;
    while (p < a + n) {
        *p = 10;
        sum += *p;
        p++;
    }
    printf("sum >=> %d\n", sum);
}

void g(int m, int n) {
    int a[m][n], (*p)[n], *q;
    p = a;

    for (q = &a[0][0]; q <= &a[m - 1][n - 1]; q++)
        *q = 10;

    while (p < &a[m]) {
        (*p)[n - 1] = 11;
        p++;
    }

    for (q = &a[0][0]; q <= &a[m - 1][n - 1]; q++)
        printf("%d ", *q);
    printf("\n");
}
