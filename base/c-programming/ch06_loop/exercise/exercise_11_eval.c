/*
 * @author Anger
 * @date 2022/9/1
 * @brief 计算 e 的近似值
 */
#include <stdio.h>

int factorial(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return n * factorial(n - 1);
}

int main(void) {

    int n;
    float e_val = 1;
    printf("Enter a number : ");
    scanf("%d", &n);

    while (n > 0)
        e_val += (1.0f / (float) factorial(n--));

    printf("e : %20.19f ", e_val);

    return 0;
}