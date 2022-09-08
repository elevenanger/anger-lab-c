/*
 * @author Anger
 * @date 2022/9/8
 * @brief 使用递归的方式求次幂
 * 以此计算多项式
 */
#include <stdio.h>

int power(int x, int p);

int power(int x, int p) {
    int result = 1;
    if (p == 0) return result;
    if (p % 2 != 0) result = x * power(x, p - 1);
    else {
        result = power(x, p / 2) * power(x, p / 2);
    }
    return result;
}

int main(void) {
    int p1 , p2;
    printf("Enter two integer to val power : ");
    scanf("%d %d", &p1, &p2);
    printf("result => %d\n", power(p1, p2));
    return 0;
}