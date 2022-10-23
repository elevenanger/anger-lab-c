/*
 * @author Anger
 * @date 2022/10/23
 * @brief 计算复利
 */
#include <stdio.h>
#include <math.h>

int main(void) {

    double a, p, r;
    int t;

    printf("输入存款金额：");
    scanf("%lf", &p);
    printf("输入利率：");
    scanf("%lf", &r);
    printf("输入存款年份：");
    scanf("%d", &t);

    r /= 100;
    a = p * exp(r * t);

    printf("总金额：%g\n", a);

    return 0;
}