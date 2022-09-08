/*
 * @author Anger
 * @date 2022/9/8
 * @brief 编写函数，对多项式求值
 * 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
 */
#include <stdio.h>

int polynomial_evaluation(int x) {
    return (3 * x + 2) * (x - 5) * (x + 7) * x - 6;
}

int main(void) {
    int x;
    printf("Enter a integer : ");
    scanf("%d", &x);
    printf("result : %d", polynomial_evaluation(x));
    return 0;
}